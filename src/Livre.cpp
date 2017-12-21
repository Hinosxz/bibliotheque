#include <iostream>
#include "Livre.h"
#include <string>
using namespace std;

Livre::Livre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, bool emprunte){
    this->id = id;
    this->auteur = auteur;
    this->titre = titre;
    this->editeur = editeur;
    this->ISBN = ISBN;
    this->public_cible = public_cible;
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

int Livre::getId(){
    return this->id;
}

void Livre::setEmprunte(bool b){
    this->emprunte = b;
}
