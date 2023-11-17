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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "120edda5b4f1f50864903e835fa6d7e2", "grade": false, "grade_id": "cell-a7cb2ec64ca805b6", "locked": true, "schema_version": 3, "solution": false}}

# TP : implanter la fonction exponentielle (2/5)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cad86446f5f005c78a920d78697c45a8", "grade": false, "grade_id": "cell-dfc454aa3b53f790", "locked": true, "schema_version": 3, "solution": false}}

## Partie 2 : calculer une somme infinie?

La définition mathématique de l'exponentielle suppose de calculer une
*somme infinie*. Ce n'est pas possible en pratique! On propose donc
d'implanter la fonction suivante qui calcule une *approximation* de la
fonction exponentielle obtenue en tronquant la somme à un certain rang
$r$ : $e^x \approx \sum_{n=0}^r \frac{x^n}{n!}$

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1f94fbadb1ecbb9f024af407fa52b411", "grade": false, "grade_id": "cell-b916e98c49f6f97c", "locked": true, "schema_version": 3, "solution": false}}

Copier-collez dans les deux cellules suivantes vos fonctions
`puissance` et `factorielle` de la [partie 1](02-exponentielle1.md),
puis complétez l'implantation de la fonction `expRang` et vérifiez
qu'elle passe les tests fournis.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 88d3dae27d40f9baab1844fc693b6120
  grade: false
  grade_id: cell-ed4b87cdbd09b4b1
  locked: false
  schema_version: 3
  solution: true
---
double factorielle(int n) {
    if (n<=1) { return 1; }
    return n * factorielle(n-1);
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 14278aa35bc3a14293143073bd1841e4
  grade: false
  grade_id: cell-40704048f0f43a58
  locked: false
  schema_version: 3
  solution: true
---
double puissance(double x, int n) {
    if (n==0) { return 1; }
    else if (n==1) { return x; }
    return x * puissance(x, n-1);
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c90183b2640252909a94b9d31e15e3a1
  grade: false
  grade_id: cell-583ab182274bf121
  locked: false
  schema_version: 3
  solution: true
---
/** Exponentielle tronquée à un certain rang r
 * @param x un nombre à virgule flottante en double précision
 * @param r un nombre entier positif
 * @return 1 + x^1/1!  + x^2/2! + x^3/3! + ...  + x^r/r!
**/
double expRang(double x, int r) {
    if (r==0) { return 1; }
    return puissance(x, r) / factorielle(r) + expRang(x, r-1);
}
```

```{code-cell}
expRang(5,1)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0f4a4207b13e8754bc0c314417e1a0ac
  grade: true
  grade_id: cell-0841e8afc22ba740
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( expRang(6, 0) == 1  ) // 6^0/1
CHECK( expRang(6, 1) == 7  ) // 6^0/1 + 6/1
CHECK( expRang(6, 2) == 25 ) // 6^0/1 + 6/1 + 36/2
CHECK( expRang(6, 3) == 61 );// 6^0/1 + 6/1 + 36/2 + 36*6/6
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f9089f2a0d909bac663832312ee14d60", "grade": false, "grade_id": "cell-162792f03bec12d9", "locked": true, "schema_version": 3, "solution": false}}

Plus on augmente le rang, plus on se rapproche de la valeur de
$e^6=403,429\cdots$.

Dans la cellule ci-dessous, calculez une approximation de la valeur de
$e^{6}$ et **augmentez le rang jusqu'à ce que la valeur affichée ne
change plus** (la valeur ajoutée est trop petite pour changer
l'affichage).

```{code-cell}
#include <iostream>
using namespace std;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 615d3115077126e55d0aa485612ed4c5
  grade: false
  grade_id: cell-c845f3c8812b2ff5
  locked: false
  schema_version: 3
  solution: true
---
for (int r=0; r<=22; r++) {
    cout << expRang(6, r) << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f7d6ccfe20e721bad0e10fd7ec3953a1", "grade": false, "grade_id": "cell-b586c5b168fc5914", "locked": true, "schema_version": 3, "solution": false}}

Calculez maintenant une approximation de la valeur de
$e^{10}=22026,46\cdots$ avec le même rang :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 0f11c2ddbd22bf72cd8d20bf4f65ff87
  grade: false
  grade_id: cell-586d52cbad6530df
  locked: false
  schema_version: 3
  solution: true
---
for (int r=0; r<=22; r++) {
    cout << expRang(10, r) << endl;
}
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f78e09df5f2a730078cba0d8a1847e1a", "grade": true, "grade_id": "cell-6e01d081ee0b9bd2", "locked": false, "points": 1, "schema_version": 3, "solution": true}}

Que constatez vous?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "72af848b4223a1ee2c5f78c395e2ed61", "grade": false, "grade_id": "cell-e1f369de58992c8b", "locked": true, "schema_version": 3, "solution": false}}

Augmentez le rang jusqu'à ce que la valeur affichée ne change plus :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 827e619c8cfbd481c965ead9dcbe8e4b
  grade: false
  grade_id: cell-9ab12e4a0fe9cddb
  locked: false
  schema_version: 3
  solution: true
---
for (int r=0; r<=30; r++) {
    cout << expRang(10, r) << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "722ee418bf5eda53acab12df0ba8fe57", "grade": false, "grade_id": "cell-c9a5001fba7bb1a4", "locked": true, "schema_version": 3, "solution": false}}

## Bilan de la partie 2

Bravo, vous avez implanté une approximation de la fonction
exponentielle en tronquant sa formule à un certain rang. Cependant, au
vu des exemples ci-dessus, l'utilisateur souhaiterait spécifier non
pas le *rang*, mais la *précision* qu'il souhaite obtenir. Pour cela
il faut d'abord formaliser cette idée de précision. C'est l'objet de
la [partie 3](02-exponentielle3.md).
