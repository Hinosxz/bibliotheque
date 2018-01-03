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
    Bibliotheque **liste_biblio_preteuses;
    int nb_livres;
public:
    //Constructors
    Bibliotheque();
    Bibliotheque(string nom, string adresse, int id_biblio);

    //Setters
    void setNom(string);
    void setAdresse(string);
    void setIdBiblio(int);
    void setLivre(Livre); //Ajoute un livre à la liste_livres
    void setBiblioPreteuse(Bibliotheque&);
    void setNbLivres(int);

    //Getters
    string getNom();
    string getAdresse();
    int getIdBiblio();
    Livre getLivre(int);
    Bibliotheque *getBiblioPreteuse(int);
    int getNbLivres();

    //Operations
    void achete(Livre&); //ajoute un livre à la bibliothèque
    void supprime(int); //supprime un livre de la bibliothèque
    void afficheLivres(); //affiche tous les livres de la bibliothèque
    void afficheLivres(string categorie); //affiche tous les livres d'une certaine catégorie de la bibliothèque

    /* Les deux suivantes sont liées, demande sur la bibliothèque 1 fait appel à cherche sur la bibliothèque 2 */
    void demande(string ISBN, Bibliotheque &biblio_preteuse); //demande un livre à une autre bibliothèque
    Livre cherche(string ISBN); //cherche un livre pour une bibliothèque demandeuse

    void rend();

    bool prete(int); //renvoie si oui ou non le livre peut être prêté, si oui elle change son état
    void reprend(int); //change l'état du livre à reprendre
};

#endif /* BIBLIOTHEQUE_H_ */
