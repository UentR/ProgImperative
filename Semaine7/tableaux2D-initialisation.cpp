#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;
/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Construit un tableau 2D L x C dont les valeurs sont initialisées à v
 * @param L un entier: le nombre de lignes
 * @param C un entier: le nombre de colonnes
 * @param v un entier pour initialiser les valeurs de chaque case
 * @return le tableau 2D d'entiers
 **/
vector<vector<int>> tableau2DInitialise(int L, int C, int v) {

    vector<vector<int>> résultat = vector<vector<int>>(L);
    for (int i=0; i<L; i++) {
        résultat[i] = vector<int>(C);
        for (int j=0; j<C; j++) {
            résultat[i][j] = v;
        }
    }

    return résultat;
}


int main() {
    cout << "Lancement des tests. Si tout marche bien," ;
    cout << " rien ne devrait s'afficher ci dessous." << endl;
    CHECK( tableau2DInitialise(0, 0, 1) == vector<vector<int>>({}) );
    CHECK( tableau2DInitialise(2, 6, 1) == 
                        vector<vector<int>> ({ { 1,1,1,1,1,1 },
                                             { 1,1,1,1,1,1 } }) );
    CHECK( tableau2DInitialise(2, 3, 4) ==
    vector<vector<int>>( {  { 4, 4, 4 }, { 4, 4, 4 } } ));
}


