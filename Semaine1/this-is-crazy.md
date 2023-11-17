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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3ec5c74d7827a86b9563e8ea4942ea3c", "grade": false, "grade_id": "cell-05f3f0bf76964094", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Laby: C'est fou!

Les obstacles se multiplient pour un défi de plus.

:::{admonition} Indication
:class: dropdown hint

Les toiles d'arraignées peuvent être neutralisées avec des cailloux

:::

[Niveau précédent](counting-the-rocks.md), <!--[Liste des niveaux](index.md#ListeDesNiveaux), !-->[Documentation](0b.md#Documentation)

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: bc35b69bd1a771b374ded8ac10994819
  grade: false
  grade_id: cell-2d8f822c47ec883b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY("this-is-crazy")
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 5175ca859f4bf6fabf94895343e7fbf4
  grade: false
  grade_id: cell-6f9c72052cad1db5
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void back_rock() {
    gauche();
    gauche();
    pose();
    droite();
    droite();
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 1bef98b8da2b78e6f16ebf6fefabc274
  grade: false
  grade_id: cell-6f9c72052cad1db6
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void AVANCE() {
    while (regarde() == Vide) { avance(); }
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: bed78d165b165fafc71f6ac63bc707ea
  grade: false
  grade_id: cell-6f9c72052cad1db7
  locked: false
  schema_version: 3
  solution: true
  task: false
---
debut();
AVANCE();
gauche();
avance();
if (regarde() != Caillou) {
    droite();
    droite();
    avance();
    gauche();
    AVANCE();
    gauche();
    avance();
}
prend();
droite();
droite();
avance();
gauche();
AVANCE(); // Devant la toile 1
pose();
prend();
gauche();
pose();
droite();
AVANCE();
gauche();
AVANCE();
prend();
AVANCE();
gauche(); // Devant la toile 2
pose();
prend();
gauche();
pose();
droite();
AVANCE();
prend();
AVANCE(); // Devant la toile 3
pose();
prend();
AVANCE();
pose();  // Devant la toile 4
prend();
back_rock();
AVANCE();
prend();
back_rock();
AVANCE();
droite();
AVANCE();
droite();
prend();
AVANCE();
pose();  // Devant la toile 5
prend();
back_rock();
AVANCE();
prend();
AVANCE();
pose(); // Devant la toile 6
prend();
AVANCE();
pose(); // Devant la toile 7
prend();
AVANCE();
gauche();
AVANCE();
gauche();
AVANCE();
pose(); // Devant la toile 8
prend();
AVANCE();
pose(); // Devant la toile 9
prend();
AVANCE();
pose(); // Devant la toile 10
prend();
back_rock();
AVANCE();
prend();
AVANCE();
pose(); // Devant la toile 11
prend();
back_rock();
AVANCE();
ouvre();
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2aa4d527a9e6c06216df456944bea12a
  grade: false
  grade_id: cell-6f9c72052cad1db8
  locked: false
  schema_version: 3
  solution: true
  task: false
---

```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ead977fe439dad8ae3c816a967e3564d
  grade: true
  grade_id: cell-5d7826a54cfe3158
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_gagne() );
```

```{code-cell}

```
