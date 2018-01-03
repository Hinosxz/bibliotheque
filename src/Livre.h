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
    bool emprunte;
public:
    //Constructors
    Livre();
    Livre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, bool emprunte = false);
    Livre(Livre const& livre_a_copier);

    //Setters
    void setId(int);
    void setAuteur(string);
    void setTitre(string);
    void setEditeur(string);
    void setISBN(string);
    void setPublicCible(string);
    void setEmprunte(bool);

    //Getters
    int getId();
    string getAuteur();
    string getTitre();
    string getEditeur();
    string getISBN();
    string getPublicCible();
    bool getEmprunte();
};

#endif /* LIVRE_H_ */
