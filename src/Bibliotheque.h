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
    //Constructors
    Bibliotheque();
    Bibliotheque(string nom, string adresse, int id_biblio);

    //Setters
    void setNom(string);
    void setAdresse(string);
    void setIdBiblio(int);

    //Getters
    string getNom();
    string getAdresse();
    int getIdBiblio();

    //Operations
    void prete(int id_livre);
    void reprend(int id_livre);
};

#endif /* BIBLIOTHEQUE_H_ */
