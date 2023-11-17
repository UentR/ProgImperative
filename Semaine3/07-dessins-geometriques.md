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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d67b3fe66a50266546f596fd72feed17", "grade": false, "grade_id": "cell-b31ba63729e95016", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : dessins géométriques ♣

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "093677f1bf2b291e803030f55d12f488", "grade": false, "grade_id": "cell-8e4fbe3af67bde53", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice :**

Dans cet exercice, nous utiliserons des affichages et aurons donc
besoin de la bibliothèque C++ correspondante :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 879d06094a1ea8eac50797cbb7bcfb18
  grade: false
  grade_id: cell-81a99c8f399b859d
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iostream>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "84421899ac11834f37fb37969794f554", "grade": false, "grade_id": "cell-352f77c979379bf6", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Écrivez une fonction `carre_plein` qui, pour un entier positif non
    nul $L$ donné, affiche sur la sortie standard un carré plein dont
    les côtés sont de longueur $L$ caractères. Par exemple, pour
    $L=5$, la fonction affichera :

        *****
        *****
        *****
        *****
        *****

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 99e6cda7e6f72a5c46084e575ba5a345
  grade: false
  grade_id: cell-aa60e6ba0f4ca604
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void carre_plein(int L) {
    for (int j=0; j<L; j++) {
        for (int i=0; i<L; i++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}
```

```{code-cell}
carre_plein(5)
```

```{code-cell}
carre_plein(3)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ce5c82ce71516683e258d150a43b5b65", "grade": false, "grade_id": "cell-38495cd34c8d0e2c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Même question mais cette fois la fonction affiche un carré vide.
    Pour l’exemple précédent, cela donne :

        *****
        *   *
        *   *
        *   *
        *****

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 9f42f7441c85a7005c8d70fad4d0512b
  grade: false
  grade_id: cell-e7cca0ee7af7856b
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void carre_vide(int L) {
    if (L==1) { cout<<"*"; return; }
    for (int j=0; j<L; j++) { cout<<"*"; }
    for (int j=2; j<L; j++) {
        cout<<"\n*";
        for (int i=2; i<L; i++) { cout<<" "; }
        cout<<"*";
    }
    cout<<"\n";
    for (int j=0; j<L; j++) { cout<<"*"; }
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: d0ae0b284bd0f707249ea4b621b76689
  grade: false
  grade_id: cell-5a8c9d90a10cbccf
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

```{code-cell}
carre_vide(5)
```

```{code-cell}
carre_vide(2)
```

```{code-cell}
carre_vide(1)
```

```{code-cell}
carre_vide(0)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b860d2a2ffa967856105357fc1717b43", "grade": false, "grade_id": "cell-21ee6e6db6c72122", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Transformez votre fonction pour qu’il soit simple de remplacer le
    caractère `*` par un autre caractère `caractere` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 9785d6c59bb0e3c587ce4c64dd0cd811
  grade: false
  grade_id: cell-432dd624ee8d341f
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void carre_vide(int L, string caractere) {
    if (L==1) { cout<<caractere; return;}
    for (int j=0; j<L; j++) { cout<<caractere; }
    for (int j=2; j<L; j++) {
        cout<<"\n"<<caractere;
        for (int i=2; i<L; i++) { cout<<" "; }
        cout<<caractere;
    }
    cout<<"\n";
    for (int j=0; j<L; j++) { cout<<caractere; }
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1e8cff66a3213f01ceb328429a03fff7
  grade: false
  grade_id: cell-fd7d28c3addf4b85
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre_vide(4, "#")
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "61699d3c21a35a1fba9aaff0d05eb057", "grade": false, "grade_id": "cell-d2be9b92b87f6618", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Écrivez une fonction qui, pour un entier positif $h$ donné, affiche
    le triangle isocèle  pointe en haut  dont le contour est décrit par
    des étoiles, de hauteur $h$ et de base $2h-1$. Par exemple, pour
    $h=5$, la fonction affichera :
    ```
            *
           * *
          *   *
         *     *
        *********
    ```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 0c716539c05f99f6ac91a684a2c9e87f
  grade: false
  grade_id: cell-ed285270a4f27c05
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void triangle(int h, string caractere="*") {
    if (h<1) {return;}
    for (int i=1; i<h; i++) { cout<<" "; }
    cout<<caractere;
    if (h==1) { return; }
    for (int j=0; j<h-2; j++) {
        cout<<"\n";
        for (int i=0; i<h-j-2; i++) { cout<<" "; }
        cout<<caractere;
        for (int i=0; i<2*j+1; i++) { cout<<" "; }
        cout<<caractere;
    }
    cout<<"\n";
    for (int j=0; j<2*h-1; j++) { cout<<caractere; }
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 95fe590e1a8105ac9ce56d95bb9d6256
  grade: false
  grade_id: cell-9f1f87379aa3a076
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "49a9e89c486bed11a20b41bee17564ae", "grade": false, "grade_id": "cell-c684cbb420e12f44", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Vous noterez ci-dessous que l'on a donné une valeur par défaut pour
`caractere` : `*`. Du coup, on peut utiliser les deux formes
suivantes :

```{code-cell}
triangle(4)
```

```{code-cell}
triangle(5, "#")
```

```{code-cell}
triangle(2)
```

```{code-cell}
triangle(1)
```

```{code-cell}
triangle(0)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5e856464f584d9ff6a7d5ffa674dff56", "grade": false, "grade_id": "cell-21a24a581169dd5f", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Écrivez une fonction qui affiche un losange. Par exemple, pour
    $h=5$, la fonction affichera :

            *
           * *
          *   *
         *     *
        *       *
         *     *
          *   *
           * *
            *

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 74922a10914d8d74ff32ceca89462301
  grade: false
  grade_id: cell-b40856987b98d13d
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void losange(int h, string caractere="*") {
    // REMPLACER CETTE LIGNE ET LA SUIVANTE PAR VOTRE RÉPONSE
    throw std::runtime_error("À faire");
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: b324897a9dd32884fe5392a6abc5aa4a
  grade: false
  grade_id: cell-91a47942d015cc05
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

```{code-cell}
losange(5)
```

```{code-cell}
losange(1)
```

```{code-cell}
losange(0)
```
