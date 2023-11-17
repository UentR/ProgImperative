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

# Mémoire et variables

Un ordinateur traite de l'information.

-   Il faut pouvoir la stocker: la *mémoire*
-   Il faut pouvoir y accéder: les *variables*

+++ {"slideshow": {"slide_type": "slide"}}

## Mémoire

[https://fr.wikipedia.org/wiki/Mémoire\_(informatique)](https://fr.wikipedia.org/wiki/Mémoire_(informatique))

:::::{grid} 4
:gutter: 0

::::{grid-item-card}
:::{image} media/4mbramvax.jpg
:height: 10ex
:::
::::
::::{grid-item-card}
:::{image} media/Memory_module_DDRAM_20-03-2006.jpg
:::
::::
::::{grid-item-card}
:::{image} media/1200px-Four_MMC_cards_front.jpg
:::
::::
::::{grid-item-card}
:::{image} media/Floppy_disk_2009_G1.jpg
:::
::::
::::{grid-item-card}
:::{image} media/Dat_cartridge.jpg
:::
::::
::::{grid-item-card}
:::{image} media/Lochkarte_Tanzorgel.jpg
:::
::::
::::{grid-item-card}
:::{image} media/CD_autolev_crop.jpg
:::
::::
::::{grid-item-card}
:::{image} media/1176px-Laptop-hard-drive-exposed.jpg
:::
::::

+++ {"slideshow": {"slide_type": "slide"}}

### Modèle simplifié

-   Une suite contiguë de `0` et de `1`
	Les ***bits***, groupés par paquets de huit appelés ***octets***

+++ {"slideshow": {"slide_type": "fragment"}}

-   Pour 1 Go, à raison de un bit par mm, cela ferait 8590 km  
    Plus que Paris-Pékin!

+++ {"slideshow": {"slide_type": "fragment"}}

-   Le processeur y accède par **adresse**

+++ {"slideshow": {"slide_type": "slide"}}

## Variables

Une **variable** est un espace de stockage *nommé* où le programme peut
mémoriser une donnée; elle possède quatre propriéfile:///home/nthiery/.local/share/jupyter/runtime/jpserver-730225-open.htmltés:

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un **nom** (ou **identificateur**): Il est choisi par le programmeur

+++ {"slideshow": {"slide_type": "fragment"}}

-   Une **adresse**:  
    Où est stockée la variable dans la mémoire

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un **type** qui spécifie:

    -   La **structure de donnée**: comment la valeur est représentée en
        mémoire  
        En particulier combien d'octets sont occupés par la variable

    -   La **sémantique** des opérations

+++ {"slideshow": {"slide_type": "fragment"}}

-   Une **valeur**:  
    Elle peut changer en cours d'exécution du programme

+++ {"slideshow": {"slide_type": "slide"}}

### Règles de formation des identificateurs

Les noms des variables (ainsi que les noms des programmes, constantes,
types, procédures et fonctions) sont appelés des **identificateurs**.

+++ {"slideshow": {"slide_type": "fragment"}}

**Syntaxe:** règles de formation des identificateurs

-   suite de lettres (minuscules `'a'...'z'` ou majuscules
    `'A'`...`'Z'`), de chiffres (`'0'...'9'`) et de
    caractères de soulignement (`'_'`)
-   premier caractère devant être une lettre
-   longueur bornée

+++ {"slideshow": {"slide_type": "fragment"}}

	Exemples et contre-exemples d'identificateurs :

-   `c14_T0` est un identificateur
-   `14c_T0` n'est pas un identificateur
-   `x*y` n'est pas un identificateur

+++ {"slideshow": {"slide_type": "slide"}}

#### Formation des identificateurs : bonnes pratiques

+++ {"slideshow": {"slide_type": "fragment"}}

-   Donnez des noms *signifiants* aux variables
-   Dans le cas de plusieurs mots, par convention dans le cadre de ce
    cours on mettra le premier mot en minuscule et les suivants avec une
    majuscule: `maVariable`
-   Autre convention possible: `ma_variable`

+++ {"slideshow": {"slide_type": "fragment"}}

-   Mauvais noms : `truc`, `toto`, `temp`, `nombre`
-   Bons noms courts: `i`, `j`, `k`, `x`, `y`, `z`, `t`
-   Bons noms longs: `nbCases`, `notes`, `moyenneNotes`, `estNegatif`

+++ {"slideshow": {"slide_type": "slide"}}

### Initialisation des variables

Quelle est la valeur de ces variables après leur déclaration?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
double d;
long l;
int i;
```

```{code-cell}
l
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
d
```

+++ {"slideshow": {"slide_type": "fragment"}}

-   Certains langages ou compilateurs garantissent que les variables
    sont initialisées à une valeur par défaut.

+++ {"slideshow": {"slide_type": "fragment"}}

-   *En `C++`, pas forcément!*

    Typiquement, la valeur de la variable correspond à l'état de la
    mémoire au moment de sa déclaration

+++ {"slideshow": {"slide_type": "fragment"}}

**Bonne pratique**: systématiquement initialiser les variables au
moment de leur déclaration:

```{code-cell}
---
slideshow:
  slide_type: fragment
---
int i = 0;
long l = 1024;
double d = 3.14159;
```

