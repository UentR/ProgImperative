#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

    int Size = 100;
    
    ofstream fichier;                           // Déclaration
    fichier.open("damier-automatique.pbm");                    // Ouverture
    fichier << "P1" << endl << Size << " " << Size << endl;
    for (int y=0; y<Size; y++) {
        for (int x=0; x<Size; x++) {
            fichier << 1 - (x+y)%2 << " ";
        }
        fichier << endl;
    }
    fichier.close();

}

