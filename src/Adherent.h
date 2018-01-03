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
    Bibliotheque *biblio_affiliee; // pointeur vers la bibliothèque affiliée
    int *liste_livres_empruntes; // liste contenant les ids des livres empruntes
    int nb_livres_max;
    int curseur; //Pas de setter car n'a vocation qu'à être incrémenté ou décrémenté
public:
    //Constructors
    Adherent();
    Adherent(int id_adherent, string nom, string prenom, string adresse, Bibliotheque &biblio_affiliee, const int nb_livres_max);

    //Setters
    void setIdAdherent(int);
    void setNom(string);
    void setPrenom(string);
    void setAdresse(string);
    void setBiblioAffiliee(Bibliotheque);
    void setLivreEmprunte(int);
    void setNbLivresMax(int);

    //Getters
    int getIdAdherent();
    string getNom();
    string getPrenom();
    string getAdresse();
    Bibliotheque* getBiblioAffiliee();
    int getLivreEmprunte(int curseur);
    int getNbLivresMax();
    int getCurseur();

    //Operations
    void emprunte(int id_livre);
    void rend(int id_livre);
};

#endif /* ADHERENT_H_ */
