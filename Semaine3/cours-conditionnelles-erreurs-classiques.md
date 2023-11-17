---
jupytext:
  notebook_metadata_filter: rise
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
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

# Conditionnelles : erreurs classiques

+++ {"slideshow": {"slide_type": "fragment"}}

Nous allons maintenant voir quelques bonnes pratiques et erreurs
classiques lorsque l'on utilise des instructions conditionnelles.

+++ {"slideshow": {"slide_type": "slide"}}

## Exemple 1

+++ {"slideshow": {"slide_type": "fragment"}}

Dans cet exemple, on souhaite affecter à la variable `estPositif` la
valeur «Vrai» si $x \geq 0$ et «Faux» sinon.  Cela se traduit
litéralement par :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 4;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
bool estPositif;

if ( x >= 0 ) {
    estPositif = true;
} else {
    estPositif = false;
}

estPositif
```

+++ {"slideshow": {"slide_type": "fragment"}}

Mais ne pourrait-on pas faire mieux?

+++ {"slideshow": {"slide_type": "fragment"}}

<!-- TODOIMG !-->

<img src="https://upload.wikimedia.org/wikipedia/commons/c/ce/George_Boole_color.jpg" align=right width="10%">

Si!

Grâce à George [Boole](https://fr.wikipedia.org/wiki/George_Boole) qui
a réalisé que «Vrai» et «Faux» sont des valeurs comme les autres avec
lesquelles on peut calculer (expressions booléennes) et que l'on peut
stocker (variables booléennes).

Exécutez les cellules ci-dessus et ci-dessous pour différentes valeurs
de `x` et vérifier que le résultat est le même :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x = 4
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x >= 0
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
bool estPositif =  x >= 0;

estPositif
```

+++ {"slideshow": {"slide_type": "fragment"}}

C'est plus concis. Plus efficace. Avec moins de risque d'erreur.

Pourquoi cela nous paraît-il moins naturel au premier abord? Parce
qu'il n'y a pas d'équivalent naturel dans la langue française! Au
mieux on peut utiliser une périphrase comme : stocker dans
`estPositif` la valeur de vérité de l'expression «x est plus grand que
zéro».

+++ {"slideshow": {"slide_type": "fragment"}}

**À retenir :**
- Chaque fois que possible, utiliser une expression booléenne plutôt
  qu'une instruction conditionnelle.

+++ {"slideshow": {"slide_type": "slide"}}

## Exemple 2

+++ {"slideshow": {"slide_type": "fragment"}}

Devinez le contenu de la variable `y` à la fin de l'exécution du
programme suivant. Vérifiez en l'exécutant :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 0;
int y = 0;

if ( x = 1 ) {
    y = 4;
}

y
```

+++ {"slideshow": {"slide_type": "fragment"}}

Pourtant `x` n'est pas égal à 1! L'instruction `y=4` n'aurait pas dû
être exécutée!?!

+++ {"slideshow": {"slide_type": "fragment"}}

Sauf que ... Nous avons utilisé une affectation `=` et non un test
d'égalité `==`! Cela se voit à la valeur de `x` :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x
```

+++ {"slideshow": {"slide_type": "fragment"}}

Jupyter + Cling nous ont prévenu avec une alerte (*warning*) : ce
n'est probablement pas ce que l'on souhaitait faire.

Il se trouve cependant que le code ci-dessus est valide en C++,
ce qui est une cause classique de bogue.

+++ {"slideshow": {"slide_type": "fragment"}}

**Pour les curieux :** ♣

En toute logique le code ci-dessus devrait être invalide et déclencher
une erreur.  En effet, une affectation, c'est juste une
**instruction** qui décrit une action à effectuer. Une action, cela
n'a pas de valeur.  Cependant de nombreux languages, dont C++,
choisissent de faire de l'affectation une **expression**, en décidant
de lui attribuer une valeur : celle qui a été affectée.

Cela permet par exemple d'affecter une valeur à deux variables
simultanément :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
x = y = 17
```

+++ {"slideshow": {"slide_type": "fragment"}}

Analysez pourquoi cela marche, en l'interprétant sous la forme : `x = (
y = 17 )`.

+++ {"slideshow": {"slide_type": "fragment"}}

Maintenant nous savons que `x = 1` est une expression qui vaut `1`
tout le temps; elle est en particulier de type `int`.  Là encore le
code devrait être invalide puisque l'on a dit que `if` prenait comme
condition une expression booléenne.

Sauf que ... C++ hérite de C une vieille convention qui date de
l'époque où les languages n'avaient pas de type `bool`.  On
représentait alors les valeurs booléennes par des entiers, en
représentant «Faux» par `0` et «Vrai» par n'importe quel nombre entier
non nul. De ce fait l'expression `x = 1` a pour valeur `1` qui est
interprétée comme «Vrai» dans le contexte d'une condition.

+++ {"slideshow": {"slide_type": "fragment"}}

**Exercice :** ♣

Quelles sont les valeurs de `x` et `y` à la fin du programme suivant :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 1;
int y = 2;
if ( x = 0 ) {
    y = 3;
}
```

