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

# Notion de flux de données

+++ {"slideshow": {"slide_type": "fragment"}}

-   Nous avons utilisé la même syntaxe pour écrire à l’écran ou dans un
    fichier : `xxx << expression`
-   Nous avons utilisé la même syntaxe pour lire au clavier ou depuis un
    fichier : `xxx >> variable`

+++ {"slideshow": {"slide_type": "fragment"}}

:::{hint} Astuce mnémotechnique

Le sens des chevrons met en valeur dans quel sens
se déplacent les informations :
- `xxx << expression` : de `expression` vers `xxx`;
- `xxx >> variable` : de `xxx` vers `variable`.
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition}
-   Un *****flux sortant***** est un dispositif où l’on peut écrire des données, successivement *l’une après
    l’autre*
-   Un *****flux entrant***** est un dispositif où l’on peut lire des données, successivement *l’une après
    l’autre*
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Exemples de flux sortants de données

+++ {"slideshow": {"slide_type": "fragment"}}

-   `cout` : *sortie standard* du programme  
    Typiquement : écran  
    ♣ Avec tampon

+++ {"slideshow": {"slide_type": "fragment"}}

-   `cerr` : *sortie d’erreur* du programme  
    ♣ Sans tampon

+++ {"slideshow": {"slide_type": "fragment"}}

-   fichiers (`ofstream`)

+++ {"slideshow": {"slide_type": "fragment"}}

-   chaînes de caractères (`ostringstream`)

+++ {"slideshow": {"slide_type": "fragment"}}

-   connexions avec d'autres programmes ...

+++ {"slideshow": {"slide_type": "slide"}}

## Exemples de flux entrants de données

+++ {"slideshow": {"slide_type": "fragment"}}

-   `cin` : *entrée standard* du programme  
    Typiquement : clavier

+++ {"slideshow": {"slide_type": "fragment"}}

-   fichiers (`ifstream`)

+++ {"slideshow": {"slide_type": "fragment"}}

-   chaînes de caractères (`istringstream`)

+++ {"slideshow": {"slide_type": "fragment"}}

-   connexions avec d'autres programmes ...

