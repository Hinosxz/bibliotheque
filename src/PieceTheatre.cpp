#include <string>
#include <iostream>
#include "PieceTheatre.h"
using namespace std;

PieceTheatre::PieceTheatre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string siecle, bool emprunte) : Livre(id, auteur, titre, editeur, ISBN, public_cible, emprunte){
	this->siecle = siecle;
}
