---
jupytext:
  notebook_metadata_filter: rise, semantic
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++14
  language: C++14
  name: xcpp14
rise:
  auto_select: first
  autolaunch: false
  centered: false
  controls: false
  enable_chalkboard: true
  height: 100%
  margin: 0
  maxScale: 1
  minScale: 1
  scroll: true
  slideNumber: true
  start_slideshow_at: selected
  transition: none
  width: 90%
semantic:
  use_module: info-111
---

+++ {"slideshow": {"slide_type": "slide"}}

# Premiers éléments de programmation impérative

+++ {"slideshow": {"slide_type": "slide"}}

## Prélude

+++ {"slideshow": {"slide_type": "slide"}}

### Résumé des épisodes précédents ...

+++ {"slideshow": {"slide_type": "fragment"}}

-   Info 111: modalités et infrastructure

+++ {"slideshow": {"slide_type": "fragment"}}

-   Informatique: usage, technologie, science

+++ {"slideshow": {"slide_type": "fragment"}}

-   Objectif d'Info 111: initier à la science via la technologie

+++ {"slideshow": {"slide_type": "fragment"}}

-   Concrètement: bases de la programmation impérative + ...

+++ {"slideshow": {"slide_type": "slide"}}

## Rappel

:::{prf:definition} Programmes

***Programme*** : séquence d'instructions qui
spécifie étape par étape les opérations à effectuer pour obtenir à
partir des ***entrées*** un résultat (la
***sortie***).

:::

+++ {"slideshow": {"slide_type": "fragment"}}

::::::{prf:example}
:::::{grid}
:gutter: 0

:::{grid-item-card}
```
debut()
droite()
avance()
prend()
gauche()
avance()
pose()
droite()
avance()
gauche()
avance()
avance()
droite()
ouvre()
```

:::

::::{grid-item-card}

:::{image} media/laby0.png
:height: 20ex
:align: center
:::

::::
:::::
::::::

+++ {"slideshow": {"slide_type": "slide"}}

## Comment rompre la monotonie?

+++ {"slideshow": {"slide_type": "fragment"}}

-   Faire des calculs : *[expressions](expression) et [variables](variable)*

+++ {"slideshow": {"slide_type": "fragment"}}

-   Découper en petits programmes : les *[fonctions](fonction_informel)*

+++ {"slideshow": {"slide_type": "fragment"}}

-   S'adapter au contexte : les *[instructions conditionnelles](instruction_conditionnelle)*

+++ {"slideshow": {"slide_type": "fragment"}}

-   Répéter : les *[instructions itératives](instruction_iterative)* (boucles)

+++ {"slideshow": {"slide_type": "slide"}}

## Expressions

+++ {"slideshow": {"slide_type": "fragment"}}

(expression)=
:::{prf:definition} Expressions

***Expression*** : combinaison de *valeurs* par
des *opérations* donnant une nouvelle *valeur*

:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
L'expression `3 * (1 + 3) + (1 + 4) * (2 + 4)` vaut `42`
:::

+++ {"slideshow": {"slide_type": "fragment"}}

(operations_sur_les_entiers)=
:::{admonition} Opérations sur les entiers

| Opération                    | Exemple  | Résultat |
|------------------------------|----------|----------|
| opposé                       | `-(-5)`  | 5        |
| addition                     | `17 + 5` | 22       |
| soustraction                 | `17 - 5` | 12       |
| multiplication               | `17 * 5` | 85       |
| division entière             | `17 / 5` | 3        |
| reste de la division entière | `17 % 5` | 2        |

:::

+++ {"slideshow": {"slide_type": "slide"}}

:::{tip} Aparté : *syntaxe*, *sémantique*, *algorithme*

(syntaxe_informel)=
-   ***Syntaxe*** : comment on l'écrit
(semantique_informel)=
-   ***Sémantique*** : ce que cela fait
(algorithme_informel)=
-   ***Algorithme*** : comment c'est fait
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
-   Syntaxe : 17 / 5
-   Sémantique : calcule la division entière de 17 par 5
-   Algorithme : division euclidienne
:::

+++ {"slideshow": {"slide_type": "slide"}}

### Expressions booléennes

+++ {"slideshow": {"slide_type": "fragment"}}

(expression_booleenne)=
:::{prf:definition} Expressions booléennes (conditions)

Une ***expression booléenne*** est une
[expression](expression) dont la valeur est «vrai» ou «faux» (type :
[bool](bool)).

(condition)=
Une [expression booléenne](<expression_booleenne>) est aussi
appelée une ***condition***.

:::

+++ {"slideshow": {"slide_type": "fragment"}}

**Exemples :**

```{code-cell}
---
slideshow:
  slide_type: fragment
---
true
```

```{code-cell}
---
slideshow:
  slide_type: null
---
false
```

