#include <string>
using namespace std;

#ifndef LIVRE_H_
#define LIVRE_H_

class Livre{
protected:
    int id;
    string auteur;
    string titre;
    string editeur;
    string ISBN;
    string public_cible;
    string categorie;
    bool emprunte; //emprunté par un adhérent
    bool preteA; //prêté à une bibliothèque
    int preteAvecId; //nous dit s'il est prêté par une bibliothèque et son id dans cette dernière

public:
    //Constructors
    Livre();
    Livre(string auteur, string titre, string editeur, string ISBN, string public_cible);
    Livre(Livre const& livre_a_copier);

    //Setters
    void setId(int);
    void setAuteur(string);
    void setTitre(string);
    void setEditeur(string);
    void setISBN(string);
    void setPublicCible(string);
    void setCategorie(string);
    void setEmprunte(bool);
    void setPreteA(bool);
    void setPreteAvecId(int);

    //Getters
    int getId();
    string getAuteur();
    string getTitre();
    string getEditeur();
    string getISBN();
    string getPublicCible();
    string getCategorie();
    bool getEmprunte();
    bool getPreteA();
    int getPreteAvecId();
};

#endif /* LIVRE_H_ */
