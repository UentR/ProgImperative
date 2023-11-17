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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "11bc746bb3f36668d563917b04467610", "grade": false, "grade_id": "cell-b78562ee2ff6d72c", "locked": true, "schema_version": 3, "solution": false}}

# TP : valeurs, types et variables

## Introduction à Jupyter et premiers calculs

Lors de ces premières semaines de cours, nous allons travailler dans
l'application web *Jupyter* qui permet d'exécuter du code `C++`
interactivement, un peu comme une super calculatrice. Plus tard, nous
verrons comment créer un programme `C++` indépendant en dehors de
*Jupyter*.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "31783578f8bde28209b21d60b4afa8df", "grade": false, "grade_id": "cell-33660fa4ef5903e4", "locked": true, "schema_version": 3, "solution": false}}

**Exercice 1 : premiers calculs**

- Cliquez sur la cellule suivante puis exécutez la en appuyant sur les
  touches <kbd>Maj</kbd>+<kbd>Entrée</kbd> :

```{code-cell}
1 + 2
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a641bd5ef111d5f779f4d06209dffffb", "grade": false, "grade_id": "cell-291a3535b726abef", "locked": true, "schema_version": 3, "solution": false}}

La première ligne donne le résultat du calcul. La deuxième ligne
indique que ce résultat est de type *entier* (`int`).

Techniquement parlant, le navigateur web a envoyé le contenu `1+1` de
la cellule à un *noyau* (kernel en anglais) qui l'a *compilé* et
*exécuté*, avant de renvoyer le résultat à afficher. Le noyau que nous
utilisons (`C++17`) permet de travailler en `C++`. Il existe des
noyaux pour beaucoup d'autres langages de programmation.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "23ac875d5810411efd84b5b11ec27071", "grade": false, "grade_id": "cell-c7495bbedb1de8c7", "locked": true, "schema_version": 3, "solution": false}}

- Modifiez l'expression dans la cellule précédente et exécutez la de
  nouveau.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d687d8f5e69fce473a4c069310d311e9", "grade": false, "grade_id": "cell-12b1679926b1768d", "locked": true, "schema_version": 3, "solution": false}}

- Utilisez la cellule suivante pour calculer la surface d'un rectangle
  de largeur 25 et de longueur 37 :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 6c2954c10ebb31553b07a0019812862e
  grade: false
  grade_id: cell-b645bc465bd310ae
  locked: false
  schema_version: 3
  solution: true
ordo_failure: "R\xE9ponse incorrecte; essayes encore!"
ordo_solution:
  text/plain: '925

    type: int'
ordo_success: "Bonne r\xE9ponse!"
---
25*37
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d8e8920ea94e7d6c8db86d6b29e849fe", "grade": false, "grade_id": "cell-1b42d53da30ded82", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice 2 : types**

Vous avez vu en cours qu'il existe plusieurs types de variables
(`int`, `double`, etc.). Il est très utile de connaître le type des
valeurs que l'on manipule. Exécutez les cellules suivantes et observez
les types obtenus :

```{code-cell}
3*4
```

```{code-cell}
3*4.0
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f91a40fc1958f4b6f1e0681d8df77441", "grade": false, "grade_id": "cell-7c72028bf998c9e5", "locked": true, "schema_version": 3, "solution": false}}

Les lignes suivantes vous présentent des exemples de
calculs. Exécutez-les en observant bien la valeur du résultat et son
type.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 593fcfb7063e8d55389842ed36c10a03
  grade: false
  grade_id: cell-678ae0462813d831
  locked: true
  schema_version: 3
  solution: false
  task: false
