---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3d00450cf0a6aa5f424c294ba17d5fb6", "grade": false, "grade_id": "cell-b31ba63729e95016", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : boucles imbriquées

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "97dd196a059c888ce7421b2de1f25564", "grade": false, "grade_id": "cell-8e4fbe3af67bde53", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice :**

Dans cet exercice, nous utiliserons les boucles imbriquées pour dessiner en laby.
On veut dessiner ligne par ligne avec la fourmi et l'instruction `seme()`.
Commencez par exécuter les cellules ci-dessous pour comprendre ce que fait
l'instruction `seme()`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 6ca4523676231f5043bd7963ed5270f7
  grade: false
  grade_id: cell-b0d580c556865d98
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iostream>
#include <cstdlib>
using namespace std;
#include <laby/global_fr.hpp>
#include "laby_check.hpp"
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5a3e6a5bd1852a5c793afd1349c9971d
  grade: false
  grade_id: cell-b0d580c556865d96
  locked: true
  schema_version: 3
  solution: false
  task: false
---
debut();
avance();
avance();
seme();
avance();
avance();
seme();
seme();
seme();
avance();
avance();
seme();
avance();
seme();
avance();
seme();
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c6ec8a8b1f1a5aceddabbcb2477eb818", "grade": false, "grade_id": "cell-8e4fbe3af67bde54", "locked": true, "schema_version": 3, "solution": false, "task": false}}

On vous donne la fonction `avance_tant_que_tu_peux` vue dans les premiers TPs.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3aa1301c22feee0e33a895d03e16ac4b
  grade: false
  grade_id: cell-81a99c8f399b859e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/**Fait avancer la fourmi tant qu'elle a un espace vide devant elle.**/
void avance_tant_que_tu_peux() {
    while ( regarde() == Vide or regarde() == PetitCaillou ) {
        avance();
    }
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "40bc47d35cd3070711193a158f4f853d", "grade": false, "grade_id": "cell-fd0933aaa600036b", "locked": true, "schema_version": 3, "solution": false, "task": false}}

