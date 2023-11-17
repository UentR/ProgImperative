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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "def6813dd09d8f7efd35adc3d093ccea", "grade": false, "grade_id": "cell-a741e2baae8a5295", "locked": true, "schema_version": 3, "solution": false}}

# TP : premières fonctions

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "443caba5749ce837c2fbe67b5e3d4b4b", "grade": false, "grade_id": "cell-8b56bb2323e686a8", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 1 : renvoyer versus afficher

Exécutez les cellules suivantes qui définissent deux fonctions.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0309a270ad04fb5aa24f938960bea063
  grade: false
  grade_id: cell-7d3032978c91517b
  locked: true
  schema_version: 3
  solution: false
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 27ad9871b0479b7db3ee1c72b262b8a2
  grade: false
  grade_id: cell-adbf3ea334252de8
  locked: true
  schema_version: 3
  solution: false
---
/** Une fonction qui calcule la valeur absolue
 * @param a un entier
 * @return la valeur absolue de a
 **/
int abs(int a) {
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cb884979fd90eee42e816e70e5d0a33f
  grade: false
  grade_id: cell-7d7a9fa58c13128d
  locked: true
  schema_version: 3
  solution: false
---
/** Une fonction qui affiche la valeur absolue
 * @param a, un entier
 **/
void afficheAbs(int a) {
    if (a > 0) {
        cout << a << endl;
    } else {
        cout << -a << endl;
    }
}
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "81b4641e12981a4d4c49365e27db05d2", "grade": true, "grade_id": "cell-ebbfec0d5cb0e626", "locked": false, "points": 1, "schema_version": 3, "solution": true}}

Observez les appels suivants; y a-t-il une différence entre `abs` et
`afficheAbs`?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c5e8883c3f9a3939488c775eeff3823a
  grade: false
  grade_id: cell-96a8003bde332ef4
  locked: true
  schema_version: 3
  solution: false
---
abs(-3)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e34051b5db2b78eebf0e4df9237f9b79
  grade: false
  grade_id: cell-acc035c120b5e1a5
  locked: true
  schema_version: 3
  solution: false
  task: false
---
abs(-3);
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1d9779641ca4534d57bd72865fe9e0f7
  grade: false
  grade_id: cell-525744fbd9aca5dd
  locked: true
  schema_version: 3
  solution: false
---
afficheAbs(-3)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0f3b4ffc6d0179133c8bbb8f69474fc3
  grade: false
  grade_id: cell-525744fbd9aca5de
  locked: true
  schema_version: 3
  solution: false
---
afficheAbs(-3);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "35af480b4fd6a6bec381cd9cf3350665", "grade": false, "grade_id": "cell-d95a34f5ac81eb33", "locked": true, "schema_version": 3, "solution": false}}

Essayez de deviner le résultat des appels suivants puis exécutez pour
vérifier :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fef171ff6f17fe7d68c30130ba3fcca3
  grade: false
  grade_id: cell-6a55898a16557a96
  locked: true
  schema_version: 3
  solution: false
---
abs(-5) + abs(3)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c2c79916db3967079effc25e0978340a
  grade: false
  grade_id: cell-866c4a0c9a4a6ab8
  locked: true
  schema_version: 3
  solution: false
---
afficheAbs(-5) + afficheAbs(3)
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9a7b8523124b8272ebb34058d0661693", "grade": true, "grade_id": "cell-6c7a39b6a3ef0358", "locked": false, "points": 1, "schema_version": 3, "solution": true}}

La seconde cellule vous donne une **erreur**, comprenez-vous pourquoi?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5a0dcb529d11d647e15b6f23762dfb94", "grade": false, "grade_id": "cell-5699e6d9d0f3d16a", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 2 : une fonction utilisant une fonction

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "725df36c83dbe0b882c8d1ac4bbc2a1e", "grade": false, "grade_id": "cell-b9cda32e468d6d8b", "locked": true, "schema_version": 3, "solution": false}}

Complétez la fonction ci-dessous dont on donne la **documentation**. 

⚠️ **Vous devez utiliser un appel à l'une des deux fonctions
précédentes, `afficheAbs` ou `abs`; laquelle faut-il choisir?
Pourquoi?** ⚠️

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 1c501e58613bbcd8d7ae1e0d610becbf
  grade: false
  grade_id: cell-ef47de23dc65918c
  locked: false
  schema_version: 3
  solution: true
