#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

using Matrice = vector<vector<int>>;

Matrice matriceVide (0);
Matrice matriceCarrée       = {  { 1,  4, 9 },
                                { 4, 11, 6 },
                                { 9, 12, 7 }};

Matrice matriceSymétrique = {   { 1,  2, 3 },
                                { 2, 11, 4 },
                                { 3,  4, 0 }};
Matrice matriceCreuse = {                      { 0,  0 },
                                               { 5,  0 },
                                               { 0,  2 }   };
Matrice matriceRectangulaire={  { 1,  2, 3 },
                                { 9, 12, 7 }};

Matrice matriceProduit =  {                    { 10,  6 },
                                               { 60, 14 }};
/// BEGIN initBizzare
Matrice matriceBizzare =    {   { 1,  2, 3 , 4},
                                { 2, 11, 4 , 5},
                                { 3, 4, 100000} };
/// END initBizzare

/// BEGIN estSymétrique
/** Teste si une matrice est symétrique
 * @param t une matrice carrée
 * @return true si t[i][j] == t[j][i] pour tout i,j, false sinon
 **/
bool estSymétrique(Matrice t) {
    if (t.size() == 0) return true;
    if (t.size() != t[0].size()) return false;

    for (int i=0; i<t.size(); i++) {
        for (int j=i; j<t[i].size(); j++) {
            if (t[i][j] != t[j][i]) return false;
        }
    }
    return true;
}
/// END estSymétrique
/// BEGIN estSymétriqueTest
void estSymétriqueTest() {
    CHECK(     estSymétrique(matriceVide) );
    CHECK( not estSymétrique(matriceCarrée) );
    CHECK(     estSymétrique(matriceSymétrique) );
    CHECK( not estSymétrique(matriceProduit) );
}
/// END estSymétriqueTest

/// BEGIN estCarréeSymétrique
/** Teste si une matrice est symétrique
 * @param t une matrice
 * @return true si la matrice est carrée et symétrique
 * cad t[i][j] == t[j][i] pour tout i,j, false sinon
 **/

bool estCarréeSymétrique(Matrice t) {
    if (t.size() == 0) return true;
        if (t.size() != t[0].size()) return false;
    
        for (int i=0; i<t.size(); i++) {
            for (int j=i; j<t[i].size(); j++) {
                if (t[i][j] != t[j][i]) return false;
            }
        }
        return true;
}
/// END estCarréeSymétrique

/// BEGIN estCarréeSymétriqueTest
void estCarréeSymétriqueTest() {
    CHECK(     estCarréeSymétrique(matriceVide) );
    CHECK( not estCarréeSymétrique(matriceCarrée) );
    CHECK(     estCarréeSymétrique(matriceSymétrique) );

    CHECK( not    estCarréeSymétrique(matriceRectangulaire) );
    CHECK( not    estCarréeSymétrique(matriceBizzare) );

}
/// END estCarréeSymétriqueTest

/// BEGIN somme
/** somme deux matrices dont les dimensions sont identiques
 * @param t1 une matrice
 * @param t2 une matrice
 * @return la matrice t1 + t2
 **/
Matrice somme(Matrice t1, Matrice t2) {
    
    Matrice résultat = vector<vector<int>>(t1.size());
    for (int i=0; i<t2.size(); i++) {
        résultat[i] = vector<int>(t1[i].size());
        for (int j=0; j<t2[i].size(); j++) {
            résultat[i][j] = t1[i][j] + t2[i][j];
        }
    }
    return résultat;
}
/// END somme

void sommeTest() {
    CHECK( somme(matriceCarrée, matriceSymétrique) ==
    Matrice({{ 2, 6, 12 }, { 6, 22, 10 }, { 12, 16, 7 }}) );
}

/// BEGIN produit
/** produit de deux matrices dont les dimensions sont compatibles
 * @param t1 une matrice
 * @param t2 une matrice
 * @return la matrice t1 * t2 (produit matriciel)
 **/
Matrice produit(Matrice t1, Matrice t2) {
    
    int L = t1.size();
    int C = t2[0].size();
    Matrice résultat = vector<vector<int>>(L);
    for (int i=0; i<L; i++) {
        résultat[i] = vector<int>(C);
        for (int j=0; j<C; j++) {
            int res = 0;
            for (int k=0; k<t1[i].size(); k++) {
                res += t1[i][k] * t2[k][j];
            }
            résultat[i][j] = res;
        }
    }
    return résultat;

}
/// END produit

void produitTest() {
    CHECK( produit(matriceCarrée, matriceCarrée) == Matrice({{ 98, 156, 96 }, { 102, 209, 144 }, { 120, 252, 202 }}) );
    CHECK( produit(matriceRectangulaire, matriceCreuse) == matriceProduit );
}

int main() {
    cout << "Lancement des tests. Si tout marche bien, rien ne devrait s'afficher ci dessous."
         << endl;
    // Lance tous les tests
    estSymétriqueTest();
    estCarréeSymétriqueTest();
    sommeTest();
    produitTest();
}

