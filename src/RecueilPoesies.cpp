#include <string>
#include <iostream>
#include "RecueilPoesies.h"
using namespace std;

RecueilPoesies::RecueilPoesies(string auteur, string titre, string editeur, string ISBN, string public_cible, string indicateur) : Livre(auteur, titre, editeur, ISBN, public_cible){
	this->categorie = "Recueil de Poesies";
	this->indicateur = indicateur;
}
