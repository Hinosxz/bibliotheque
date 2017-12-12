#include <string>
#include <iostream>
#include "Livre.h"
using namespace std;

#ifndef ROMAN_H_
#define ROMAN_H_

class Roman: public Livre
{
protected:
	string genre;
public:
	Roman(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string genre, bool emprunte = false);
};

#endif /* ROMAN_H_ */
