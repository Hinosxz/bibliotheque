#include <string>
#include <iostream>
#include "RecueilPoesies.h"
using namespace std;

RecueilPoesies::RecueilPoesies(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string indicateur, bool emprunte) : Livre(id, auteur, titre, editeur, ISBN, public_cible, emprunte){
	this->indicateur = indicateur;
}
