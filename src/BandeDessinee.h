#include <string>
#include <iostream>
#include "Livre.h"
using namespace std;

#ifndef BANDEDESSINEE_H_
#define BANDEDESSINEE_H_

class BandeDessinee: public Livre
{
protected:
	string dessinateur;
public:
	BandeDessinee(string auteur, string titre, string editeur, string ISBN, string public_cible, string dessinateur);
};

#endif /* BANDEDESSINEE_H_ */
