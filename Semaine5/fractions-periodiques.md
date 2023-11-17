---
jupytext:
  notebook_metadata_filter: rise
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
rise:
  auto_select: first
  autolaunch: false
  centered: false
  controls: false
  enable_chalkboard: true
  height: 100%
  margin: 0
  maxScale: 1
  minScale: 1
  scroll: true
  slideNumber: true
  start_slideshow_at: selected
  transition: none
  width: 90%
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a99f9f25c1e45bf7597532a66d3d2223", "grade": false, "grade_id": "cell-8871e65d0c07dba2", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : fractions unitaires et périodicité

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "30f5851089984008c6165a81004370f0", "grade": false, "grade_id": "cell-f9a970f036e2b3bd", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Cet exercice est inspiré du problème 26 du projet Euler.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: bb49ce7837d0704f2579abca0a28d4c0
  grade: false
  grade_id: cell-2aa694517c39cd0c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <vector>
#include <iostream>
using namespace std;
using tableau = vector<int>;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "63cd77e973e49124e05e035347e0ea72", "grade": false, "grade_id": "cell-cdbee297fc69d2bc", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Une fraction unitaire est une fraction dont le numérateur est 1. Les
représentations décimales des premières fractions unitaires sont
données dans la table ci-dessous :

| Fraction unitaire | représentation décimale |
| ---               | ---                     |
| $1/2$             | 0.5                     |
| $1/3$             | 0.(3)                   |
| $1/4$             | 0.25                    |
| $1/5$             | 0.2                     |
| $1/6$             | 0.1(6)                  |
| $1/7$             | 0.(142857)              |
| $1/8$             | 0.125                   |
| $1/9$             | 0.(1)                   |
| $1/10$            | 0.1                     |
|                   |                         |

où 0.1(6) dénote $0.166666...$, la séquence de un chiffre, 6, se
répétant à l'infini. On peut y voir aussi que la représentation
décimale de $1/7$ a une période à six chiffres.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e196ac5ff18ab5cb3ea8cb307b26ba07", "grade": false, "grade_id": "cell-cdbee297fc69d2bd", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Problème (Euler 26) :** déterminer la plus grande période pour une fraction unitaire dont le dénominateur est inférieur à 1000.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "24ecf0cdd52b4c831aecc5bbde2d0a3b", "grade": false, "grade_id": "cell-3ce9050810fd9ba3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

À vous de résoudre ce problème! Vous pouvez suivre les indications ci-dessous ou,
pour un défi plus élevé, résoudre le problème entièrement par vous même.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "06a672a3c38bcc58c1da6eb3b3e58b58", "grade": false, "grade_id": "cell-36cd2483e21543b6", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Algorithme de division

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cc10e51dd3ab722887ae25ddd462b59b", "grade": false, "grade_id": "cell-c0f2e00a250998df", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- En s'inspirant de la manière dont vous faisiez des divisions à la
  main en primaire, écrivez une fonction `fractionUnitaire` qui
  calcule, grâce à des divisions euclidiennes successives, les $k$
  premières décimales de la fraction $1/n$.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e95b741baf9ca85fab56ec46c6952a86
  grade: false
  grade_id: cell-2aa694517c39cd0d
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fraction unitaire décimale par décimale.
 *  @param n un entier, dénominateur de la fraction calculée.
 *  @param k un entier, une précision.
 *  @return un tableau de taille k qui contient les k premières décimales de 1/n
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: bb05c570ae6257c5b6759cac25dea659
  grade: false
  grade_id: cell-07a129546cc1cbfc
  locked: false
  schema_version: 3
  solution: true
  task: false
---
tableau fractionUnitaire(int n, int k) {
    int Num = 1;
    vector<int> tab = vector(k, 0);
    for (int Idx=0; Idx<k; Idx++) {
        while (Num < n) { Num *= 10; }
        int biggestDiv = Num/n;
        tab[Idx] = (biggestDiv);
        Num -= biggestDiv*n;
        if (!Num) { return tab; }
    }
    return tab;
}
```

```{code-cell}
fractionUnitaire(11, 10)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "da6e01aff1b26273d3c8349f08ce16e6", "grade": false, "grade_id": "cell-03108fe73c1fd2f8", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Recherche d'un algorithme

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "77642b8075041dbff115fcdbf2edf9e7", "grade": false, "grade_id": "cell-73afe13495aefcbe", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Exécuter la fonction précédente à la main pour `n=7`.
- Que remarque-t-on sur les valeurs successives de `r`.

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b27df0641941c7c07448f7ab4145bea4", "grade": true, "grade_id": "cell-5fdeea9d6c4a011e", "locked": false, "points": 0, "schema_version": 3, "solution": true, "task": false}}

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "53b50d68678721e92e76f539d56f6126", "grade": false, "grade_id": "cell-8d91e2dc34b9067d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Implantation de la fonction

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "19aed2c0c5685f4f1f3bffec1362871f", "grade": false, "grade_id": "cell-2cd128856bfbb333", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- En se basant sur la remarque précédente, inspirez-vous de la
  fonction `factionUnitaire` afin d'avoir une fonction qui pour un $n$
  donné calcule la taille de la période de $1/n$. On pourra utiliser
  un tableau `T` de taille `n`, dont toutes les valeurs sont
  initialement -1, que l'on remplira de la sorte que `T[i] = k` si,
  dans la k-ième exécution de la boucle, $r=i$.

```{code-cell}
---
editable: false
nbgrader:
  cell_type: code
  checksum: bb49ce7837d0704f2579abca0a28d4c0
  grade: false
  grade_id: cell-2aa694517c39cd0c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <vector>
#include <iostream>
using namespace std;
using tableau = vector<int>;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2b2cc590f4879e6381267b9b49831fbf
  grade: false
  grade_id: cell-d19fd418b56ea721
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int periode(int n) {
    int Num = 10;
    vector<int> firstFind = vector(n, 0);
    vector<bool> alreadyFound = vector(n, false);
    int i=1;
    do {
        while (Num < n) { Num *= 10; i++; }
        int biggestDiv = Num/n;
        Num -= biggestDiv*n;
        i++;
        
        if (!alreadyFound[Num]) {
            alreadyFound[Num] = true;
            firstFind[Num] = i;
        } else {
            return i-firstFind[Num];
        }

        Num *= 10;
        // cout << biggestDiv << "-";
        // cout << Num << endl;
    } while (Num!=0);
    return 0;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "782bd92ddc50bb4fe0a83757c54a09b9", "grade": false, "grade_id": "cell-74b54337048a5622", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Vous pouvez maintenant écrire un programme qui répond à la question
  posée en stockant dans une variable `P` la longueur de la plus
  grande période et dans une variable `N` le plus petit entier positif
  pour lequel cette période est atteinte.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: db32df2ac4890f77000c243e80934320
  grade: false
  grade_id: cell-d8a205c6a3ba699d
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int P = 0;
int N = 0;
int Per;
for (int i=2; i<=1000; i++) {
    Per = periode(i);
    if (Per > P) {
        P = Per;
        N = i;
    }
}
```

La longueur de la plus grande période est :

```{code-cell}
P
```

Le plus petit entier positif pour lequel elle est atteinte est :

```{code-cell}
N
```

```{code-cell}

```
