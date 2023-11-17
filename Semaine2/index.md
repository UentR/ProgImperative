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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "56ec0a4cabda6c0696ea19160d6d7e34", "grade": false, "grade_id": "cell-65f24a4fe8c153b9", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Semaine 2: Premiers éléments de programmation impérative

La semaine dernière, Laby nous a amené à la découverte de premiers
éléments de la programmation impérative: programmes, fonctions,
instructions conditionnelles et itératives. Cette semaine, nous allons
commencer à formaliser ces éléments, en y ajoutant expressions et
variables.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4e2d6846c80331c1469f58ec637e7e4a", "grade": false, "grade_id": "cell-65f24a4fe8c153c0", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## [Cours](cours.md)

## [TD : affectations, instructions conditionnelles](TD.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6b66466b7f04d30b80167a5b5f733e1f", "grade": false, "grade_id": "cell-65f24a4fe8c153c1", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## TP

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9510d5dd72e75753d592cc04121c4d9f", "grade": false, "grade_id": "cell-65f24a4fe8c153c2", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{attention} Rappel
Tout exercice non marqué d'un ♣ est à terminer pour la semaine prochaine.
:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "16d262add0837e4334ab87b904b85f8f", "grade": false, "grade_id": "cell-bf0808a9dcb0b572", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 0 : Notes de cours

1.  Consultez les notes de cours de la semaine 1 sur le site web.
2.  Que signifie *syntaxe*? Et *sémantique*? Vérifiez dans les notes
    de cours.
3.  Quelle est la syntaxe et la sémantique de l'affectation de
    variables? Vérifiez dans les notes de cours de la semaine 2 (voir
    le site web ou ci-dessus).

<!--
### Exercice: Téléchargement du sujet de TP

