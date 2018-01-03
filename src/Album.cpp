#include <string>
#include <iostream>
#include "Album.h"
using namespace std;

Album::Album(string auteur, string titre, string editeur, string ISBN, string public_cible, string type_illustration) : Livre(auteur, titre, editeur, ISBN, public_cible){
	this->categorie = "Album";
	this->type_illustration = type_illustration;
}
