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

# Portée des variables : variables locales et globales

+++ {"slideshow": {"slide_type": "fragment"}}

Nous avons vu dans les cours précédents que l'on pouvait
déclarer des variables à différents endroits :

-   Directement dans une cellule Jupyter ou l'entête d'un programme :
    ``` c++
    int a = 1;
    ```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Dans une boucle `for` :

    ``` c++
    for ( int a = 0; i <= 5; i ++ ) {
        ...
    }
    ```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Comme paramètre d'une fonction :
    ``` c++
    int f(int a) {
        ...
    }
    ```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Dans le corps d'une fonction :
    ``` c++
    int f() {
        int a;
        ...
    }
    ```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Et en fait, plus généralement, dans un bloc :
    ``` c++
    {
        int a;
        ...
    }
    ```

+++

:::{admonition} Objectif pédagogique

Formaliser les cas précédents en introduisant la notion de **portée** d'une variable.

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Quelques exemples

Dans un programme, le même nom peut être utilisé pour plusieurs
variables, ce qui peut amener des ambiguïtés.

+++ {"slideshow": {"slide_type": "fragment"}}

:::{exercise}
Devinez le résultat des commandes suivantes.
:::

```{code-cell}
int i = 1;
{
    i = 2;
    i = i + 1;
}
i
```

```{code-cell}
int i = 1;
{
    int i = 2;
    i = i + 1;
}
i
```

```{code-cell}
int i = 1;
for ( int i = 1; i < 10; i++ ) {
}
i
```

+++ {"slideshow": {"slide_type": "slide"}}

:::{exercise}
Essayez, sans les exécuter, de prédire ce qui est affiché
par les cinq cellules suivantes.
:::

```{code-cell}
#include <iostream>
using namespace std;
```

```{code-cell}
int a = 0, b = 0;
```

```{code-cell}
void f(int b) {
    int c = 5;
    cout << "1: " << a << " " << b << " " << c << endl;
}
```

```{code-cell}
void g() {
    int a = 2, c = 2;
    cout << "2: " << a << " " << b << " " << c << endl;
    {
        long a = 3, c = 3;
        cout << "3: " << a << " " << b << " " << c << endl;
    }
    cout << "4: " << a << " " << b << " " << c << endl; 
    f(4);
}
```

```{code-cell}
g()
```

+++ {"slideshow": {"slide_type": "fragment"}}

Exécutez maintenant les cellules; avez-vous le bon résultat?

+++ {"slideshow": {"slide_type": "fragment"}}

:::{attention} La réponse pourrait en fait dépendre du langage!

Pour prédire rigoureusement le comportement du programme, il faut
préciser la sémantique des variables et notamment leur **portée**.

:::

+++ {"slideshow": {"slide_type": "slide"}}

## La portée des variables

+++ {"slideshow": {"slide_type": "notes"}}

En `C++`, comme dans la plupart des langages modernes, la **portée d'une
variable** (où elle est définie) est déterminée par le **contexte
lexical** (comment le code est écrit) sans avoir à considérer le
**contexte d'exécution** (comment le code s'exécute). Cela permet en effet
de raisonner localement à une fonction, à un fichier, sans se préocuper
du reste du programme.

+++ {"slideshow": {"slide_type": "fragment"}}

### Sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

(portee_d_une_variable)=
:::{prf:definition} Portée des variables

Une variable est visible depuis sa déclaration jusqu'à la fin du
bloc `{ ... }` où elle est déclarée.

:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{attention} Cas particulier
Dans le cas d'une boucle `for`, le bloc comprend l'entête 
`for (int i ...) { ... }`.
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition} Variables locales, paramètres formels et variables globales
-   Une ***variable locale*** est définie dans un bloc (par exemple d'une fonction).
-   Un ***paramètre formel*** est défini dans l'entête d'une fonction; il
    se comporte comme une variable locale.
-   Une ***variable globale*** est définie ailleurs (cellule Jupyter, entête de programme)
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{attention}

Une variable peut masquer des variables issues des contextes englobants!

:::

+++ {"slideshow": {"slide_type": "slide"}}

:::{exercise}

Reprenez l'exemple ci-dessus, et annotez chaque déclaration et chaque
utilisation de variable : quelles variables y sont
locales, globales, ... Puis exécutez le pas-à-pas en dessinant la
pile d'exécution pour prédire à nouveau l'affichage. Vérifiez.
::::

+++ {"slideshow": {"slide_type": "fragment"}}

**Solution**

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int a = 0, b = 0;                  // Variables globales
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
void f(int b) {                    // Paramètre (donc local à f)
    int c = 5;                     // Variable locale de f
    // a: globale; b: paramètre de f; c: local à f
    cout << "1: " << a << " " << b << " " << c << endl;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
void g() {
    int a = 2, c = 2;              // Variables locales à g
    // a, c: locales à g; b: globale
    cout << "2: " << a << " " << b << " " << c << endl;
    {
        long a = 3, c = 3;         // Variables locales au bloc
        // a, c: locales au bloc; b: globale
        cout << "3: " << a << " " << b << " " << c << endl;
    }
    // a, c: locales à g; b: globale
    cout << "4: " << a << " " << b << " " << c << endl; 
    f(4);
}
```

```{code-cell}
g()
```

+++ {"slideshow": {"slide_type": "slide"}}

### Rappels

-   Une variable locale à une fonction n'existe que le temps d'exécution
    de la fonction

-   La valeur de cette variable d'un appel à la fonction est perdue lors
    du retour au programme appelant et ne peut pas être récupérée lors d'un
    appel ultérieur

+++ {"slideshow": {"slide_type": "slide"}}

## Variables globales : bonnes pratiques

-   Accessible à l'intérieur de toutes les fonctions

-   On peut modifier la valeur d'une variable globale  
    Ceci est déconseillé (*effet de bord*)

-   Une variable locale masque une variable globale du même nom  
    Ceci est déconseillé (ambiguïté à la lecture rapide)

-   On évitera ces pratiques dans le cadre de ce cours

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé: portée des variables

+++ {"slideshow": {"slide_type": "fragment"}}

- Une variable est définie depuis sa déclaration jusqu'à la fin du
  bloc la contenant  
  (en considérant l'entête d'une fonction ou d'une boucle `for`
  comme faisant partie du bloc)

+++ {"slideshow": {"slide_type": "fragment"}}

- Une variable hors de tout bloc est dite **globale**  
  En général, on évite les variables globales

+++ {"slideshow": {"slide_type": "fragment"}}

- Sinon elle est **locale**
