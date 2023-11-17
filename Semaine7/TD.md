---
exports:
- format: pdf
  output: TD.pdf
  template: ../../template/TD
- format: tex
  output: TDmd.tex
  template: ../../template/TD
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

# TD 7 : Tableaux à deux dimensions (tableaux 2D)

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1ef4fd816f5faa6afd9b524a701ef95b", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\enlargethispage{1.5cm}`
%{latexonly}`\vspace{-1ex}`

::::{admonition} Exercice 1 : Échauffement

On considère le tableau d'entiers à deux dimensions suivant :

{latexonly}`\small`
:::{literalinclude} tableaux2D.cpp
:start-after: BEGIN initialisationTD
:end-before: END initialisationTD
:::
{latexonly}`\normalsize`
{latexonly}`\vspace{-.1ex}`

1.  Quelles sont les valeurs `tab2d[0][0]`, `tab2d[0][1]`, `tab2d[2][3]` ?

	% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  Donnez le nombre de lignes et de colonnes du tableau `tab2d`.

	% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a967177474cae1f1a71ebbbe22e3c6bf", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\vspace{-3ex}`

::::{admonition} Exercice 2 : Déclaration, allocation et initialisation de tableau 2D

Écrire un fragment de programme qui construit un tableau 2D `résultat`
de `L` lignes et `C` colonnes et qui l'initialise avec un entier `v`
dans chaque case (on supposera `L`, `C` et `v` prédéfinis).

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "697892e4080de0418270746d65fb58de", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\vspace{-3ex}`

::::{admonition} Exercice 3 : Opérations sur tableaux à deux dimensions

Dans cet exercice on considère des tableaux de caractères à deux
dimensions. Par exemple l'un des tableaux respectivement carré `tc`,
rectangulaire `tr` ou quelconque `tq` définis comme suit :

{latexonly}`\tiny`
:::{literalinclude} tableaux2Dchar-correction.cpp
:start-after: BEGIN init
:end-before: END init
:::
{latexonly}`\normalsize`
{latexonly}`\vspace{-.1ex}`

Pour chaque opération ci-dessous, spécifiez et implantez une fonction
qui prend au moins un tableau à deux dimensions `t` en paramètre et la
réalise :

1.  renvoyer le nombre de lignes de `t`.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  renvoyer le nombre de colonnes de `t` (supposé rectangulaire).

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

3.  afficher les éléments de la ligne d'indice $\ell$ de `t`.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

4.  afficher les éléments de la colonne d'indice $c$ de `t` (supposé rectangulaire).

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

5.  afficher les éléments de la diagonale de `t` (supposé carré).

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

6.  afficher les éléments de `t`; pour `tc`, `tr` et `tq`, les
    affichages seront respectivement :

	{latexonly}`\tiny`

        Pour          Bravo          Tout
        bien          bonne          va
        rire          ANNEE          mieux 
        lis!

    {latexonly}`\normalsize`
	{latexonly}`\vspace{-.1ex}`

    %	{latexonly}`\footnotesize`
    %
    %	::::{grid}
    %	
    %	:::{grid-item-card}
    %      |   |   |   |   |
    %      |---|---|---|---|
    %      | P | o | u | r |
    %      | b | i | e | n |
    %      | r | i | r | e |
    %      | l | i | s | ! |
    %    :::
    %	:::{grid-item-card}
    %      |   |   |   |   |   |
    %      |---|---|---|---|---|
    %      | B | r | a | v | o |
    %      | b | o | n | n | e |
    %      | A | N | N | E | E |
    %    :::
    %    :::{grid-item-card}
    %      |   |   |   |   |   |
    %      |---|---|---|---|---|
    %      | T | o | u | t |   |
    %      | v | a |   |   |   |
    %      | m | i | e | u | x |
    %    :::
    %	::::
    %
    %	{latexonly}`\normalsize`
    %
    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

7.  indiquer si oui ou non, `t` contient le caractère `c`.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f213bc021ff233876cb51430a686be85", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\vspace{-3ex}`

::::{admonition} Exercice 4 : Matrices

Pour être plus spécifique et éviter d'avoir à écrire
`vector<vector<int>>` à tout bout de champ, on peut définir un
raccourci. Dans les questions suivantes, qui traitent de matrices, on
utilisera par exemple le raccourci suivant :

```
using Matrice = vector<vector<int>>;
```

Les deux constructions suivantes sont alors totalement équivalentes :

```
vector<vector<int>> tab = { {1,2,3}, {4,5,6}, {7,8,9} };
Matrice tab = { {1,2,3}, {4,5,6}, {7,8,9} };
```

%:::

Spécifiez et implantez une fonction pour chacune des questions suivantes :

