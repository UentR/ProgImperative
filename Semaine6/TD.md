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

# TD 6 : Jeu de Yam's

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f2042a3306c8c7c32d8d57b1474c4aee", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 : Aparté: boucles imbriquées

Devinez l'affichage du fragment de programme mystère suivant :

:::{literalinclude} bouclesImbriquees-correction.cpp
:start-after: BEGIN bouclesImbriquees
:end-before: END bouclesImbriquees
:::

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

# Problème : le jeu de Yam's

+++

Le jeu de Yam's (ou Yahtzee) est un jeu de dés dont le but est
d'enchaîner les combinaisons à l'aide de cinq dés pour remporter un
maximum de points.

Nous ne nous intéressons ici qu'à une version simplifiée du Yam's et
chercherons à reconnaître les figures suivantes :

-   **brelan**: 3 dés identiques parmi les 5 dés
-   **yam's**: les 5 dés identiques.

Les figures permettent de marquer des points.  À chacune de ces
figures sont associés des bonus : **10 pour le brelan**, et **60 pour
le yam's**.  À cela, on ajoute **la somme des dés qui composent la
figure**.  Par exemple, les dés $\lbrace 2, 5, 3, 5, 5 \rbrace$
permettent de marquer 10 points de bonus (brelan) et $5 + 5 + 5 = 15$
points, soit au total 25 points.  Le but des prochains exercices est
de commencer l'implantation d'un jeu de Yam's basique.

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "36617e5ef6927107b147d4c7c243596d", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : Échauffement : trois fonctions utilitaires

1.  Spécifiez (documentation) et implantez (code) une fonction
    `afficheDes` qui affiche le contenu d'un tableau d'entiers,
    en affichant chaque entier du tableau suivi d'un espace.
    Ainsi l'appel `afficheDes({1,2,3,5,4})` devra entraîner
    l'affichage `1 2 3 5 4 `.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Spécifiez et implantez une fonction `chercheDansTableau`
    qui cherche l'emplacement d'un entier donné dans un tableau d'entiers.
    Si l'entier est présent dans le tableau, `chercheDansTableau`
    renvoie **l'indice d'une case du tableau le contenant**.
    Si l'entier n'est pas présent dans le tableau on renverra **-1**.
    Ainsi:
    -   l'appel `chercheDansTableau(3, {1,2,3})`
        devra renvoyer `2`,
    -   l'appel `chercheDansTableau(4, {1,2,3})`
        devra renvoyer `-1`, etc.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Spécifiez et implantez une fonction `nombreOccurrences`
    qui prend en paramètre un tableau d'entiers `t` et un
    entier `v`, et qui renvoie le nombre d'occurrences de
    `v` dans `t` (combien de fois il apparaît).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8fc95a68ccd6398eb7fe5de5f9b42d5d", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 3 :

1.  Observez les tests suivants et déduisez-en la spécification (rôle,
    entrées et sortie) de la fonction `compteDes`:

    :::{literalinclude} yams-correction.cpp
    :start-after: BEGIN compteDesTests
    :end-before: END compteDesTests
    :::

2.  Proposez une implantation de cette fonction.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2c3df57577ccaf81b5337879b7456348", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 : Yam's!

1.  Le yam's (cinq chiffres identiques) est la figure la plus facile à
    reconnaître.  Spécifiez et implantez une fonction
    `pointsFigureYams` qui, lorsqu'on lui donne en entrée un tableau
    contenant 5 entiers, renvoie les points obtenus (**somme des 5
    dés + 60**) s'il s'agit d'un yam's, **0** sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Complétez la liste de tests suivante avec au moins deux autres cas
    que vous jugez intéressants :

        CHECK( pointsFigureYams({4,4,4,4,4}) == 80 );
        CHECK( pointsFigureYams({1,1,1,1,1}) == 65 );

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Pour simplifier la fonction `pointsFigureYams`, on peut utiliser
    les fonctions `compteDes` et `chercheDansTableau`. Donnez une
    nouvelle implantation de `pointsFigureYams`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9ee77cc740014f12ab8281bece82fe9a", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : Brelan

1.  À l'image de la question 2 de l'exercice précédent, proposez des
    tests pour une fonction `pointsFigureBrelan` qui, lorsqu'on lui
    donne en entrée un tableau contenant 5 entiers, renvoie les points
    obtenus (**somme des 3 dés qui forment un brelan + 10**) s'il
    s'agit d'un brelan, **0** sinon.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Spécifiez et implantez cette fonction en vous aidant de la fonction
    `compteDes`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b4c6b7a3e41c9b2164ab79c3f4545c31", "grade": true, "grade_id": "60", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 6 : Le jeu

1.  Implantez une fonction `pointsFigure` qui, étant donné un tableau
    de cinq dés et le nom d'une figure parmi «brelan» et «yams»,
    renvoie le score associé en appelant respectivement la fonction
    `pointsFigureBrelan` ou la fonction `pointsFigureYams`.  Cette
    fonction doit renvoyer **0** si le nom de figure entré n'est pas
    valide.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Donner la spécification et l'implantation d'une fonction
    `lanceDes` qui renvoie un tableau contenant cinq entiers choisis
    aléatoirement entre 1 et 6.  Pour cela vous pouvez utiliser une
    fonction `int aleaInt(int a, int b)` qui étant donné deux entiers
    $a$ et $b$ renvoie un entier aléatoire $n$ tel que $a \leq n \leq
    b$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Complétez le squelette de code ci-dessous (3 endroits à modifier) pour :

    -   lancer les dés;
    -   afficher le tirage au joueur et lui demander d'entrer une
        figure **tant que** sa réponse est différente de «brelan»,
        «yams» et «exit»;
    -   si le joueur choisit «brelan» ou «yams», afficher les points
        qu'il marque.

	:::{literalinclude} yams-correction.cpp
	:start-after: BEGIN yamsMainTrous
	:end-before: END yamsMainTrous
	:::

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Une partie de Yam's consiste en de nombreux lancers successifs des
    dés.  Introduisez une boucle supplémentaire pour refléter ce
    comportement tant que le joueur ne tape pas «exit».  Ajoutez un
    calcul du score total de la partie, qui est la somme des scores de
    chaque lancer.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "60443c3c485cf42f4feaf95669f16377", "grade": true, "grade_id": "70", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 7 : $\clubsuit$ Relance

Dans le vrai jeu de Yam's, le joueur peut relancer jusqu'à trois fois
un ou plusieurs dés avant de choisir une figure.

1.  Ajoutez une fonction `vector<int> relance(int numDe, vector<int>
    des)` qui «relance» uniquement le dé numéro `numDe` choisi en
    premier argument et le remplace donc par un nouvel entier
    aléatoire entre 1 et 6.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Dans la boucle de jeu, ajoutez les instructions nécessaires pour
    que le joueur puisse choisir jusqu'à trois dés à relancer et les
    relancer.

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "77f8e09e9dd4bb24b1483c062ca5ac1d", "grade": true, "grade_id": "80", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 8 : $\clubsuit$ Scores

La partie de Yam's se termine lorsqu'un joueur a marqué des points
pour toutes les figures possibles.

1.  Ajoutez dans la fonction `main` un tableau de scores contenant une
    case pour chaque figure.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Lorsque le joueur choisit une figure, les points qu'il gagne
    doivent être stockés dans la partie correspondante du tableau.
    Une fois une case du tableau remplie, elle ne peut plus être
    modifiée.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  La partie se termine lorsque toutes les cases du tableau sont
    remplies. Le score du joueur correspond à la somme des cases du
    tableau.

	% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::
