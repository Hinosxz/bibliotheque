#include <string>
#include "Livre.h"
using namespace std;

#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

class Bibliotheque{
private:
    string nom;
    string adresse;
    int id_biblio;
    Livre *liste_livres;
public:
    Bibliotheque(string nom, string adresse, int id_biblio);
    void prete(int id_livre);
    void reprend(int id_livre);
};

#endif /* BIBLIOTHEQUE_H_ */
