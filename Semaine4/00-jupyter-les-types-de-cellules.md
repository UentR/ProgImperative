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

+++ {"deletable": false, "editable": false}

# TP : Jupyter : les deux types de cellules

:::{admonition} Objectif pédagogique

Mieux comprendre les deux types de cellules qui
composent un carnet Jupyter et permettent d'alterner texte riche et
code exécutable.

:::

+++ {"deletable": false, "editable": false}

L'intérêt des carnets numériques est de permettre d'entremêler, au
sein d'un même document, **narration**, **interaction**, **calcul**,
**visualisation** et **programmation**. Pour cela, Jupyter propose un
modèle très simple : un carnet Jupyter est une simple succession de
cellules de deux types :

* Des cellules de texte riche, au format ***Markdown*** ;
* Des cellules de code exécutable.

:::{admonition} [Markdown](https://fr.wikipedia.org/wiki/Markdown) : Kesako ?

* Un langage à balisage léger pour écrire du texte riche;
* Avec une syntaxe facile à lire et écrire.

Markdown vous permet ainsi de rédiger du texte ***mis en forme*** et
structuré (sections, listes à puces, ...) avec, par exemple :

* Du contenu multimédia: images, vidéos, ...
* Des mathématiques : $e^{2i\pi}=1$ ;
* Des fragments de code non exécutables : `x = x + 1` ;
* Des liens hypertexte : [lien vers l'index](index.md) ;
* Des tableaux :

    | Colonne 1 | Colonne 2 |
    |-----------|-----------|
    | cellule 1 | cellule 2 |

* Du HTML : `<br>`, `<div>`, ...
* ...

:::

**Exercice 1 :**

- Consultez les cellules de texte riche de ce document pour voir
  comment elles ont été rédigées en Markdown.

+++ {"deletable": false, "editable": false}

## Comment changer le type d'une cellule

* À la souris : dans la barre d'outil de la feuille, sélectionnez
  `Markdown` ou `Code`.
* Au clavier: passez en mode commande (voir le
  [tutoriel](concept-mode-edition-vs-commande.md)) puis utilisez
  <kbd>Y</kbd> pour convertir une cellule Markdown en cellule de code.
* Inversement, toujours en mode commande, utilisez <kbd>M</kbd> pour
  convertir une cellule de code en cellule de Markdown.

+++ {"deletable": false, "editable": false}

**Exercice 2 :** La cellule ci-dessous est « accidentellement » une
cellule de texte. Changez-la en cellule de code pour pouvoir
l'exécuter :

```{code-cell} ipython3
:deletable: false
:editable: false

import codecs
codecs.decode('Oenib!', 'rot_13')
```

+++ {"deletable": false, "editable": false}

## En savoir plus sur la syntaxe Markdown

Voici quelques tutoriels :

* [Tutoriel Markdown (SNDS)](https://documentation-snds.health-data-hub.fr/contribuer/guide_contribution/tutoriel_markdown.html)
* [La syntaxe Markdown (Framasoft)](https://docs.framasoft.org/fr/grav/markdown.html)

+++ {"deletable": false, "editable": false}

## Conclusion

Dans la plupart des cas d'usage, le rôle d'un carnet numérique est de
transmettre des idées, en racontant une histoire
interactive. L'alternance des cellules permet la micro-scénarisation
de cette histoire, avec des cellules de texte riche qui en donnent la
trame narrative et des cellules de code exécutable, synthétiques et
parcimonieuses, qui engagent le lecteur par des interactions.
