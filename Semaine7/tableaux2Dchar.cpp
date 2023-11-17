#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;


/***Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file "<< __FILE__ << " line " << __LINE__ << ": " #test << endl


/** renvoie le nombre de lignes du tableau
*@param t tableau de caractères à deux dimensions
*@return l'entier correspondant à son nombre de lignes
**/
int nombreDeLignes (vector<vector<char>> t) {
    return t.size();
}



/** renvoie le nombre de colonnes du tableau
* supposé rectangulaire
*@param t tableau de caractères rectangulaire à deux dimensions
*@return l'entier correspondant à son nombre de colonnes
*/
int nombreDeColonnes (vector<vector<char>> t) {
    if (t.size()==0) return 0;
    return t[0].size();
}



/** affiche les éléments du tableau
*@param t tableau de caractères a deux dimensions
**/
void affiche(vector<vector<char>> t) {
    for (int numLigne = 0; numLigne < t.size() ; numLigne++) {
        for (int numColonne = 0; numColonne < t[numLigne].size() ;
             numColonne++
            ) {
            cout << t[numLigne][numColonne] << " ";
        }
        cout << endl; // passage à la ligne
    }
    cout << endl;  //ligne après l(affichage)
}



/** affiche, en ligne, les éléments de la ligne d'indice l
*@param t tableau de caractères à deux dimensions
*@param l entier l'indice de la ligne à afficher
**/
void afficheLigne(vector<vector<char>> t, int l) {
    cout << "ligne d'indice " << l << " : " << endl;
    for (int colonne = 0; colonne < t[l].size() ; colonne++) {
        cout << t[l][colonne] << " ";
    }
    cout << endl;
}



/** affiche, en colonne, les éléments de la colonne d'indice c
*@param t tableau de caractères à deux dimensions
*@param c entier  l'indice de la colonne à afficher
*/
void afficheColonne(vector<vector<char>> t, int c) {
    cout << "colonne d'indice " << c << " : " << endl;
    for (int ligne = 0; ligne < t.size() ; ligne++) {
        cout << t[ligne][c] << endl;
    }
    cout << endl; // aeration de l'affichage
}



/** affiche, en diagonale, les éléments de la première diagonale
*@param t tableau de caractères carré à deux dimensions
*/
void afficheDiagonaleEnDiagonale(vector<vector<char>> t) {
    cout << "Diagonale  : " << endl;
    for (int numLigne = 0; numLigne < t.size() ; numLigne++) {
        for ( int numColonne = 0;
              numColonne < t[numLigne].size();
              numColonne++
            ) {
            if (numLigne == numColonne) {
                cout << t[numLigne][numColonne] << " "; //affichage
            } else {
                cout << "   "; // espaces pour cacher les non affichés
            }
        }
        cout << endl;          // changement de ligne
    }
    cout << endl;             // aération de l'affichage
}



/** affiche, en ligne, les éléments de la première diagonale
*@param t tableau de caractères carré à deux dimensions
*/
void afficheDiagonaleEnLigne(vector<vector<char>> t) {
    cout << "Diagonale  : " << endl;
    for (int numeroElement = 0; numeroElement < t.size() ; numeroElement++) {
        cout<< t[numeroElement][numeroElement]<<" ";
    }
    cout << endl;             // aération de l'affichage
}



/** indique si un element est présent dans un tableau
*@param c caractère à rechercher
*@param t tableau de caractères à deux dimensions
**/
bool appartient(char c, vector<vector<char>> t) {
    for (int ligne = 0; ligne < t.size() ; ligne++) {
        for (int colonne = 0; colonne < t[ligne].size() ; colonne++) {
            if ( c == t[ligne][colonne] ) {
                return true;
            }
        }
    }
    return false;
}




/**
*  programme principal
**/
int main() {

    vector<vector<char>> tc = { {'P','o','u','r'}, {'b','i','e','n'}, {'r','i','r','e'}, {'l','i','s','!'} };   
    vector<vector<char>> tr = { {'B','r','a','v','o'}, {'b','o','n','n','e'}, {'A','N','N','E','E'}        };
    vector<vector<char>> tq = { {'T','o','u','t'}, {'v','a'}, {'m','i','e','u','x'}                        };


    cout << "testeur Carre :" << endl;
    cout << "---------------" << endl;
    affiche(tc);
    afficheLigne(tc, 1);
    cout << endl;
    afficheColonne(tc, 1);
    cout << endl;
    afficheDiagonaleEnDiagonale(tc);
    cout << endl;
    afficheDiagonaleEnLigne(tc);
    cout << endl;

    cout << "testeur rectangulaire :" << endl;
    cout << "-----------------------" << endl;
    affiche(tr);
    afficheLigne(tr, 0);
    cout << endl;
    afficheColonne(tr, 2);
    cout << "le testeur rectangulaire est non concerné par l'affichage de diagonale"
         << endl;


    cout << "testeur quelconque :" << endl;
    cout << "--------------------" << endl;
    affiche(tq);
    afficheLigne(tq, 2);
    cout << endl;


    cout << "Lancement des tests. Si tout marche bien, rien ne devrait s'afficher ci dessous."
         << endl;

    CHECK (     nombreDeLignes(tc)   == 4 );
    CHECK (     nombreDeLignes(tr)   == 3 );
    CHECK (     nombreDeLignes(tr)   == 3 );

    CHECK (     nombreDeColonnes(tc) == 4 );
    CHECK (     nombreDeColonnes(tr) == 5 );

    CHECK (     appartient('!', tc) );
    CHECK (     appartient('i', tc) );

    CHECK ( not appartient('i', tr) );
    CHECK (     appartient('o', tr) );
    CHECK ( not appartient('x', tr ) );

    CHECK (     appartient('i', tq) );
    CHECK (     appartient('x', tq ) );
    CHECK ( not appartient(' ', tq ) );

}
