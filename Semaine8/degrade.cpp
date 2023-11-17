#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

    int Size = 180;
    float Max = 255.;
    float Step = Max / (Size*2);
    ofstream fichier;                           // Déclaration
    fichier.open("degrade.pgm");                    // Ouverture
    fichier << "P2" << endl << Size << " " << Size << endl << Max << endl;
    for (int y=0; y<=Size; y++) {
        for (int x=0; x<Size; x++) {
            int Coord = x+y;
            int Nbr = Coord * Step;
            fichier << Nbr << " ";
        }
        fichier << endl;
    }
    fichier.close();

}


