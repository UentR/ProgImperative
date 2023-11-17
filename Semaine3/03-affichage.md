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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1c7e2ea76ef0b7265cec2e66b881497f", "grade": false, "grade_id": "cell-5c4b0b2f0931e30a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : prélude : affichages

Comme dans le dernier amphi, nous aurons besoin dans ce TP d'afficher
des informations pour tracer pas à pas l'exécution d'un
programme. Nous vous donnons ici le minimum nécessaire pour cela. Nous
reviendrons dessus plus en détail ultérieurement.

L'affichage à l'écran est une des façons de communiquer entre le
programme et l'utilisateur. On a vu la semaine dernière que, lorsque
l'on exécute une cellule dans Jupyter, la valeur de la *dernière
expression* de la cellule est affichée, avec son type, le tout précédé
de `Out[...]` dans la marge :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a719a9a91d58c5950c493585043d77a7
  grade: false
  grade_id: cell-19cd93362f420a66
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1+2;
3+4;
5+6
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e7472843ea183da01250ad28f17ecbcb", "grade": false, "grade_id": "cell-367e4b99458161a3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Les autres calculs ont bien été effectués par la machine, mais sans
montrer les valeurs obtenues.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2dacf66691dc91d26bcecba001756035", "grade": false, "grade_id": "cell-367e4b99458161a4", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Nous allons maintenant voir comment afficher des informations. Tout
d'abord, nous avons besoin d'exécuter la ligne suivante qui charge la
bibliothèque `C++` d'*entrées / sorties* (nous reviendrons sur cette
notion en cours).

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 055187c3467d7a5f823ee14d3ec0b7be
  grade: false
  grade_id: cell-7625170582ccbac3
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iostream>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "68d0760a2cf2f5f28f70db66fbdbea33", "grade": false, "grade_id": "cell-c94dd426cd30fc59", "locked": true, "schema_version": 3, "solution": false, "task": false}}

La ligne suivante affiche le résultat du calcul, suivi d'un retour à
la ligne :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4b0fa1652ae6607442bf881e67e3018e
  grade: false
  grade_id: cell-026cd32f310cdcf6
  locked: true
  schema_version: 3
  solution: false
  task: false
---
cout << 1+2 << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7bd73f8b71b96c7f29d96b42387ba632", "grade": false, "grade_id": "cell-8213e311891544b5", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Remarquez que, cette fois, ni le *type* ni `Out[...]` n'apparaissent.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "30b1be1f2b5e447462b77d6c9be85843", "grade": false, "grade_id": "cell-8213e311891544b6", "locked": true, "schema_version": 3, "solution": false, "task": false}}

On peut afficher plusieurs valeurs à la suite :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d55fab22ee6473ae152b90e4f5d86480
  grade: false
  grade_id: cell-3c6a9159f8402f5e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
cout << 1+2 << endl;
cout << 3+4 << endl;
cout << 5+6 << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "eda5e649574587ff8f4b45f522fa77cd", "grade": false, "grade_id": "cell-b86b795dcc6ef7ba", "locked": true, "schema_version": 3, "solution": false, "task": false}}

On peut aussi afficher du texte (chaînes de caractères) en utilisant
les guillemets :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2aa11d0f9907b8c3cc60fc9586afa19c
  grade: false
  grade_id: cell-6758df96fcdc4ca4
  locked: true
  schema_version: 3
  solution: false
  task: false
---
cout << "Bonjour, comment allez-vous ?" << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "84cf7886c43cc57a1448a84b661e45c1", "grade": false, "grade_id": "cell-992882d71d4cf502", "locked": true, "schema_version": 3, "solution": false, "task": false}}

♣ On peut mélanger texte et valeurs comme ci-dessous :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 80013d2679d7b0311783fc6b6e5f2891
  grade: false
  grade_id: cell-68e9d8e21f072ecf
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int age;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: deec6aca39365c83a4be40c965836cbf
  grade: false
  grade_id: cell-5642d7e1a8103e36
  locked: true
  schema_version: 3
  solution: false
  task: false
---
age = 32;
cout << "J'ai " << age << " ans." << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6736c471bc21943b123d0e2d44a622f5", "grade": false, "grade_id": "cell-63ee395ef8395a98", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice ♣**

- Adaptez l'exemple précédent pour afficher votre âge :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 02da9518433bd69da747f40aceb62958
  grade: true
  grade_id: cell-9314857feab44e21
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
cout << "J'ai " << 18 << " ans." << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3ddfaa1e456e52d38b9bc66c8611c288", "grade": false, "grade_id": "cell-63ee395ef8395a99", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- **Utilisez la variable `annee` ci-dessous pour afficher "Je suis
  né(e) en ****" où les **** sont votre année de naissance :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8f8fbc109383a5de2f7196a151bb95db
  grade: false
  grade_id: cell-a83264f8ccc04d6b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int annee;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c02d3e528a6ace12be83ed6c8c4c59df
  grade: true
  grade_id: cell-c5e44d0cc9300b2c
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
annee = 2005;
cout << "Je suis né en " << annee << endl;
```

## Bilan

Dans cette feuille, nous avons aperçu le minimum requis pour afficher
des valeurs en C++. Comme dans le cours, cela servira dans la suite du
TP pour tracer les étapes intermédiaires dans l'exécution d'une
boucle.
