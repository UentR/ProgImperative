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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0d65b1db4ff4d2aefc74ed2c66a51567", "grade": false, "grade_id": "cell-d4e64962efcbc324", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : Jupyter : mode Édition vs mode Commande

<div class="alert alert-info">

Objectif pédagogique : Découvrir les deux modes d'interaction avec un
carnet Jupyter.

</div> 

Lorsque l'on travaille sur un carnet Jupyter, on est amené à
alternativement éditer le contenu d'une cellule (par exemple y écrire
du texte) et naviguer entre les cellules et les manipuler
(par exemple supprimer une cellule, ou en insérer une
nouvelle). Jusqu'ici, vous avez probablement utilisé la souris et les
menus pour effectuer ces manipulations de cellules.

Pour travailler plus efficacement, notamment à l'aide de raccourcis clavier,
les carnets Jupyter offrent deux modes d'éditions:

- Le mode ***Édition*** qui permet, comme son nom l'indique, d'éditer le
  contenu d'une cellule. C'est celui que vous avez utilisé lorsque
  vous avez cliqué ou double cliqué dans une cellule.

- Le mode ***Commande*** qui permet de naviguer d'une cellule à
  l'autre et de les manipuler.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c9b9cbd959df806a0c76d72bd69931b6", "grade": false, "grade_id": "cell-da8f72cb85b2d1de", "locked": true, "schema_version": 3, "solution": false, "task": false}}

<!--
Vous trouverez tous les raccourcis clavier dans le menu `Aide` ->
`Raccourcis` clavier. Ils sont aussi rappelés dans les menus
eux-même.
!-->

<div class="alert alert-info">

**Les raccourcis clavier essentiels :**
    
En mode commande :
- Naviguer entre cellules : touches <kbd>↑</kbd> et <kbd>↓</kbd>; 
- Basculer en mode Édition sur la cellule courante : touche <kbd>Entrée</kbd>
- Ajouter une cellule Avant : touche <kbd>A</kbd> (comme *above*)
- Ajouter une cellule Après : touche <kbd>B</kbd> (comme *below*)
- Couper une cellule : touche <kbd>X</kbd>
- Copier une cellule : touche <kbd>C</kbd>
- Coller une cellule : touche <kbd>V</kbd>
- Annuler : toucher <kbd>Z</kbd>
- Fusionner avec la cellule du dessous : touches <kbd>Maj</kbd>+<kbd>M</kbd>

<!--
- Obtenir la liste des raccourcis claviers : touche <kbd>H</kbd> (comme *help*);
!-->

En mode édition :
- Basculer en mode Commande : touche <kbd>Esc</kbd>
- Sélectionner au clavier : <kbd>Maj</kbd>-touche de déplacement
- Couper : <kbd>Ctrl</kbd>-<kbd>x</kbd>
- Copier : <kbd>Ctrl</kbd>-<kbd>c</kbd>
- Coller : <kbd>Ctrl</kbd>-<kbd>v</kbd>

</div>

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4586f168f62b18c016204ff685941479", "grade": false, "grade_id": "cell-1ac7fa2533514788", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice

Votre défi est d'effectuer l'ensemble de cet exercice, sans toucher
votre souris!

1.  Observez la cellule actuellement sélectionnée. Est-elle encadrée
    d'un liseré bleu? Si oui vous êtes en mode Édition. Sinon, vous
    êtes mode Commande. Utilisez les touches <kbd>Entrée</kbd> et
    <kbd>Echap</kbd> pour basculer de l'un à l'autre de ces
    modes. Finissez par <kbd>Echap</kbd> pour être en mode commande.
2.  Utilisez les flèches <kbd>↑</kbd> et <kbd>↓</kbd> pour vous déplacer rapidement
    d'une cellule à l'autre
3.  Éditez les cellules ci-dessous en suivant les instructions
    qu'elles contiennent.

+++

Je suis la cellule A. Déplacez moi avant la cellule B.

+++

Je suis la cellule B. Écrivez votre nom ici : Riggi

```{code-cell} ipython3

```

Je souhaiterai qu'on rajoute une cellule avant moi.

+++ {"deletable": false, "editable": true}

Entrez en **mode édition** dans cette cellule, puis suivez les instructions ci-dessous :  
Je conserve cette ligne  
Je conserve cette ligne aussi  
Je conserve également cette ligne  
Je garde celle là aussi  

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5287c2683d7b592a5729b8e5f528cbce", "grade": false, "grade_id": "cell-6144a810d1986571", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Conclusion

Utiliser alternativement les deux modes Édition et Commande vous
permettra de manipuler efficacement les carnets Jupyter au clavier.
Consultez régulièrement la liste des raccourcis disponibles et
apprenez en un ou deux à chaque séance!

<!-- TODO: liens vers les suites naturelles: réordonner cellules, -->
<!-- jeter sa souris -->

<!--
<div class="btn btn-default btn-xs" role="button">

[<i class="fa fa-home"></i> Revenir à l'accueil du Tutoriel Jupyter](https://jupyter.gitlab.dsi.universite-paris-saclay.fr/tutoriel-jupyter/intro.html)

</div>

## Pour aller plus loin 

* Découvrez comment différencier et utiliser les cellules de texte (Markdown) et de code executable avec ce [tuto](https://jupyter.gitlab.dsi.universite-paris-saclay.fr/tutoriel-jupyter/tuto-les-types-de-cellules.html)
* 
!-->
