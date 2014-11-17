//FileAttente.h
//David Sylvestre et Dominic Cl�ment
//8 novembre 2014
//D�claration de la classe FileAttente

#pragma once
#include "ClientEnAttente.h"
#include "Client.h"
#include <iostream>

//Nombre de caract�re de la console en largeur
const int LargeurConsole = 80;

//Conteneur du file doublement chain�e
class FileAttente
{
	//D�claration des variables priv�es
	ClientEnAttente* premier_;
	ClientEnAttente* dernier_;
	int nbElements_;
   int nbPersonnesAssignes_;
   int nbGroupesAssignes_;

	//Retire un noeud de la file
	void Retirer(ClientEnAttente* client);

public:
	//Constructeur par d�faut
	FileAttente() : premier_(0), dernier_(0), nbElements_(0), nbGroupesAssignes_(0), nbPersonnesAssignes_(0) {}

   //Gets
   int GetNbPersonnesAssignes() { return nbPersonnesAssignes_; }
   int GetNbGroupesAssignes() { return nbGroupesAssignes_; }

	//Renvoie un bool�en pour dire si la file est vide
	bool EstVide();

	//Renvoie le nombre de groupes dans la file
	int ObtenirNbGroupes();

	//Retourne le nombre de personnes pr�sentes dans la file
	int ObtenirNbPersonnes();

	//Ajoute un nouveau client dans la file
	void Ajouter(Client clientAMettreEnFile);

	//Retire un client � une table selon la meilleur groupe
	Client FileAttente::Retirer(int nbPlacesDeLaTable, SectionInteressees sectionDeLaTable);

	//Retire une personne qui veut partir de la file
	bool Retirer(string nomClient, int nbPersonnes);

	//Affiche le file au complet
	void Afficher(ostream& out);

	//Retourne une chaine de caract�re repr�sentant les informations d'un client
	string GetClient(int indice);
};