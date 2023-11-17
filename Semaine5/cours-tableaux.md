---
jupytext:
  notebook_metadata_filter: rise
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.2
kernelspec:
  display_name: C++11
  language: C++11
  name: xcpp11
rise:
  auto_select: first
  autolaunch: true
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

# Tableaux (introduction)

+++ {"slideshow": {"slide_type": "fragment"}}

## Résumé des épisodes précédents

Pour le moment nous avons vu :

-   Expressions : `3 * (4+5)` `1 < x and x < 5 or y == 3`
-   Variables, types, affectation : ` variable = expression`
-   Instruction conditionnelle : `if`
-   Instructions itératives : `while`, `do ... while`, `for`
-   Fonctions, procédures

+++ {"slideshow": {"slide_type": "fragment"}}

### Pourquoi aller plus loin?

+++ {"slideshow": {"slide_type": "fragment"}}

**<div style="color:red; text-align:center;">Pour passer à l'échelle!</div>**

+++ {"slideshow": {"slide_type": "fragment"}}

**<div style="color:red; text-align:center">Manipulation de collections de données</div>**

+++ {"slideshow": {"slide_type": "slide"}}

## Les tableaux

+++ {"slideshow": {"slide_type": "slide"}}

### Exemple : Mini annuaire

```{code-cell}

```

+++ {"slideshow": {"slide_type": "notes"}}

On souhaite implanter un mini annuaire. Pour cela, on
va stocker, pour chaque personne, un nom et un numéro de
téléphone. Nous utiliserons pour chacun d'entre eux une
chaîne de caractères (`string`). Noter que le numéro n'est
pas un nombre : il peut contenir des espaces, etc.

Commençons par les incantations magiques usuelles :

```{code-cell}
---
slideshow:
  slide_type: notes
---
#include <iostream>
using namespace std;
```

+++ {"slideshow": {"slide_type": "notes"}}

Dans un premier temps, notre annuaire aura trois personnes (les noms
et numéros sont factices!) :

```{code-cell}
---
slideshow:
  slide_type: notes
---
string nom1 = "Jeanne";
string telephone1 = "04 23 23 54 56";
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
string nom2 = "Franck";
string telephone2 = "03 23 42 34 26";
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
string nom3 = "Marie";
string telephone3 = "06 52 95 56 06";
```

+++ {"slideshow": {"slide_type": "notes"}}

Écrivons un petit programme pour afficher le contenu de l'annuaire :

```{code-cell}
---
slideshow:
  slide_type: notes
---
cout << nom1 << " " << telephone1 << endl;
cout << nom2 << " " << telephone2 << endl;
cout << nom3 << " " << telephone3 << endl;
```

+++ {"slideshow": {"slide_type": "notes"}}

Est-ce satisfaisant comme manière de procéder?

Non : ce code est très redondant. Imaginez s'il y avait
100 personnes dans l'annuaire. La ligne d'affichage
serait répétée 100 fois.

+++ {"slideshow": {"slide_type": "notes"}}

Répéter 3 fois (quasiment) la même ligne cela s'appelle une boucle `for`.
Essayons :

```{code-cell}
---
slideshow:
  slide_type: notes
---
for ( int i=1; i <= 3; i++ ) {
    cout << nom1 << " " << telephone1 << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Ce n'est pas encore ce que l'on veut. En effet, pour $i=1$, on
voudrait utiliser la variable `nom1`, pour $i=2$ la variable
`nom2`, etc. Mais ce sont des variables distinctes!

+++ {"slideshow": {"slide_type": "notes"}}

La solution va être de regrouper les trois variables `nom1`, `nom2`, `nom3`
contenant chacune un nom en une seule variable contenant les trois noms.
Pour cela, on va utiliser un **tableau**. En C++, on utilisera
le type `vector<string>` pour représenter un tableau de chaînes de caractères.
Il faut au préalable charger la bibliothèque `vector` :

```{code-cell}
---
slideshow:
  slide_type: notes
---
#include <vector>
using namespace std;
```

+++ {"slideshow": {"slide_type": "notes"}}

On construit un tableau pour les trois noms et un pour les trois numéros de téléphone :

```{code-cell}
---
slideshow:
  slide_type: notes
---
vector<string> noms;
noms = vector<string>(3);

vector<string> telephones;
telephones = vector<string>(3);
```

+++ {"slideshow": {"slide_type": "notes"}}

`noms` et `telephones` contiennent chacun trois chaînes vide
(ne vous préocuppez pas du type affiché en deuxième ligne;
c'est essentiellement `vector<string>`.

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
telephones
```

