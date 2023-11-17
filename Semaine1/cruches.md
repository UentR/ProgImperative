---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "30edab3c3b48b688a1fe7deb30ec6d2f", "grade": false, "grade_id": "cell-531faa6d137cc87a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Les cruches

Soient deux cruches de capacités respectives 5 et 7 litres. Ces
cruches ne sont pas graduées.  Vous avez accès à un robinet qui
vous permet de remplir à tout moment l'une ou l'autre des cruches:

    remplir(0)
    remplir(1)

De même, vous disposez d'une évacuation d'eau permettant de vider
l'une ou l'autre des cruches:

    vider(0)
    vider(1)
    
Enfin, vous pouvez transvaser le contenu de la première cruche
dans la seconde, et réciproquement:

    verser(0)
    verser(1)

Et c'est tout.

```{code-cell} ipython3
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2a0ad69dfc58b0a6c3172644adaacb03
  grade: false
  grade_id: cell-7d3ed103afb89c6c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
from ipywidgets_game_jugs.__global__.fr import *
CRUCHES(5, 7)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0bf332bdfc40a34fc025eb7b8c87d5b9", "grade": false, "grade_id": "cell-498cce0f0d44af99", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Écrire un programme de sorte que l'une ou l'autre des cruches contienne 4 litres
à la fin. Noter que, dans cette feuille, le programme doit être écrit en Python, mais
ici cela ne change pas grand chose.

```{code-cell} ipython3
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 41898fb056db165792fae267e0ee7eeb
  grade: false
  grade_id: cell-c2904c17dda5ff4d
  locked: false
  schema_version: 3
  solution: true
  task: false
---
vider(0)
vider(1)
# REMPLACER CETTE LIGNE ET LA SUIVANTE PAR VOTRE RÉPONSE
remplir(1)
verser(1)
vider(0)
verser(1)
remplir(1)
verser(1)
```

```{code-cell} ipython3
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 96e64d30164135c4e7f85c40d940fdf5
  grade: true
  grade_id: cell-fc05ad6c1f39ca29
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
assert valides()[4]
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "394bca589f2fe7337d679ff07c826fae", "grade": false, "grade_id": "cell-e74cb261b0883571", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Compléter le programme pour que tous les volumes entre 1 et 7
soient atteints:

```{code-cell} ipython3
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 6a3febe1c7eb1e49c1fe845e4d7cebc0
  grade: false
  grade_id: cell-5a9025cc96a5d3cc
  locked: false
  schema_version: 3
  solution: true
  task: false
---
vider(0)
vider(1)
remplir(1) # 0 && 7
verser(1)  # 5 && 2
vider(0)   # 0 && 2
verser(1)  # 2 && 0
remplir(1) # 2 && 7
verser(1)  # 5 && 4
vider(0)
vider(1)
remplir(0) # 5 && 0
verser(0)  # 0 && 5
remplir(0) # 5 && 5
verser(0)  # 3 && 7
vider(0)
vider(1)
remplir(1) # 0 && 7
verser(1)  # 5 && 2
vider(0)   # 0 && 2
verser(1)  # 2 && 0
remplir(1) # 2 && 7
verser(1)  # 5 && 4
vider(0)   # 0 && 4
verser(1)  # 4 && 0
remplir(1) # 4 && 7
verser(1)  # 5 && 6
vider(0)   # 0 && 6
verser(1)  # 5 && 1
```

```{code-cell} ipython3
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 073da6c5c1ab521b2edc9619dffb81bd
  grade: true
  grade_id: cell-b3fb4f73e1c7ca78
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
assert all(valides())
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b8e47555c1b29fa07ad21227d819a7c1", "grade": false, "grade_id": "cell-05ad37a017d55ccc", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Pour aller plus loin:

Dans une nouvelle feuille de travail:
- essayez avec des cruches de tailles différentes
- est-il toujours possible d'obtenir n'importe quel
  volume?
- écrire un algorithme qui, étant donné deux
  cruches de capacités quelconques, détermine
  et obtienne tous les volumes possibles.
