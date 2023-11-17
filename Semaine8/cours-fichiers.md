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

# Fichiers, lecture, écriture

+++ {"slideshow": {"slide_type": "fragment"}}

## Qu’est-ce qu’un fichier?

Un **fichier informatique** est, au sens commun, une collection
d’informations numériques réunies sous un même **nom**, enregistrées sur
un support de stockage tel qu’un disque dur, un CD-ROM ou une bande
magnétique, et manipulées comme une unité.

Techniquement, un fichier est une **information numérique** constituée
d'une **séquence d’octets**, c'est-à-dire d'une séquence de nombres,
permettant des usages divers.

+++ {"slideshow": {"slide_type": "fragment"}}

En bref, c'est comme la mémoire, mais en **persistant**!

De même que le type d'une variable indique comment l'information
est encodée dans la mémoire, le **format du fichier** indique
comment l’information y est encodée.

+++ {"slideshow": {"slide_type": "fragment"}}

Voyons maintenant comment on peut écrire et lire dans un fichier.

+++ {"slideshow": {"slide_type": "slide"}}

## Écriture dans un fichier

+++ {"slideshow": {"slide_type": "fragment"}}

L'exemple suivant écrit `Noel 42` dans le fichier `bla.txt` :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <fstream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
// Déclaration
ofstream  fichier;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
// Ouverture
fichier.open("bla.txt");
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
// Écriture
fichier << "Noel " << 42 << endl;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
// Fermeture
fichier.close();
```

+++ {"slideshow": {"slide_type": "slide"}}

:::{admonition} À retenir

Écrire dans un fichier se fait  en **quatre étapes** :

1.  Déclaration
2.  Ouverture du fichier
3.  Écriture
4.  Fermeture du fichier
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Lecture depuis un fichier

+++ {"slideshow": {"slide_type": "fragment"}}

Nous allons maintenant faire l'opération inverse : lire
les informations stockées dans `bla.txt` :

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
#include <fstream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
// Déclaration
ifstream fichier;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
// Ouverture du fichier
fichier.open("bla.txt");
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
string s;
// Lecture
fichier >> s;
s
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
int i;
fichier >> i;
i
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
// Fermeture du fichier
fichier.close();
```

+++ {"slideshow": {"slide_type": "slide"}}

:::{admonition} À retenir

De même que l'écriture dans un fichier, la lecture se fait en **quatre
étapes** :

1.  Déclaration
2.  Ouverture du fichier
3.  Lecture
4.  Fermeture du fichier

:::

