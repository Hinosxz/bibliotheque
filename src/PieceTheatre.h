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
	PieceTheatre(string auteur, string titre, string editeur, string ISBN, string public_cible, string siecle);
};

#endif /* PIECETHEATRE_H_ */
