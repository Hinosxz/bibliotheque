#include <iostream>
#include "Bibliotheque.h"
#include <string>
using namespace std;


//Constructors
Bibliotheque::Bibliotheque(){
    this->nom = string();
    this->adresse = string();
    this->id_biblio = -1;
    this->liste_livres = new Livre[0];
}

Bibliotheque::Bibliotheque(string nom, string adresse, int id_biblio){
    this->nom = nom;
    this->adresse = adresse;
    this->id_biblio = id_biblio;
    this->liste_livres = new Livre[100]; /* 100 livres max pour l'instant par bibliothèque */
}


//Setters
void Bibliotheque::setNom(string nom){
    this->nom = nom;
}

void Bibliotheque::setAdresse(string adresse){
    this->adresse = adresse;
}

void Bibliotheque::setIdBiblio(int id_biblio){
    this->id_biblio = id_biblio;
}


//Getters
string Bibliotheque::getNom(){
    return this->nom;
}

string Bibliotheque::getAdresse(){
    return this->adresse;
}

int Bibliotheque::getIdBiblio(){
    return this->id_biblio;
}


//Operations
void Bibliotheque::prete(int id_livre){
    for (int i = 0; i < 100; i++){
        if (liste_livres[i].getId() == id_livre){
            liste_livres[i].setEmprunte(true);
        }
    }
}

void Bibliotheque::reprend(int id_livre){
    for (int i = 0; i < 100; i++){
        if (liste_livres[i].getId() == id_livre){
            liste_livres[i].setEmprunte(false);
        }
    }
}
