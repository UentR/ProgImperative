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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0a15ddb6db175b9077cc40cc1329f7dd", "grade": false, "grade_id": "cell-64acacb345e940e0", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Laby: Compter les cailloux
Ce niveau se résout facilement quand on peut compter… La boucle «for» est là pour vous !

[Niveau précédent](4b.md), <!--[Liste des niveaux](index.md#ListeDesNiveaux), !-->[Niveau suivant](this-is-crazy.md), [Documentation](0b.md#Documentation)

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 10d050a6ba96c43f9d67257dbfae88ca
  grade: false
  grade_id: cell-ee3432e66e9fe991
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY("counting-the-rocks")
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 73e4e8dd92f614b3b9e861393d196db0
  grade: false
  grade_id: cell-dc0eba466ac0f399
  locked: false
  schema_version: 3
  solution: true
  task: false
---
void enleve_caillou() {
    prend();
    avance();
    gauche();
    gauche();
    pose();
    droite();
    droite();
}
```

```{code-cell}
int go_for_it(int Nbr) {
    int count = 0;
    for (int i=0; i<Nbr; i++) {
        if (regarde() == Caillou) {
            count++;
            enleve_caillou();
        }
        else {
            avance();
        }
    }
    return count;
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c3a9b016a860f30abb2b7212dc0e99da
  grade: false
  grade_id: cell-dc0eba466ac0f400
  locked: false
  schema_version: 3
  solution: true
  task: false
---
debut();
int count = 0;
count += go_for_it(9);
if (regarde() == Caillou) {
    count++;
}
gauche();
gauche();
if (regarde() == Caillou) {
    enleve_caillou();
}
droite();
count += go_for_it(2);
gauche();
count += go_for_it(2);
droite();
count += go_for_it(5);
if (regarde() == Caillou) {
    count++;
}
gauche();
gauche();
if (regarde() == Caillou) {
    enleve_caillou();
}
gauche();
count += go_for_it(6);
gauche();
count += go_for_it(2);
//dit(count);
ouvre();
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 54b0a770261b037c31cd1ae3e9742d63
  grade: true
  grade_id: cell-f81330eca20c0208
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
