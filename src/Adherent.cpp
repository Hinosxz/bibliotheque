#include <iostream>
#include "Adherent.h"
#include "Bibliotheque.h"
#include <string>
using namespace std;

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
