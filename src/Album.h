#include <string>
#include <iostream>
#include "Livre.h"
using namespace std;

#ifndef ALBUM_H_
#define ALBUM_H_

class Album: public Livre
{
protected:
	string type_illustration;
public:
	Album(string auteur, string titre, string editeur, string ISBN, string public_cible, string type_illustration);
};

#endif /* ALBUM_H_ */
