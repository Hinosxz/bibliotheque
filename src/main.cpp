#include <iostream>
#include <string>
#include <vector>
#include "BandeDessinee.h"
#include "Roman.h"
#include "RecueilPoesies.h"
#include "PieceTheatre.h"
#include "Album.h"
#include "Adherent.h"
#include "Bibliotheque.h"
using namespace std;


/**
 * Règles d'utilisation du code sans interface
 * Les ids commencent à 0
 * L'id d'un livre qui n'appartient à aucune bibliothèque est fixé à -1, c'est la bibliothèque qui l'initialise
 * Les catégories disponibles sont 'Bande Dessinee', 'Recueil de Poesies', 'Piece de Theatre', 'Album' et 'Roman'
 * Il n'est pas prévu qu'un adhérent change de bibliothèque affiliée, la fonction de prêt ne vérifie donc pas
 * si l'adhérent est membre avant d'aller chercher le livre
 **/

int main()
{
    vector <Livre> liste_livres_disponibles;
    vector <Bibliotheque> liste_bibliotheques;
    vector <Adherent> liste_adherents;

    Bibliotheque alcazar("Alcazar", "Marseille", 0);
    Bibliotheque castellane("Castellane", "Marseille", 1);
    BandeDessinee bd("Hergé", "Tintin au Tibet", "Casterman", "9782203007642", "Tout public", "Hergé");
    Roman station_eleven("Emily St John Mandel", "Station Eleven", "Rivages", "9782743637552", "Tout public", "Science-Fiction");

    liste_livres_disponibles.push_back(station_eleven);
    liste_livres_disponibles.push_back(bd);

    liste_bibliotheques.push_back(alcazar);
    liste_bibliotheques.push_back(castellane);

    Adherent dupont("Dupont", "Jean", "Allauch", liste_bibliotheques[0], 3); //adhérent à Alcazar
    Adherent haddock("Haddock", "Capitaine", "Moulinsart", liste_bibliotheques[1], 3); //adhérent à Castellane
    liste_adherents.push_back(dupont);
    liste_adherents.push_back(haddock);

    int choix_menu_principal, choix_menu_bibliotheque, choix_menu_livre;

    while (choix_menu_principal != 3){
        cout << "Administration de bibliothèques\n---------------------" << endl;
        cout << "1. Bibliothèque\n2. Livre\n3. Quitter" << endl;
        cin >> choix_menu_principal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail()){
            __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
        }
        switch (choix_menu_principal){
            case 1:
                while (choix_menu_bibliotheque != 4){
                    cout << "1. Créer une bibliothèque" << endl;
                    cout << "2. Afficher les bibliothèques" << endl;
                    cout << "3. Sélectionner une bibliothèque" << endl;
                    cout << "4. Retour" << endl;
                    cin >> choix_menu_bibliotheque;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (cin.fail()){
                        __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                    }
                    switch (choix_menu_bibliotheque){
                        case 1: {
                            string nom, adresse;
                            int id_biblio = liste_bibliotheques.size();
                            while (nom.empty()) {
                                cout << "Entrez le nom de la bibliothèque" << endl;
                                getline(cin, nom);
                            }
                            while (adresse.empty()) {
                                cout << "Entrez l'adresse de la bibliothèque" << endl;
                                getline(cin, adresse);
                            }
                            Bibliotheque b(nom, adresse, id_biblio);
                            liste_bibliotheques.push_back(b);
                            break;
                        }
                        case 2: {
                            cout << "Liste des bibliothèques\n--------------------" << endl;
                            for (int i = 0; i < liste_bibliotheques.size(); i++){
                                cout << "Bibliothèque n°" << i << " --> " << liste_bibliotheques[i].getNom() << endl;
                            }
                            break;
                        }
                        case 3: {
                            int id_biblio;
                            do {
                                cout << "Saisissez l'id de la bibliothèque à sélectionner" << endl;
                                cin >> id_biblio;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                if (cin.fail()){
                                    __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                }
                            } while (id_biblio >= liste_bibliotheques.size() || id_biblio < 0);
                            int choix_action;
                            while (choix_action != 10) {
                                cout << "Bibliothèque : " << liste_bibliotheques[id_biblio].getNom() << endl;
                                cout << "Actions possibles\n----------" << endl;
                                cout << "1. Acheter un livre disponible\n2. Afficher les livres possédés\n"
                                        "3. Afficher les livres possédés par catégorie\n4. Supprimer un livre\n"
                                        "5. Demander un livre à une autre bibliothèque\n"
                                        "6. Rendre les livres prêtés par d'autres bibliothèques mais pas empruntés\n"
                                        "7. Ajouter un adhérent\n8. Afficher les adhérents\n9. Sélectionner un adhérent\n"
                                        "10. Retour" << endl;
                                cin >> choix_action;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                if (cin.fail()){
                                    __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                }
                                switch (choix_action){
                                    case 1: {
                                        int choix_livre;
                                        do {
                                            cout << "Veuillez entrer l'id d'un livre disponible !" << endl;
                                            cin >> choix_livre;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                        } while (choix_livre >= liste_livres_disponibles.size() || choix_livre < 0);
                                        liste_bibliotheques[id_biblio].achete(liste_livres_disponibles[choix_livre]);
                                        liste_livres_disponibles.erase(liste_livres_disponibles.begin() + choix_livre);
                                        break;
                                    }
                                    case 2: {
                                        liste_bibliotheques[id_biblio].afficheLivres();
                                        break;
                                    }
                                    case 3: {
                                        int choix_categorie;
                                        string categorie;
                                        do {
                                            cout
                                                    << "Choisissez la catégorie\n1. Album\n2. Bande dessinée\n3. Pièce de théâtre\n4. Recueil de poésies\n5. Roman"
                                                    << endl;
                                            cin >> choix_categorie;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                            switch (choix_categorie) {
                                                case 1: {
                                                    categorie = "Album";
                                                    break;
                                                }
                                                case 2: {
                                                    categorie = "Bande Dessinee";
                                                    break;
                                                }
                                                case 3: {
                                                    categorie = "Piece de Theatre";
                                                    break;
                                                }
                                                case 4: {
                                                    categorie = "Recueil de Poesies";
                                                    break;
                                                }
                                                case 5: {
                                                    categorie = "Roman";
                                                    break;
                                                }
                                                default:
                                                    cout << "Veuillez choisir une catégorie existante !" << endl;
                                                    break;
                                            }
                                        } while (choix_categorie != 1 && choix_categorie != 2 && choix_categorie != 3 && choix_categorie != 4 && choix_categorie != 5);
                                        liste_bibliotheques[id_biblio].afficheLivres(categorie);
                                        break;
                                    }
                                    case 4: {
                                        int id_livre;
                                        do {
                                            cout << "Veuillez entrer l'id d'un livre en stock" << endl;
                                            cin >> id_livre;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                        } while (id_livre >= liste_bibliotheques[id_biblio].getNbLivres() || id_livre < 0);
                                        liste_bibliotheques[id_biblio].supprime(id_livre);
                                        break;
                                    }
                                    case 5: {
                                        int choix_bibliotheque;
                                        string ISBN;
                                        while (ISBN.empty()) {
                                            cout << "Entrez l'ISBN du livre désiré" << endl;
                                            cin >> ISBN;
                                        }
                                        do {
                                            cout << "Entrez le numéro de la bibliothèque prêteuse" << endl;
                                            cin >> choix_bibliotheque;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                        } while (choix_bibliotheque < 0||choix_bibliotheque >= liste_bibliotheques.size());
                                        liste_bibliotheques[id_biblio].demande(ISBN, liste_bibliotheques[choix_bibliotheque]);
                                        break;
                                    }
                                    case 6: {
                                        liste_bibliotheques[id_biblio].rend();
                                        break;
                                    }
                                    case 7: {
                                        string nom, prenom, adresse;
                                        int nb_livres_max;
                                        while (nom.empty()) {
                                            cout << "Entrez le nom de l'adhérent" << endl;
                                            getline(cin, nom);
                                        }
                                        while (prenom.empty()) {
                                            cout << "Entrez le prénom de l'adhérent" << endl;
                                            getline(cin, prenom);
                                        }
                                        while (adresse.empty()) {
                                            cout << "Entrez l'adresse de l'adhérent" << endl;
                                            getline(cin, adresse);
                                        }
                                        do {
                                            cout << "Entrez le nombre de livres maximum que l'adhérent peut emprunter" << endl;
                                            cin >> nb_livres_max;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                        } while (nb_livres_max < 1);
                                        Adherent adherent(nom, prenom, adresse, liste_bibliotheques[id_biblio], nb_livres_max);
                                        liste_adherents.push_back(adherent);
                                        break;
                                    }
                                    case 8: {
                                        bool pas_d_adherent = true;
                                        for (int i = 0; i < liste_adherents.size(); i++){
                                            // Si l'adhérent considéré appartient à la bibliothèque sélectionnée
                                            if (liste_adherents[i].getBiblioAffiliee()->getIdBiblio() == id_biblio){
                                                pas_d_adherent = false;
                                                cout << "Adhérent n°" << liste_adherents[i].getIdAdherent() << " --> M/Mme "
                                                     << liste_adherents[i].getNom() << " " << liste_adherents[i].getPrenom()
                                                     << endl;
                                            }
                                        }
                                        if (pas_d_adherent){
                                            cout << "La bibliothèque ne contient aucun adhérent !" << endl;
                                        }
                                        break;
                                    }
                                    case 9: {
                                        int id_adherent;
                                        do {
                                            cout << "Saisissez l'id de l'adhérent à sélectionner" << endl;
                                            cin >> id_adherent;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                        } while (id_adherent >= liste_bibliotheques[id_biblio].getNbAdherents() || id_adherent < 0);

                                        //Récupère la position de l'adhérent dans la liste d'adhérents
                                        int pos_adherent;
                                        for (int i = 0; i < liste_adherents.size(); i++){
                                            if (liste_adherents[i].getIdAdherent() == id_adherent){
                                                pos_adherent = i;
                                            }
                                        }

                                        int choix_action_adherent;
                                        while (choix_action_adherent != 3) {
                                            cout << "Adhérent : " << liste_adherents[pos_adherent].getNom()
                                                 << endl;
                                            cout << "Actions possibles\n----------" << endl;
                                            cout << "1. Emprunter un livre de la bibliothèque\n2. Rendre un livre\n"
                                                    "3. Retour" << endl;
                                            cin >> choix_action_adherent;
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            if (cin.fail()){
                                                __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                            }
                                            switch (choix_action_adherent) {
                                                case 1:
                                                    int id_livre_emprunte;
                                                    if (liste_bibliotheques[id_biblio].getNbLivres() != 0) {
                                                        do {
                                                            cout
                                                                    << "Entrez le numéro du livre que vous souhaitez emprunter"
                                                                    << endl;
                                                            cin >> id_livre_emprunte;
                                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                            if (cin.fail()) {
                                                                __throw_runtime_error(
                                                                        "Vous deviez obligatoirement entrer un nombre entier !");
                                                            }
                                                        } while (id_livre_emprunte < 0 || id_livre_emprunte >=
                                                                                          liste_bibliotheques[id_biblio].getNbLivres());
                                                    }
                                                    liste_adherents[pos_adherent].emprunte(id_livre_emprunte);
                                                    break;
                                                case 2:
                                                    int id_livre_rendu;
                                                    do {
                                                        cout << "Entrez le numéro du livre que vous souhaitez rendre"
                                                             << endl;
                                                        cin >> id_livre_rendu;
                                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                                        if (cin.fail()){
                                                            __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                                        }
                                                    } while (id_livre_rendu < 0||id_livre_rendu >= liste_bibliotheques[id_biblio].getNbLivres());
                                                    liste_adherents[pos_adherent].rend(id_livre_rendu);
                                                    break;
                                                case 3:
                                                    break;
                                                default:
                                                    cout << "Choisissez un item existant svp !" << endl;
                                                    break;
                                            }
                                        }
                                        choix_action_adherent = 0;
                                        break;
                                    }
                                    case 10: {
                                        break;
                                    }
                                    default:
                                        cout << "Choisissez un item existant svp !" << endl;
                                        break;
                                }
                            }
                            choix_action = 0;
                            break;
                        }
                        case 4:
                            break;
                        default:
                            cout << "Choisissez un item existant svp !" << endl;
                            break;
                    }
                }
                choix_menu_bibliotheque = 0;
                break;
            case 2:
                while (choix_menu_livre != 3){
                    cout << "1. Créer un livre" << endl;
                    cout << "2. Afficher les livres disponibles" << endl;
                    cout << "3. Retour" << endl;
                    cin >> choix_menu_livre;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (cin.fail()){
                        __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                    }
                    switch (choix_menu_livre){
                        case 1: {
                            string auteur, titre, editeur, ISBN, public_cible, categorie;
                            int choix_public_cible, choix_categorie;
                                cout << "Entrez le nom de l'auteur" << endl;
                                getline(cin, auteur);
                            while (titre.empty()) {
                                cout << "Entrez le titre du livre" << endl;
                                getline(cin, titre);
                            }
                            while (editeur.empty()) {
                                cout << "Entrez l'éditeur" << endl;
                                getline(cin, editeur);
                            }
                            while (ISBN.empty()) {
                                cout << "Entrez l'ISBN-13" << endl;
                                cin >> ISBN;
                            }
                            while (public_cible.empty()) {
                                cout << "Choisissez le public ciblé\n1. Adulte\n2. Ados\n3. Jeunesse\n4. Tout public"
                                     << endl;
                                cin >> choix_public_cible;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                if (cin.fail()){
                                    __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                }
                                switch (choix_public_cible) {
                                    case 1:
                                        public_cible = "Adulte";
                                        break;
                                    case 2:
                                        public_cible = "Ados";
                                        break;
                                    case 3:
                                        public_cible = "Jeunesse";
                                        break;
                                    case 4:
                                        public_cible = "Tout public";
                                        break;
                                    default:
                                        cout << "Veuillez choisir une catégorie existante !" << endl;
                                        break;
                                }
                            }
                            while (categorie.empty()) {
                                cout << "Choisissez la catégorie\n1. Album\n2. Bande dessinée\n3. Pièce de théâtre\n4. Recueil de poésies\n5. Roman"
                                     << endl;
                                cin >> choix_categorie;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                if (cin.fail()){
                                    __throw_runtime_error("Vous deviez obligatoirement entrer un nombre entier !");
                                }
                                switch (choix_categorie) {
                                    case 1: {
                                        string type_illustration;
                                        cout << "Entrez le type d'illustration" << endl;
                                        getline(cin, type_illustration);
                                        Album a(auteur, titre, editeur, ISBN, public_cible, type_illustration);
                                        liste_livres_disponibles.push_back(a);
                                        categorie = "Album";
                                        break;
                                    }
                                    case 2: {
                                        string dessinateur;
                                        cout << "Entrez le nom du dessinateur" << endl;
                                        getline(cin, dessinateur);
                                        BandeDessinee bd(auteur, titre, editeur, ISBN, public_cible, dessinateur);
                                        liste_livres_disponibles.push_back(bd);
                                        categorie = "Bande Dessinee";
                                        break;
                                    }
                                    case 3: {
                                        string siecle;
                                        cout << "Entrez le siècle d'écriture" << endl;
                                        getline(cin, siecle);
                                        PieceTheatre p(auteur, titre, editeur, ISBN, public_cible, siecle);
                                        liste_livres_disponibles.push_back(p);
                                        categorie = "Piece de Theatre";
                                        break;
                                    }
                                    case 4: {
                                        string indicateur;
                                        cout << "Entrez l'indicateur du recueil" << endl;
                                        getline(cin, indicateur);
                                        RecueilPoesies recueil(auteur, titre, editeur, ISBN, public_cible, indicateur);
                                        liste_livres_disponibles.push_back(recueil);
                                        categorie = "Recueil de Poesies";
                                        break;
                                    }
                                    case 5: {
                                        string genre;
                                        cout << "Entrez le genre du roman" << endl;
                                        getline(cin, genre);
                                        Roman roman(auteur, titre, editeur, ISBN, public_cible, genre);
                                        liste_livres_disponibles.push_back(roman);
                                        categorie = "Roman";
                                        break;
                                    }
                                    default:
                                        cout << "Veuillez choisir une catégorie existante !" << endl;
                                        break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            cout << "Liste des livres disponibles à l'achat\n--------------------" << endl;
                            for (int i = 0; i < liste_livres_disponibles.size(); i++) {
                                cout << "Livre n°" << i << " --> " << liste_livres_disponibles[i].getTitre() << endl;
                            }
                            break;
                        }
                        case 3:
                            break;
                        default:
                            cout << "Choisissez un item existant svp !" << endl;
                            break;
                    }
                }
                choix_menu_livre = 0;
                break;
            case 3:
                break;
            default:
                cout << "Choisissez un item existant svp !" << endl;
                break;
        }
    }
    choix_menu_principal = 0;

    return 0;
}
