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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "47200b3983327236aad45efbac77bf8d", "grade": false, "grade_id": "cell-68267a047d81d6a0", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : Jupyter : le noyau

<div class="alert alert-info">

Objectif pédagogique : Apprendre à gérer le noyau (*kernel*)

</div>

**Exercice : à quoi sert le noyau**

- Cliquez sur la cellule suivante puis exécutez la en appuyant sur les
  touches <kbd>Maj</kbd>+<kbd>Entrée</kbd> :

```{code-cell} ipython3
1 + 1
```

Techniquement parlant, le navigateur web a envoyé le contenu `1 + 1`
de la cellule à un *noyau* (kernel en anglais) qui l'a *exécuté*,
avant de renvoyer le résultat à afficher. Le noyau que nous utilisons
ici (`Python 3`) permet de travailler en `Python`. Il existe des
noyaux pour de nombreux langages de programmation et systèmes de
calculs : Julia, Python, R -- d'où le nom de Jupyter --, mais aussi
des dizaines d'autres dont C++ ou SageMath.

+++

**Exercice : changer de noyau** <br>

À un moment donné, une feuille Jupyter est reliée à un unique
noyau. Le nom de ce noyau est affiché en haut à droite de la feuille
de travail. Cliquez dessus pour afficher la liste des noyaux
disponibles sur votre instance de Jupyter. Essayez la cellule
ci-dessus avec ces autres noyaux. Puis sélectionnez à nouveau le noyau
Python.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "eed93eaa93f53235e5ade90fcd15eb2c", "grade": false, "grade_id": "cell-c6929b395e52ee35", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice : relancer le noyau**

- Exécutez les deux cellules ci-dessous avec <kbd>Maj</kbd>-<kbd>Enter</kbd> :

```{code-cell} ipython3
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4a63d928cc411c53fb3b4074ccf19e1d
  grade: false
  grade_id: noyaux1C1
  locked: true
  schema_version: 3
  solution: false
---
i = 0
while True:
  i = i + 2
```

```{code-cell} ipython3
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4d81a852de72553d8eaed1ab42dbc5d5
  grade: false
  grade_id: noyaux1C2
  locked: true
  schema_version: 3
  solution: false
---
1 + 1
```

- La première cellule contenant une boucle infinie, l'exécution est
  maintenant bloquée. Vous noterez notamment l'étoile dans le `In[*]`
  qui indique que les deux cellules sont en attente de la fin du
  calcul -- fin qui n'arrivera ici jamais.  

  Pour pouvoir reprendre la main, il faut arrêter ou redémarrer le
  noyau.

- Relancez le noyau, en allant dans la barre de Menu «Noyau» ou
  «Kernel», ou bien avec le raccourci clavier
  <kbd>Esc</kbd>-<kbd>0</kbd>-<kbd>0</kbd>.
  
- Réessayez l'exercice, cette fois en arrêtant le noyau.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f60b280ff2fa50714d8aa960b0ae024b", "grade": false, "grade_id": "cell-2a38289b226028cc", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Conclusion**

Dans cette feuille, vous avez vu comment changer, arrêter, ou relancer
le noyau. Cela permet notamment de changer de langage de
programmation, de sortir d'une boucle infinie, ou de repartir sur une
base neuve en oubliant les calculs précédents.