1.  Écrivez une fonction `carre(int L)` qui prend en paramètre un entier L,
    et qui fait dessiner à la fourmi un carré plein avec côtés de longueur L.
    Par exemple, pour $L=5$, la fourmi dessinera :

        *****
        *****
        *****
        *****
        *****

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 67616729600b99f3d2914836bb54b4be
  grade: false
  grade_id: cell-b0d580c556865d9A
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 7427c954e4bf5589e7e8c1b7cfdd06d1
  grade: false
  grade_id: cell-bf212efeb0472746
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// Entrée : un entier L, correspondant à la longueur d'un côté de la trajectoire.
// Sortie : aucune, déplace la fourmi selon un carré de longueur L
void carre(int L) {
    debut();
    for (int j=0; j<L; j++) {
        for (int i=0; i<L-1; i++) {
            seme();
            avance();
        }
        seme();
        if (j%2) {
            gauche();
            avance();
            gauche();
        } else {
            droite();
            avance();
            droite();
        }
    }
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 790c74491a9f86127655787f4a78934b
  grade: false
  grade_id: cell-b7280173f444a974
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre(0) // La fourmi ne fait rien
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 962f5e80910cf020042ab2e32508ff9d
  grade: false
  grade_id: cell-61f6cbe5090c44f8
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre(1) // La fourmi doit tourner et dessiner sur elle-même.
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d6c2801c5d982ae88b23a6b862c3b218
  grade: false
  grade_id: cell-cd855fcd1a51f005
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre(5) // Dessin d'un carré plein avec côtés de longueur 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0f6b0ce28a1b736a884038e699ff2290
  grade: true
  grade_id: cell-3db90e21fd69b2fc
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_obtenu(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o o o o o o o o o o o o\n") )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ea88a4c21dc1657e357ec147df2df411", "grade": false, "grade_id": "cell-fd0933aaa600036c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

2. Même question mais cette fois la fonction `carre_vide(int L)`
   affiche un carré vide. Pour l’exemple précédent, la fourmi
   dessinera :

        *****
        *   *
        *   *
        *   *
        *****

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b0949b406fc96af23521ad8ac5713e16
  grade: false
  grade_id: cell-b0d580c556865d99
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 68bd8549e0197353beaf612ff96f2cd0
  grade: false
  grade_id: cell-bf212efeb0472747
  locked: false
  schema_version: 3
  solution: true
  task: false
---
// Entrée : un entier L, correspondant à la longueur d'un côté de la trajectoire.
// Sortie : aucune, déplace la fourmi selon un carré de longueur L
void carre_vide(int L) {
    debut();
    for (int i=0; i<L-1; i++) {
        seme();
        avance();
    }
    seme();
    droite();
    avance();
    for (int i=2; i<L; i++) {
        seme();
        avance();
    }
    seme();
    droite();
    avance();
    for (int i=2; i<L; i++) {
        seme();
        avance();
    }
    seme();
    droite();
    avance();
    for (int i=2; i<L; i++) {
        seme();
        avance();
    }
    droite();
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0bf3d74a71340c8363f55644f8633a1e
  grade: false
  grade_id: cell-b7280173f444a975
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre_vide(0) // La fourmi ne fait rien
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: aab30c2f950f2b796bd72e8543711c47
  grade: false
  grade_id: cell-61f6cbe5090c44f7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre_vide(1) // La fourmi doit tourner et dessiner sur elle-même.
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f901988a796628455365e70062f5facb
  grade: false
  grade_id: cell-cd855fcd1a51f006
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carre_vide(5) // Dessin d'un carré vide avec côtés de longueur 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 612306d5fded79d15c5f1228e99df379
  grade: true
  grade_id: cell-6f634cb11eedd8ea
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_obtenu(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ . . . ŕ . . . . . o\n"
u8"o ŕ . . . ŕ . . . . . o\n"
u8"o ŕ . . . ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o o o o o o o o o o o o\n") )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2b2986b15d9f60f722fb91a2ecc47de4", "grade": false, "grade_id": "cell-d2be9b92b87f6618", "locked": true, "schema_version": 3, "solution": false, "task": false}}

3.  Écrire une fonction `triangle_rect(int h)` qui, pour un entier
    positif $h$ donné, affiche le triangle rectangle plein avec côtés
    de longueur $h$. Par exemple, pour $h=5$, la fourmi dessinera :
    ```
        *
        **
        ***
        ****
        *****
    ```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 78c47945c84070809371bca38ff53a45
  grade: false
  grade_id: cell-b0d580c556865d97
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: de689caa5235783733a0df679ff30049
  grade: false
  grade_id: cell-ed285270a4f27c05
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void triangle_rect(int h) {
    debut();
    for (int x=0; x<h; x++) {
        for (int y=x; y<h; y++) {
            seme();
            avance();
        }
        if (!(x%2)) {
            droite();
            avance();
            droite();
            avance();
            avance();
        } else {
            gauche();
            avance();
            gauche();
        }
    }
    
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3c6d143ab0259cb8194d4e5dc2ead50d
  grade: false
  grade_id: cell-5c4d732d3a1123ee
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_rect(4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 656404d69dfb03c7b999175c93a7da31
  grade: false
  grade_id: cell-8e7b499c66fffb3b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_rect(2)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 62f1178ec8e81c3b2349e57352605152
  grade: false
  grade_id: cell-bf57f437151efdb7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_rect(0)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 05cebef706ed31af65f1de882219f703
  grade: false
  grade_id: cell-a6894e216af096f8
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_rect(8)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 145dad8dd6a2accb217c673ce7994efa
  grade: true
  grade_id: cell-33a95fb6009889b8
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_obtenu(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ŕ . . . . . . . . . o\n"
u8"o ŕ ŕ . . . . . . . . o\n"
u8"o ŕ ŕ ŕ . . . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ . . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ . . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ ŕ . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ ŕ ŕ . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ ŕ ŕ ŕ . . o\n"
u8"o o o o o o o o o o o o\n") )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e049ec9e8b2ac24216e686457f847716", "grade": false, "grade_id": "cell-d2be9b92b87f6619", "locked": true, "schema_version": 3, "solution": false, "task": false}}

4.  ♣ Écrire une fonction `triangle_iso(int h)` qui, pour un entier
    positif $h$ donné, affiche le triangle isocèle pointe en haut,
    de hauteur $h$ et de base $2 h - 1$. Par exemple, pour $h = 5$,
    la fourmi dessinera :
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
editable: false
nbgrader:
  cell_type: code
  checksum: a925773535b684f1f0536fa900e9bf55
  grade: false
  grade_id: cell-b0d580c556865d95
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 04b40cfcf981d3d4bf7c4d706e230119
  grade: false
  grade_id: cell-ed285270a4f27c06
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void triangle_iso(int h) {
    debut();
    droite();
    for (int y=0; y<2*h-1; y++) {
        seme();
        avance();
    }
    gauche();
    avance();
    gauche();
    avance();
    avance();
    for (int y=1; y<2*h-3; y++) {
        for (int x=y; x<2*h-1; x++) {
            if (x==y || x == (2*y-x)) {
                seme();
            }
            avance();
        }
        if ((y%2)) {
            droite();
            avance();
            droite();
            avance();
        } else {
            gauche();
            avance();
            gauche();
            avance();
        }
    }
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ec4d70d3efdde9ced516e282a9640e41
  grade: false
  grade_id: cell-be34b3115e72630b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_iso(3)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2af47fd8aed0cffa277e8ec727dd0c60
  grade: false
  grade_id: cell-54c116a5733d20dc
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_iso(1)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e94f76ed3aefca9b0244d9e14cbbc6a3
  grade: false
  grade_id: cell-8253182c44da7f88
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_iso(0)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f7996d70ea81def96b31077dae02903b
  grade: false
  grade_id: cell-138626276cc765e2
  locked: true
  schema_version: 3
  solution: false
  task: false
---
triangle_iso(4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a8763836933f8f214cd435a90e72d363
  grade: true
  grade_id: cell-660a57ec689ad5c8
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_obtenu(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . ŕ . . . . . . o\n"
u8"o . . ŕ . ŕ . . . . . o\n"
u8"o . ŕ . . . ŕ . . . . o\n"
u8"o ŕ ŕ ŕ ŕ ŕ ŕ ŕ . . . o\n"
u8"o o o o o o o o o o o o\n") )
```

```{code-cell}

```
