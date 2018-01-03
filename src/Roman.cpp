#include <string>
#include <iostream>
#include "Roman.h"
using namespace std;

Roman::Roman(string auteur, string titre, string editeur, string ISBN, string public_cible, string genre) : Livre(auteur, titre, editeur, ISBN, public_cible){
	this->categorie = "Roman";
	this->genre = genre;
}