+++ {"slideshow": {"slide_type": "notes"}}

Commençons à remplir le tableau. Notez que, pour accéder au i-ème nom, on
utilise la syntaxe `noms[i]`.

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms[1] = "Jeanne";
telephones[1] = "04 23 23 54 56";
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms[2] = "Franck";
telephones[2] = "03 23 42 34 26";
```

+++ {"slideshow": {"slide_type": "notes"}}

Voyons ce que cela donne :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms
```

+++ {"slideshow": {"slide_type": "notes"}}

Oups! Que s'est-il passé????

+++ {"slideshow": {"slide_type": "notes"}}

Explication : en C++, comme dans la plupart des langages, les tableaux
commencent à 0. Ainsi, le premier nom est `noms[0]`, le deuxième `noms[1]`,
etc.

+++ {"slideshow": {"slide_type": "notes"}}

Reprenons :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms[0] = "Jeanne";
telephones[0] = "04 23 23 54 56";

noms[1] = "Franck";
telephones[1] = "03 23 42 34 26";

noms[2] = "Marie";
telephones[2] = "06 52 95 56 06";
```

+++ {"slideshow": {"slide_type": "notes"}}

Maintenant, nos tableaux sont remplis correctement :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
telephones
```

+++ {"slideshow": {"slide_type": "notes"}}

Nous pouvons enfin écrire notre boucle `for` :

```{code-cell}
---
slideshow:
  slide_type: notes
---
#include <iostream>
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
for ( int i=0; i < 3; i++ ) {
    cout << noms[i] << " " << telephones[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Notez bien que nous avons fait varier `i` de `0` à `2`!

Si vous êtes aventureux, regardez ce qui se passe si on fait varier
`i` de `1` à `3`. Soyez prêt à redémarrer votre noyau!

+++ {"slideshow": {"slide_type": "notes"}}

:::{hint} Nommage : `telephone` ou `telephones`?

Il pourrait être tentant de nommer notre variable `telephone`, pour
que `telephone[i]` ressemble à `telephonei`. Mais ce n'est pas la
bonne convention. Le nom d'une variable doit refléter ce qu'elle
contient. Ici c'est plusieurs numéros de téléphones. Donc
`telephones`.
:::

+++ {"slideshow": {"slide_type": "notes"}}

Un annuaire avec seulement trois personnes, c'est un peu triste.
Ajoutons une quatrième personne :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms[3] = "Joël";
telephones[3] = "07 23 63 92 38"
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms
```

+++ {"slideshow": {"slide_type": "notes"}}

Oups! Que s'est-il passé? On a essayé de rajouter un quatrième
nom dans un tableau prévu pour trois noms, et ça a tout planté.

+++ {"slideshow": {"slide_type": "notes"}}

Redémarrez votre noyau.

+++ {"slideshow": {"slide_type": "notes"}}

Reprenons à zéro : incantations magiques, création de tableau de
taille 4, remplissage :

```{code-cell}
---
slideshow:
  slide_type: notes
---
#include<vector>
#include<iostream>
using namespace std;

vector<string> noms;
noms = vector<string>(4);
vector<string> telephones;
telephones = vector<string>(4);

noms[0] = "Jeanne";
telephones[0] = "04 23 23 54 56";
noms[1] = "Franck";
telephones[1] = "03 23 42 34 26";
noms[2] = "Marie";
telephones[2] = "06 52 95 56 06";
noms[3] = "Joël";
telephones[3] = "07 23 63 92 38";
```

+++ {"slideshow": {"slide_type": "notes"}}

Réutilisons notre programme pour afficher l'annuaire :

```{code-cell}
---
slideshow:
  slide_type: notes
---
for ( int i=0; i < 3; i++ ) {
    cout << noms[i] << " " << telephones[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Oups! Quel est le problème?

+++ {"slideshow": {"slide_type": "notes"}}

Forcément, on ne peut pas réutiliser exactement le même
programme. Il faut changer le `3` en `4` :

```{code-cell}
---
slideshow:
  slide_type: notes
