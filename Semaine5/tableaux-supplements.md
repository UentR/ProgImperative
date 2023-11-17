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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9476a623851cad9fd4fd67d8bf37263e", "grade": false, "grade_id": "cell-3cbc94081bd728ce", "locked": true, "schema_version": 3, "solution": false}}

# TP : exercices supplémentaires : tableaux, chaînes de caractères, `switch`

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 196643acace6c1aaf7d475b4b7f32a45
  grade: false
  grade_id: cell-ce888f6efcf83b87
  locked: true
  schema_version: 3
  solution: false
---
#include <vector>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "49fa096423a82362554b7e211f4927cf", "grade": false, "grade_id": "cell-19ad87e1d8a9a99f", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 1 : tableaux

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "54c11f90b150ab4b35a35fdb70c9cbe4", "grade": false, "grade_id": "cell-058102d9d95e90a6", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- ♣ Implantez une fonction `plus_proche` qui prend en arguments un
  tableau de réels et un réel, puis renvoie l'élement du tableau le
  plus proche de ce réel. S'il y en a plusieurs, n'importe lequel
  convient. Commencez par en écrire la documentation.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: bf724bb92f5fd2cff3b10027262efbff
  grade: true
  grade_id: cell-27f7673b67041a81
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
/** Renvoie l'élément le plus proche de la target
 *  @param t un tableau de float
 *  @param target
 *  @return élément le plus proche
**/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: fbaa43df2ad011152854c05b29cb327a
  grade: false
  grade_id: cell-e5ca6d001b080384
  locked: false
  schema_version: 3
  solution: true
  task: false
---
double plus_proche(vector<double> tab, double target) {
    double Space = abs(tab[0] - target);
    int Idx = 0;
    for (int i=1; i<tab.size(); i++) {
        if (abs(tab[i]-target) < Space) {
            Space = abs(tab[i]-target);
            Idx = i;
        }
    }
    return tab[Idx];
}
```

```{code-cell}
plus_proche( {42., -4.2, 4.2}, 0.)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f7aef7ca6bcc1229af144600a00745d7
  grade: true
  grade_id: cell-34d0d4cb0f65e1ab
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: subslide
---
CHECK( plus_proche( {0., 100., 200., 300.}, 245.) == 200. );
CHECK( plus_proche( {42., -4.2, 4.2}, 0.) == -4.2 or plus_proche( {42., -4.2, 4.2}, 0.) == 4.2);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8a38f09c7768133e8ec6599f8affae7b", "grade": false, "grade_id": "cell-d70f04be873364d3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- ♣ Implantez une fonction `est_dense` qui prend en arguments un
  tableau de réels et une valeur d'espacement réelle, et renvoie vrai
  si le tableau est dense et faux sinon. Un tableau est dense si deux
  valeurs consécutives du tableau n'ont jamais une différence
  supérieure à la valeur d'espacement.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 9cda26d2f050404c9355c86d9a77e21e
  grade: false
  grade_id: cell-596e4232a582ada2
  locked: false
  schema_version: 3
  solution: true
  task: false
---
/** Tester si un tableau est dense
 *  @param t un tableau de réels
 *  @param espacement un réel
 *  @return vrai deux valeurs consécutives de t ont une différence d au plus espacement
 **/
