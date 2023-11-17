#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl;




// DEFINITIONS DES DIMENSIONS DU PROBLEME (variables globales)
int nbPlagesHoraires = 11;
int nbJours = 5;
int decalagePremiereHeure = 8;
double precision = 0.000000001;
///end dimensions

/// BEGIN jours
vector<string> jours = {"lundi", "mardi", "mercredi", "jeudi", "vendredi"};
/// END jours

vector<string> joursPerso = {"  Lundi  ", "  Mardi  ", " Mercredi ", "  Jeudi  ", " Vendredi "};

/** Le planning hebdomadaire d'une salle est modélisé par un tableau
 * de booléens à deux dimensions: cinq lignes correspondant aux cinq
 * jours de la semaine, onze colonnes correspondant aux onze plages
 * horaires de la journée. La valeur pour un jour et une plage horaire
 * donnée est true si la salle est réservée sur cette plage horaire,
 * et false si elle est libre.

 * Les plages sont d'une heure et commencent à l'heure pile.
 * Les plages sont les mêmes pour les cinq jours de la semaine.
**/

using Planning = vector<vector<bool>>;


// DEFINITION DES FONCTIONNALITES (fonctions)

/// BEGIN creationPlanning
/** créé un planning vide
 **/
Planning creationPlanning() {

    return Planning ({{false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}});

}
/// END creationPlanning


/// BEGIN testCreationPlanning
void creationPlanningTest(){
     Planning planning007 = creationPlanning();
     CHECK(planning007 ==
        Planning ({ {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false},
                                {false, false, false, false, false}
                                }
                            )
          );
}
/// END testCreationPlanning

/// BEGIN affichePlanning
/** Affiche en mode textuel mais lisible le planning d'occupation
* (par exemple en faisant la liste des horaires de reservations)
* @param planning un tableau de nbJours*nbPlagesHoraires booléens
*/


void affichePlanning(Planning planning) {

    for (int i=0; i<nbJours; i++) {
        cout << "Occupation pour " << jours[i] << " :" << endl;
        for (int j=0; j<nbPlagesHoraires; j++) {
            if (planning[i][j]) {
                cout << "\t" << "Occupé à " << j+decalagePremiereHeure << "h" << endl;
            }
        }
        cout << endl;
    }

}
/// END affichePlanning

/// BEGIN tauxOccupation
/** calcule le taux d'occupation en pourcentage de la salle
* dont on transmet le planning sous forme codé.
* @param planning un tableau de nbJours*nbPlagesHoraires
* booléens supposé rectangulaire car cree avec creationPlanning()
* qui code la prévision d'occupation de la salle concernée
* true: la salle est réservée sur la plage horaire concernée,
* false : la salle est libre à l'heure codée.
* @return le taux d'occupation en pourcentage
* C'est à dire le nombre de réservations dans le planning
* divisé par le nombre de plages de réservations possibles
* (normalement nbJours*nbPlagesHoraires)
*/
double tauxOccupation(Planning planning) {
    int sum = 0;
    for (int i=0; i<nbJours; i++) {
        for (int j=0; j<nbPlagesHoraires; j++) {
            sum += planning[i][j];
        }
    }
    return sum/(nbJours*nbPlagesHoraires) * 100;

}
/// END tauxOccupation

/// BEGIN testTauxOccupation
void tauxOccupationTest() {
    //une salle presque entièrementLibre
    Planning salle306 =
                          creationPlanning();
    // une salle très occupée
    Planning salleTresOccupee =
                          creationPlanning();
    //une salle quelconque
    Planning salleRose =
                          creationPlanning();
    CHECK(  abs(tauxOccupation( salle306        )) < precision);
    CHECK(  abs(tauxOccupation( salleRose       )) < precision);
    CHECK(  abs(tauxOccupation( salleTresOccupee)) < precision);
    //réservations
    salle306[1][2] = true;
    salle306[1][1] = true;

    for (int j = 0; j < nbJours; j++) {
        for (int p = 0; p < nbPlagesHoraires; p++) {
            if (p % 2 == 1) {
                salleRose[j][p] = false;
            } else        {
                salleRose[j][p] = true;
            }
        }
    }

    for (int j = 0; j < nbJours; j++) {
        for (int p = 0; p < nbPlagesHoraires; p++) {
            salleTresOccupee[j][p] = true;
        }
    }
    CHECK( abs(tauxOccupation( salle306         ) -   4) < precision);
    CHECK( abs(tauxOccupation( salleRose        ) -  50) < precision);
    CHECK( abs(tauxOccupation( salleTresOccupee ) - 100) < precision);
}
/// END testTauxOccupation

/// BEGIN afficheEmploiDuTemps
/** affiche le même caractère n fois
*@param c char le caractère à afficher plusieurs fois
*@param nFois entier le nb de fois que la répétion doit avoir lieu
*/
void afficheCaractere(char c, int nFois) {
    for ( int i = 0; i < nFois; i++ ) {
        cout << c;
    }
}

/// BEGIN affichePlanningGrille
/** (trèfle) affiche un planning sous la forme d'une "grille".
* Chaque colonne commence par le nom du jour representé,
* chaque ligne commence par la plage horaire representée.
* Le mot "Réservé" apparaît sur les plages réservées
* et les autres apparaissent en blanc.
* On pourra utiliser les symboles '|' et '_' pour tracer des lignes
* On pourra aussi utiliser la fonction afficheCaractere
*@param planning: tableau de booléens: le planning à afficher
*/

void affichePlanningGrille(Planning planning) {
    // Affiche jour
    afficheCaractere('-', 59);
    cout << endl;
    cout << "|     |";
    for (string jours : joursPerso) {
        cout << jours << "|";
    }
    cout << endl;


    
    for (int i=0; i<nbPlagesHoraires; i++) {
        afficheCaractere('-', 59);
        
        cout << endl << "|" << setw(3) << decalagePremiereHeure+i << "h |";
        for (int j=0; j<nbJours; j++) {
            if (planning[i][j]) {
                if (j!=2 && j!=4) {
                cout << " Réservé |";
                } else {
                    cout << "  Réservé |";
                }
            } else {
                if (j!=2 && j!=4) {
                cout << "         |";
                } else {
                    cout << "          |";
                }
            }
            
        }
        cout << endl;
    }
    afficheCaractere('-', 59);
    cout << endl;
}
/// END affichePlanningGrille


// EXEMPLE SUCCINT D'UTILISATION
int main() {

    Planning planning = creationPlanning();

    // réservation de la salle le mardi à 9h00
    planning[1][1] = true;
    //réservation de la salle le mercredi entier
    int jour = 2;
    for (int plage = 0;
             plage < nbPlagesHoraires;
             plage++) {
        planning[jour][plage] = true;
    }

    cout << "============================================" << endl;
    cout << "== Affichage planning textuel"                << endl;
    cout << "============================================" << endl;
    affichePlanning(planning);
    cout << endl;
    cout << "Taux d'occupation : " << tauxOccupation(planning);
    cout << "%" << endl;

    cout << "============================================" << endl;
    cout << "== Affichage planning grille"                 << endl;
    cout << "============================================" << endl;
    affichePlanningGrille(planning);
    return 0;
}

