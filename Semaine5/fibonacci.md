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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b5edbf69e154afbfef2e05e9de25f541", "grade": false, "grade_id": "cell-b8ffd3e2724b20a4", "locked": true, "schema_version": 3, "solution": false}}

# TP : suite de Fibonacci
Dans cette feuille, vous allez implanter les trois algorithmes vus en TD pour calculer la suite de Fibonacci.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 6abc94e6f60d4b65559aa19ff9bea687
  grade: false
  grade_id: cell-23c28693bb24e284
  locked: true
  schema_version: 3
  solution: false
---
#include <iostream>
#include <vector>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9ef35b0294410cb38e1ac596178ac2bd", "grade": false, "grade_id": "cell-c1cf4d9dd7f36f7a", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 1 : Fibonacci, version tableau

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "116a7c11b4ffb1be62a837b89616a849", "grade": false, "grade_id": "cell-af9fdb729ae1af5e", "locked": true, "schema_version": 3, "solution": false}}

- Écrire la documentation puis implanter la fonction `fibonacciTableau`:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 1834a6d204d6946e472bf601c2201747
  grade: true
  grade_id: cell-fe5ec9160e7fe4ed
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
/** Renvoie le N-eme nombre de Fibonacci
 * @param Idx un int
 * @return le N-eme nombre de Fibonacci
 **/
```

```{code-cell}
using tableau = vector<int>;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: dd71de7beceee401407239599749eb13
  grade: false
  grade_id: cell-3e99d334583cf0cf
  locked: false
  schema_version: 3
  solution: true
---
int fibonacciTableau(int n) {
    vector<int> tab = {1, 1};
    for (int i = 1; i<n; i++) {
        tab.push_back(tab[i-1]+tab[i]);
    }
    return tab[n-1];
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dcd1bd0619b33082946d82eded78e986", "grade": false, "grade_id": "cell-3a5a77e9d38662a1", "locked": true, "schema_version": 3, "solution": false}}

- Vérifier que votre fonction passe les tests:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e2bab872eedc0eb8df1a699bb5d3e3ff
  grade: true
  grade_id: cell-de81c742ca06b1fe
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( fibonacciTableau(1) == 1 );
CHECK( fibonacciTableau(2) == 1 );
CHECK( fibonacciTableau(3) == 2 );
CHECK( fibonacciTableau(4) == 3 );
CHECK( fibonacciTableau(5) == 5 );
CHECK( fibonacciTableau(6) == 8 );
CHECK( fibonacciTableau(9) == 34 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "013ff844af2152e465a1e4f15cab2aa8", "grade": false, "grade_id": "cell-96df4c2d033a6499", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 2 : Fibonacci, version trois variables

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c8796c470ea2f913e51c1eb4d55c95b0", "grade": false, "grade_id": "cell-769dae242b7fe173", "locked": true, "schema_version": 3, "solution": false}}

- Écrire la documentation puis implanter la fonction `fibonacciVariables`:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 83f7e1802f970ecff74a9459382c357f
  grade: true
  grade_id: cell-e9a26741525a8c7f
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
/** Renvoie le N-eme nombre de Fibonacci
 * @param Idx un int
 * @return le N-eme nombre de Fibonacci
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 4795c4df7c1e88a86dbfd63d79275e99
  grade: false
  grade_id: cell-0293b05d6b32527e
  locked: false
  schema_version: 3
  solution: true
---
int fibonacciVariables(int n) {
    int Last = 1;
    int Current = 1;
    int Temp;
    for (int i = 2; i<n; i++) {
        Temp = Current;
        Current += Last;
        Last = Temp;
    }
    return Current;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0e0ec37b8dc48f1d3d232ee77d1f726e", "grade": false, "grade_id": "cell-a58a9782a8e07d88", "locked": true, "schema_version": 3, "solution": false}}

- Tests :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 680abd6defdbd6e020821494f65b5e35
  grade: true
  grade_id: cell-64a1a8cdcb6263c0
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( fibonacciVariables(1) == 1 );
CHECK( fibonacciVariables(2) == 1 );
CHECK( fibonacciVariables(3) == 2 );
CHECK( fibonacciVariables(4) == 3 );
CHECK( fibonacciVariables(5) == 5 );
CHECK( fibonacciVariables(6) == 8 );
CHECK( fibonacciVariables(9) == 34 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f00560578a1039ff9685c0341a70dc97", "grade": false, "grade_id": "cell-dca03131b57768e0", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 3 : Fibonacci, version récursive

- Écrire la documentation puis implanter la fonction `fibonacciRecursive`:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: b2eeaee5d66b9693c435ca3c7b26be38
  grade: true
  grade_id: cell-c6bdea95ffb619b8
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
/** Renvoie le N-eme nombre de Fibonacci
 * @param Idx un int
 * @return le N-eme nombre de Fibonacci
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 518b33ce5ca8bbc1a807361ece3b2622
  grade: false
  grade_id: cell-06ce675728db14a4
  locked: false
  schema_version: 3
  solution: true
---
int fibonacciRecursive(int n) {
    if (n<=2) { return 1; }
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "915ef8b631f036a710480b7efbdcf966", "grade": false, "grade_id": "cell-7433fd515737443c", "locked": true, "schema_version": 3, "solution": false}}

- Tests :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9f51a7caf0fd54250e8dea8b09aa6910
  grade: true
  grade_id: cell-f86b56741701c2a2
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( fibonacciRecursive(1) == 1 );
CHECK( fibonacciRecursive(2) == 1 );
CHECK( fibonacciRecursive(3) == 2 );
CHECK( fibonacciRecursive(4) == 3 );
CHECK( fibonacciRecursive(5) == 5 );
CHECK( fibonacciRecursive(6) == 8 );
CHECK( fibonacciRecursive(9) == 34 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0ef2d09428d0a67c4b807c318f8b16f3", "grade": false, "grade_id": "cell-c33cb1e5921e4f23", "locked": true, "schema_version": 3, "solution": false}}

# - ♣ Exécuter la version récursive avec une grande valeur pour n (par exemple 200).

```{code-cell}
fibonacciRecursive(200)
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fa8d3706adf9f82e253743869ff9bbbe", "grade": true, "grade_id": "cell-15aced9ad15bb5cd", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

- Que se passe-t-il?
  % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
- ♣ A votre avis, est-il possible de remédier à ce problème?