---
/** Distance de deux points sur une droite
 * @param a un entier: la coordonnée du premier point
 * @param b un entier: la coordonnée du deuxième point
 * @return la valeur absolue de la différence entre a et b
 **/
int distance(int a, int b) {
    return abs(a-b);
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "184b61b25fb6ef12cb43f2e56de91f11", "grade": false, "grade_id": "cell-cf373e1ce7210f3a", "locked": true, "schema_version": 3, "solution": false}}

Vérifiez le comportement de votre fonction `distance` sur l'exemple
ci-dessous; essayez sur quelques autres exemples; corrigez la fonction
si nécessaire :

```{code-cell}
distance(5,3)
```

Les tests ci-dessous automatisent partiellement la vérification du
comportement de votre fonction; comme la valeur attendue est
spécifiée, il ne reste qu'à vérifier que l'on obtient bien `true` à
chaque fois :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 01bf41a5374fd85045dc1ecac10625bb
  grade: false
  grade_id: cell-1468d3b77d12dfbb
  locked: true
  schema_version: 3
  solution: false
---
distance(5,3) == 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e1a95f5a8a681bd97cdec030b4f599b2
  grade: false
  grade_id: cell-fb7ffc1acf3cf457
  locked: true
  schema_version: 3
  solution: false
---
distance(-4,2) == 6
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: eb0feb62d6805cce13956c83fb65cade
  grade: false
  grade_id: cell-973b66f0d812df05
  locked: true
  schema_version: 3
  solution: false
---
distance(2,-5) == 7
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dfa32ff0db129aa2f5efb92474d9c543", "grade": false, "grade_id": "cell-f389d530bfbe35e0", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 3 : tests automatiques

Dans l'exercice précédent, on a testé la fonction
`distance`. Cependant, il a fallu exécuter les trois cellules de test
séparément et s'assurer pour chacune d'entre elles que `true` était
affiché et pas `false`. Pour n'être averti que s'il y a un problème et
savoir d'où il provient, nous allons rassembler les tests en une seule
cellule à l'aide de l'infrastructure d'automatisation des tests vue en
cours.

Essayez les exemples suivants. Si vous avez une erreur du type `no
member named 'cerr'`, vous avez probablement redémarré le noyau en
oubliant d'exécuter la première cellule de cette feuille contenant
`#include <iostream>`.

:::{admonition} Astuce
:class: tip

À chaque fois que vous redémarrez le noyau, allez ensuite dans
`Cellule` -> `Exécuter toutes les précédentes`. Cela exécute toutes
les cellules qui sont avant celle où vous vous trouvez. Vous éviterez
ainsi de perdre du temps à chercher où sont les cellules qu'il faut
ré-exécuter.

:::

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0221e87f4b916f592a1fc11cebac8564
  grade: false
  grade_id: cell-409ed522d0d7ce28
  locked: true
  schema_version: 3
  solution: false
---
CHECK ( 1 < 2 );
CHECK ( 1 > 2 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "91d22ff843b1df78f27bb38067c82617", "grade": false, "grade_id": "cell-4f9b5f26274b8d47", "locked": true, "schema_version": 3, "solution": false}}

On remarque que, si la condition en paramètre de `CHECK` est vraie, il
n'y a aucun affichage. Par contre si la condition est fausse, un
message d'erreur indiquant la condition fausse est affiché.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "98ae6292c69003d4671b02e864c4ed41", "grade": false, "grade_id": "cell-c7c30794bfe3d639", "locked": true, "schema_version": 3, "solution": false}}