1.  teste si un tableau carré est symétrique, *i.e.* si $T_{i, j} =
    T_{j, i}$ pour tous $i$ et $j$.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  $\clubsuit$ teste si une matrice est carrée et symétrique.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

3.  calcule la somme de deux matrices (supposées de mêmes
    dimensions). On vous rappelle que la somme de deux matrices $T$ et
    $T'$ est une matrice $C$, où $C_{i,j}=T_{i,j}+T'_{i,j}$ pour tous
    $i$ et $j$.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

4.  $\clubsuit$ calcule le produit de deux matrices. On vous rappelle
    que le produit de deux matrices $T$ et $T'$ est une matrice $C$,
    où $C_{i,j}=T_{i,1}T'_{1,j}+ T_{i,2}T'_{2,j} + \cdots$.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b17d2388a371d1fc44bd9b47598a7e3f", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\enlargethispage{1.2cm}`
{latexonly}`\vspace{-2ex}`

::::{admonition} Exercice 5 : Réservation de salle

Une salle de réunion peut être utilisée par les employés d'une
entreprise. La réservation se fait par plages d'une heure, de 8h00 à
19h00, chaque plage horaire commençant à l'heure pile; par exemple, il
y a une plage 9h00-10h00 mais il n'y a pas de plage 9h15-10h15.  Le
planning hebdomadaire de la salle est modélisé par un tableau de
booléens à deux dimensions: cinq lignes correspondant aux cinq jours
de la semaine, onze colonnes correspondant aux onze plages horaires de
la journée. La valeur pour un jour et une plage horaire donnée est
`true` si la salle est réservée sur cette plage horaire, et `false` si
elle est libre. On suppose pour la suite de l'exercice avoir accès au
tableau suivant :

{latexonly}`\small`
:::{literalinclude} occupation-salle.cpp
:start-after: BEGIN jours
:end-before: END jours
:::
{latexonly}`\normalsize`

1.  Écrivez une fonction qui construit un planning vide.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  Écrivez une fonction qui prend en paramètre le planning de
    réservation d'une salle et qui l'affiche de façon intelligible :

    1.  avec des phrases (par exemple : salle réservée le mardi de
        9h00 à 10h00).

        % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

    2.  $\clubsuit$ sous la forme d'une grille jour / plage horaire,
        où le mot «Réservée» figure dans les cases concernées.

        % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

3.  Écrivez une fonction, avec son test, qui calcule le taux
    d'occupation d'une salle, c'est à dire le nombre de plages
    réservées divisé par le nombre total de plages.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2bfff56e8285845ac146780067498481", "grade": true, "grade_id": "60", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\vspace{-3ex}`

::::{admonition} Exercice 6 : $\clubsuit$ Le jeu du démineur

L'objectif de cet exercice est de réaliser une version simple du jeu
du «démineur». Le but est de localiser des mines cachées dans un champ
virtuel avec pour seule indication le nombre de mines dans les zones
adjacentes.

Plus précisément, le champ consiste en une grille rectangulaire dont
chaque case contient ou non une mine. Au départ, le contenu de chaque
case est masqué. À chaque étape, l'utilisateur peut :

-   Démasquer le contenu d'une case; s'il y a une mine, "BOUM!", il a
    perdu. Sinon, le nombre de cases adjacentes (y compris en
    diagonale) contenant une mine est affiché.

-   Marquer une case, s'il pense qu'elle contient une mine.

L'utilisateur a gagné lorsqu'il a démasqué toutes les cases ne
contenant pas de mine.

Pour représenter en mémoire l'état interne de la grille, on utilisera
un tableau à deux dimensions de caractères (type
`vector<vector<char>>`). On utilisera les conventions suivantes pour
représenter l'état d'une case :

-   'm': présence d'une mine, 'M': présence d'une mine, case marquée;

-   'o': absence de mine, 'O': absence de mine, case marquée;

-   ' ': absence de mine, case démasquée.

Afin d'éviter d'avoir à écrire `vector<vector<char>>` à tout bout de
champ on utilise un raccourci :

:::{literalinclude} demineur.cpp
:start-after: BEGIN GrilleDemineur
:end-before: END GrilleDemineur
:::

1.  Implantez une fonction permettant de compter le nombre total de
    mines (marquées ou pas) dans une grille.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  Implantez une fonction permettant de tirer au hasard une grille
    initiale. On supposera fournie une fonction `bool boolAleatoire()`
    renvoyant un booléen tiré au hasard.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

3.  Implantez une fonction permettant de tester si une grille est gagnante.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

4.  Implantez une fonction permettant de compter le nombre de mines
    dans les cases adjacentes à une case donnée d'une grille.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

5.  Implantez une fonction permettant de renvoyer une chaîne de
    caractères représentant la grille telle que doit la voir le
    joueur.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE
::::
