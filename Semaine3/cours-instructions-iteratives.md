---
jupytext:
  notebook_metadata_filter: rise
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.2
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
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
---

+++ {"slideshow": {"slide_type": "slide"}}

# Les instructions itératives

<!--
**Prérequis:**
- [Affichages](TODO)
- Instructions conditionnelles
!-->

+++ {"slideshow": {"slide_type": "slide"}}

## Motivation : retour sur laby

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <laby/global_fr.hpp>
LABY("2a")
```

+++ {"slideshow": {"slide_type": "fragment"}}

Voilà une première proposition de solution. Est-elle correcte?
Est-elle satisfaisante?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
debut();
avance();
avance();
avance();
avance();
avance();
avance();
avance();
avance();
avance();
avance();
avance();
ouvre();
```

+++ {"slideshow": {"slide_type": "fragment"}}

Inconvénients:
- C'est *long*, *répétitif*;
- Ce n'est pas *général* : il faut compter le nombre de cases du
  couloir et écrire une solution différente selon le cas.

+++ {"slideshow": {"slide_type": "fragment"}}

En français, on dirait plutôt :
«Tant que c'est vide devant toi, avance!».

En C++, cela se traduit par :

+++ {"slideshow": {"slide_type": "fragment"}}

``` c++
debut();

while ( regarde() == Vide ) {
    avance();
}

ouvre();
```

+++ {"slideshow": {"slide_type": "slide"}}

## Répéter ou ne pas se répéter

Un ordinateur est capable d'effectuer des tâches répétitives très
rapidement et sans s'ennuyer.

Pas nous!

Aussi le principe suivant de programmation va revenir comme un
leitmotiv tout au long de ce cours :

> **«Ne te répètes pas».**

