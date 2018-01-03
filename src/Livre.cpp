#include <iostream>
#include "Livre.h"
#include <string>
using namespace std;


//Constructors
Livre::Livre(){
    this->id = -1;
    this->auteur = string();
    this->editeur = string();
    this->ISBN = string();
    this->public_cible = string();
    this->emprunte = false;
}

Livre::Livre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, bool emprunte){
    this->id = id;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->ISBN = ISBN;
    this->public_cible = public_cible;
    this->emprunte = emprunte;
}

Livre::Livre(Livre const& livre_a_copier){
    id = livre_a_copier.id;
    auteur = livre_a_copier.auteur;
    titre = livre_a_copier.titre;
    editeur = livre_a_copier.editeur;
    ISBN = livre_a_copier.ISBN;
    public_cible = livre_a_copier.public_cible;
    emprunte = livre_a_copier.emprunte;
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

void Livre::setEmprunte(bool emprunte){
    this->emprunte = emprunte;
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

bool Livre::getEmprunte(){
    return this->emprunte;
}