Avec `CHECK`, les tests de la fonction `distance` se mettent sous la
forme :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 956310f8b997c93c0ef30516de98e53b
  grade: true
  grade_id: cell-30fde9ec08937b80
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK ( distance(5,3)  == 2 );
CHECK ( distance(-4,2) == 6 );
CHECK ( distance(2,-5) == 7 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f26ab0e5548a3ba352d9ed7b5d520f8f", "grade": false, "grade_id": "cell-5a60b1893097e9fd", "locked": true, "schema_version": 3, "solution": false}}

Exécutez ces tests. Leur exécution ne devrait rien afficher.

+++

Exécutez les deux cellules suivantes pour définir et tester la
fonction `maxAbs`. Corrigez la fonction pour qu'elle passe les tests.

```{code-cell}
/** Une fonction qui renvoie la valeur absolue du plus grand des deux entiers 
 *  en valeur absolue
 * @param a un entier
 * @param b un entier
 * @return la valeur absolue du plus grand des deux entiers en valeur absolue
 **/
int maxAbs(int a, int b) {
    if (abs(a) >= abs(b)) {
        return abs(a);
    } else {
        return abs(b);
    }
}
```

```{code-cell}
CHECK( maxAbs(  6,  2) ==  6 );
CHECK( maxAbs(-15,  5) == 15 );
CHECK( maxAbs( -2, -3) ==  3 ); 
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f66e3e5bd16c39ca56cbcfbbfc163f64", "grade": false, "grade_id": "cell-d27b0a203d050706", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 4 (à la maison)

Mêmes consignes que pour l'exercice 1 :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: cfd4fe8e6c25625a8354e27169bcb955
  grade: false
  grade_id: cell-a3cf80e3952bdd34
  locked: false
  schema_version: 3
  solution: true
---
/** somme des valeurs absolues (aussi appelée norme L1)
 * @param a un entier
 * @param b un entier
 * @return la somme des valeurs absolues de a et b
 **/
int sommeAbs(int a, int b) {
    return abs(a) + abs(b);
}
```

```{code-cell}
sommeAbs(5,-3)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b932adcb116bc5d1b788b63a371b40e5
  grade: false
  grade_id: cell-6d67d87937dbe617
  locked: true
  schema_version: 3
  solution: false
---
sommeAbs(5,-3)  == 8
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8fdc77fae0f04f969ee5bc5fadb70753
  grade: false
  grade_id: cell-1cf910256b7ba798
  locked: true
  schema_version: 3
  solution: false
---
sommeAbs(-4,-2) == 6
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 985de6994cc90979fd7380dc7b744023
  grade: false
  grade_id: cell-b0072c6876feea78
  locked: true
  schema_version: 3
  solution: false
---
sommeAbs(2,5) == 7
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "373cff5b3615bb36534febe3e5fd1f9b", "grade": false, "grade_id": "cell-6501a3f1941bd272", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 5 : suivre la documentation et les tests

Implantez la fonction `nombreSecondes` dont la documentation est
donnée ci-dessous :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 52f65b81f67d2b65943e20b3dec2a2c6
  grade: false
  grade_id: cell-0d59febaf9233496
  locked: false
  schema_version: 3
  solution: true
---
/** Renvoie en secondes la durée décrite en jours, heures, minutes, secondes
 * @param j un entier représentant le nombre de jours
 * @param h un entier représentant le nombre d heures
 * @param m un entier représentant le nombre de minutes
 * @param s un entier représentant le nombre de secondes
 * @return la durée totale en secondes
**/
int nombreSecondes(int J, int H, int M, int S) {
    return J*86400 + H*3600 + M*60 + S;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "027ba9c90c0dce365d59909fbfec802f", "grade": false, "grade_id": "cell-e103b2353b1c2e15", "locked": true, "schema_version": 3, "solution": false}}

Vérifiez son fonctionnement sur les exemples et tests ci-dessous :

```{code-cell}
nombreSecondes(1,1,1,1)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 47ff5f144f91796cca062801d0d6cc26
  grade: true
  grade_id: cell-babf9ae1f3f02491
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( nombreSecondes(0,0,0,1)  == 1      );
CHECK( nombreSecondes(0,0,1,0)  == 60     );
CHECK( nombreSecondes(0,1,0,0)  == 3600   );
CHECK( nombreSecondes(1,0,0,0)  == 86400  );
CHECK( nombreSecondes(3,2,5,25) == 266725 );
```

## Bilan

Dans cette feuille, vous vous êtes familiarisés avec les fonctions :
distinction entre afficher et renvoyer, fonction appelant des
fonctions, documentation, tests, tests automatiques. Vous avez
maintenant le bagage requis pour la [suite du
TP](02-exponentielle1.md) où vous implanterez la fonction
exponentielle.
