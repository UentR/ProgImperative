---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++11
  language: C++11
  name: xcpp11
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6fa4f3661289650411f3a4b47da750d8", "grade": false, "grade_id": "cell-66ec1911286fbe2b", "locked": true, "schema_version": 3, "solution": false}}

# TP : tableaux : prise en main

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "afdda67551c4ee28f2b2423401c12387", "grade": false, "grade_id": "cell-28df08e3e0e1160c", "locked": true, "schema_version": 3, "solution": false}}

Comme indiqué dans le cours, on utilisera les `vector` de C++ comme tableaux. Pour cela, il est nécessaire de charger la bibliothèque standard pour les `vector`:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a4d83227a7ae55eae7a62b9c4f4e73c9
  grade: false
  grade_id: cell-63fea443dd9227d0
  locked: true
  schema_version: 3
  solution: false
---
#include <vector>
using namespace std;
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3b7ab619c3f70a5f2ad5a771106e5bda", "grade": true, "grade_id": "cell-edff045470e36941", "locked": false, "points": 1, "schema_version": 3, "solution": true, "task": false}}

**Exercice: (Cours)**

* Retrouvez dans le cours les trois étapes de la construction d'un tableau
* Dans la cellule suivante, on effectue **deux des trois étapes**.
    - Quelle étape est effectuée à la première ligne?
      % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
    - Quelle étape est effectuée à la deuxième ligne?
      % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 46b6b44c7c18489d037595fd7c745562
  grade: false
  grade_id: cell-255bc998349f2396
  locked: true
  schema_version: 3
  solution: false
  task: false
---
vector<int> v;
v = vector<int>(5);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e892c99bceae28d9ab7d1318e1fa0b44", "grade": false, "grade_id": "cell-2aac88f808c031a1", "locked": true, "schema_version": 3, "solution": false}}

`v` est maintenant un tableau de taille 5. Exécutez la cellule suivante pour voir les valeurs contenues dans le tableau.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3f704a2c00cf87f76201b1525b35d73f
  grade: false
  grade_id: cell-752d1cbd8b1096cd
  locked: true
  schema_version: 3
  solution: false
---
v
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c9c745b160258e8a70d264327fd5f937", "grade": false, "grade_id": "cell-9aefe25bfabe4077", "locked": true, "schema_version": 3, "solution": false}}

Il n'y a que des zéros ! C'est le comportement par défaut du compilateur que nous utilisons sur `Jupyter` mais ce n'est pas un *standard du `C++`*. On peut initialiser `v` de la façon suivante.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cb578093d047fc48d59e2cbd30555f78
  grade: false
  grade_id: cell-962f6ddd7bfde0eb
  locked: true
  schema_version: 3
  solution: false
---
v = {4, 1, 5, 2, 3};
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "49cef0b7dda7885875a89be81f70a16a", "grade": false, "grade_id": "cell-398f97ae39213d80", "locked": true, "schema_version": 3, "solution": false}}

**Dans la cellule suivante, déclarez, allouez et initilisez un tableau d'entier `v2` de taille 8 et contenant les valeurs : `2,5,1,8,4,6,3,5`.**

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: bd9240cc33149b19aba297f0819300b6
  grade: false
  grade_id: cell-c4a433e02211ce0a
  locked: false
  schema_version: 3
  solution: true
---
vector<int> v2 = {2,5,1,8,4,6,3,5};
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8f352ae820fafd22d4782bd5bbc40739", "grade": false, "grade_id": "cell-1c80844bfe695be1", "locked": true, "schema_version": 3, "solution": false}}

Exécutez les cellules suivantes pour vérifier que votre tableau contient les bonnes valeurs.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7f01e61c5e3fbb49b744eed6a4798267
  grade: false
  grade_id: cell-9a8d0b3142b0d6b8
  locked: true
  schema_version: 3
  solution: false
---
v2.size() // doit afficher 8
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8ffc58c70896f816b16525f50621a8a5
  grade: false
  grade_id: cell-a8a288f2cec8193d
  locked: true
  schema_version: 3
  solution: false
---
v2 // doit afficher {2, 5, 1, 8, 4, 6, 3, 5}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ca7667a9f4f3bf4cd7141247558d5e3d", "grade": false, "grade_id": "cell-47c4200601bed715", "locked": true, "schema_version": 3, "solution": false}}

On vérifie à présent avec `CHECK`

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 48934bfa7308bc4a50b66e3e50813716
  grade: true
  grade_id: cell-4463b0e3563ac7d7
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK ( v2.size() == 8 )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f11b3992b5ed5fc3a1b4d72110530839
  grade: true
  grade_id: cell-002c8f24fad7d1b9
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK(v2 == vector<int>({2, 5, 1, 8, 4, 6, 3, 5}))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6ec9cc6134ed6da823e51f3f88c9eacb", "grade": false, "grade_id": "cell-e91078439b442d19", "locked": true, "schema_version": 3, "solution": false}}

Un tableau permet l'accès à ces différentes valeurs à travers **un accès par indice**. Exécutez les cellules suivantes en exemple.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 89b3936611117fe85c80cd8b64142d6b
  grade: false
  grade_id: cell-133e86bc49f4c5ae
  locked: true
  schema_version: 3
  solution: false
---
v
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4f1ef730345160eda373ec77ce3be25f
  grade: false
  grade_id: cell-0566fca45132cf47
  locked: true
  schema_version: 3
  solution: false
---
v[0] // la première valeur du tableau (4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: bac9bee053ca4818501c6358014e4bce
  grade: false
  grade_id: cell-01f21aad0110fc98
  locked: true
  schema_version: 3
  solution: false
---
v[3] //  la valeur à l'indice 3 (2)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "05563438a1e2b5745f1c151c609089a6", "grade": false, "grade_id": "cell-226c7bcc4b40760f", "locked": true, "schema_version": 3, "solution": false}}

**De la même façon, affichez la dernière valeur du tableau**

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 7c58b3ec11761878a72c1e575e55ca43
  grade: true
  grade_id: cell-edfd07fa6d564992
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
v[v.size()-1]
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "40cd60433273c2af2a532488c1ffce04", "grade": false, "grade_id": "cell-f61f7fe07349fe42", "locked": true, "schema_version": 3, "solution": false}}

L'accès par indice permet aussi de **modifier** le tableau. Par exemple :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ef7bd5ef2d43c7e6ac8db0b357394ef9
  grade: false
  grade_id: cell-1844749dd1800a5a
  locked: true
  schema_version: 3
  solution: false
---
v = { 4, 1, 3, 2, 3 };
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 99dc98975da12796dcead06f6bbbc9b8
  grade: false
  grade_id: cell-cf88c740436f8a19
  locked: true
  schema_version: 3
  solution: false
---
v[1] = 3;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5815f7c40255f0d38499a472891610b8
  grade: false
  grade_id: cell-025de3fab22bfd96
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v // qu'est-ce qui a changé ?
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a1ecc5aa4e95758d002a836a9b0ca474", "grade": false, "grade_id": "cell-c0e002f4d47749ac", "locked": true, "schema_version": 3, "solution": false}}

**De la même façon, complétez le code ci-dessous pour que le test CHECK soit vérifié**.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 217fa1808e6a749ce6c2b7355266bd83
  grade: false
  grade_id: cell-a2fcc242365fb620
  locked: false
  schema_version: 3
  solution: true
---
v = { 4, 1, 3, 5, 3 };
CHECK(v.size() == 5 )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fc63f9da4a5c72e65d5c03d4f20683a3
  grade: true
  grade_id: cell-b970b03c018063b4
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( v == vector<int>({4,1,3,5,3} ) )
```
