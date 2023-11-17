#include <fstream>
using namespace std;

int main() {
    ofstream fichier;                           // Déclaration
    fichier.open("bla.txt");                    // Ouverture
    fichier << "Noel " << 42 << endl;           // Écriture
    fichier.close();                            // Fermeture
}

