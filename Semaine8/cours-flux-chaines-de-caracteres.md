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

# Lecture et écriture dans des chaînes de caractères

+++ {"slideshow": {"slide_type": "notes"}}

Nous avons vu comment lire et écrire facilement des valeurs de types
divers (entiers, flottants) dans un fichier texte.  Sous le capot cela
a requis des opérations de natures différentes :
1. interactions avec le système pour lire et écrire du texte dans un
   fichier
2. conversions de valeurs en texte et réciproquement

Ne pourrait-on pas utiliser ce deuxième point pour lire et écrire des
valeurs dans des chaînes de caractères?  Après tout, elles contiennent
du texte elles aussi!  Allons-y.

+++ {"slideshow": {"slide_type": "fragment"}}

Au préalable, nous aurons besoin de la bibliothèque suivante :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <sstream>
using namespace std;
```

+++ {"slideshow": {"slide_type": "slide"}}

## Lecture depuis une chaîne de caractères

+++ {"slideshow": {"slide_type": "fragment"}}

### Exemple

+++ {"slideshow": {"slide_type": "fragment"}}

La chaîne de caractère suivante contient -- sous forme de texte --
plusieurs nombres :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string s = "1 2 4 8 16";
```

Comment extraire ces nombres de `s`?

+++ {"slideshow": {"slide_type": "notes"}}

On souhaiterait extraire ces nombres en les convertissant en entiers.
Pour cela on créé un *flux* de type `istringstream` (nous verrons dans
la feuille suivante ce qu'est un flux et la signification du nom
`istringstream`) :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
istringstream flux = istringstream(s)
```

+++ {"slideshow": {"slide_type": "fragment"}}

Maintenant il est possible de lire le premier nombre, en procédant
comme s'il était dans un fichier :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int i;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux >> i;
i
```

+++ {"slideshow": {"slide_type": "fragment"}}

Lorsque l'on effectue de nouvelles lectures, les nombres suivants sont
lus un à un :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux >> i;
i
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux >> i;
i
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux >> i;
i
```

+++ {"slideshow": {"slide_type": "slide"}}

L'exemple suivant illustre que l'on peut lire successivement des
valeurs de types mixtes, et que l'on peut chaîner ces lectures :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string s = "truc 33 bidule 2.5 reste"
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
istringstream flux = istringstream(s);
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string a, b;
int i;
float f;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux >> a >> i >> b >> f;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
a
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
b
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
i
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
f
```

+++ {"slideshow": {"slide_type": "slide"}}

### Syntaxe et sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

```c++
istringstream flux = istringstream(s);
flux >> variable1;
flux >> variable2;
          ...
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

Affecte aux variables `variable1`, `variable2`, ... les valeurs lues
successivement depuis la chaîne de caractères `s`, en tenant compte de
leurs types respectifs.

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Écriture dans une chaîne de caractères

Réciproquement, on peut souhaiter écrire le contenu de variables non
pas directement à l'écran ou dans un fichier mais dans une chaîne de
caractères. Le principe sera le même que pour une lecture.

+++ {"slideshow": {"slide_type": "fragment"}}

### Exemple

+++ {"slideshow": {"slide_type": "fragment"}}

On commence par définir un flux de type `ostringstream` (là encore,
nous verrons dans la feuille suivante la signification du nom de ce
type) :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
ostringstream flux;
```

+++ {"slideshow": {"slide_type": "fragment"}}

Nous pouvons maintenant écrire dans ce flux :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
flux << 3.53 << " coucou " << 1 << endl;
flux << 42 << endl;
```

+++ {"slideshow": {"slide_type": "fragment"}}

et enfin extraire la chaîne de caractère produite :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string s = flux.str();
s
```

+++ {"slideshow": {"slide_type": "slide"}}

### Syntaxe et sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

```c++
ostringstream flux;
flux << variable1;
flux << variable2;
string s = flux.str()
```

:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

Construit une chaîne de caractères `s` en écrivant successivement le
contenu des variables `variable1`, `variable2`, ... en tenant compte
de leurs types respectifs.

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Application typique : séparation calcul et entrées sorties

+++ {"slideshow": {"slide_type": "notes"}}

Ce que nous venons de voir sera très utile pour séparer proprement ce
qui relève du **calcul** et ce qui relève des **entrées-sorties**.
Supposons par exemple que nous souhaitions afficher joliment une
entrée d'un annuaire :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
using namespace std;
#include <iostream>
#include <sstream>
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
void afficheEntreeAnnuaire(string nom, string prenom, string tel) {
    cout << "Nom: " << nom 
         << ", Prénom: " << prenom
         << ", Téléphone: " << tel;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
afficheEntreeAnnuaire("Lovelace", "Ada", "07 23 23 23 23")
```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Questions
- Comment réutiliser cette fonction pour écrire le texte non pas à
  l'écran mais dans un fichier?
- Comment tester cette fonction?
:::

+++ {"slideshow": {"slide_type": "fragment"}}

Cela est rendu difficile par le mélange de deux actions de natures
différentes dans une seule fonction :
1. Construire le texte représentant l'entrée dans l'annuaire.
2. Afficher ce texte à l'écran.

+++ {"slideshow": {"slide_type": "fragment"}}

Il faut donc **séparer** ces deux actions. L'écriture dans une chaîne
va nous aider à le faire.

+++ {"slideshow": {"slide_type": "fragment"}}

La fonction suivante se concentre sur la construction du texte
représentant l'entrée dans l'annuaire :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string formateEntreeAnnuaire(string nom, string prenom, string tel) {
    ostringstream flux;
    flux << "Nom: " << nom 
         << ", Prénom: " << prenom
         << ", Téléphone: " << tel;
    return flux.str();
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

Le texte produit est **renvoyé** par la fonction au lieu d'être **affiché**.
Nous pouvons donc maintenant :

- l'affecter à une variable :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string s = formateEntreeAnnuaire("Lovelace", "Ada", "07 23 23 23 23")
```

+++ {"slideshow": {"slide_type": "fragment"}}

- l'afficher :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
cout << s << endl;
```

+++ {"slideshow": {"slide_type": "fragment"}}

- calculer avec :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
"- " + s
```

+++ {"slideshow": {"slide_type": "fragment"}}

- ou nous en servir pour toute autre opération, comme l'écrire dans un fichier.

+++ {"slideshow": {"slide_type": "fragment"}}

De plus, nous pouvons maintenant aisément tester notre fonction :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
CHECK( formateEntreeAnnuaire("Lovelace", "Ada", "07 23 23 23 23")
       == "Nom: Lovelace, Prénom: Ada, Téléphone: 07 23 23 23 23" );
```

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

Dans cette feuille:
- nous avons vu comment **lire et écrire** des données de types divers **dans des chaînes de caractères**.
- Nous l'avons appliqué pour mieux séparer **fonctions qui calculent** et **fonctions d'entrées-sorties**.
- Enfin nous avons noté que l'on utilise la même syntaxe que pour lire et écrire dans un fichier ou
  pour interagir avec l'utilisateur.  
  Cela est rendu possible par le concept de flux qui est le sujet de la [feuille suivante](cours-flux.md).

