#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl
///BEGIN initialisationTD
vector<vector<int>> t={{7, -1, 4, 3}, {15, 11, 17, 12}, {20, 34, 42, 25}};
///END initialisationTD
vector<vector<int>> tabVide (0);
vector<vector<int>> tabCarre         = { { 1,  2, 3 },
                                         { 4, 11, 6 },
                                         { 9, 12, 7 } };
vector<vector<int>> tabRectangulaire = { { 1,  2, 3 },
                                         { 9, 12, 7 } };
vector<vector<int>> tabBizarre       = { { 1,  2, 3 },
                                         { 4,  5 },
                                         { 6,  7, 8, 10 } };

/// BEGIN initialisation



/// BEGIN nombreDeLignes

/** renvoie le nombre de lignes d'un tableau 2D d'entiers
 * @param t le tableau 2D d'entiers
 * @return le nombre de lignes du tableau t
 **/
int nombreDeLignes(vector<vector<int>> t) {
    return t.size();
}
/// END nombreDeLignes

void nombreDeLignesTest() {
    CHECK( nombreDeLignes(tabVide) == 0 );
    CHECK( nombreDeLignes(tabCarre) == 3 );
    CHECK( nombreDeLignes(tabRectangulaire) == 2 );
    CHECK( nombreDeLignes(tabBizarre) == 3 );
}

/// BEGIN nombreDeColonnes

/** renvoie le nombre de colonnes d'un tableau 2D d'entiers
 * @param t le tableau 2D d'entiers
 * @return le nombre de colonnes du tableau t
 **/
int nombreDeColonnes(vector<vector<int>> t) {
    if (t.size()==0) { return 0; }
    return t[0].size();
}
/// END nombreDeColonnes

void nombreDeColonnesTest() {
    CHECK( nombreDeColonnes(tabVide) == 0 );
    CHECK( nombreDeColonnes(tabCarre) == 3 );
    CHECK( nombreDeColonnes(tabRectangulaire) == 3 );
}

/// BEGIN afficheLigne

/** affiche tous les elements de la ligne l de t.
 * @param t le tableau 2D d'entiers
 * @param l un entier
 **/
void afficheLigne(vector<vector<int>> t, int l) {
    for ( int i = 0; i < t[l].size(); i++ ) {
        cout << setw(4) << t[l][i] << " ";
    }
    cout << endl;
}
/// END afficheLigne

/// BEGIN afficheColonne

/** affiche tous les elements de la colonne c de t.
 * @param t le tableau 2D d'entiers
 * @param c un entier
 **/
void afficheColonne(vector<vector<int>> t, int c) {
    for ( int i = 0; i < t.size(); i++ ) {
        cout << setw(4) << t[i][c] << " ";
    }
    cout << endl;
}
/// END afficheColonne

/// BEGIN afficheDiagonale

/** affiche tous les éléments de la première diagonale d'un
    tableau t supposé carré
 * @param t le tableau 2D d'entiers
 **/
void afficheDiagonale(vector<vector<int>> t) {
    for ( int i = 0; i < t.size(); i++ ) {
        cout << setw(4) << t[i][i] << " ";
    }
    cout << endl;
}
/// END afficheDiagonale

/// BEGIN affiche

/** affiche tous les elements de t.
 * @param t le tableau 2D d'entiers
 **/
void affiche(vector<vector<int>> t) {
    for ( int i = 0; i < t.size(); i++ ) {
        for ( int j = 0; j < t[i].size(); j++ ) {
            cout << setw(4) << t[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
/// END affiche

/// BEGIN appartient

/** Test d'appartenance
 * @param t un tableau d'entiers à deux dimensions
 * @param x un entier
 * @return un booleen: true si x apparaît dans t, false sinon
 **/
bool appartient(vector<vector<int>> t, int x) {
    for (int i=0; i<t.size(); i++) {
        for (int j=0; j<t[i].size(); j++) {
            if (x == t[i][j]) { return true; }
        }
    }
    return false;
}
/// END appartient

/** ajouter 4 tests verifiant le bon fonctionnement de la fonction appartient
**/
void appartientTest() {
    CHECK( not appartient(tabVide, 3) );

    CHECK( appartient(tabCarre, 11) );
    CHECK( not appartient(tabRectangulaire, 4) );
    CHECK( appartient(tabBizarre, 8) );

}

int main() {
    cout << "Lancement tests de nombreDeLignes" << endl;
    nombreDeLignesTest();
    cout << "Lancement tests de nombreDeColonnes" << endl;
    nombreDeColonnesTest();
    cout << "Appel de afficheLigne:" << endl;
    afficheLigne(tabCarre, 1);
    cout << "Appel de afficheColonne:" << endl;
    afficheColonne(tabCarre, 2);
    cout << "Appel de afficheDiagonale:" << endl;
    afficheDiagonale(tabCarre);
    cout << "Appel de affiche:" << endl;
    affiche(tabCarre);

    cout << "Lancement tests de appartient" << endl;
    appartientTest();
}

