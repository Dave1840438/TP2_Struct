//Client.h
//David Sylvestre et Dominic Clément
//8 novembre 2014
//Déclaration de la structure Client et de l'énumération
//des sections du restaurent

#pragma once
#include <string>

using namespace std;

//Constante représentant le nombre de sections
const int NB_SECTIONS = 3;

//Énumération des sections du restaurent
enum SectionInteressees
{
   TerrasseFumeur = 1, TerrasseNonFumeur = 2, SalleAManger = 4
};

//Opérateur pour concaténer les valeurs de l'énumération
inline SectionInteressees operator| (SectionInteressees a, SectionInteressees b)
{
   return static_cast<SectionInteressees>(static_cast<int>(a) | static_cast<int>(b));
}

//Opérateur pour tester si la valeur de l'énumération se trouve dans une combinaison de celle-ci
inline bool operator& (SectionInteressees test, SectionInteressees testé)
{
   return ((static_cast<int>(test) & static_cast<int>(testé)) != 0);
}

//Représente les informations d'un client
struct Client
{
	//Variables publiques
   string nom_;
   int nbPersonnes_;
   SectionInteressees sections_;

   //Constructeur paramétrique
   Client(string nom, int nbPersonnes, SectionInteressees sections) : nom_(nom), nbPersonnes_(nbPersonnes), sections_(sections)
   {
      if (nbPersonnes < 0) throw (exception("Le nombre de personne ne peut pas etre negatif"));
   }

   //Fonction renvoyant les informations du client dans une chaine de caractère
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

