#include <iostream>
#include "Adherent.h"
#include "Bibliotheque.h"
#include <string>
using namespace std;

//Constructors
Adherent::Adherent(){
    this->id_adherent = -1;
    this->nom = string();
    this->prenom = string();
    this->adresse = string();
    this->biblio_affiliee = NULL;
    this->nb_livres_max = 0;
    this->liste_livres_empruntes = new int[0];
    this->curseur = 0;
}

Adherent::Adherent(int id_adherent, string nom, string prenom, string adresse, Bibliotheque biblio_affiliee, int nb_livres_max){
    this->id_adherent = id_adherent;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->biblio_affiliee = &biblio_affiliee;
    this->nb_livres_max = nb_livres_max;
    this->liste_livres_empruntes = new int[nb_livres_max];
    this->curseur = 0;
}



//Setters
void Adherent::setIdAdherent(int id_adherent){
    this->id_adherent = id_adherent;
}

void Adherent::setNom(string nom){
    this->nom = nom;
}

void Adherent::setPrenom(string prenom){
    this->prenom = prenom;
}

void Adherent::setAdresse(string adresse){
    this->adresse = adresse;
}

void Adherent::setBiblioAffiliee(Bibliotheque biblio_affiliee){
    this->biblio_affiliee = &biblio_affiliee;
}

void Adherent::setNbLivresMax(int nb_livres_max){
    this->nb_livres_max = nb_livres_max;
}

void Adherent::setListeLivresEmpruntes(int nb_livres_max){
    this->liste_livres_empruntes = new int[nb_livres_max];
}


//Getters
int Adherent::getIdAdherent(){
    return this->id_adherent;
}

string Adherent::getNom(){
    return this->nom;
}

string Adherent::getPrenom(){
    return this->prenom;
}

string Adherent::getAdresse(){
    return this->adresse;
}

int Adherent::getNbLivresMax(){
    return this->nb_livres_max;
}

int Adherent::getIdLivreEmprunte(int curseur){
    return this->liste_livres_empruntes[curseur];
}

int Adherent::getCurseur(){
    return this->curseur;
}


//Operations
void Adherent::emprunte(int id_livre){
    if (curseur < nb_livres_max){
        liste_livres_empruntes[curseur] = id_livre; /* Ajoute l'id du livre emprunté à la liste à la position curseur */
        curseur++; /* Incrémente le curseur */
        biblio_affiliee->prete(id_livre);
    }
    else{
        cout << "Désolé, vous avez atteint le nombre maximum de livres empruntés.";
    }
}

void Adherent::rend(int id_livre){
    /* Recherche le livre dans la liste */
    int indice;
    for (int i = 0; i < nb_livres_max; i++){
        if (liste_livres_empruntes[i] == id_livre){
            indice = i;
        }
    }
    /* Recopie l'ancienne liste sans le livre en question dans une nouvelle */
    int *nouvelle_liste = new int[nb_livres_max];
    /* On recopie la première partie de la liste jusqu'à l'indice du livre à supprimer */
    for (int i = 0; i < indice; i++){
        nouvelle_liste[i] = liste_livres_empruntes[i];
    }
    /* On recopie la seconde partie de la liste jusqu'à la fin en sautant le livre liste_livres_empruntes[indice] */
    for (int i = indice; i < curseur - 1; i++){
        nouvelle_liste[i] = liste_livres_empruntes[i+1];
    }
    /* On change la liste de livres empruntés par la nouvelle liste */
    liste_livres_empruntes = nouvelle_liste;
    /* On décrémente le curseur */
    curseur--;
    /* La bibliothèque reprend le livre */
    biblio_affiliee->reprend(id_livre);
}
