//FileAttente.cpp
//David Sylvestre et Dominic Clément
//8 novembre 2014
//Définition des fonctions membres la classe FileAttente

#include "FileAttente.h"

bool FileAttente::EstVide()
{
   return nbElements_ == 0;
}

int FileAttente::ObtenirNbGroupes()
{
   return nbElements_;
}

int FileAttente::ObtenirNbPersonnes()
{
   int nbPersonnes = 0;

   if (!EstVide())
   {
      ClientEnAttente* client = premier_;

      while (client != 0)
      {
      nbPersonnes += client->GetNombrePersonnes();
      client = client->GetSuivant();
      }
   }

   return nbPersonnes;
}

void FileAttente::Ajouter(Client clientAMettreEnFile)
{
   ClientEnAttente* client = new ClientEnAttente(clientAMettreEnFile);

   if (EstVide())
      premier_ = client;
   else
   {
      client->SetPrecedent(dernier_);
      dernier_->SetSuivant(client);
   }

   dernier_ = client;

   nbElements_++;

}

void FileAttente::Retirer(ClientEnAttente* client)
{
   if (nbElements_ == 1)
   {
      premier_ = 0;
      dernier_ = 0;
   }
   else
   {
      if (client != dernier_)
         client->GetSuivant()->SetPrecedent(client->GetPrecedent());
      else
      {
         if (client != premier_)
            client->GetPrecedent()->SetSuivant(0);
         dernier_ = client->GetPrecedent();
      }

      if (client != premier_)
         client->GetPrecedent()->SetSuivant(client->GetSuivant());
      else
      {
         if (client != dernier_)
            client->GetSuivant()->SetPrecedent(0);
         premier_ = client->GetSuivant();
      }
   }


   nbElements_--;
   delete client;
}


Client FileAttente::Retirer(int nbPlacesDeLaTable, SectionInteressees sectionDeLaTable)
{
   ClientEnAttente* client = premier_;
   ClientEnAttente* temporaire = new ClientEnAttente(Client("", 0, TerrasseFumeur));
   bool trouve = false;

   while (client != 0)
   {
      if (client->GetNombrePersonnes() <= nbPlacesDeLaTable
         && client->GetSections() & sectionDeLaTable
         && temporaire->GetNombrePersonnes() < client->GetNombrePersonnes())
      {
         trouve = true;
         temporaire = client;
      }

      client = client->GetSuivant();
   }

   if (trouve)
   {
      Client buffer = temporaire->GetClient();
      nbPersonnesAssignes_ += buffer.nbPersonnes_;
      nbGroupesAssignes_++;
      Retirer(temporaire);
      return buffer;
   }
   else
      throw (exception("Aucun client correspondant trouve (Retirer a une table)\n"));
}

bool FileAttente::Retirer(string nomClient, int nbPersonnes)
{
   ClientEnAttente* client = premier_;
   bool trouve = false;

   while (client != 0 && !trouve)
   {
      if (client->GetNombrePersonnes() == nbPersonnes
         && client->GetNomClient() == nomClient)
         trouve = true;
      else
         client = client->GetSuivant();
   }

   if (trouve)
      Retirer(client);

   return trouve;
}

void FileAttente::Afficher(ostream& out)
{
   ClientEnAttente* client = premier_;

   while (client != 0)
   {
      cout << string(LargeurConsole, '-');
      cout << client->GetClient().ToString() << endl;
      client = client->GetSuivant();
   }
}

string FileAttente::GetClient(int indice)
{
   if (indice > nbElements_ || indice <= 0)
      throw (exception("L'indice n'est pas dans la file"));

   ClientEnAttente* client = premier_;

   for (int i = 1; i < indice; i++)
      client = client->GetSuivant();

   return client->GetClient().ToString();
}