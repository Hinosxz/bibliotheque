#include <iostream>
#include "Adherent.h"
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

Adherent::Adherent(int id_adherent, string nom, string prenom, string adresse, Bibliotheque &biblio_affiliee, const int nb_livres_max){
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

void Adherent::setNbLivresMax(const int nb_livres_max){
    this->nb_livres_max = nb_livres_max;
}

void Adherent::setLivreEmprunte(int id_livre){
    //Ajoute l'id du livre emprunté à la liste à la position curseur
    liste_livres_empruntes[getCurseur()] = id_livre;
    //Incrémente le curseur
    curseur++;
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

Bibliotheque* Adherent::getBiblioAffiliee(){
    return this->biblio_affiliee;
}

int Adherent::getLivreEmprunte(int curseur){
    return this->liste_livres_empruntes[curseur];
}

int Adherent::getNbLivresMax(){
    return this->nb_livres_max;
}

int Adherent::getCurseur(){
    return this->curseur;
}


//Operations

void Adherent::emprunte(int id_livre){
    //Si l'adhérent n'a pas atteint son nombre d'emprunts maximal
    if (getCurseur() < getNbLivresMax()){
        //Demande à la bibliothèque si l'emprunt est possible
        bool possible = getBiblioAffiliee()->prete(id_livre);
        //Si c'est possible, ajoute le livre à la liste des livres empruntés
        if (possible) {
            setLivreEmprunte(id_livre);
        }
    } else{
        cout << "Désolé, vous avez atteint le nombre maximum de livres empruntés.";
    }
}

void Adherent::rend(int id_livre){
    // Recherche le livre dans la liste
    int indice = -1;
    for (int i = 0; i < getCurseur(); i++){
        if (getLivreEmprunte(i) == id_livre){
            indice = i;
        }
    }
    // Si le livre n'est pas dans la liste, il ne doit pas être rendu
    if (indice != -1) {
        // Recopie l'ancienne liste sans le livre en question dans une nouvelle liste
        int *nouvelle_liste = new int[getNbLivresMax()];
        // Recopie la première partie de la liste jusqu'à l'indice du livre à supprimer
        for (int i = 0; i < indice; i++) {
            nouvelle_liste[i] = getLivreEmprunte(i);
        }
        // Recopie la seconde partie de la liste jusqu'à la fin en sautant le livre à supprimer */
        for (int i = indice; i < getCurseur() - 1; i++) {
            nouvelle_liste[i] = getLivreEmprunte(i + 1);
        }
        // Change la liste de livres empruntés par la nouvelle liste et supprime la ensuite
        liste_livres_empruntes = nouvelle_liste;
        delete[] nouvelle_liste;
        // Décrémente le curseur
        curseur--;
        // La bibliothèque reprend le livre
        getBiblioAffiliee()->reprend(id_livre);
        cout << "Vous avez bien rendu le livre n°" << id_livre << " !" << "\n";
    } else{
        cout << "Vous n'êtes pas en possession du livre n°" << id_livre << " !" << "\n";
    }
}
