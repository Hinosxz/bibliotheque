#include <string>
#include <iostream>
#include "Livre.h"
using namespace std;

#ifndef RECUEILPOESIES_H_
#define RECUEILPOESIES_H_

class RecueilPoesies: public Livre
{
protected:
	string indicateur;
public:
	RecueilPoesies(string auteur, string titre, string editeur, string ISBN, string public_cible, string indicateur);
};

#endif /* RECUEILPOESIES_H_ */
