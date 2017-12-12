#include <string>
#include <iostream>
#include "Roman.h"
using namespace std;

Roman::Roman(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string genre, bool emprunte) : Livre(id, auteur, titre, editeur, ISBN, public_cible, emprunte){
	this->genre = genre;
}
