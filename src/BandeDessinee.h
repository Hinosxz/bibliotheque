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
	BandeDessinee(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string dessinateur, bool emprunte = false);
};

#endif /* BANDEDESSINEE_H_ */