+++ {"slideshow": {"slide_type": null}}

- `regarde() == Vide`
- `x > 3.14`
- `2 <= n  and  n <= 5`

+++ {"slideshow": {"slide_type": "fragment"}}

(operations_booleennes_usuelles)=
:::{admonition} Opérations booléennes usuelles

| Opération             | Exemple             | Résultat   |
| --------------------- | :-----------------: | ---------- |
| comparaison           | `3 <= 5`            | `true`     |
| comparaison stricte   | `3 < 5`             | `true`     |
| comparaison stricte   | `3 > 5`             | `false`    |
| égalité               | `3 == 5`            | `false`    |
| inégalité             | `3 != 5`            | `true`     |
| négation              | `not 3 <= 5`        | `false`    |
| et                    | `3 < 5 and 3 > 5`   | `false`    |
| ou                    | `3 < 5 or  3 > 5`   | `true`     |

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Variables

+++ {"slideshow": {"slide_type": "fragment"}}

(exemple:calcul_energie_cinetique)=
:::{prf:example}
:for: expression
:good_to_have: cinetic_energy
:motivates: variable
:name: exemple_variables_énergie_cinétique

Calculer l'[énergie cinétique](<energie_cinetique>) $\frac12 m
v^2$ d'un objet de masse $14,5$ kg selon qu'il aille à $1$, $10$,
$100$, ou $1000$ m/s.
:::

```{code-cell}
---
slideshow:
  slide_type: fragment
---
1./2 * 14.5 * 1 * 1
```

```{code-cell}
1./2 * 14.5 * 10 * 10
```

```{code-cell}
1./2 * 14.5 * 100 * 100
```

```{code-cell}
1./2 * 14.5 * 1000 * 1000 
```

+++ {"slideshow": {"slide_type": "fragment"}}

Qu'est-ce qui n'est pas satisfaisant?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
double v;
double m;
```

```{code-cell}
v = 1000;
m = 14.5;
```

```{code-cell}
1./2 * m * v * v
```

+++ {"slideshow": {"slide_type": "slide"}}

(variable)=
:::{prf:definition} Variables

Une ***variable*** est un espace de stockage *nommé* où le
programme peut mémoriser une donnée

:::

+++ {"slideshow": {"slide_type": "fragment"}}

Le nom de la variable est choisi par le programmeur

-   Objectif : stocker des informations durant l'exécution d'un programme

-   Analogie : utiliser un récipient pour stocker des ingrédients en
    cuisine :

    -   Verser le sucre dans un *saladier*
    -   Ajouter la farine dans le *saladier*
    -   Laisser reposer
    -   Verser le contenu du *saladier* dans ...

+++ {"slideshow": {"slide_type": "slide"}}

:::{admonition} À retenir

En C++, une variable possède quatre propriétés :

-   un **nom** (ou **identificateur**)
-   une **adresse**  
    à préciser la semaine prochaine
-   un **type**
-   une **valeur**

La valeur peut changer en cours d'exécution du programme
(d'où le nom de variable)

:::

+++ {"slideshow": {"slide_type": "slide"}}

### Notion de type

Les variables peuvent contenir toutes sortes de données différentes :

-   nombres entiers, réels, booléens, ...
-   textes
-   relevés de notes, images, musiques, ...

+++ {"slideshow": {"slide_type": "fragment"}}

(type_informel)=
:::{prf:definition} Types

-   Une variable C++ ne peut contenir qu'une seule sorte de données.
-   On appelle cette sorte le ***type*** de la variable.
-   On dit que C++ est un langage typé statiquement.

:::

+++ {"slideshow": {"slide_type": "slide"}}

:::{prf:definition} Types de base

Les types de base en C++ sont :

(entier)=
-   Les ***entiers*** (mots clés `int`, `long int`)  
    Exemples : 1, 42, -32765
(reel)=
-   les ***réels*** (mots clés `float`, `double`)  
    Exemples : 10.43, 1.0324432e22
(caractere)=
-   les ***caractères*** (mot clé `char`) <a name="char"/>   
    Exemples : 'a', 'b', ' ', ']'
(chaine_de_caractere)=
-   les ***chaînes de caractères*** (mot clé `string`)  
    Exemples : "bonjour", "Alice aime Bob"
(booleen)=
-   les ***booléens*** (mot clé `bool`)  
    Exemples : `true` (vrai), `false` (faux)

(type_ordinal)=
Les entiers, les caractères et les booléens forment les
***types ordinaux***.

:::

+++ {"slideshow": {"slide_type": "slide"}}

(declaration)=
### La déclaration des variables

Pour chaque variable, il faut donner au programme son nom et son type.
On dit que l'on ***déclare*** la variable.

:::{admonition} Syntaxe : déclaration des variables

``` c++
type nomvariable;
type nomvariable1, nomvariable2, ...;
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
```
int x, y, monEntier;
double f, g;
bool b;
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

**Note :** en C++ (compilé) on ne peut pas redéclarer une variable avec le même nom!

+++ {"slideshow": {"slide_type": "slide"}}

(affectation)=
### L'affectation

:::{admonition} Syntaxe
```
identificateur = expression;
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
```
x = 3 + 5;
```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique
-   Calcul (ou évaluation) de la valeur de l'expression
-   Stockage de cette valeur dans la case mémoire associée à cette
    variable.
