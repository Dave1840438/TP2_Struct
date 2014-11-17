//FileAttente.h
//David Sylvestre et Dominic Clément
//8 novembre 2014
//Déclaration de la classe FileAttente

#pragma once
#include "ClientEnAttente.h"
#include "Client.h"
#include <iostream>

//Nombre de caractère de la console en largeur
const int LargeurConsole = 80;

//Conteneur du file doublement chainée
class FileAttente
{
	//Déclaration des variables privées
	ClientEnAttente* premier_;
	ClientEnAttente* dernier_;
	int nbElements_;
   int nbPersonnesAssignes_;
   int nbGroupesAssignes_;

	//Retire un noeud de la file
	void Retirer(ClientEnAttente* client);

public:
	//Constructeur par défaut
	FileAttente() : premier_(0), dernier_(0), nbElements_(0), nbGroupesAssignes_(0), nbPersonnesAssignes_(0) {}

   //Gets
   int GetNbPersonnesAssignes() { return nbPersonnesAssignes_; }
   int GetNbGroupesAssignes() { return nbGroupesAssignes_; }

	//Renvoie un booléen pour dire si la file est vide
	bool EstVide();

	//Renvoie le nombre de groupes dans la file
	int ObtenirNbGroupes();

	//Retourne le nombre de personnes présentes dans la file
	int ObtenirNbPersonnes();

	//Ajoute un nouveau client dans la file
	void Ajouter(Client clientAMettreEnFile);

	//Retire un client à une table selon la meilleur groupe
	Client FileAttente::Retirer(int nbPlacesDeLaTable, SectionInteressees sectionDeLaTable);

	//Retire une personne qui veut partir de la file
	bool Retirer(string nomClient, int nbPersonnes);

	//Affiche le file au complet
	void Afficher(ostream& out);

	//Retourne une chaine de caractère représentant les informations d'un client
	string GetClient(int indice);
};