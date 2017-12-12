#include <string>
#include <iostream>
#include "Livre.h"
using namespace std;

#ifndef PIECETHEATRE_H_
#define PIECETHEATRE_H_

class PieceTheatre: public Livre
{
protected:
	string siecle;
public:
	PieceTheatre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string siecle, bool emprunte = false);
};

#endif /* PIECETHEATRE_H_ */