-   *La variable et l'expression doivent être de même type!*
:::

+++ {"slideshow": {"slide_type": "slide"}}

#### Exemples d'affectations

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x, y;
```

+++ {"slideshow": {"slide_type": "fragment"}}

On affecte la valeur 1 à la variable `x` :

```{code-cell}
x = 1;
```

+++ {"slideshow": {"slide_type": "fragment"}}

On affecte la valeur 3 à la variable `y` :

```{code-cell}
y = 3;
```

+++ {"slideshow": {"slide_type": "fragment"}}

Valeurs des variables après l'affectation :

```{code-cell}
x
```

```{code-cell}
y
```

+++ {"slideshow": {"slide_type": "slide"}}

**Exemple :** affecter la valeur d'une variable à une autre variable

```{code-cell}
x = y;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
y
```

+++ {"slideshow": {"slide_type": "fragment"}}

**Note**
-   Affectation `x = y` : copie de la valeur

+++ {"slideshow": {"slide_type": "fragment"}}

-   `y` garde sa valeur
-   L'ancienne valeur de `x` est perdue!

+++ {"slideshow": {"slide_type": "fragment"}}

-   Différent de transférer un ingrédient d'un récipient à l'autre

+++ {"slideshow": {"slide_type": "slide"}}

**Exemple : incrémentation**

+++ {"slideshow": {"slide_type": "fragment"}}

int x;
x = 1;

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x = x + 1;
x
```

+++ {"slideshow": {"slide_type": "fragment"}}

Variantes :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x -= 2;
x
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x++;
x
```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Quelques raccourcis pratiques

| Syntaxe  | Sémantique             | Syntaxe équivalente |
| -------  | ----------             | ---                    |
| `x += a` | Incrémenter `x` de `a` | `x = x + a`         |
| `x -= a` | Décrémenter `x` de `a` | `x = x - a`         |
| `x++`    | Incrémenter `x`        | `x = x + 1`         |
| `x--`    | Décrémenter `x`        | `x = x - 1`         |

:::

+++ {"slideshow": {"slide_type": "slide"}}

:::{warning} Affectation et égalité : deux concepts différents

- **L'affectation `x = 5` :**

  Une instruction modifiant l'état de la mémoire.

- **Le test d'égalité `x == 5` :**

  Une expression booléenne (valeur vrai ou faux) :

  « `x` est égal à `5`? »

  Autrement dit : est-ce que la valeur contenue dans la variable `x` est `5`?

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Fonctions

+++ {"slideshow": {"slide_type": "fragment"}}

Retour sur notre [exemple](exemple:calcul_energie_cinetique) :

Calculer l'énergie cinétique $\frac12 m v^2$ d'un objet de masse $14,5$
kg selon qu'il aille à $1$, $10$, $100$, ou $1000$ km/h.

Voilà comment nous avions procédé :

```{code-cell}
m = 14.5;
v = 100;
1./2 * m * v * v
```

+++ {"slideshow": {"slide_type": "fragment"}}

Comment éviter de retaper chaque fois la formule?

+++ {"slideshow": {"slide_type": "slide"}}

### Fonctions

(fonction_informel)=
:::{prf:definition} Fonctions

Informellement, une ***fonction*** est un
petit [programme](programme_informel) :
-   Entrées
-   Traitement
-   Sortie

:::

+++ {"slideshow": {"slide_type": "fragment"}}

**Exemple :**

```{code-cell}
---
slideshow:
  slide_type: null
---
double energie_cinetique(double m, double v) {
    return 1./2 * m * v * v;
}
```

```{code-cell}
---
slideshow:
  slide_type: null
