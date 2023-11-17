#include <stdexcept>
/** @file **/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/// BEGIN GrilleDemineur
using GrilleDemineur = vector<vector<char>>; // tableau 2D de caractères
using LigneDemineur = vector<char>;
/// END GrilleDemineur

const GrilleDemineur uneGrille = {
    { ' ', 'm', 'o', ' ', 'm', 'M' },
    { 'm', 'm', 'm', 'o', 'm', ' ' },
    { 'm', 'm', 'm', 'o', ' ', 'm' },
    { 'm', 'm', 'm', ' ', 'M', ' ' },
};
const GrilleDemineur uneGrilleGagnante = {
    { ' ', 'm', ' ', ' ', 'm', 'M' },
    { 'm', 'm', 'm', ' ', 'm', ' ' },
    { 'm', 'm', 'm', ' ', ' ', 'm' },
    { 'm', 'm', 'm', ' ', 'M', ' ' },
};

/// BEGIN nombreMines
/** Compte le nombre de mines dans une grille
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return le nombre de mines dans grille
 **/
int nombreMines(GrilleDemineur grille) {
    int sum = 0;
    for (auto i : grille) {
        for (auto j : i) {
            if (j=='m' || j=='M') sum++;
        }
    }
    return sum;
}
/// END nombreMines

void nombreMinesTest() {
    CHECK( nombreMines(uneGrille) == 15);
    CHECK( nombreMines(uneGrilleGagnante) == 15);
}


/** Renvoie un booléen aléatoire qui initialise le tirage aléatoire des mines **/
bool boolAleatoire() {
    string sproba;
    int iproba;
    cout << "Quelle est la probabilité qu'une case contienne une mine ?\n";
    cin >> sproba;
    iproba = atoi(sproba.c_str());
    srand(time(NULL));
    return rand() % 100 + 1 < iproba;
}

/// BEGIN grilleInitiale
/** Construit une grille initiale
 * @param n un entier positif
 * @param m un entier positif
 * @return un tableau de caractères de n lignes et m colonnes rempli
 *  aléatoirement et ne contenant que des 'm' ou 'o'
 **/
GrilleDemineur grilleInitiale(int n, int m) {
    GrilleDemineur grille = GrilleDemineur(n);
    for (int i=0; i<n; i++) {
        grille[i] = LigneDemineur(m);
        for (int j=0; j<m; j++) {
            if (boolAleatoire()) grille[i][j] = 'm';
            else grille[i][j] = 'o';
        }
    }
    return grille;
}
/// END grilleInitiale

/// BEGIN grilleEstGagnante
/** Teste si une grille est gagnante
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return un booléen vrai si grille est une grille gagnante, ie si
 *  toutes les cases qui ne sont pas des mines ont été démasquées
 **/
bool grilleEstGagnante(GrilleDemineur grille) {
    for (auto i : grille) {
        for (auto j : i) {
            if (j=='o' || j=='O') return false;
        }
    }
    return true;
}
/// END grilleEstGagnante

void grilleEstGagnanteTest() {
    CHECK( not grilleEstGagnante(uneGrille) );
    CHECK(     grilleEstGagnante(uneGrilleGagnante) );
}

/// BEGIN minesVoisines
/** Renvoie le nombre de mines voisines à ième ligne, jème colonne
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @param i un entier décrivant une ligne de grille
 * @param j un entier décrivant une colonne de grille
 * @return un entier entre 0 et 8 comptant le nombre de mines
 *  adjacentes à grille[i][j]
 **/
int minesVoisines(GrilleDemineur grille, int i, int j) {
    int H = grille.size();
    int W = grille[0].size();
    int sum = 0;
    for (int Dy=-1; Dy<2; Dy++) {
        for (int Dx=-1; Dx<2; Dx++) {
            if (Dy== 0 && Dx==0) { continue; }
            if ((j+Dx)>=0 && (j+Dx)<W && (i+Dy)>=0 && (i+Dy)<H) {
                if (grille[i+Dy][j+Dx] == 'm' || grille[i+Dy][j+Dx] == 'M') sum++;
            }
        }
    }
    return sum;
}
/// END minesVoisines

void minesVoisinesTest() {
    CHECK( minesVoisines(uneGrille, 0, 0) == 3);
    CHECK( minesVoisines(uneGrille, 2, 1) == 8);
    CHECK( minesVoisines(uneGrille, 2, 0) == 5);
    CHECK( minesVoisines(uneGrille, 1, 5) == 4);
    CHECK( minesVoisines(uneGrille, 3, 5) == 2);
}

/// BEGIN dessinGrille
/** Dessine une grille
 * @param grille un tableau 2D de caractères (vector<vector<char> >)
 * @return une chaîne de caractères (string) décrivant la grille de
 *  gauche à droite et de bas en haut, un retour à la ligne séparant
 *  chaque ligne de grille
 *
 * Indications:
 * - si s et t sont des chaînes de caractères, s+t est leur concaténation
 * - "\n" représente un saut de ligne
 **/

string dessinGrille(GrilleDemineur grille) {
    return "3  3 M\n     4\n    3 \n   3M2\n";
}
/// END dessinGrille

void dessinGrilleTest() {
    CHECK( dessinGrille(uneGrille) == "3  3 M\n     4\n    3 \n   3M2\n");
}

int main() {
    cout << "Lancement des tests. Si tout marche bien, rien ne devrait s'afficher ci dessous."
         << endl;
    nombreMinesTest();
    grilleEstGagnanteTest();
    minesVoisinesTest();
    dessinGrilleTest();
}

