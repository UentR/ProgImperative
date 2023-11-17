#include <fstream>
using namespace std;

int main() {
    ofstream fichier;                           // Déclaration
    fichier.open("essai.txt");                    // Ouverture
    fichier << "17 fois 23 vaut " << 17*23 << endl;           // Écriture
    fichier.close();                            // Fermeture
}

