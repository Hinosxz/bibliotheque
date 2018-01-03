#include <iostream>
#include <string>
#include "BandeDessinee.h"
#include "Roman.h"
#include "RecueilPoesies.h"
#include "PieceTheatre.h"
#include "Album.h"
#include "Adherent.h"
#include "Bibliotheque.h"
using namespace std;

/* On va dire que les ids commencent à 1 */

int main()
{
    // Une bibliothèque, une bande dessinée, un adhérent
    Bibliotheque biblio("Alcazar", "Marseille", 1);
    BandeDessinee bd(1, "Hergé", "Tintin au Tibet", "Casterman", "9782203007642", "Tout public", "Hergé");
    Adherent adherent(1, "Dupont", "Jean", "Allauch", biblio, 3);
    //M. Dupont emprunte le livre 1 à la biblio
    adherent.emprunte(1);
    cout << adherent.getIdLivreEmprunte(0) << "\n";
    //M. Dupont rend le livre 1 à la biblio
    adherent.rend(1);
    cout << adherent.getIdLivreEmprunte(0) << "\n";
    return 0;
}
