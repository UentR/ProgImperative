#include <stdexcept>
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#define CHECK(C) if ( !(C) ) { std::cerr << "Test failed: "#C << std::endl; }

using namespace std;
using tableau = vector<int>;

// Copiez ici les différentes fonctions nécessaires au jeu de Yams :
int aleaInt(int a, int b) {
    return rand() % (b - a + 1) + a;
}

tableau lanceDes() {
    vector<int> Des = vector<int>(5);
    for (int Idx=0; Idx<5; Idx++) {
        Des[Idx] = aleaInt(1, 6);
    }
    return Des;
}

void afficheDes(vector<int> Des) {
    for (int i=0; i<Des.size(); i++) {
        cout << Des[i] << "; ";
    }
    cout << endl;
}

tableau compteDes(vector<int> des) {
    vector<int> Count = vector<int>(6);
    for (int Idx=0; Idx<5; Idx++) {
        Count[des[Idx]-1]++;
    }
    return Count;
}

int chercheDansTableau(int Target, vector<int> Tab) {
    for (int Idx=0; Idx<Tab.size(); Idx++) {
        if (Target == Tab[Idx]) return Idx;
    }
    return -1;
}

int pointsFigureYams(vector<int> des) {
    for (int i=0; i<des.size()-1; i++) {
        if (des[i] != des[i+1]) return 0;
    }
    return des[0] * 5 + 60;
}

int pointsFigureBrelan(vector<int> des) {
    vector<int> compte = compteDes(des);
    
    int valeur = (chercheDansTableau(3, compte) + 1)
               + (chercheDansTableau(4, compte) + 1)
               + (chercheDansTableau(5, compte) + 1);

    if (valeur > 0) {
        return (valeur * 3) + 10;
    } else {
        return 0;
    }
}

int pointsFigureFull(vector<int> Des) {
    vector<int> Count = compteDes(Des);

    int Three = chercheDansTableau(3, Count) + 1;
    int Two = chercheDansTableau(2, Count) + 1;
    
    bool Full = Three * Two;


    if (Full) {
        return 3*Three + 2*Two + 20;
    }
    return 0;
}

int pointsFigureCarre(vector<int> Des) {
    vector<int> Count = compteDes(Des);

    for (int Idx=0; Idx<6; Idx++) {
        if (Count[Idx] == 4) return (Idx+1)*4 + 30;
    }
    return 0;
}

int pointsFigureGrandeSuite(vector<int> Des) {
    set<int> Unique(Des.begin(), Des.end());
    if (Unique.count(2) && Unique.count(3) && Unique.count(4) && Unique.count(5)) {
        if (Unique.count(6)) return 70;
        else if (Unique.count(1)) return 65;
    }
    return 0;
}

int pointsFigurePetiteSuite(vector<int> Des) {
    set<int> Unique(Des.begin(), Des.end());
    if (Unique.count(3) && Unique.count(4)) {
        if (Unique.count(5)) {
            if (Unique.count(6)) return 58;
            else if (Unique.count(2)) return 54;
        }
        else if (Unique.count(2) && Unique.count(1)) return 50;
    }
    return 0;
}

int pointsFigure(vector<int> des, string figure) {
    if        ( figure == "brelan" ) {
      return pointsFigureBrelan(des);
    } else if ( figure == "full"   ) {
        return pointsFigureFull(des);
    } else if ( figure == "carre"  ) {
        return pointsFigureCarre(des);
    } else if ( figure == "yams"   ) {
        return pointsFigureYams(des);
    } else if ( figure == "petitesuite") {
        return pointsFigurePetiteSuite(des);
    } else if ( figure == "grandesuite") {
        return pointsFigureGrandeSuite(des);
    }
    return 0;
}

int main() {
    // Initialisation de la fonction rand (pour les nombres aléatoires).
    srand(time(0));

    // AVANT LA BOUCLE PRINCIPALE
    vector<int> des;
    int score = 0;
    string reponse = "";

    // BOUCLE PRINCIPALE
    while ( true ) {
        des = lanceDes();

        afficheDes(des);
        cout << "Quelle figure voulez-vous chercher ?" << endl;

        // On boucle tant que la réponse de l'utilisateur n'est pas parmi
        // "brelan", "carre", "full", "yams" et "exit".
        do {
            // L'instruction suivante attend que le joueur entre du texte au clavier
            // et stocke sa réponse dans la chaine de caractères "reponse"
            cin >> reponse;
        } while ( reponse != "brelan"
            and reponse != "full" 
            and reponse != "carre" 
            and reponse != "yams" 
            and reponse != "exit" 
            and reponse != "petitesuite"
            and reponse != "grandesuite");

        // Si la réponse est "exit", on annonce la fin du jeu, on affiche le score et on termine.
        if ( reponse == "exit" ) { 
            cout << score << endl;
            return 0; 
        }

        score += pointsFigure(des, reponse);
    }
    // FIN DE LA BOUCLE PRINCIPALE
    return 0;
}