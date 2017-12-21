#include <iostream>
#include "Bibliotheque.h"
#include <string>
using namespace std;

Bibliotheque::Bibliotheque(string nom, string adresse, int id_biblio){
    this->nom = nom;
    this->adresse = adresse;
    this->id_biblio = id_biblio;
    this->liste_livres = new Livre[100]; /* 100 livres max pour l'instant par bibliothèque */
}

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
