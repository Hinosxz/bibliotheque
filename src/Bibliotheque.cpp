#include <iostream>
#include "Bibliotheque.h"
using namespace std;


//Constructors
Bibliotheque::Bibliotheque(){
    this->nom = string();
    this->adresse = string();
    this->id_biblio = -1;
    this->liste_livres = new Livre[0];
    this->liste_biblio_preteuses = new Bibliotheque*[0];
    this->nb_livres = 0;
}

Bibliotheque::Bibliotheque(string nom, string adresse, int id_biblio){
    this->nom = nom;
    this->adresse = adresse;
    this->id_biblio = id_biblio;
    this->liste_livres = new Livre[100]; /* 100 livres max pour l'instant par bibliothèque */
    this->liste_biblio_preteuses = new Bibliotheque*[100];
    this->nb_livres = 0;
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

void Bibliotheque::setLivre(Livre livre){
    liste_livres[getNbLivres()] = livre;
    nb_livres++;
}

void Bibliotheque::setBiblioPreteuse(Bibliotheque &biblio_preteuse){
    liste_biblio_preteuses[getNbLivres()] = &biblio_preteuse;
}

void Bibliotheque::setNbLivres(int nb_livres){
    this->nb_livres = nb_livres;
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

Livre Bibliotheque::getLivre(int i){
    return liste_livres[i];
}

Bibliotheque* Bibliotheque::getBiblioPreteuse(int i){
    return liste_biblio_preteuses[i];
}

int Bibliotheque::getNbLivres(){
    return this->nb_livres;
}


//Operations
void Bibliotheque::achete(Livre &livre){
    //Règle l'id du livre sur le nombre actuel de livres
    livre.setId(getNbLivres());
    //Ajoute le livre à la liste des livres en stock et incrémente le nombre de livres
    setLivre(livre);
    cout << "Le livre n°" << livre.getId() << " a bien été acheté !" << "\n";
}

void Bibliotheque::supprime(int id_livre){
    //Même procédure que dans Adhérent.cpp
    if (getLivre(id_livre).getEmprunte()){
        cout << "Le livre n°" << id_livre << " est actuellement emprunté et ne peut donc pas être "
                "supprimé" << "\n";
    } else {
        Livre *nouvelle_liste = new Livre[100];
        for (int i = 0; i < id_livre; i++) {
            nouvelle_liste[i] = getLivre(i);
        }
        for (int i = id_livre; i < getNbLivres() - 1; i++) {
            nouvelle_liste[i] = getLivre(i + 1);
        }
        liste_livres = nouvelle_liste;
        delete[] nouvelle_liste;
        nb_livres--;
        cout << "Le livre n°" << id_livre << " a bien été supprimé de la bibliothèque "
             << this->getNom() << ".\n";
    }
}

void Bibliotheque::afficheLivres(){
    if (getNbLivres() == 0){
        cout << "La bibliothèque " << this->getNom() << " est pour l'instant vide !" << "\n";
    }
    else {
        cout << "Liste des livres possédés par la bibliothèque " << this->getNom() << " :" << "\n";
        //Parcours de la liste de livres
        for (int i = 0; i < getNbLivres(); i++) {
            //Si le livre est emprunté ou prêté à une autre bibliothèque
            if (getLivre(i).getEmprunte()||getLivre(i).getPreteA()) {
                cout << "Livre n°" << i << " --> " << getLivre(i).getTitre()
                     << " - Non disponible" << "\n";
            } else{
                cout << "Livre n°" << i << " --> " << getLivre(i).getTitre()
                     << " - Disponible" << "\n";
            }
        }
    }
}

void Bibliotheque::afficheLivres(string categorie){
    //Permet de savoir à la fin de la fonction si la catégorie de livres existe dans la liste
    bool categorieVide = true;
    if (getNbLivres() == 0){
        cout << "La bibliothèque est pour l'instant vide !" << "\n";
    }
    else {
        cout << "Liste des livres de la catégorie '" << categorie << "' possédés par la bibliothèque :" << "\n";
        for (int i = 0; i < getNbLivres(); i++) {
            if (getLivre(i).getCategorie() == categorie) {
                if (getLivre(i).getEmprunte()||getLivre(i).getPreteA()) {
                    cout << "Livre n°" << i << " --> " << getLivre(i).getTitre()
                         << " - Non disponible" << "\n";
                } else{
                    cout << "Livre n°" << i << " --> " << getLivre(i).getTitre()
                         << " - Disponible" << "\n";
                }
                // Cela veut dire que la catégorie n'est pas vide
                categorieVide = false;
            }
        }
        if (categorieVide){
            cout << "La bibliothèque ne contient aucun livre de cette catégorie !" << "\n";
        }
    }
}

void Bibliotheque::demande(string ISBN, Bibliotheque &biblio_preteuse){
    //Va chercher le livre grâce à son ISBN dans la bibliothèque cible
    Livre livre_prete = biblio_preteuse.cherche(ISBN);
    //Enregistre l'id qu'avait ce livre dans l'autre bibliothèque (pour le rendre plus tard)
    livre_prete.setPreteAvecId(livre_prete.getId());
    //Donne un état libre au livre
    livre_prete.setPreteA(false);
    //Règle le nouvel id du livre dans cette bibliothèque
    livre_prete.setId(getNbLivres());
    //Enregistre la bibliothèque d'origine pour pouvoir le rendre plus tard
    setBiblioPreteuse(biblio_preteuse);
    //Ajoute le livre à la liste de livres possédés
    setLivre(livre_prete);
    cout << "Le livre n°" << livre_prete.getId() << " a bien été emprunté à la bibliothèque " << biblio_preteuse.getNom()
         << " par la bibliothèque " << this->getNom() << "." << "\n";
}

Livre Bibliotheque::cherche(string ISBN){
    //Parcours de la liste de livres possédés
    for (int i = 0; i < getNbLivres(); i++)
        //Si le livre i correspond à l'ISBN demandé et s'il est libre
        if (getLivre(i).getISBN() == ISBN && !getLivre(i).getEmprunte() && !getLivre(i).getPreteA()){
            getLivre(i).setPreteA(true);
            return getLivre(i);
        }
    }
    /* Une erreur doit être renvoyée si le livre n'est pas disponible, sinon la fonction demande
     * ne fonctionnera pas
     */
    __throw_runtime_error("Le livre demandé n'est pas disponible dans cette bibliothèque.");
}

void Bibliotheque::rend(){
    for (int i = 0; i < getNbLivres(); i++){
        //Récupère l'id du livre dans sa bibliothèque d'origine
        int ancienId = getLivre(i).getPreteAvecId();
        //Si le livre est prêté par une autre bibliothèque et qu'il est libre
        if (ancienId >= 0 && !getLivre(i).getEmprunte()){
            //Rend le à nouveau disponible pour sa bibliothèque d'origine
            getBiblioPreteuse(i)->getLivre(ancienId).setPreteA(false);
            //Supprime le de cette bibliothèque ci
            this->supprime(i);
            cout << "Le livre n°" << i << " a été rendu à sa bibliothèque d'origine." << "\n";
        }
    }
}

bool Bibliotheque::prete(int id_livre){
    //Parcours de la liste de livres possédés
    for (int i = 0; i < getNbLivres(); i++){
        //Si le livre demandé existe
        if (getLivre(i).getId() == id_livre){
            //S'il n'est pas libre
            if (getLivre(i).getEmprunte()||getLivre(i).getPreteA()) {
                cout << "Le livre n°" << id_livre << " n'est pas disponible, veuillez en choisir un autre ou revenir "
                        "plus tard" << "\n";
                return false;
            } else{
                getLivre(i).setEmprunte(true);
                cout << "Vous avez emprunté le livre n°" << id_livre << ". Merci de votre confiance !" << "\n";
                return true;
            }
        }
    }
    cout << "Le livre n°" << id_livre << " n'est pas disponible dans cette bibliothèque." << "\n";
    return false;
}

void Bibliotheque::reprend(int id_livre){
    //Parcours de la liste de livres possédés
    for (int i = 0; i < getNbLivres(); i++){
        //Si le livre demandé existe dans la bibliothèque
        if (getLivre(i).getId() == id_livre){
            //Libère le
            getLivre(i).setEmprunte(false);
        }
    }
}