---
for ( int i=0; i < 4; i++ ) {
    cout << noms[i] << " " << telephones[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Ce n'est pas très pratique de devoir à chaque fois ajuster notre programme.
Imaginez le vendeur de téléphone s'il devait changer son programme chaque
fois qu'il rajoute un client!

+++ {"slideshow": {"slide_type": "notes"}}

Pour éviter cela, nous allons exploiter le fait qu'un tableau connaît
sa taille :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms.size()
```

+++ {"slideshow": {"slide_type": "notes"}}

Nous pouvons maintenant écrire notre boucle de sorte qu'elle
fonctionne pour un annuaire de taille quelconque :

```{code-cell}
---
slideshow:
  slide_type: notes
---
for ( int i=0; i < noms.size(); i++ ) {
    cout << noms[i] << " " << telephones[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Ce n'est pas encore satisfaisant de devoir reconstruire l'annuaire
chaque fois que l'on veut rajouter une personne. Imaginez si vous
deviez retaper tous vos contacts sur votre téléphone chaque fois que
vous souhaitez en rajouter un.

Pour pallier cela, nous allons voir une dernière opération sur
les tableaux: `push_back`; littéralement, rajouter à la fin :

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms.push_back("Zoé");
telephones.push_back("04 12 43 93 27");
```

```{code-cell}
---
slideshow:
  slide_type: notes
---
noms
```

+++ {"slideshow": {"slide_type": "notes"}}

Observez ce qui se passe si vous exécutez à nouveau les deux cellules précédentes.

+++ {"slideshow": {"slide_type": "notes"}}

Tout ceci n'est pas encore parfait : on mélange
encore beaucoup **données** et **code**. Imaginez
si chaque propriétaire de téléphone portable
devait réécrire le code pour afficher le contenu
de son annuaire.

Un peu plus tard aujourd'hui, nous verrons comment écrire le code
une bonne fois pour toutes dans une fonction réutilisable.
Dans deux semaines, nous verrons comment regrouper toute l'information
dans un tableau unique, où le nom et le numéro de téléphone sont
proches l'un de l'autre.
Plus tard dans le semestre, nous verrons comment
utiliser les **fichiers** pour stocker les données
complètement séparément.

+++ {"slideshow": {"slide_type": "slide"}}

### Les tableaux

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition}

Un ***tableau*** est une ***valeur composite*** ***homogène***  
C'est-à-dire qu'elle est formée de plusieurs valeurs du même type

:::

+++ {"slideshow": {"slide_type": "fragment"}}

-   Une valeur (ou ***élément***) d'un tableau $t$ est désignée par son
    ***indice*** $i$ dans le tableau  
    on la note $t[i]$

+++ {"slideshow": {"slide_type": "fragment"}}

-   En C++ : cet indice est un entier *entre $0$ et $\ell-1$*,  
    où $\ell$ est le nombre d'éléments du tableau

+++ {"slideshow": {"slide_type": "fragment"}}

**Exemple :**

-   Voici un tableau de six entiers :
    $\begin{array}{|c|c|c|c|c|c|c|c|c|c|}
       \hline
       1 & 4 & 1 & 5 & 9 & 2\\\hline
     \end{array}$

-   Avec cet exemple, `t[0]` vaut 1, `t[1]` vaut 4, `t[2]` vaut 1, ...

-   Notez que l'ordre et les répétitions sont importants!

+++ {"slideshow": {"slide_type": "slide"}}

### Les tableaux en C++

**Exemple :**

+++ {"slideshow": {"slide_type": "fragment"}}

Au préalable :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <vector>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
vector<int> t;
t = vector<int>(6);
t[0] = 1;
t[1] = 4;
t[2] = 1;
t[3] = 5;
t[4] = 9;
t[5] = 2;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
t[1] + 2 * t[3]
```

+++ {"slideshow": {"slide_type": "slide"}}

### Construction des tableaux

+++ {"slideshow": {"slide_type": "fragment"}}

**Déclaration d'un tableau d'entiers :**

```{code-cell}
---
slideshow:
  slide_type: fragment
---
vector<int> t;
```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Pour un tableau de nombres réels : `vector<double>`, etc.

-   ♣ `vector` est un *template*

+++ {"slideshow": {"slide_type": "fragment"}}

**Allocation d'un tableau de six entiers :**

(on réserve de l'espace en mémoire pour ces six entiers)

```{code-cell}
---
slideshow:
  slide_type: fragment
---
t = vector<int>(6);
```

+++ {"slideshow": {"slide_type": "fragment"}}

**Initialisation du tableau :**

```{code-cell}
---
slideshow:
  slide_type: fragment
---
t[0] = 1;
t[1] = 4;
t[2] = 1;
```

+++ {"slideshow": {"slide_type": "slide"}}

### Les trois étapes de la construction d'un tableau

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} À retenir

Une variable de type tableau se construit en *trois étapes*:

1.  *Déclaration*

2.  *Allocation*   
    Sans elle : *faute de segmentation* (au mieux!)

3.  *Initialisation*  
    Sans elle : même problème qu'avec les variables usuelles

:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{tip} Raccourci

Déclaration, allocation et initialisation en un coup :

    vector<int> t = { 1, 4, 1, 5, 9, 2 };

Introduit par la norme C++ de 2011

:::

+++ {"slideshow": {"slide_type": "slide"}}

### Utilisation des tableaux

+++ {"slideshow": {"slide_type": "fragment"}}

#### Syntaxe et sémantique

-   `t[i]` s'utilise comme une variable usuelle :
    ```
    // Exemple d'accès en lecture
    x = t[2] + 3 * t[5];
    y = sin( t[3]*3.14 );

    // Exemple d'accès en écriture
    t[4] = 2 + 3*x;
	```

+++ {"slideshow": {"slide_type": "fragment"}}

-   En C++ *les indices ne sont pas vérifiés*!

+++ {"slideshow": {"slide_type": "fragment"}}

-   Le comportement de `t[i]` n'est pas spécifié en cas de débordement

+++ {"slideshow": {"slide_type": "fragment"}}

-   Source numéro 1 des trous de sécurité!!!

+++ {"slideshow": {"slide_type": "fragment"}}

-   Accès avec vérifications: `t.at(i)` au lieu de `t[i]`

+++ {"slideshow": {"slide_type": "slide"}}

:::{admonition} Quelques autres opérations sur les tableaux
```
t.size();       // Taille du tableau `t`
t.push_back(3); // Ajout d'un élément à la fin de `t`
```
:::

+++ {"slideshow": {"slide_type": "notes"}}

:::{hint} Remarque

La syntaxe de ces opérations peut vous paraître suprenante :
que vient le `.` faire là? Pourquoi n'écrit-on pas plutôt
`size(t)` ou `push_back(t,3)`?

En fait, nous sommes en train d'utiliser de la programmation
objet sans le dire. Vous n'avez pas besoin de connaître les
détails pour le moment; juste de mémoriser la syntaxe un peu
particulière. Les détails vous seront donnés dans le cours de
programmation modulaire.

:::

+++ {"slideshow": {"slide_type": "slide"}}

### Fonctions et tableaux

:::{hint} Remarque
Nous avons dit qu'un tableau était une valeur. Il est
donc tout à fait possible d'écrire une fonction qui prend
un ou des tableaux en paramètres et/ou qui renvoie des tableaux.
:::

+++ {"slideshow": {"slide_type": "fragment"}}

Voici par exemple une fonction qui affiche le contenu d'un annuaire :

```{code-cell}
#include <iostream>
#include <vector>
using namespace std;
```

```{code-cell}
void affiche_annuaire(vector<string> noms, vector<string> telephones) {
   for ( int i = 0; i < noms.size(); i++ ) {
      cout << noms[i] << " " << telephones[i] << endl;
   }   
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

Appliquons la à notre annuaire :

```{code-cell}
vector<string> noms = {"Jeanne", "Franck", "Marie", "Joël"};
vector<string> telephones = {"04 23 23 54 56", "03 23 42 34 26", "06 52 95 56 06", "07 23 63 92 38"}
```

```{code-cell}
affiche_annuaire(noms, telephones)
```

+++ {"slideshow": {"slide_type": "fragment"}}

En voici une autre qui calcule la somme des éléments d'un tableau :

```{code-cell}
#include<vector>
using namespace std;
```

```{code-cell}
int somme(vector<int> v) {
    int s = 0;
    for ( int i = 0; i < v.size(); i++) {
        s = s + v[i];
    }
    return s;
}
```

```{code-cell}
vector<int> v = { 1, 2, 3 };
```

```{code-cell}
somme(v)
```

+++ {"slideshow": {"slide_type": "notes"}}

Voir la fiche d'exercices sur les [tableaux et fonctions](tableaux-fonctions.md).

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé : les tableaux

+++ {"slideshow": {"slide_type": "fragment"}}

-   Motivation : manipulation de collections de données  
    Exemple : un annuaire

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un **tableau** est une valeur composite formée de plusieurs valeurs du même type

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un tableau se construit en trois étapes :
    -   *Déclaration* : `vector<int> t;`
    -   *Allocation* : `t = vector<int>(3);`
    -   *Initialisation* : `t[0] = 3;  t[1] = 0; ...`

+++ {"slideshow": {"slide_type": "fragment"}}

-   Utilisation : `t[i] = t[i]+1`, `t.size()`, `t.push_back(3)`

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un tableau est une valeur comme les autres

+++ {"slideshow": {"slide_type": "fragment"}}

-   Il peut être passé en paramètre à, ou renvoyé par, une fonction

