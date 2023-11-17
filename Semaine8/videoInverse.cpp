#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

/** Image en vidéo inverse
* @param image1: le nom du fichier contenant l’image à lire
* @param image2: le nom du fichier pour l’image à écrire **/
void videoInverse(string image1, string image2){
    int Size;
    int Max;
    
    ifstream fichier1;
    ofstream fichier2;
    fichier1.open(image1);

    string type;
    fichier1 >> type;
    fichier1 >> Size;
    fichier1 >> Size;
    fichier1 >> Max;
    
    fichier2.open(image2);
    fichier2 << type << endl << Size << " " << Size << endl << Max << endl;
    int Current;
    for (int y=0; y<=Size; y++) {
        for (int x=0; x<Size; x++) {
            fichier1 >> Current;
            int Inv = Max - Current;
            fichier2 << Inv << " ";
        }
        fichier2 << endl;
    }
    fichier2.close();
    fichier1.close();

}

int main () {
    string image1, image2;
    cout << "Veuillez indiquer le nom de fichier de l'image à inverser." << endl;
    cin >> image1;
    cout << "Où voulez-vous sauvegarder l'image inversée ?" << endl;
    cin >> image2;
    videoInverse(image1, image2);
    return 0;
}

