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

# Les types entiers en C++

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <climits>
#include <cmath>
```

+++ {"slideshow": {"slide_type": "fragment"}}

## Type `unsigned short int`

```{code-cell}
---
slideshow:
  slide_type: fragment
---
unsigned short int u;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = 10000
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = 100000
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
USHRT_MAX
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
pow(2,16) - 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = 65533 
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = u + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = u + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = u + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
u = u - 1
```

+++ {"slideshow": {"slide_type": "slide"}}

## Type `signed short int`

```{code-cell}
---
slideshow:
  slide_type: fragment
---
short int s;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = 1000
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = 100000
```

+++ {"slideshow": {"slide_type": "fragment"}}

Quel est le plus grand entier que l'on peut représenter avec un short int?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
SHRT_MAX
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = SHRT_MAX
```

+++ {"slideshow": {"slide_type": "fragment"}}

Que se passe-t-il si on lui ajoute `1`?

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = s + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = SHRT_MIN
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s -= 1
```

+++ {"slideshow": {"slide_type": "fragment"}}

Conséquence amusante:

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = SHRT_MIN
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = -s 
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
s = abs(s)
```

+++ {"slideshow": {"slide_type": "slide"}}

## Type `int`

```{code-cell}
int i;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
i = INT_MAX
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
i + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
i = INT_MIN
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
-i
```

+++ {"slideshow": {"slide_type": "slide"}}

## Type `long`

```{code-cell}
---
slideshow:
  slide_type: fragment
---
long l = LONG_MAX
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
l + 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
l = LONG_MIN
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
l - 1
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
- l
```

+++ {"slideshow": {"slide_type": "slide"}}

## À retenir

+++ {"slideshow": {"slide_type": "fragment"}}

- Les entiers des types `int`, `long`, ... sont des **entiers machine**; ce sont des **approximations** des entiers mathématiques  
  Il est possible de représenter les entiers mathématiques arbitraires avec un type adéquat

+++ {"slideshow": {"slide_type": "fragment"}}

- De même pour `float`, `double`, ...: ce sont des **approximations** des nombres réèls  
  Il n'est pas possible de représenter tous les nombres réels!
