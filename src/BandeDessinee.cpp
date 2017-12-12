#include <string>
#include <iostream>
#include "BandeDessinee.h"
using namespace std;

BandeDessinee::BandeDessinee(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, string dessinateur, bool emprunte) : Livre(id, auteur, titre, editeur, ISBN, public_cible, emprunte){
	this->dessinateur = dessinateur;
}
