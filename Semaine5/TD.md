---
exports:
- format: pdf
  output: TD.pdf
  template: ../../template/TD
- format: tex
  output: TDmd.tex
  template: ../../template/TD
jupytext:
  notebook_metadata_filter: exports, myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.2
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# TD 5 : Fonctions et tableaux

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0df8d3413d80d37570cce0c88624ddaf", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 : Échauffement

Quelles sont les valeurs `v[0]`, `v[1]`, ...
contenues dans le tableau `v` à la fin de l'exécution du
programme suivant :

:::{literalinclude} carres-correction.cpp
:start-after: BEGIN CODE
:end-before: END CODE
:::

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5a3d41e16d20c52382ad98f128d90ffe", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : Mystère

On considère la fonction mystère suivante :

:::{literalinclude} max-mystere-correction.cpp
:start-after: BEGIN mystere
:end-before: END mystere
:::

1.  Exécutez pas à pas le programme suivant :

    :::{literalinclude} max-mystere-correction.cpp
    :start-after: BEGIN mystere.utilisation
    :end-before: END mystere.utilisation
    :::

    Quelle est la valeur de la variable `resultat` à la fin
    de l'exécution? Que fait la fonction mystère?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Modifiez la fonction pour qu'elle calcule le minimum d'un tableau.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "47aefb68fbc2cae180226c8916ed4728", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 3 : Quelques fonctions sur les tableaux

1.  Spécifiez (sous forme de documentation) et implantez (sous forme
    de code) une fonction qui renvoie vrai si tous les éléments d'un
    tableau d'entiers sont positifs, et faux sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Spécifiez et implantez une fonction qui incrémente de 1 tous les
    éléments d'un tableau d'entiers et renvoie le tableau.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Spécifiez et implantez une fonction qui teste si deux tableaux
    d'entiers sont égaux.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Spécifiez et implantez une fonction qui compte le nombre
    d'éléments strictement plus grands qu'un seuil donné dans un
    tableau d'entiers.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

5.  Spécifiez et implantez une fonction qui renvoie vrai si un tableau
    d'entiers est trié dans l'ordre croissant, et faux sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76e07962fa1bb58ddbd1ed3a43ca2935", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 :

La suite de Fibonacci est définie récursivement par la relation :
$U_{n}=U_{n-1}+U_{n-2}$. Cette définition doit être complétée par une
condition d'initialisation, en l'occurrence :
$U_{1}=U_{2}=1$. Introduite par Léonard de Pise (surnommé Fibonacci),
cette suite décrit un modèle simplifié de l'évolution d'une population
de lapins. Les premiers termes sont donnés par : 1, 1, 2, 3, 5, 8, 13,
21, 34, 55, 89, 144, 233, 377, 610, ... Voir aussi
<https://oeis.org/A000045>.

L'objectif est de donner trois implantations de la fonction dont la
documentation et les tests sont donnés ci-dessous :

:::{literalinclude} fibonacci-correction.cpp
:start-after: BEGIN fibonacciDoc
:end-before: END fibonacciDoc
:::

:::{literalinclude} fibonacci-correction.cpp
:start-after: BEGIN fibonacciTestBroken
:end-before: END fibonacciTestBroken
:::

1.  Vérifiez la cohérence entre tests et documentation. Corrigez si
    nécessaire.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Implantez la fonction fibonacci avec une boucle `for` et un
    tableau de taille $n$ pour stocker tous les éléments de la suite
    $U_1,\ldots,U_n$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Implantez la fonction fibonacci sans tableau, en utilisant une
    boucle `for` et trois variables dont deux qui, au début de chaque
    tour de boucle, contiennent respectivement les valeurs de
    $U_{k-1}$ et $U_{k-2}$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Implantez une version récursive de la fonction fibonacci.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

5.  Laquelle de ces trois implantations est-elle la plus expressive?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

6.  $\clubsuit$ Comparez l'efficacité des trois implantations. Quel
    phénomène a lieu pour la fonction récursive? Comment pourrait-on
    le corriger?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "138ae8af7c9ad6a28d00cc0f86445773", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : $\clubsuit$

1.  Que fait la fonction suivante?

    :::{literalinclude} mirror-mystere-correction.cpp
    :start-after: BEGIN mystere
    :end-before: END mystere
    :::

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Un **palindrome** est un tableau comme $\{2,8,-1,6,-1,8,2\}$ qui
    peut se lire de la même façon dans les deux sens. Écrivez une
    fonction `palindrome` qui teste si un tableau est un palindrome en
    utilisant les fonctions déjà vues dans le TD.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Réécrivez une fonction `palindromeIndependant`, testant si un
    tableau est un palindrome, sans utiliser les fonctions déjà vues
    dans les exercices précédents.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Commentez les avantages et inconvénients des deux implantations.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