1.  Ouvrez un terminal (vous pouvez consulter l'exercice 2 du TP 1).

3.  Exécutez la commande `info-111` et observez le résultat.

4.  Vous venez de lire la documentation de la commande `info-111`.
    Téléchargez le sujet de TP «Semaine2» en suivant les instructions
    données à ce sujet par cette documentation.
    Remarque: Si vous n'avez pas fait le TP1, vous aurez besoin d'activer
    votre compte gitlab (voir TP1).

6.  Consultez la liste des fichiers de votre nouveau répertoire
    `~/ProgImperative/Semaine2/` à l'aide de la commande `ls` (cf. l'UE
    Introduction à l'Informatique pour ceux qui la suivent):

	    ls ~/ProgImperative/Semaine2/

5.  Observez ce qui est affiché; notez que `info-111` a fait appel à la
    commande `git clone ...`.
!-->

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e97d0f3d2c198c10d8f8aa4313e2f707", "grade": false, "grade_id": "cell-bf0808a9dcb0b574", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 1 : Jupyter

Chaque semaine, nous commencerons par une petite feuille pour vous
familiariser progressivement à l'utilisation de Jupyter. Aujourd'hui,
ce sera:

- [00: Jupyter: mode édition versus mode commande](00-jupyter-mode-edition-vs-commande.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1974cd8f2b5e472f6c0416829c9031d3", "grade": false, "grade_id": "cell-bf0808a9dcb0b573", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 2 : Jupyter, valeurs, types, types, variables, conditionnelles, fonctions

Travaillez successivement sur les feuilles suivantes :

- [01: Expressions, valeurs et types](01-valeurs-types.md);
- [02: Variables](02-variables.md);
- [03: Conditions et fonctions](03-conditions-fonctions.md);

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d82b17ec12b05990bfd4e9bd1aff611e", "grade": false, "grade_id": "cell-bf0808a9dcb0b575", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 3 : Dépôt de votre travail

1.  Utilisez le tableau de bord pour déposer votre travail sur GitLab
    (consultez au besoin la page
	[Case départ](https://nicolas.thiery.name/Enseignement/Info111/ComputerLab/index.html)
    du site web).

3.  N'oubliez pas de déposer à nouveau votre travail en fin de séance,
    afin que tout soit bien sauvegardé.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e5203c02432c8ea4b5dc0d24105bc30d", "grade": false, "grade_id": "cell-bf0808a9dcb0b576", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 4 : Service JupyterHub@Paris-Saclay

:::{hint} Rappel
L'université a déployé un service `JupyterHub` (expérimental)
vous permettant de travailler en dehors des séances avec simplement
une connexion internet et un navigateur web (firefox, chrome, safari,
...).
:::
:::{attention}
Cet exercice n'est à faire que si vous n'avez pas encore utilisé ce
service ou si vous avez rencontré des difficultés. Demandez de l'aide au besoin à votre enseignant.
:::

1.  Suivez les instructions de la page
	[Case départ](https://nicolas.thiery.name/Enseignement/Info111/ComputerLab/index.html)
	du site web
    pour vous connecter au service JupyterHub;
2.  Téléchargez-y vos TP 1 et 2 et consultez les;

<!--
2.  Fermez votre serveur avec `Control Panel -> Stop My Server`, puis
    fermez la page.
!-->

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3e6182e1ad41cd0c966bafd7c7405f45", "grade": false, "grade_id": "cell-bf0808a9dcb0b577", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 5 : Retour sur le TD

Travaillez successivement sur les deux feuilles suivantes :

1.  [04-td-exercice3.md](04-td-exercice3.md).
2.  [05-td-exercice4.md](05-td-exercice4.md).

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9e02be34bb97f5a80a6ad0f6e9729ec5", "grade": false, "grade_id": "cell-bf0808a9dcb0b578", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 6 : **Pour la semaine prochaine**

1.  Vous vérifierez que vous pouvez vous connecter au service
    JupyterHub depuis chez vous et que vous pouvez y exécuter vos
    feuilles Jupyter (voir exercice « Service JupyterHub » ci dessus).

2.  Terminez les fiches Jupyter de ce TP, soit en salle informatique
    de l'université, soit depuis chez vous en utilisant le service
    JupyterHub.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76412fe4e07321dadd3cc05830f425fc", "grade": false, "grade_id": "cell-bf0808a9dcb0b57a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{note}

Vous pouvez aborder les exercices ♣ suivants dans l'ordre que vous
souhaitez.

Pour les réaliser, vous créerez au fur et à mesure de nouvelles
feuilles de travail (notebook). Pour cela : utilisez le menu `Fichier
-> Nouveau -> Notebook` et sélectionnez le noyau `Python 3` ou `C++
17`. Vous noterez dans le titre de l'onglet que votre feuille
s'appelle `Untitled.ipynb`; utilisez un clic droit sur le titre de
l'onglet et choisissez `Renommer` dans le menu pour donner un nom
informatif à la feuille.
</div>

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0e5590c0564fa84b30aec895de9bf212", "grade": false, "grade_id": "cell-bf0808a9dcb0b57c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{tip} Astuce

Pour que le dépôt sur GitLab tienne compte de vos nouveaux fichiers,
vous devez au préalable les déclarer au système de gestion de version
sous-jacent `git`. Par exemple, pour déclarer un nouveau fichier
`mon_fichier.md` que vous avez créé dans votre répertoire `Semaine2`,
vous ouvrirez un terminal et ferez :

    cd ~/ProgImperative/Semaine2
    git add mon_fichier.md

Il sera alors inclus dans tous les dépôts ultérieurs.

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d2ac8dc671e598607d2d1c2dff7cc736", "grade": false, "grade_id": "cell-bf0808a9dcb0b57b", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice ♣ : Euler forever!

Vous trouverez sur le site du projet Euler <https://projecteuler.net>
une série de problèmes mathématiques qui nécessitent chacun une
combinaison de réflexion sur feuille et de programmation (voir
<http://submoon.freeshell.org/fr/sphinx/euler.html> pour avoir les
énoncés en français).

Essayez de résoudre les problèmes 1, 2, 5 et tous ceux qui vous
plairont!

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ea53bc2ad33d30f8800bbf95e6f35dd1", "grade": false, "grade_id": "cell-bf0808a9dcb0b579", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice ♣ : Python

Dans le cours «Introduction à la programmation», vous (re)découvrirez
le langage de programmation Python. Pour prendre un peu d'avance,
refaites le TP en utilisant cette fois `Python`.

Vous pouvez consulter la feuille [Résumé de la syntaxe de base
Python](fiche-resume-python.md).

<!--
Vous trouverez un cours complet sur `Python` à cette adresse:

<http://fr.openclassrooms.com/informatique/cours/apprenez-a-programmer-en-python>

Il est intéressant de le lire et de comparer avec ce que vous apprenez
en C++ ce semestre.
!-->
