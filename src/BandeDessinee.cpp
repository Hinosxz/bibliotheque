#include <string>
#include <iostream>
#include "BandeDessinee.h"
using namespace std;

BandeDessinee::BandeDessinee(string auteur, string titre, string editeur, string ISBN, string public_cible, string dessinateur) : Livre(auteur, titre, editeur, ISBN, public_cible){
	this->categorie = "Bande Dessinee";
	this->dessinateur = dessinateur;
}
