//Main.cpp
//David Sylvestre et Dominic Clément
//8 novembre 2014
//Ce fichier gère une file d'attente par un menu
//défini ici-même


#include "ClientEnAttente.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "FileAttente.h"
#include <list>
#include <iterator>

using namespace std;

//Affiche les différents choix du menu
void AfficherMenu()
{
   cout << "1. Ajouter un client dans la file" << endl;
   cout << "2. Assigner une table" << endl;
   cout << "3. Retirer un client de la file" << endl;
   cout << "4. Afficher un client de la file" << endl;
   cout << "5. Afficher la file d'attente en entier" << endl;
   cout << "6. Quitter le programme" << endl << endl;
   cout << "Votre choix? ";

   list<int> d;
   d.begin() + 1;
}

list<int>::iterator operator+ (list<int>::iterator it, int n)
{
	return ++it;
}

//La fonction montre un menu permettant de choisir une seule section
//et renvoie le choix
SectionInteressees ChoisirSectionResto()
{
   SectionInteressees sections;
   int indice;

   cout << "Veuillez choisir une section:" << endl;
   cout << "1. Terrasse fumeur" << endl;
   cout << "2. Terasse non fumeur" << endl;
   cout << "3. Salle a manger" << endl;

   do
   {
      cin >> indice;

      if (indice < 1 || indice > NB_SECTIONS)
         cout << "Valeur invalide, veuillez en entrer une autre" << endl;

   } while (indice < 1 || indice > NB_SECTIONS);
   sections = static_cast<SectionInteressees>(static_cast<int>(pow(2, indice - 1)));
   cout << endl;

   return sections;
}

//La fonction montre un menu permettant de montrer son intérêt dans les 
//trois sections en même temps et renvoie le choix sous forme de flag binaire
SectionInteressees ChoisirSectionClient()
{
   SectionInteressees sections;
   string section;
   char choix;

   do
   {
      sections = static_cast<SectionInteressees>(0);

      for (int i = 0; i < NB_SECTIONS; i++)
      {


         switch (i)
         {
         case 0: section = "terasse fumeur"; break;
         case 1: section = "terasse non fumeur"; break;
         case 2: section = "salle a manger"; break;
         }

         cout << "Le client est-il interesse par la " << section << " (O ou N) ";
         cin >> choix;

         if (toupper(choix) == 'O')
            sections = sections | static_cast<SectionInteressees>(static_cast<int>(pow(2, i)));
      }

      if (sections == 0)
      {
         cout << "Vous devez choisir au moins une section" << endl;
         system("pause");
         cout << endl;
      }
   } while (sections == 0);

   return sections;
}

//La fonction montre un menu permettant de choisir le nombre de personne
//qui sont avec le client et le renvoie
int ChoisirNbPersonnes(bool placeTable)
{
   int nbPersonnes;

   if (placeTable)
      cout << "Veuillez entrer le nombre de places presentes a la table: ";
   else
      cout << "Veuillez entrer le nombre de personnes qui sont avec le client: ";
   cin >> nbPersonnes;

   return nbPersonnes;
}

//La fonction affiche un menu demandant le nom d'un client et le renvoie
string ChoisirNomClient()
{
   string nom;

   cout << "Veuillez entrer le nom du client: ";
   cin >> nom;

   return nom;
}

void GererMenu(FileAttente &file, int &choixUtilisateur)
{
   int indiceClient;
   char choix;

   switch (choixUtilisateur)
   {
   case 1:
      file.Ajouter(Client(ChoisirNomClient(), ChoisirNbPersonnes(false), ChoisirSectionClient()));
      break;

   case 2:
      cout << "Client retire: " << endl <<
         file.Retirer(ChoisirNbPersonnes(true), ChoisirSectionResto()).ToString() << endl;
      break;

   case 3:
      if (file.Retirer(ChoisirNomClient(), ChoisirNbPersonnes(false)))
         cout << "La personne a ete retire avec succes" << endl;
      else
         cout << "Impossible de trouver la personne dans la file" << endl;
      break;

   case 4:
      cout << "Veuillez entrer l'indice du client: ";
      cin >> indiceClient;
      cout << file.GetClient(indiceClient);
      break;

   case 5:
      file.Afficher(cout);
      break;

   case 6:
      if (!file.EstVide())
      {
         cout << "La file n'est pas vide. Voulez-vous vraiment quitter? O ou N ";
         cin >> choix;
         if (toupper(choix) != 'O')
            choixUtilisateur = 0;
      }
      break;

   default:
      cout << "Valeur invalide." << endl;
      break;
   }

}

//La fonction gère les 6 choix du menu selon le choix de l'utilsateur
int main()
{
   int choixUtilisateur;
   FileAttente file;
   const int choixPourSortir = 6;

   do
   {
      std::system("cls");
      AfficherMenu();
      cin >> choixUtilisateur;

      try
      {
         GererMenu(file, choixUtilisateur);
      }
      catch (exception e)
      {
         cerr << e.what() << endl;
      }

      std::system("pause");
   } while (choixUtilisateur != choixPourSortir);

   //Après la sortie du programme
   cout << "Nombre de personnes assignes: " << file.GetNbPersonnesAssignes() << endl;
   cout << "Nombre de groupes assignes: " << file.GetNbGroupesAssignes() << endl;
   cout << "Nombre de personnes restantes dans la file: " << file.ObtenirNbPersonnes() << endl;
   cout << "Nombre de groupes restants dans la file: " << file.ObtenirNbGroupes() << endl << endl;
}