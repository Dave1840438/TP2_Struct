//Client.h
//David Sylvestre et Dominic Cl�ment
//8 novembre 2014
//D�claration de la structure Client et de l'�num�ration
//des sections du restaurent

#pragma once
#include <string>

using namespace std;

//Constante repr�sentant le nombre de sections
const int NB_SECTIONS = 3;

//�num�ration des sections du restaurent
enum SectionInteressees
{
   TerrasseFumeur = 1, TerrasseNonFumeur = 2, SalleAManger = 4
};

//Op�rateur pour concat�ner les valeurs de l'�num�ration
inline SectionInteressees operator| (SectionInteressees a, SectionInteressees b)
{
   return static_cast<SectionInteressees>(static_cast<int>(a) | static_cast<int>(b));
}

//Op�rateur pour tester si la valeur de l'�num�ration se trouve dans une combinaison de celle-ci
inline bool operator& (SectionInteressees test, SectionInteressees test�)
{
   return ((static_cast<int>(test) & static_cast<int>(test�)) != 0);
}

//Repr�sente les informations d'un client
struct Client
{
	//Variables publiques
   string nom_;
   int nbPersonnes_;
   SectionInteressees sections_;

   //Constructeur param�trique
   Client(string nom, int nbPersonnes, SectionInteressees sections) : nom_(nom), nbPersonnes_(nbPersonnes), sections_(sections)
   {
      if (nbPersonnes < 0) throw (exception("Le nombre de personne ne peut pas etre negatif"));
   }

   //Fonction renvoyant les informations du client dans une chaine de caract�re
   string ToString()
   {
      string resultat = "Nom du client: " + nom_ + "\nNombre de personnes: " + 
         to_string(nbPersonnes_) + "\nSection(s) voulue(s): ";

      if (sections_ & TerrasseFumeur)
         resultat += "Terasse fumeur   "; 

      if (sections_ & TerrasseNonFumeur)
         resultat += "Terasse non fumeur   "; 

      if (sections_ & SalleAManger)
         resultat += "Salle a manger";

      return resultat;
   }

};

