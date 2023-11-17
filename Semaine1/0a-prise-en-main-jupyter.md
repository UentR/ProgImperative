---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.0
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"deletable": false, "editable": false}

# Prise en main des carnets Jupyter

+++ {"deletable": false, "editable": false}

Un *carnet interactif* (*notebook* en anglais) est un document
interactif permettant de mixer narration, interaction, visualisation,
calcul ou programmation. Dans ce premier carnet, vous allez découvrir
les trois opérations essentielles pour utiliser un carnet: lire,
exécuter, éditer.

+++ {"deletable": false, "editable": false}

**Définition :** 

Un carnet interactif est composé d'une séquence de *cellules*. Chaque
cellule peut contenir du texte riche, un calcul à effectuer, des
visualisations, etc. La **cellule active** est encadrée, ce qui permet
de voir sa portée. C'est l'auteur du document qui a préalablement
spécifié les propriétés de chaque cellule.

+++ {"deletable": false, "editable": false}

**Exercice 1 : à la découverte des cellules**

1.  Cliquez à différents endroits de ce document pour activer tour à
    tour les cellules qui le compose et voir leur portée.

+++ {"deletable": false, "editable": false}

**Exercice 2 : utilisation des cellules exécutables**

1.  Cliquez dans la cellule ci-dessous, puis tapez
    <kbd>Maj</kbd>+<kbd>Entrée</kbd> (la touche <kbd>Maj</kbd> est
    usuellement accompagnée du symbole ⇧; sur les claviers anglais,
    elle est dénotée <kbd>Shift</kbd>). Cela **exécutera** le calcul
    $1+1$ et affichera le résultat :

```{code-cell} ipython3
1 + 1
```

+++ {"deletable": false, "editable": false}

Exécutez de même les cellules ci-dessous, en modifiant les calculs à
effectuer selon votre goût :

```{code-cell} ipython3
2 * 3
```

```{code-cell} ipython3
2 * (3 + 4)
```

<div class="alert alert-info">

Dans cette feuille, les exemples de calculs ont volontairement été
choisis pour être très simples; bien entendu l'intérêt de Jupyter est
de donner accès à des calculs bien plus riches.

</div>

+++ {"deletable": false, "editable": false}

**Exercice 3 : modifications des cellules de texte**

1.  Saisissez vos noms et prénoms et couleur préférée dans la cellule ci-dessous.  
    **Indication :** double cliquez sur la cellule de texte; quand
    vous avez terminé, appuyez sur les touches
    <kbd>Maj</kbd>+<kbd>Entrée</kbd>.
2.  Essayez de modifier la cellule où est écrite ce texte; vous
    constaterez qu'elle est verrouillée.

+++

- Nom : Riggi
- Prénom : Quentin
- Couleur préférée : Vert

+++ {"deletable": false, "editable": false}

<!--
**Exercice 4 : à la découverte de l'aide en ligne de Jupyter**

1.  Lancez la visite guidée de l'interface Jupyter.  
    **Indication :** Menu `Aide` -> `Visite de l'interface utilisateur`.
2.  Consultez les raccourcis claviers.  
    **Indication :** Menu `Aide` -> `Raccourcis clavier`.  
!-->

+++ {"deletable": false, "editable": false}

## Conclusion

+++ {"deletable": false, "editable": false}

Vous savez maintenant lire, exécuter et éditer un carnet Jupyter. Cela
sera suffisant dans un premier temps pour utiliser des carnets
préexistants.

Vous pouvez maintenant fermer ce carnet et revenir à la [page d'accueil](index.md).
