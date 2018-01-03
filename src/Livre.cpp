#include <iostream>
#include "Livre.h"
using namespace std;


//Constructors
Livre::Livre(){
    this->id = -1;
    this->auteur = string();
    this->editeur = string();
    this->ISBN = string();
    this->public_cible = string();
    this->categorie = string();
    this->emprunte = false;
    this->preteA = false;
    this->preteAvecId = -1;
}

Livre::Livre(string auteur, string titre, string editeur, string ISBN, string public_cible){
    this->id = -1;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->ISBN = ISBN;
    this->public_cible = public_cible;
    this->categorie = string();
    this->emprunte = false;
    this->preteAvecId = -1;
}

Livre::Livre(Livre const& livre_a_copier){
    id = livre_a_copier.id;
    auteur = livre_a_copier.auteur;
    titre = livre_a_copier.titre;
    editeur = livre_a_copier.editeur;
    ISBN = livre_a_copier.ISBN;
    public_cible = livre_a_copier.public_cible;
    categorie = livre_a_copier.categorie;
    emprunte = livre_a_copier.emprunte;
    preteA = livre_a_copier.preteA;
    preteAvecId = livre_a_copier.preteAvecId;
}


//Setters
void Livre::setId(int id){
    this->id = id;
}

void Livre::setAuteur(string auteur){
    this->auteur = auteur;
}

void Livre::setTitre(string titre){
    this->titre = titre;
}

void Livre::setEditeur(string editeur){
    this->editeur = editeur;
}

void Livre::setISBN(string ISBN){
    this->ISBN = ISBN;
}

void Livre::setPublicCible(string public_cible){
    this->public_cible = public_cible;
}

void Livre::setCategorie(string categorie){
    this->categorie = categorie;
}

void Livre::setEmprunte(bool emprunte){
    this->emprunte = emprunte;
}

void Livre::setPreteA(bool preteA){
    this->preteA = preteA;
}

void Livre::setPreteAvecId(int preteAvecId){
    this->preteAvecId = preteAvecId;
}

//Getters
int Livre::getId() {
    return this->id;
}

string Livre::getAuteur(){
    return this->auteur;
}

string Livre::getTitre(){
    return this->titre;
}

string Livre::getEditeur(){
    return this->editeur;
}

string Livre::getISBN(){
    return this->ISBN;
}

string Livre::getPublicCible(){
    return this->public_cible;
}

string Livre::getCategorie(){
    return this->categorie;
}

bool Livre::getEmprunte(){
    return this->emprunte;
}

bool Livre::getPreteA(){
    return this->preteA;
}

int Livre::getPreteAvecId(){
    return this->preteAvecId;
}