+++ {"slideshow": {"slide_type": "slide"}}

## Erreurs classiques avec les conditionnelles

+++ {"slideshow": {"slide_type": "fragment"}}

Devinez ce qu'affiche le programme suivant? Vérifiez en l'exécutant :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 0;
int y = 0;

if ( x == 1 ); {
    y = 4;
}

y
```

+++ {"slideshow": {"slide_type": "fragment"}}

Ce programme est équivalent à :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
if ( x == 1 );
y = 4;
```

+++ {"slideshow": {"slide_type": "fragment"}}

qui ne tient pas compte du `if` et affecte toujours `4` à `y` (quel
que soit `x`).

+++ {"slideshow": {"slide_type": "fragment"}}

**À retenir :**
- Le point-virgule `;` est un **séparateur d'instruction**;
- Le bloc d'instructions d'un `if` peut être vide en C++;
- Il ne faut **jamais de point-virgule avant un bloc d'instructions!**

+++ {"slideshow": {"slide_type": "slide"}}

## Tests imbriqués

+++ {"slideshow": {"slide_type": "fragment"}}

Devinez ce qu'affiche le programme suivant? Vérifiez en l'exécutant :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int x = 5;
int y = 4;
std::string resultat = "";
    
if ( x >= y ) {
    if ( x == y ) {
        resultat = "égalité";
    }
else {
    resultat = "x est plus petit que y";
}
}

resultat
```

+++ {"slideshow": {"slide_type": "fragment"}}

Oups. Il y a un bogue.

+++ {"slideshow": {"slide_type": "fragment"}}

Explication : en C++, la structuration est entièrement déterminée par
les accolades : `{`, `}`. Les espaces et sauts de lignes ne jouent
aucun rôle. Aussi, ici, le `else` se rapporte au deuxième `if`,
contrairement à ce que la disposition visuelle du code pourrait faire
croire.

+++ {"slideshow": {"slide_type": "fragment"}}

Maintenant, **indentons** correctement le code : c'est-à-dire décalons
chaque ligne de quatre espaces par niveau d'imbrication dans des
accolades :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
resultat = "";

if ( x >= y ) {
    if ( x == y ) {
        resultat = "égalité";
    }
    else {
        resultat = "x est plus petit que y";
    }
}

resultat
```

+++ {"slideshow": {"slide_type": "fragment"}}

La source du bogue est devenue claire, et on peut facilement le
corriger :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
resultat = "";

if ( x >= y ) {
    if ( x == y ) {
        resultat = "égalité";
    }
} else {
    resultat = "x est plus petit que y";
}

resultat
```

+++ {"slideshow": {"slide_type": "fragment"}}

**À retenir :**

-   Un `else` se rapporte au dernier `if` rencontré;
-   En C++, la structuration est déterminée pas les accolades;
-   La mauvaise indentation induit en erreur le lecteur!

+++ {"slideshow": {"slide_type": "slide"}}

## Apparté : l'indentation

-   L'***indentation*** consiste à espacer les lignes de code
    par rapport au bord gauche de la fenêtre de saisie de texte;
-   L'espacement doit être proportionnel au *niveau d'imbrication* des
    instructions du programme;
-   Quatre espaces par niveau d'imbrication est un bon compromis.

La plupart des éditeurs de texte offrent des facilités pour réaliser
une bonne indentation. *Apprenez-les*.

+++ {"slideshow": {"slide_type": "slide"}}

## De la lisibilité des programmes

> «Programs must be written for people to read, and only incidentally
> for machines to execute.»
>
> -- Harold Abelson, Structure and Interpretation of Computer Programs
> 1984

-   Un programme s'adresse à un *lecteur*
-   La *lisibilité* est un objectif essentiel

+++ {"slideshow": {"slide_type": "slide"}}

## Conclusion

Nous avons vu les bonnes pratiques et erreurs classiques suivantes sur
les instructions conditionnelles :
- Bonne pratique : lorsque cela est possible, utiliser une expression
  booléenne plutôt qu'une instruction conditionnelle;
- Erreur classique : insérer accidentellement une instruction vide `;`
  ;
- Erreur classique : imbriquer incorrectement `if` et `else`.

Nous avons aussi vu l'importance de l'**indentation** pour la
**lisibilité** des programmes.
