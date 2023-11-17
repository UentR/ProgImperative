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

# Lecture depuis le clavier

+++ {"slideshow": {"slide_type": "fragment"}}

Avant de voir comment lire et écrire dans un fichier, nous avions vu
comment afficher; c'est-à-dire écrire à l'écran au moyen de
`cout`. Nous avons occasionnellement vu comment lire depuis le clavier
`cin`. Voici l'occasion de le formaliser.

+++ {"slideshow": {"slide_type": "fragment"}}

## Exemple

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
string nom;
cout << "Comment t'appelles-tu?" << endl;
cin >> nom;
cout << "Bonjour " << nom << "!" << endl;
```

+++ {"slideshow": {"slide_type": "slide"}}

## Syntaxe et sémantique

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

Lecture d’une variable :

    cin >> variable;
 
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique
-   Lit depuis le clavier une valeur du type indiqué par celui de la variable
-   Affecte cette valeur à la variable
:::