---
energie_cinetique(14.5, 10)
```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Entrées : la masse et la vitesse (des nombres réels)
-   Sortie : l'énergie cinétique (un nombre réel)
-   Traitement : `1./2 * m * v * v`

+++ {"slideshow": {"slide_type": "slide"}}

#### Autres exemples de fonctions

:::{prf:example}
:for: function, while_loop

Chou-Chèvre-Loup :
``` c++ 
void transporter(... T) {
    charger(T);
    traverser();
    decharger(T);
}
```

Laby :
``` c++
void avance_tant_que_tu_peux() {
    while ( regarde() == Vide ) {
        avance();
    }
}
```
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Structures de contrôle

+++ {"slideshow": {"slide_type": "slide"}}

### Rôle des structures de contrôle

+++ {"slideshow": {"slide_type": "fragment"}}

#### Rappel

Les instructions sont exécutées de manière séquentielle (les unes après
les autres), dans l'ordre du programme.

**Exemple :**

:::::{grid}
:gutter: 0

:::{grid-item-card}
```
debut()
droite()
avance()
prend()
gauche()
avance()
pose()
droite()
avance()
gauche()
avance()
avance()
droite()
ouvre()
```

:::

::::{grid-item-card}

:::{image} media/laby0.png
:height: 20ex
:align: center
:::

::::
:::::

+++ {"slideshow": {"slide_type": "fragment"}}

#### Le problème

On a souvent besoin de *rompre l'exécution séquentielle* :

+++ {"slideshow": {"slide_type": "fragment"}}

-   Des instructions différentes selon le contexte :

    :::{image} media/laby3a.png
    :height: 5ex
    :align: center
    :alt: Le labyrinthe 3a avec petite et grande toile
    :::

+++ {"slideshow": {"slide_type": "fragment"}}

-   Des instructions répétées :

    :::{image} media/laby2a.png
    :height: 5ex
    :align: center
    :alt: Un labyrinthe tout en longueur
    :::

+++ {"slideshow": {"slide_type": "fragment"}}

Nous avons besoin des **structures de contrôle**.

+++ {"slideshow": {"slide_type": "slide"}}

(instruction_conditionnelle)=
### Instructions conditionnelles

+++ {"slideshow": {"slide_type": "fragment"}}

En fonction d'une **[condition](condition)**, on va exécuter ou non un
**[bloc d'instructions](bloc_d_instruction)**.

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <laby/global_fr.hpp>
LABY("3a")
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
debut();
droite();
avance();
gauche();
```

+++ {"slideshow": {"slide_type": "fragment"}}

Solution complète :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
LABY("3a")
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
debut()
droite();
avance();
gauche();

if ( regarde() == Toile ) {
    gauche();
    avance();
    avance();
    droite();
    avance();
    avance();
    droite();
    avance();
    gauche();
} else {
    avance();
    avance();
    gauche();
    avance();
    droite();
}
ouvre();
```

+++ {"slideshow": {"slide_type": "slide"}}

(bloc_d_instruction)=
:::{prf:definition} Blocs d'instructions

Un ***bloc d'instructions*** est une suite d'instructions à
exécuter successivement. Il est décrit par la syntaxe suivante :

    {
        instruction 1;
        instruction 2;
        ...
        instruction n;
    }

Une instruction toute seule est aussi considérée comme un bloc d'instructions.

:::

+++ {"slideshow": {"slide_type": "slide"}}

#### Instruction conditionnelle simple : «si ... alors ...»

:::{admonition} Syntaxe :

``` c++
if ( condition ) {
    bloc d instructions;
}
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

1.  Évaluation de la condition
2.  Si sa valeur est vraie, exécution du bloc d'instructions
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
```c++
if ( regarde() == Toile ) {     // Au secours, fuyons!
    gauche();
    gauche();
}
```
```c++
if ( x >= 0 ) gauche();
```
:::

+++ {"slideshow": {"slide_type": "slide"}}

#### Instruction conditionnelle : «si ... alors ... sinon ...»

:::{admonition} Syntaxe
```c++
if ( condition ) {
    bloc d instructions 1;
} else {
    bloc d instructions 2;
}
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique
1.  Évaluation de la condition
2.  Si sa valeur est «Vrai», exécution du bloc d'instructions 1
3.  Si sa valeur est «Faux», exécution du bloc d'instructions 2
:::

+++ {"slideshow": {"slide_type": "fragment"}}

#### Exemples d'instruction alternative

:::{prf:example}
```c++
if ( regarde() == Toile ) {     // Au secours, fuyons!
    gauche();
    gauche();
} else {                        // Tout va bien
    avance();
}
```
:::

+++ {"slideshow": {"slide_type": "slide"}}

#### Exemples d'instruction alternative (2)

**Exemple :** Calcul du maximum et du minimum de `x` et `y`

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 3, y = 5;              // Les entrées
int maximum, minimum;          // Les sorties

if ( x > y ) {
    maximum = x;
    minimum = y;
} else {
    maximum = y;
    minimum = x;
}
```

```{code-cell}
minimum
```

```{code-cell}
maximum
```

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

:::{admonition} Un aperçu de premiers éléments de programmation :

-   [Expressions](expression), valeurs et [types](type_informel)
-   [Variables](variable) (*affectation ≠ égalité!*)
-   [Fonctions](fonction_informel)
-   [Instructions conditionnelles](instruction_conditionnelle) (`if`)
:::

+++ {"slideshow": {"slide_type": "fragment"}}

On reviendra dessus!

