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
    Livre(int id, string auteur, string titre, string editeur, string ISBN, string public_cible, bool emprunte = false);
    Livre(Livre const& livre_a_copier);
    int getId();
    void setEmprunte(bool);
};

#endif /* LIVRE_H_ */
