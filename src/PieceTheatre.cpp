#include <string>
#include <iostream>
#include "PieceTheatre.h"
using namespace std;

PieceTheatre::PieceTheatre(string auteur, string titre, string editeur, string ISBN, string public_cible, string siecle) : Livre(auteur, titre, editeur, ISBN, public_cible){
	this->categorie = "Piece de Theatre";
	this->siecle = siecle;
}
