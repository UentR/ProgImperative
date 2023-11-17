---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

% Fin entête jupytext
# Résumé de la syntaxe de base C++

Les exemples suivants résument la syntaxe des instructions de base
C++, et précisent les conventions de codage utilisées dans le cadre de
ce module: indentation, espacement, documentation au format javadoc
[^1]
et tests. *Complétez cette feuille à la main au verso comme vous le
souhaitez. Ce sera le seul document autorisé au partiel et à l'examen*.

[^2]: Pour plus de détails sur javadoc, voir par exemple
    <http://fr.openclassrooms.com/informatique/cours/presentation-de-la-javadoc/les-tags-javadoc-1>

```
if ( x == 1 ) {                  // Instruction conditionnelle (if)
    ...;
}
```
```
if ( x == 1 ) {                  // Instruction conditionnelle (if/else)
    ...;
} else if ( x < 2 and not y >= 3 ) {
    ...;
} else {
    ...;
}
```
```
for ( int i = 0; i < 10; i++ ) { // Instruction itérative: boucle for
    ...;
}
```
```
while ( i <= 10 ) {              // Instruction itérative: boucle while
    ...;
}
```
```
do {                             // Instruction itérative: boucle do ... while
    ...;
} while ( i <= 10 );
```
```
/** La fonction factorielle      // Documentation de la fonction factorielle
 * @param  n un nombre entier positif
 * @return n!
 **/
int factorielle(int n) {         // Exemple de déclaration de fonction
    int resultat = 1;
    for ( int k = 1; k <= n; k++ ) {
        resultat = resultat * k;
    }
    return resultat;
}
```
```
void factorielleTest() {         // Les tests de la fonction factorielle
    CHECK( factorielle(0) ==  1 );
    CHECK( factorielle(1) ==  1 );
    CHECK( factorielle(2) ==  2 );
    CHECK( factorielle(4) == 24 );
}
```
```
#include <iostream>              // Squelette de programme
using namespace std;
int main() {
    ...
}
```
```
cin >> n;                        // Lit la variable n au clavier
cout << 3*x + 1;                 // Affiche la valeur d'une expression
cout << endl;                    // Affiche un saut de ligne
```