En anglais cela donne l'acronyme mnémotechnique
«**[DRY](https://en.wikipedia.org/wiki/Don't_repeat_yourself)**»:

> **Don't Repeat Yourself**

+++ {"slideshow": {"slide_type": "slide"}}

## Les **instructions itératives**

Dans cette feuille, nous abordons un premier outil pour ne pas se
répéter : les **instructions itératives**. Elles permettent de répéter
un certain nombre de fois l'exécution d'un bloc d'instructions sous
certaines conditions. De façon imagée, on appelle **boucle** cette
méthode permettant de répéter l'exécution d'un bloc d'instructions.

+++ {"slideshow": {"slide_type": "fragment"}}

Il y a trois cas typiques d'utilisation de boucles, illustrés par les
exemples suivants :

-   Tant que l'on est pas à la fin du film, afficher une image puis
    attendre 1/24ème de seconde;
    
-   Dans un jeu sur ordinateur, à la fin d'une partie, demander
    «voulez vous rejouer?» et si oui recommencer une nouvelle partie;

-   Afficher tous les nombres entre 1 et 1000.

Il serait tout à fait possible de n'avoir qu'une seule instruction
itérative pour couvrir tous les usages. L'expérience a cependant
montré qu'il était plus pratique, plus sûr et surtout plus
**expressif** d'avoir trois types d'instructions itératives distincts
dans un language de programmation :

+++ {"slideshow": {"slide_type": "fragment"}}

-   Boucles «while» : «tant que ... faire ...»;

-   Boucles «do ... while» : «Faire ... tant que ...»;

-   Boucles «for» : «Pour ... de ... à ... faire ...»;

Nous allons maintenant les voir tour à tour.

+++ {"slideshow": {"slide_type": "slide"}}

## La boucle while : «tant que ... répéter ...»

### La boucle while : syntaxe et sémantique

**Syntaxe :**

``` c++
    while ( condition ) {
        bloc d instructions;
    }
```

**Sémantique :**

1.  Évaluation de la condition
2.  Si sa valeur est «Vrai» :

    1.  Exécution du bloc d'instructions
    2.  On recommence en 1.

+++ {"slideshow": {"slide_type": "fragment"}}

### La boucle while : exemples

+++ {"slideshow": {"slide_type": "fragment"}}

Une petite digression : pour visualiser l'exécution d'une boucle, il
est pratique d'utiliser des affichages, pour lesquels nous avons
besoin d'une petite incantation magique :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
```

+++ {"slideshow": {"slide_type": "fragment"}}

Exécutez pas-à-pas le programme ci-dessous en appliquant la syntaxe et
sémantique de la boucle «while» :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;

while ( n <= 5 ) {
    cout << n << endl;    // Affiche la valeur de n
    n = n + 1;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

On a réalisé un programme permettant de compter de 1 à 5. On verra un
peu plus loin que ce n'est pas la meilleure instruction itérative pour
cet usage.

+++ {"slideshow": {"slide_type": "fragment"}}

**Exercice :**

Modifiez l'exemple ci-dessus pour :
- compter jusqu'à 10 (inclus);
- compter de -5 à 5 (inclus);
- compter de deux en deux de 0 à 10.

+++ {"slideshow": {"slide_type": "slide"}}

### Cas particulier : condition toujours fausse

*Si la valeur de la condition est fausse dès le départ, alors le bloc
d'instructions ne sera **jamais exécuté**!*

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;

while ( n <= 0 ) {
    cout << n << endl;    // Affiche la valeur de n
    n = n + 1;
}
```

+++ {"slideshow": {"slide_type": "slide"}}

### Cas particulier : condition toujours vraie

*Si la valeur de la condition est toujours vraie, alors le bloc
d'instructions sera **exécuté indéfiniment**!*

<span style="background-color:orange">⚠️ **L'exemple suivant ne va pas
s'arrêter! Il faudra redémarrer le noyau (menu Noyau)** ⚠️</span>

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;

while ( true ) {
    cout << n << endl;    // Affiche la valeur de n
    n = n + 1;
}
```

+++ {"slideshow": {"slide_type": "slide"}}

### Erreur classique : oublier l'incrémentation

+++ {"slideshow": {"slide_type": "fragment"}}

<span style="background-color:orange">⚠️ **L'exemple suivant ne va pas
s'arrêter! Il faudra redémarer le noyau (menu Noyau).** ⚠️</span>

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;

while ( n <= 5 ) {
    cout << n << endl;    // Affiche la valeur de n
}
```

+++ {"slideshow": {"slide_type": "slide"}}

### Erreur classique: fin de boucle

+++ {"slideshow": {"slide_type": "fragment"}}

Que vaut $n$ à la fin du programme suivant?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;

while ( n <= 5 ) {
    n = n + 1;
}

cout << n << endl;    // Affiche la valeur de n;
```

+++ {"slideshow": {"slide_type": "fragment"}}

**À retenir :**
- On sort de la boucle quand la condition vaut «Faux»; le compteur est
  donc «un cran trop loin».

+++ {"slideshow": {"slide_type": "slide"}}

## La boucle do ... while : «faire ... tant que ...»

+++ {"slideshow": {"slide_type": "fragment"}}

### La boucle do ... while : motivation

Dans un jeu sur ordinateur, à la fin d'une partie, on veut demander
«voulez vous rejouer?» et si oui recommencer une nouvelle partie.

Cela peut s'écrire avec une boucle `while`, mais ce n'est pas très
pratique car :

-   On veut jouer la partie *au moins une fois*
-   On veut tester la condition *après* la partie

Pour traiter ce cas d'usage classique de façon plus élégante, la
plupart des langages de programmation introduisent une variante de la
boucle «while» : la boucle **«do ... while»**; littéralement : «faire
... tant que ...»;

+++ {"slideshow": {"slide_type": "slide"}}

### La boucle do ... while : syntaxe et sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

**Syntaxe :**
``` c++
    do {
        bloc d instructions;
    } while ( condition );
```

+++ {"slideshow": {"slide_type": "fragment"}}

**Sémantique**
1.  Exécution du bloc d'instructions
2.  Évaluation de la condition
3.  Si sa valeur est «Vrai», on recommence en 1.

+++ {"slideshow": {"slide_type": "slide"}}

### La boucle do ... while : exemple

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
using namespace std;
std::string reponse;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
do {
    cout << "Une partie de jeu ..."          << endl;
    cout << "Voulez-vous rejouer (oui/non)?" << endl;
    cin >> reponse;                 // Lit la réponse
} while ( reponse == "oui" );
```

+++ {"slideshow": {"slide_type": "slide"}}

## La boucle for : «pour ... de ... à ... faire ...»; compteurs

+++ {"slideshow": {"slide_type": "fragment"}}

### La boucle for : motivation

+++ {"slideshow": {"slide_type": "fragment"}}

Revenons sur notre programme pour compter de 1 à 5 :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 1;
while ( n <= 5 ) {
    cout << n << endl;    // Affiche la valeur de n
    n = n + 1;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

Il suit un schéma classique de programme avec un *compteur* :

+++ {"slideshow": {"slide_type": "fragment"}}

``` c++
    initialisation;

    while ( condition ) {
        bloc d instructions;
        incrémentation;
    }
```

+++ {"slideshow": {"slide_type": "fragment"}}

- L'***initialisation*** (`n = 1`) détermine à partir de quelle valeur on compte;
- L'***incrémentation*** (`n = n + 1`) détermine par pas de combien on compte;
- La ***condition*** (`n <= 10`) détermine jusqu'à quelle valeur on compte.

+++ {"slideshow": {"slide_type": "fragment"}}

**Problème :**

La gestion du compteur est dispersée : le lecteur doit chercher à
trois endroits pour avoir toutes les informations sur le
compteur. L'incrémentation notamment se retrouve loin si le bloc
d'instructions est long. Nous avons vu les conséquences si on l'oublie
accidentellement!

+++ {"slideshow": {"slide_type": "fragment"}}

Pour pallier à cela, la plupart des langages de programmation
introduisent la boucle «**for**» : «pour ... de ... à ... faire
...». Voici ce que cela donne sur notre exemple :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
for ( int n = 1; n <= 5; n = n + 1 ) {
    cout << n << endl;    // Affiche la valeur de n
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

**Exercice :**

Comparer les deux programmes ci-dessus pour compter de $1$ à $5$; retrouver les différents éléments : initialisation, incrémentation, condition, instruction.

+++ {"slideshow": {"slide_type": "fragment"}}

**À retenir :**
- Avec la boucle «for», toute la gestion du compteur est centralisée sur une seule ligne.
- La boucle «for» est strictement équivalent à while, mais elle **exprime une intention** : on utilise un compteur.

+++ {"slideshow": {"slide_type": "slide"}}

## La boucle for : syntaxe et sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

**Syntaxe :**

``` c++
    for ( initialisation ; condition ; incrémentation ) {
        bloc d instructions;
    }
```

+++ {"slideshow": {"slide_type": "fragment"}}

**Sémantique :**

1.  Exécution de l'instruction d'initialisation

2.  Évaluation de la condition

3.  Si sa valeur est «Vrai» :

    1.  Exécution du bloc d'instructions
    2.  Exécution de l'instruction d'incrémentation
    3.  On recommence en 2.

+++ {"slideshow": {"slide_type": "slide"}}

### La boucle for : exemples

+++ {"slideshow": {"slide_type": "fragment"}}

Notre exemple ci-dessus peut s'écrire de façon plus compacte :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
for ( int n = 1 ; n <= 5 ; n++ ) {
    cout << n << endl;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

-   La variable `n` est locale à la boucle (on y reviendra)

-   `n++` est un raccourci pour `n = n + 1`

+++ {"slideshow": {"slide_type": "slide"}}

## Compteurs et accumulateurs

+++ {"slideshow": {"slide_type": "fragment"}}

On souhaite calculer la factorielle de $7$ :
$7!=1 \cdot 2 \cdot 3 \cdots 7$

+++ {"slideshow": {"slide_type": "fragment"}}

Cela peut s'écrire de la façon suivante :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int resultat = 1;

resultat = resultat * 2;
resultat = resultat * 3;
resultat = resultat * 4;
resultat = resultat * 5;
resultat = resultat * 6;
resultat = resultat * 7;

resultat
```

+++ {"slideshow": {"slide_type": "fragment"}}

La variable `resultat` sert d'***accumulateur*** : on y
accumule les entiers $1, 2, 3, ...$ par produit et elle vaut
successivement :
- $1$
- $1\cdot2$
- $1\cdot2\cdot3$
- ...
- $1\cdot2\cdot3\cdot4\cdot5\cdot6\cdot7$

+++ {"slideshow": {"slide_type": "fragment"}}

**Problèmes :**

-   Ce code [sent mauvais](https://fr.wikipedia.org/wiki/Code_smell) :
    il y a beaucoup de répétitions!

-   Et si on veut calculer $10!$ ou $100!$ ?

+++ {"slideshow": {"slide_type": "fragment"}}

Des instructions répétées? Cela suggère une boucle.
On compte de 1 à 7? C'est une mission pour la boucle «for»!

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int n = 10;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int resultat = 1;
for ( int i = 2; i <= n; i = i + 1) {
     resultat = resultat * i;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
resultat
```

+++ {"slideshow": {"slide_type": "fragment"}}

Exécutez pas-à-pas le code ci-dessus pour $n=3$; pour $n=0$.

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

Nous avons vu les **instructions itératives** -- les **boucles** --
pour répéter des instructions :
- la boucle «while»
- la boucle «do while»
- la boucle «for»

Elles sont toutes les trois strictement équivalentes. Mais chacune est
mieux adaptée à un type d'utilisation, et exprime une **intention**.

+++ {"slideshow": {"slide_type": "fragment"}}

Plus tard nous verrons une quatrième boucle, la boucle «foreach»,
lorsque nous voudrons parcourir les éléments d'une collection.

+++ {"slideshow": {"slide_type": "fragment"}}

Nous avons aussi vu deux techniques classiques de boucles :

-   L'utilisation d'un ***compteur*** : `k`
    qui parcours les valeurs de ... à ... par pas de ...

-   L'utilisation d'un ***accumulateur*** : `resultat`
    qui accumule progressivement des valeurs par produit, somme, ...

<!-- temporary workaround jupytext bug # !-->

