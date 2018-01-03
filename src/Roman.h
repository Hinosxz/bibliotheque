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
	Roman(string auteur, string titre, string editeur, string ISBN, string public_cible, string genre);
};

#endif /* ROMAN_H_ */
