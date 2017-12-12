#include <string>
#include <iostream>
#include "Album.h"
using namespace std;

Album::Album(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string type_illustration, bool emprunte) : Livre(id, auteur, titre, editeur, ISBN, public_cible, emprunte){
	this->type_illustration = type_illustration;
}