---
3*(1+3) + (1+4)*(2+4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9f3cc6c0e458e40336da192b6f55aa16
  grade: false
  grade_id: cell-8c8f01689a82794b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
42 / 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: babcd64046ca10ca7696da6a16825c30
  grade: false
  grade_id: cell-9678ffe15c270b81
  locked: true
  schema_version: 3
  solution: false
  task: false
---
42 / 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a1b61504a42f653f72eeb746b99dd23f
  grade: false
  grade_id: cell-15172444994cbdff
  locked: true
  schema_version: 3
  solution: false
  task: false
---
42. / 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7f94e7cc2a78f5f84d00835ab6e3c7fc
  grade: false
  grade_id: cell-7009aedea5b1e925
  locked: true
  schema_version: 3
  solution: false
  task: false
---
42 % 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 73faf81ec97e7a196d35eb58d0016ed1
  grade: false
  grade_id: cell-7c66e2817d57b95c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 + 1.
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: eb7d7730da271c2d1e497aa89c9ad470
  grade: false
  grade_id: cell-33bc66dde9266641
  locked: true
  schema_version: 3
  solution: false
  task: false
---
42 == 6*7
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 88c54f98c8270c287d5ff9cf434e1f2a
  grade: false
  grade_id: cell-3163364eab44d8d7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
41 == 2*21
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b03fd9ec2be270091121833ce867f1cc", "grade": false, "grade_id": "cell-cf97d7e3ffc985a0", "locked": true, "schema_version": 3, "solution": false}}

Remarque: dans les deux cellules précédentes, nous avons utilisé un
**double égal** `==` qui sert à **tester** l'égalité entre deux
valeurs. Nous reverrons bientôt la signification du **simple égal**
`=`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: dbabeaac7e3f9d86ef9a32e951cd5df1
  grade: false
  grade_id: cell-d4b738450011dd37
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 < 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0a8e6b094ad756a7c0ffa364fcc7ee15
  grade: false
  grade_id: cell-3e5e3a25f145a973
  locked: true
  schema_version: 3
  solution: false
  task: false
---
2 > 3
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cb08d8a9c4574e2b2adad48f3464fad8
  grade: false
  grade_id: cell-606159825dc54bf9
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 < 2 and 2 > 3
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 697a998ec2daa1290313a8fc7797575d
  grade: false
  grade_id: cell-783a55b0abd2377f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 < 2 or 2 > 3
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "af204e753d48317334d009d9df551827", "grade": false, "grade_id": "cell-05caf97c8306b9b4", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Note: pour éviter de fausses manœuvres, nous configurons de nombreuses
cellules, telles celles ci-dessus, pour qu'elles soient non
modifiables. Pour faire vos propres expérimentations ou pour prendre
des notes personnelles, vous pouvez à tout moment insérer de nouvelles
cellules. Insérez maintenant une cellule ci-dessous en utilisant le
bouton `+` sous les onglets. Dans la barre d'outil de cette feuille,
sélectionnez `Markdown` à la place de `Code` pour en faire une cellule
de texte.

```{code-cell}

```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f111bfd79786faaa5d38dc0f13967c66", "grade": false, "grade_id": "cell-884721498ad284a1", "locked": true, "schema_version": 3, "solution": false}}

**Exercice 3 :**

Pour chacune des expressions suivantes, déterminez **de tête** le type
et la valeur du résultat, et donnez votre réponse à l'endroit indiqué
sous la forme `type`, `valeur`; puis vérifiez en exécutant les
cellules.

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2c2010fc398715fd883ec87dbcf20298", "grade": true, "grade_id": "cell-a8d152d15809265f", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, ou double ?
 * Valeur : 7, 9, 11, ou 21 ?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a72897335f295c7d452b11e914f2fc49
  grade: false
  grade_id: cell-0f3ff9e9e4c33f41
  locked: true
  schema_version: 3
  solution: false
---
3 * 2 + 5
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dfe5e7372570d9dea7fd0e5805abc6c1", "grade": true, "grade_id": "cell-b866905e681f44cb", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, ou double ?
 * Valeur : 12 ou 12.5 ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 962d88d6809f73496c72662e2f1a341d
  grade: false
  grade_id: cell-127febc577edfc08
  locked: true
  schema_version: 3
  solution: false
---
25 / 2
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6c2e63ea6633366117382f5c3f127e60", "grade": true, "grade_id": "cell-899fabbcd7ecd371", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, ou double ?
 * Valeur : 6, 7, 6.0000, ou 7.0000?

 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: dfc73c6565beb9718da57a04d56a539a
  grade: false
  grade_id: cell-286c54ae7e34701d
  locked: true
  schema_version: 3
  solution: false
---
3.5*2
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "71eee2fa3fea6fb3788badde6e41dfc0", "grade": true, "grade_id": "cell-fe0c64ef514d2b0f", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type: int, bool, ou double ?
 * Valeur : 5, 4, ou 4.66667 ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 20a02b357e2b564128c22de02d6bafff
  grade: false
  grade_id: cell-b52c330c011b1b89
  locked: true
  schema_version: 3
  solution: false
  task: false
---
14. / 3
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "26ca09cd9707728cdd34ca521aed3382", "grade": true, "grade_id": "cell-b1b2d0d4b7baa06e", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, ou double ?
 * Valeur : 3,7,21, true, ou false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5d1d2f1a6a8c2051575b59fe5305d7ab
  grade: false
  grade_id: cell-67ced375854c7fb3
  locked: true
  schema_version: 3
  solution: false
  task: false
---
3*7 == 21
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ff1acd99636db830d19c4999334bfe63", "grade": true, "grade_id": "cell-59ff90739ae5b7b2", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, double ?
 * Valeur : 21, 25, true, false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1ed41b3835b89e6fcbc70955741fe280
  grade: false
  grade_id: cell-959d3023456a140e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
(3*7 == 21) and (4.2 > 5.3 or 4*4 == 8*2)
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "334e68aa2b0ee056926c9e5d3f54bf12", "grade": true, "grade_id": "cell-2bf659cbac5d597a", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

 ---
 * Type : int, bool, double ?
 * Valeur : 1, 0, true, false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: abfc8ff20663be8e6949ec8c6c06ce55
  grade: false
  grade_id: cell-f47f3ad36d564ee3
  locked: true
  schema_version: 3
  solution: false
  task: false
---
true and false
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4ca4d1bcbd35f830508935fdcf0b1e2a", "grade": true, "grade_id": "cell-e5856c338c095691", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

---
 * Type : int, bool, double ?
 * Valeur : 1, 0, true, false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 84b49eb8f761d684f8e79173e910b814
  grade: false
  grade_id: cell-e0555c4a9b71b38e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
true or false
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ced8c634c6cc49e5a69c156df6e90a91", "grade": true, "grade_id": "cell-89f6e927581416a9", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

---
 * Type : int, bool, double ?
 * Valeur : 1, 0, true, false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ab4121e4a092cce93227b3fe2b6c7ca1
  grade: false
  grade_id: cell-b578732ac62c6681
  locked: true
  schema_version: 3
  solution: false
  task: false
---
(false and false) or true
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d0147601a4bf7a09551fff8080059637", "grade": true, "grade_id": "cell-447af0863372964d", "locked": false, "points": 2, "schema_version": 3, "solution": true}}

---
 * Type : int, bool, double ?
 * Valeur : 1, 0, true, false ?
 
 % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cb2b8d971ecd3f9ac908ced0e3a2f28b
  grade: false
  grade_id: cell-64d5df8a0de7fed9
  locked: true
  schema_version: 3
  solution: false
  task: false
---
false and (false or true)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b13d62422ced658b42da7508a80bcb1a", "grade": false, "grade_id": "cell-6e834cd22ecc144b", "locked": true, "schema_version": 3, "solution": false}}

Bravo, vous avez terminé cette première feuille où vous avez exploré
les expressions, valeurs, types en C++. Dans la feuille suivante, vous
aborderez les variables.

Vous pouvez maintenant fermer cette feuille; utilisez pour cela le
raccourci clavier <kbd>Ctrl</kbd>+<kbd>Maj</kbd>+<kbd>Q</kbd>.

```{code-cell}

```
