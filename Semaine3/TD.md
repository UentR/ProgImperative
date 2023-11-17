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

# TD 3 : Structures de contrôles: instructions conditionnelles, boucles simples

+++

Dans les exercices suivants, vous préciserez le nom, l'entrée et la
sortie de vos programmes. Par exemple, pour un programme calculant le
maximum de deux nombres, vous écrirez :

``` c++
// Programme maximum
// Entrée: deux entiers a et b de type int
// Sortie: le maximum de a et de b, stocké dans la variable max
int max;
if ( a >= b ) {
    max = a;
} else {
    max = b;
}
```

Si vous vous sentez à l'aise, mettez votre programme sous la forme
d'une fonction :

``` c++
int maximum(int a, int b) {
    if ( a >= b ) {
        return a;
    } else {
        return b;
    }
}
```

## Instructions conditionnelles: `if`

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "996bd57cf5ea56d05d149dc4e1e33440", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 :
<i></i>
1.  Écrivez un programme qui prend en entrée l'âge d'une personne (un
    entier donc) et dont la sortie est `true` si la personne est
    majeure et `false` sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Modifiez votre programme pour que la sortie soit une chaîne de
    caractères (type `string`) contenant le tarif SNCF appliqué à
    cette personne: `"enfant"` (moins de 11 ans), `"jeune"` (12-27
    ans), `"senior"` (60 ans ou plus) ou `"plein tarif"` sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3ec812dfbf769053d024666dd02748b0", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : À faire chez vous
<i></i>
1.  Le magasin Honeydukes est ouvert de 10h à 12h et de 14h à 19h.
    Écrivez un programme qui prend en entrée l'heure sous forme d'un
    entier et dont la sortie est `true` si le magasin est ouvert et
    `false` sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Si ce n'est pas déjà le cas, modifiez votre programme pour qu'il y
    ait au plus un `if`.

3.  Si ce n'est pas déjà le cas, modifiez votre programme pour
    qu'il n'y ait pas de `if`.  
    **Indication :** remarquez que l'expression booléenne qui sert de
    condition au `if` a déjà la valeur recherchée (voir aussi le
    cours : «Erreurs classiques avec les conditionnelles»).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

## Instructions itératives: boucle `while` et `for`

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0782ad9e8f42097a648b80a98753ea79", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 3 : Programme mystère
<i></i>
1.  Exécutez pas à pas le fragment de programme suivant pour $a=3$ et
    $b=11$:

    ``` c++
    while ( b >= a ) {
        b = b - a;
    }
    ```

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Pour $a$ et $b$ entiers positifs quelconques, quelle est la valeur
    de $b$ après la boucle?

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8cb6e5cf43af5a03c8ae3fac4f181ed0", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 : logarithme entier en base $2$
<i></i>
1.  Écrivez un programme dont l'entrée est un entier positif `n` et
    qui calcule le plus petit $i$ de la forme $2^k$ tel que $n\leq i$.
    Rappel: il n'y a pas d'opérateur puissance en `C++`.   
    **Indication :** partir de `i=1` et le multiplier par $2$ tant que
    nécessaire.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Modifiez votre programme pour que la sortie soit `k` tel que
    $i=2^k$ (où $i$ est l'entier défini à la question précédente).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "42db2c8b8e797d8e884a256797dd69bd", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : Instructions itératives avec compteur

On rappelle les exemples de programmes vus en cours pour afficher les
nombres de $1$ à $10$ avec respectivement une boucle `while` et une
boucle `for` :

``` c++
int i = 1;
while ( i <= 10 ) {
    cout << i << endl;   // Affiche la valeur de i
    i = i + 1;
}
```
```
for ( int i = 1; i <= 10; i = i + 1 ) {
    cout << i << endl;   // Affiche la valeur de i
}
```

1.  Dans chacun de ces deux programmes, entourez la déclaration du
    compteur, l'initialisation, la condition et l'incrémentation.

2.  Adaptez le premier exemple pour afficher les nombres pairs
    inférieurs ou égaux à $10$, en commençant par $0$. De même avec le
    deuxième exemple.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Même chose pour afficher les nombres de $10$ à $1$;

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Même chose pour afficher les nombres entiers de carré inférieur à $10$;

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

5.  Même chose pour calculer la valeur de la somme $1^2 + 2^2 + \cdots + 10^2$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

À votre avis, dans chacun des cas ci-dessus, laquelle des deux formes
est la plus naturelle?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "45f167402632dd0afbe68dc39e613d11", "grade": true, "grade_id": "60", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 6 : $\clubsuit$ Nombres premiers
<i></i>

1.  Écrivez une fonction qui prend en argument (entrée) un entier $n$
    et **teste** si $n$ est un nombre premier (c'est-à-dire renvoie
    `true` si $n$ est premier et `false` sinon).

2.  Écrivez une fonction qui prend en argument un entier $n$ et
    affiche tous les nombres premiers entre $1$ et $n$.

3.  Écrivez une fonction qui affiche les $n$ premiers nombres
    premiers.

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "51c3618b1dc197c0b81ea879c01b03c6", "grade": true, "grade_id": "70", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 7 : $\clubsuit$ Dates
<i></i>
1.  Écrivez une fonction qui prend en entrée une date sous la forme de
    trois entiers jour / mois / année, et teste si c'est une date
    valide. Pour l'instant, on ignore les années bissextiles. Par
    exemple:

    -   `date_valide(28, 5, 1973)` renvoie
        `true`

    -   `date_valide(31, 2, 2015)` renvoie
        `false`

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Écrivez une fonction qui prend en argument une date valide sous la
    forme de trois entiers et affiche la date du lendemain. Par
    exemple:

    -   `jour_suivant(18, 12, 2017)` affiche
        `Le jour suivant est le 19 12 2018`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Reprenez la question 1 en considérant les années bissextiles (une
    année est bissextile si elle est divisible par 4, mais pas 100
    sauf si elle est divisible par 400).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Écrivez une fonction qui prend en argument une date valide et
    renvoie le jour de la semaine de cette date.

5.  [Projet Euler- 19](https://projecteuler.net/problem=19): Combien
    de 1 du mois ont été des dimanches au XX{sup}`e` siècle?

::::
