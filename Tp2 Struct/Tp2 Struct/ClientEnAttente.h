//ClientEnAttente.h
//David Sylvestre et Dominic Cl�ment
//8 novembre 2014
//D�claration de la classe ClientEnAttente

#pragma once
#include "Client.h"

//Repr�sente un noeud dans une file doublement chain�e
class ClientEnAttente
{
	//D�claration des membres priv�es
	Client client_;
	ClientEnAttente* precedent_;
	ClientEnAttente* suivant_;

public:

	//Constructeur qui prend un client en param�tre
	ClientEnAttente(Client client) : client_(client), precedent_(0), suivant_(0){}

	//Retounr le client contenu dans le noeud
	Client GetClient() { return client_; }

	//Retourne les sections qui sont d�sir�es par client contenu dans le noeud
	SectionInteressees GetSections() { return client_.sections_; }

	//Retounr le nom du client contenu dans le noeud
	string GetNomClient() { return client_.nom_; }

	//Retourne le nombre de personnes qui sont avec le client contenu dans le noeud
	int GetNombrePersonnes() { return client_.nbPersonnes_; }

	//Retounr un pointeurs vers le noeud suivant
	ClientEnAttente* GetSuivant() { return suivant_; }

	//Retounr un pointeurs vers le noeud pr�c�dent
	ClientEnAttente* GetPrecedent() { return precedent_; }

	//Affecte un pointeur vers le suivant au noeud
	void SetSuivant(ClientEnAttente* client) { suivant_ = client; }

	//Affecte un pointeur vers le pr�c�dent
	void SetPrecedent(ClientEnAttente* client) { precedent_ = client; }
};