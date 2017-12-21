#include <string>
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

#ifndef ADHERENT_H_
#define ADHERENT_H_

class Adherent{
private:
    int id_adherent;
    string nom;
    string prenom;
    string adresse;
    Bibliotheque *biblio_affiliee; /* pointeur vers la bibliothèque affiliée */
    int *liste_livres_empruntes; /* liste contient les livres empruntes*/
    int nb_livres_max;
    int curseur;
public:
    Adherent(int id_adherent, string nom, string prenom, string adresse, Bibliotheque biblio_affiliee, int nb_livres_max);
    void emprunte(int id_livre);
    void rend(int id_livre);
};

#endif /* ADHERENT_H_ */
