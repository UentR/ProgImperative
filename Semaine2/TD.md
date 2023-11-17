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
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# TD 2: affectations, instructions conditionnelles

+++

:::{todo}
Mettre à jour la note pour les enseignants selon que les polys ont déjà été imprimés / distribués ou pas.
:::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3646ea08d143a76ae9ab457e4dca2a32", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 : affectations

Voici un fragment de programme `Échange`. On suppose que les variables
entières `n1` et `n2` ont été préalablement déclarées et initialisées:

    n1 = n2;
    n2 = n1;

1.  En première lecture, que fait ce fragment de programme?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Exécutez le fragment de programme pas à pas avec comme valeurs
    initiales `5` et `7` pour les variables `n1` et `n2`
    respectivement. Obtient-on à la fin les valeurs attendues dans ces
    variables ?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Modifiez le programme pour qu'il réponde à ce qui est
    attendu. Seules des déclarations de variables et des affectations
    sont nécessaires pour cela.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8d908402d296f5bbdca6839ac9c533f7", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : conditionnelles

En relisant votre cours après l'amphi, vous avez appris les opérations
sur les entiers ainsi que les opérations booléennes.  Cela vous sera
utile dans cet exercice. On suppose que l'on a déjà déclaré et
initialisé une variable `n` de type entier. On veut diviser $n$ par
$2$ s'il est pair et lui enlever $1$ s'il est impair. Écrivez les
quelques lignes d'instructions correspondantes.

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e751bbbc92e4e72670429fdf78bd2db2", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 3 : conditionnelles, fonctions

Dans cet exercice (et les suivants), vous préciserez le nom, l'entrée
et la sortie de vos programmes comme dans l'exemple suivant :

    // Programme produit
    // Entrée: deux entiers a et b de type int
    // Sortie: le produit de a et b stocké dans une variable p
    int p;
    p = a*b;

Si vous vous sentez à l'aise, ou lorsque cela est demandé, mettez
votre programme sous la forme d'une fonction :

    int produit(int a, int b) {
        return a*b;
    }

Lors de la fin d'un semestre dans une Université X, les enseignants
sont amenés à calculer la moyenne générale des notes de physique et de
mathématiques selon une règle précise : la meilleure note des trois
épreuves de mathématiques est comptée coefficient 3, et la meilleure
note des deux épreuves de physique est comptée coefficient 2; les
autres notes ne comptent pas.

Un enseignant est chargé de concevoir un algorithme prenant en entrée
les trois notes de mathématiques et les deux notes de physique, et
donnant la moyenne générale suivant la règle énoncée ci-dessus.

1.  Spécifiez et écrivez un algorithme `max2` qui, étant donnés deux
    nombres réels `a` et `b` (qu'on suppose déjà déclarés et
    initialisés), calcule le plus grand des deux et met le résultat
    dans une variable `m`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Transformez cet algorithme en une fonction nommée `max2` pour
    pouvoir par la suite calculer le maximum de deux nombres avec un
    appel à la fonction, par exemple `max2(7,5)`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  De même, étant donnés trois nombres réels, donnez un algorithme
    calculant le plus grand des trois (dans une variable `m`). On
    pourra utiliser la fonction `max2(a,b)`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  $\clubsuit$ Transformer cet algorithme en fonction.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

5.  Spécifiez et donnez un algorithme qui prend en entrée trois
    notes de mathématiques, puis deux notes de physique, et calcule la
    moyenne selon la règle spécifiée.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

6.  $\clubsuit$ Transformez cet algorithme en fonction.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "03d6304a8490edbd7fa7090d540ab529", "grade": true, "grade_id": "70", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 : rendu de monnaie

On considère une machine qui distribue des sucreries. Le problème
consiste à écrire le programme qu'elle exécute pour rendre la monnaie
sur une somme, à l'aide de pièces de 50 centimes, 20 centimes, 10
centimes et 5 centimes d'euro, de façon à minimiser le nombre de
pièces rendues sachant que l'on connaît le prix et la somme donnée par
le client. On suppose que les sommes sont données en centimes d'euro,
qu'il n'y a pas de risque de pénurie de pièces de monnaie, et que les
prix sont un multiple de 5 centimes.  Par exemple si le prix à payer
est de 110 centimes et que le client a donné 200 centimes, il faut lui
rendre 1 pièce de 50 centimes et 2 pièces de 20 centimes.

1.  Quelles sont les entrées / sorties du problème ?

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Écrivez un programme pour résoudre le problème. On pourra supposer
    que les variables `prix` et `somme` contiennent respectivement le
    prix et la somme donnée par le client. À la fin du programme, la
    variable `npieces50` devra contenir le nombre de pièces de
    cinquante centimes à rendre, et de même pour les variables
    `npieces20`, `npieces10` et `npieces5`.
    
    Note : avec ce que vous avez appris, vous ne pouvez pas encore
    écrire une fonction pour ce problème (pourquoi?).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE


3.  $\clubsuit$ Comment gérer un nombre limité de pièces en réserve
    dans la caisse de la machine?

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "26a341fc1567103da0dee7eff55ae08f", "grade": true, "grade_id": "80", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : $\clubsuit$ pierre-feuille-ciseaux

Héloïse et Gabriel veulent jouer à pierre-feuille-ciseaux, mais, têtes
en l'air, ils ne se souviennent jamais de qui bat quoi.

1.  On numérote les joueurs par $1$ et $2$, et on représente un choix
    par un entier: $1$ pour une pierre, $2$ pour une feuille, et $3$
    pour les ciseaux. On suppose que les variables `choix1` et
    `choix2` ont été déclarées et initialisées respectivement avec les
    choix du joueur $1$ et $2$.  Écrivez un programme dont la sortie,
    stockée dans une variable `gagnant` contienne le numéro du joueur
    gagnant (ou zéro si égalité).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Transformez votre programme sous forme d'une fonction.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Même chose en représentant un choix par un caractère (type
    `char`): 'p' pour pierre, 'f' pour feuille, 'c' pour ciseaux.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  $\clubsuit$ Même chose en utilisant un type `enum`.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++

Vous avez fini la feuille? Regardez les exercices du **Projet
Euler**[^1], une série de défis, de difficulté croissante, mêlant
mathématiques, algorithmique, et programmation. Chaque problème
possède une unique solution qu'il s'agit de découvrir par soi-même. Le
Problème 19 aborde les thématiques de cette semaine.

[^1]: <http://projecteuler.net/>; voir
    <http://submoon.freeshell.org/fr/sphinx/euler.html> pour les
    énoncés en français.
