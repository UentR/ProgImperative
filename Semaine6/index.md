---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "939b66fee3be7613eff2a7ac0a131809", "grade": false, "grade_id": "cell-405b64781fe13bde", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Semaine 6 : modèle de mémoire, collections, consolidation

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "366186eb37b99a42048d85978668c70e", "grade": false, "grade_id": "cell-249063faf999e9b3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Les semaines précédentes nous avons successivement empilé de nombreux
éléments de la programmation impérative: variables, conditionnelles,
boucles, fonctions, tableaux. Cette semaine est consacrée à la
consolidation de ces éléments, en vue du partiel fin octobre.

En cours, nous commencerons par un exemple jouet de **piratage par
débordement**. Cela motivera l'introduction d'un **modèle de mémoire**
raffiné (**pile** + **tas**) pour mieux comprendre l'allocation des
tableaux. Nous généraliserons ensuite les tableaux avec la notion de
collections et introduirons la boucle **for each**.

En TD et TP, nous combinerons tout ce que nous avons vu jusqu'ici pour
implanter le **jeu de Yams**.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "929eed3f8851580b6068cf323497a686", "grade": false, "grade_id": "cell-b74ea1a2236a0f8c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## [Cours](cours.md)

1. [Prélude : exemple jouet de piratage par débordement](cours-login.md)
2. [Modèle de mémoire et tableaux](cours-memoire-tableaux.md)
3. [Collections](cours-collections.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "320c58c6a47cfaed12aa67bbc2a7a713", "grade": false, "grade_id": "cell-b74ea1a2236a0f8d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## [TD : premiers pas vers le jeu de Yam's](TD.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a1f152c9032ca2563d40b4da565497f6", "grade": false, "grade_id": "cell-2cb5de2667417f2e", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## TP : Implantation du jeu de Yam's

**Exercice 0 :** [Jupyter : jeter sa souris](00-jupyter-jeter-sa-souris.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "314b0aec61c00db496da6c253ef0d2fa", "grade": false, "grade_id": "cell-47ce0b02cfcdb434", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice 1 :** Yam's simplifié

Nous allons travailler en parallèle dans une feuille Jupyter
[yams.md](yams.md) et dans un fichier source [yams.cpp](yams.cpp)
afin, à la fin du TP, d'obtenir un exécutable autonome permettant de
jouer une partie de Yam's simplifiée.

Ouvrez la feuille [yams.md](yams.md) et suivez les instructions.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d3ca9160fdccf3d9052c3088133ccf12", "grade": false, "grade_id": "cell-47ce0b02cfcdb435", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice 2 :** Interlude: [boucles imbriquées](laby-imbriquee.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1ce010caf89b8a769ef75ba418bb4a8e", "grade": false, "grade_id": "cell-1272d7485b5484ce", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Exercice 3 :** ♣ Yam's complet

Le programme que vous obtenez à la fin de l'exercice 1 est encore loin
de représenter le jeu de Yam's réel.

Dans cet exercice nous vous proposons plusieurs extensions (dont
certaines déjà évoquées dans le sujet de TD) qui vous permettront
de vous en approcher.

Vous pouvez utiliser Jupyter pour prototyper vos fonctions, mais vous
devez au final implémenter ces extensions dans votre programme compilé
(fichier [`yams.cpp`](yams.cpp)).

-   Dans le vrai jeu de Yam's, le joueur peut relancer jusqu'à trois
    fois un ou plusieurs dés avant de choisir une figure.

    1.  Ajouter une fonction
        `vector<int> relance(int nde, vector<int> des)` qui "relance" le
        dé choisi en premier argument et le remplace donc par un nouveau
        nombre aléatoire entre 1 et 6.

    2.  Dans la boucle de jeu, ajouter les instructions nécessaires pour
        que le joueur puisse choisir jusqu'à trois dés à relancer et les
        relancer.

-   La partie de Yam's se termine lorsqu'un joueur a marqué des points
    pour toutes les figures possibles.

    1.  Ajouter dans la fonction `main` un tableau de score contenant
        une case pour chaque figure.

    2.  Lorsque le joueur choisit une figure, les points qu'il gagne
        doivent être stockés dans la partie correspondante du tableau.
        Une fois une case du tableau remplie, elle ne peut plus être
        modifiée.

    3.  La partie se termine lorsque toutes les cases du tableau sont
        remplies. Le score du joueur correspond à la somme des cases du
        tableau.

-   Raccourcis : permettre à l'utilisateur d'utiliser des raccourcis
    pour nommer les figures: `b` pour brelan, `y` pour yams, ...

-   C'est un peu triste de jouer tout seul! Modifiez la boucle
    principale pour alterner les tours entre 2 joueurs dont les scores
    seront stockés dans deux tableaux de score distincts. La partie
    s'arrête lorsqu'un joueur a fini de remplir son tableau de score. On
    compare alors le score de chaque joueur pour désigner le gagnant.

-   Si vous êtes très motivés vous pouvez transformer une dernière fois
    votre programme afin de rendre possible des parties entre un nombre
    quelconque de joueurs. Pour cela vous aurez besoin d'utiliser un
    tableau de tableaux de scores. Ce tableau contiendra un tableau de
    score pour chaque joueur présent dans la partie.
