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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0002ad389d04f5ad842a48ed07d7a82a", "grade": false, "grade_id": "cell-53166fdd3d08082a", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "slide"}}

# Cours et exercices: les instructions conditionnelles enchaînées

Lors des séances précédentes, nous avons manipulé des conditionnelles simples,
permettant de distinguer entre deux cas à traiter avec des actions différentes.

```python
    if ( condition ) {
        bloc d instructions 1;   // Instructions dans le premier cas
    } else {
        bloc d instructions 2;   // Instructions dans le deuxième cas
    }
```

Comment faire lorsqu'il y a plus de deux cas à traiter? Nous allons voir
qu'il n'y a pas besoin de nouvelle instruction; il suffit d'**enchaîner
les instructions conditionnelles**.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "97bfcabf09c68343e6aa48a6aee59cc6", "grade": false, "grade_id": "cell-eb41e6cbf60996cc", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "slide"}}

**Exercice :**

- Observez le programme suivant, sans l'exécuter, que fait-il?
- Vérifiez votre intuition en l'exécutant avec plusieurs valeurs de `note`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5059b097294985842591c91656de6b5f
  grade: false
  grade_id: cell-d23302d998d62a57
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
---
int note;
std::string resultat;
```

```{code-cell}
---
slideshow:
  slide_type: null
---
note = 10;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7c1e074b1affe26ce7ef9e15e7dcd325
  grade: false
  grade_id: cell-54742e5fe0249163
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
---
if ( note < 0  or note > 20 ) {
    resultat = "La note n'est pas correcte.";
} else {
    if ( note < 10 ) {
        resultat = "Vous avez raté l'examen!";
    } else {
        resultat = "Vous avez réussi l'examen!";
    }
}

resultat
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2ad790c5220904955fd174dc82966356", "grade": false, "grade_id": "cell-0974f56385050e4f", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "fragment"}}

Comment est-ce que cela marche?

Pour gérer trois cas, nous avons
simplement distingué entre deux cas (note incorrecte ou correcte),
puis distingué ce deuxième cas en deux (examen raté ou réussi).

Comparez maintenant le programme ci-dessus avec le programme ci-dessous:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 30293eff0a3002b3c712aa7c46bcad9c
  grade: false
  grade_id: cell-54742e5fe0249162
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
if ( note < 0  or note > 20 ) {
    resultat = "La note n'est pas correcte.";
} else if ( note < 10 ) {
    resultat = "Vous avez raté l'examen!";
} else {
    resultat = "Vous avez réussi l'examen!";
}

resultat
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b0b172a6da07941d74110bb8013620b3", "grade": false, "grade_id": "cell-c9a382b563911444", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "fragment"}}

La seule chose qui a changé, c'est une paire d'accolades en moins (laquelle?),
ainsi que l'**indentation** (les espaces en début de ligne). Les deux programmes
sont en fait équivalents (vérifiez le!) car:
- le deuxième `if` forme une seule instruction;
- les accolades ne sont pas requises en C++ lorsqu'un bloc est formé d'une seule instruction.

Cependant le deuxième programme est plus lisible, et **exprime une intention différente**:
il y a trois cas, tous sur le même plan, et non deux cas dont le deuxième avec sous-cas.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5d4f5bf1237e41bdbb4e90a2b0369063", "grade": false, "grade_id": "cell-82cd1e741648a440", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "slide"}}

## À vous de jouer 
Recopiez le programme précédent ci-dessous en l'adaptant pour qu'il affiche en plus la mention (de 12 à 14, mention *assez bien*, de 14 à 16 mention *bien* et au dessus de 16, mention *très bien*):

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 97484f60c2115e54038f9505cd043946
  grade: true
  grade_id: cell-54742e5fe0249161
  locked: false
  points: 2
  schema_version: 3
  solution: true
  task: false
slideshow:
  slide_type: fragment
---
if ( note < 0  or note > 20 ) {
    resultat = "La note n'est pas correcte.";
} else if ( note < 10 ) {
    resultat = "Vous avez raté l'examen!";
} else if (note < 12) {
    resultat = "Vous avez réussi l'examen!";
} else if (note < 14) {
    resultat = "Vous avez réussi l'examen mention assez bien!";
} else if (note < 16) {
    resultat = "Vous avez résussi l'examen mention bien!";
} else {
    resultat = "Vous avez réussi l'examen mention très bien!";
}

resultat
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f3dc3ce9fa75b8d3d13d18403175e18b", "grade": false, "grade_id": "cell-4619918197722582", "locked": true, "schema_version": 3, "solution": false, "task": false}, "slideshow": {"slide_type": "skip"}}

## Bilan

Bravo, vous maîtrisez maintenant les instructions conditionnelles avec cas multiples.

<!--
Vous pouvez passer à la feuille [conditionnelles: bonnes pratiques et erreurs classiques](cours-conditionnelles-erreurs-classiques.md).
!-->
