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

/* Reste à faire
 * Mettre à jour l'UML
 * Ecrire un compte-rendu de projet
 * Programmer l'interface (Q5) OU écrire des commandes de test pour chaque point demandé dans l'énoncé
 */

/**
 * Règles d'utilisation
 * Les ids commencent à 0
 * L'id d'un livre qui n'appartient à aucune bibliothèque est fixé à -1, c'est la bibliothèque qui l'initialise
 * Les catégories disponibles sont 'Bande Dessinee', 'Recueil de Poesies', 'Piece de Theatre', 'Album' et 'Roman'
 **/

int main()
{
    // Une bibliothèque, une bande dessinée, un adhérent
    Bibliotheque alcazar("Alcazar", "Marseille", 1);
    Bibliotheque castellane("Castellane", "Marseille", 2);
    BandeDessinee bd("Hergé", "Tintin au Tibet", "Casterman", "9782203007642", "Tout public", "Hergé");
    Roman station_eleven("Emily St John Mandel", "Station Eleven", "Rivages", "9782743637552", "Tout public", "Science-Fiction");
    Adherent dupont(1, "Dupont", "Jean", "Allauch", alcazar, 3);
    Adherent haddock(2, "Haddock", "Capitaine", "Moulinsart", alcazar, 3);

    alcazar.achete(bd);
    castellane.afficheLivres();
    castellane.demande("9782203007642", alcazar);
    castellane.afficheLivres();

    return 0;
}
