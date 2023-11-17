#include <stdexcept>
#include <iostream>
#include <fstream>
using namespace std;

int main () {

    int Num1, Num2;
    cout << "Num1 : ";
    cin >> Num1;
    cout << "Num2 : ";
    cin >> Num2;
    
    ofstream fichier;                           // Déclaration
    fichier.open("multiplication.txt");                    // Ouverture
    fichier << Num1 << " fois " << Num2 << " vaut " << Num1*Num2 << endl;           // Écriture
    fichier.close();

    return 0;
}