bool est_dense(vector<double> t, double espacement) {
    double Last = t[0];
    for (double i : t) {
        if (abs(i-Last) > espacement) {
            return false;
        }
        Last = i;
    }
    return true;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e7f77fd23a71fc7a47bc5ce0e47eb2e5
  grade: true
  grade_id: cell-cb4acc7da37cb36d
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( not est_dense( {100., 200., 300.}, 10. ));
CHECK(     est_dense( {0.7, 1.5, 2.4, 3.2}, 1. ));
CHECK( not est_dense( {0.7, 1.5, 2.1, 3.2}, 1. ));
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0dd21a5e340f7d2e2f244568cdbc5c8b", "grade": false, "grade_id": "cell-66b633c1602039e5", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 2 : code Morse ♣

- Voici une fonction qui traduit une lettre en code Morse. Elle
  contient une instruction `switch` que nous n'avons pas encore vue. À
  quoi ressemblerait la fonction avec des `if` à la place?

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 638271550e090f184479dde8cf0e9a99
  grade: false
  grade_id: cell-f07298860784b45c
  locked: true
  schema_version: 3
  solution: false
---
/** Traduction d une lettre en Morse
 *  @param a un caractère
 *  @return une chaîne de caractère représentant le code Morse du caractère
 **/
string morseCaractere(char a) {
    switch(a) {
    case 'A':
        return ".-";
    case 'B':
        return "-...";
    case 'C':
        return "-.-.";
    case 'D':
        return "-..";
    case 'E':
        return ".";
    case 'F':
        return "..-.";
    case 'G':
        return "--.";
    case 'H':
        return "....";
    case 'I':
        return "..";
    case 'J':
        return ".---";
    case 'K':
        return "-.-";
    case 'L':
        return ".-..";
    case 'M':
        return "--";
    case 'N':
        return "-.";
    case 'O':
        return "---";
    case 'P':
        return ".--.";
    case 'Q':
        return "--.-";
    case 'R':
        return ".-.";
    case 'S':
        return "...";
    case 'T':
        return "-";
    case 'U':
        return "..-";
    case 'V':
        return "...-";
    case 'W':
        return ".--";
    case 'X':
        return "-..-";
    case 'Y':
        return "-.--";
    case 'Z':
        return "--..";
    case ' ':
        return " ";
    default:
        return "???";
    }
}
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "830ad7ae891bc64f18778c6d424b8bd1", "grade": true, "grade_id": "cell-24dc4e8cc41056bd", "locked": true, "points": 0, "schema_version": 3, "solution": true}}

- Quel est le code morse pour «ZUT»? Pour «GSM»? Que se passerait-il
  si l'on ne mettait pas de séparation entre les lettres?

  % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

- Implantez une fonction `morseString` qui prend en entrée une chaîne
  de caractères de longueur arbitraire et qui la traduit entièrement
  en code Morse.

  :::{tip} Astuce

  Les chaînes de caractères (`string`) se comportent essentiellement
  comme des tableaux de caractères (`char`).

  :::

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: e3b6baac72b3d2620f742c9e5e659c57
  grade: false
  grade_id: cell-edcc8a9c8d2d2b2c
  locked: false
  schema_version: 3
  solution: true
---
/** Traduction d un texte en Morse
 *  @param chaine une chaîne de caractères
 *  @return une chaîne de caractère contenant la traduction en Morse de la chaîne de caractère
 **/
string morseString(string texte) {
    string Message = "";
    for (int i=0; i<texte.size(); i++) {
        Message += morseCaractere(texte[i]);
        if (i!=texte.size()-1) { Message += " "; }
    }
    return Message;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ccd4d4918f014fe051345faff7a66062", "grade": false, "grade_id": "cell-47d8a29517433827", "locked": true, "schema_version": 3, "solution": false}}

- Complétez les tests ci-dessous et vérifiez que la fonction les passe :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f87473d12802f0c9347c414b94aefc99
  grade: true
  grade_id: cell-ba2015b421b4196e
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( morseString("HELLO") == ".... . .-.. .-.. ---" );
CHECK( morseString("GOOD LUCK") == "--. --- --- -..   .-.. ..- -.-. -.-" );
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 889c87732e077777edee808912c3da8b
  grade: false
  grade_id: cell-ba2015b421b4196f
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2eb61f3077e5bd45166de943b3be34c3", "grade": false, "grade_id": "cell-951b06851913ec61", "locked": true, "schema_version": 3, "solution": false}}

## Bilan

Si vous êtes arrivés jusqu'ici, bravo! Votre prochain défi est de
résoudre le [projet Euler 26](fractions-periodiques.md).
