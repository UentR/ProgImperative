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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "428f797fd97eab35723ed43789ccd075", "grade": false, "grade_id": "cell-9aacd071eecda33d", "locked": true, "schema_version": 3, "solution": false}}

# TP : implanter la fonction exponentielle (4/5)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "943cb325764477f09b90da7018053f43", "grade": false, "grade_id": "cell-fd5a373907e22622", "locked": true, "schema_version": 3, "solution": false}}

## Partie 4 : calcul de l'exponentielle avec une précision relative fixée ♣

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "43746ea5872030ae2307912750f92b48", "grade": false, "grade_id": "cell-0749edc234488c4e", "locked": true, "schema_version": 3, "solution": false}}

Dans la partie 2, vous avez implanté une fonction `expRang` qui
calcule une approximation de l'exponentielle en tronquant la somme à
un certain rang décidé à l'avance. Cependant le rang nécessaire pour
obtenir une bonne précision dépend du nombre réel $x$ pour lequel on
veut calculer $e^x$. On cherche maintenant à calculer une
approximation de l'exponentielle en fixant la *précision* et non plus
le rang. Pour cela on va écrire une nouvelle fonction d'approximation
de l'exponentielle, dans laquelle le rang auquel on arrête la somme ne
sera pas décidé à l'avance, mais dépendra de l'évolution du calcul
qu'on est en train de faire.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f3b1671851712e8d13e69edbd5f91296", "grade": false, "grade_id": "cell-3e4cb5925b030399", "locked": true, "schema_version": 3, "solution": false}}

Commencez par copier-coller dans les quatre cellules suivantes vos
fonctions `puissance` et `factorielle` de la 
[partie 1](02-exponentielle1.md) ainsi que `abs` et `egal` de la
[partie 3](02-exponentielle3.md):

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 78b2bca5554209d4141ed9b08dce5ba2
  grade: false
  grade_id: cell-26c2f80b0554f206
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
  checksum: 335f18c22a70fc7a50c179c1f6c539fa
  grade: false
  grade_id: cell-7e5ba48349f32c00
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
  checksum: aa67d244c491bd94c8c5f05bbee83a2c
  grade: false
  grade_id: cell-40ce2ba5515a4b3f
  locked: false
  schema_version: 3
  solution: true
---
double abs(double x) {
    if (x<0) { return -x; }
    return x;
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 3b4d70901173c631877ca29fdcdc62c3
  grade: false
  grade_id: cell-5658ebbda24de111
  locked: false
  schema_version: 3
  solution: true
---
bool egal(double x, double y, double E) {
    double Ax = abs(x);
    double Ay = abs(y);
    double Axy = abs(x-y);
    return (Axy<E*Ax) && (Axy<E*Ay);
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2522232378f4015788ae347cb76d26d6", "grade": false, "grade_id": "cell-d6b02ebdc5e27637", "locked": true, "schema_version": 3, "solution": false}}

Implantez une nouvelle fonction d'approximation de l'exponentielle qui
somme les termes $\frac{x^i}{i!}$ jusqu'à ce que le prochain terme à
ajouter ne modifie pas la valeur de la somme, selon la précision
donnée :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 090a4ebec90224d67d5af06fbc3265ee
  grade: false
  grade_id: cell-5b6857150b2f0d95
  locked: false
  schema_version: 3
  solution: true
---
/** Calcul de la fonction exponentielle à precision fixée
 * @param x un nombre de type double
 * @param epsilon un nombre de type double
 * @return e^x avec précision epsilon
**/
double expPrecision(double x, double epsilon) {
    double lastSomme = 1;
    double currentSomme = 1;
    int n = 1;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance(x, n) / factorielle(n));
        n++;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c181420de39a3d84a7aa9da1c4024f6a
  grade: false
  grade_id: cell-acdedc110ac3a389
  locked: true
  schema_version: 3
  solution: false
  task: false
---
double epsilon = 0.000000001
```

```{code-cell}
epsilon = 1e-9
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "18a04a06444876f326add610f77c2c43", "grade": false, "grade_id": "cell-83bc9f0ce83996e3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Le calcul suivant devrait renvoyer $2.718 281 828 459$ :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 14805f291bc97cc06f4686c02635b0e1
  grade: false
  grade_id: cell-7c1f3a734b045e42
  locked: true
  schema_version: 3
  solution: false
---
expPrecision(1, epsilon)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "131c9b8eeee35161bfaf9550181247c5", "grade": false, "grade_id": "cell-76536f0d66f087bc", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Il n'y a pas forcément suffisament de chiffres significatifs affichés
pour le vérifier. Faisons à la place un test :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cddbd8a05eb769065c71af2806ff8dbf
  grade: true
  grade_id: cell-f21a4cde086edd2b
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( abs( expPrecision(1, epsilon) - 2.718281828459 ) < epsilon )
```

Notre test d'arrêt ne garantit en fait pas d'obtenir une précision de epsilon : même si le terme suivant est plus petit que epsilon, l'accumulation de tous les termes suivants pourrait largement dépasser epsilon, comme dans les exemples suivants :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3458a7cb840a0ec3e18cd083d9d786cf
  grade: true
  grade_id: cell-9841d2b60ca74549
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( abs(expPrecision(3, epsilon) - 20.085536923 ) < 5*epsilon )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9ef2607b3820d17a5f0d2fbc0732a5e9
  grade: true
  grade_id: cell-4fb64a4278d2ce62
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( abs( expPrecision(5, epsilon) - 148.413159102 ) < 50*epsilon )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d13d4c02f28a1c75e40f8c79e4ce0174", "grade": false, "grade_id": "cell-f14c9177d33e54ce", "locked": true, "points": 1, "schema_version": 3, "solution": false, "task": true}}

Comparez vos résultats avec la fonction `exp` de C++ définie dans `cmath` :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2537f1aeb98505f096c75097b9b62f85
  grade: false
  grade_id: cell-2586899de62aebf4
  locked: true
  schema_version: 3
  solution: false
---
#include <cmath>
```

```{code-cell}
exp(5)
```

```{code-cell}
exp(3)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "114c7a66addc06fcec7170b5891d5ec4", "grade": false, "grade_id": "cell-9b25311fb953a3d7", "locked": true, "schema_version": 3, "solution": false}}

## Bilan de la partie 4

Très bien, vous avez implanté le calcul de la fonction exponentielle à
précision fixée. Maintenant étudions sa performance en calculant son
temps d'exécution :

```{code-cell}
%timeit expPrecision(10, 0.00000001);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "15e1d20aa7a0fec7765c2e53f92a4aba", "grade": false, "grade_id": "cell-44bb7d35a9655256", "locked": true, "schema_version": 3, "solution": false}}

Dans la [partie 5](02-exponentielle5.md), vous tenterez d'optimiser
cette implantation.
