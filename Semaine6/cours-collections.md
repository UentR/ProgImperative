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

# Collections et boucle «pour tout ... dans ...»

+++ {"slideshow": {"slide_type": "slide"}}

## Collections : définition et exemples

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition} Collection
Une ***collection*** est une **valeur composite homogène**  
(elle regroupe plusieurs valeurs du même type).
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:example}
Un tableau (`vector`) est une collection
:::

+++ {"slideshow": {"slide_type": "fragment"}}

Dans un tableau, les valeurs sont **dans un ordre donné**, **en tenant compte des répétitions** :

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
#include<vector>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
vector<int> v = { 3, 2, 5, 2 };
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
v
```

+++ {"slideshow": {"slide_type": "fragment"}}

Cela donne un sens au i-ième élément d'un tableau :

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
v[3]
```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{note}
Il existe d'autres types de collections. Voyons quelques exemples.
:::

+++ {"slideshow": {"slide_type": "slide"}}

### Ensembles (`set`)

+++ {"slideshow": {"slide_type": "fragment"}}

Lorsque l'on souhaite ne tenir compte ni de l'ordre, ni des
répétitions -- comme dans un ensemble mathématique -- on peut
utiliser un `set` :

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
#include <set>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
set<int> s = { 3, 2, 5, 2};
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
s
```

+++ {"slideshow": {"slide_type": "fragment"}}

Du coup, accéder au i-ième élément n'a pas de sens :

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
s[0]
```

+++ {"slideshow": {"slide_type": "slide"}}

### Multi-ensembles (`multiset`)

+++ {"slideshow": {"slide_type": "fragment"}}

Si l'on ne souhaite pas tenir compte de l'ordre mais tout de même
des répétitions, on peut utiliser un multi-ensemble (`multiset`) :

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
multiset<int> m = { 3, 2, 5, 2 };
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
m
```

```{code-cell}
:tags: []

m[0]
```

+++ {"slideshow": {"slide_type": "slide"}, "tags": []}

## Boucle `for each`

<!-- TODO: rajouter syntaxe / sémantique !-->

+++ {"slideshow": {"slide_type": "fragment"}}

Une opération omniprésente sur une collection est de parcourir
toutes ses valeurs : jusqu'ici on l'a fait à l'aide d'un index :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include<vector>
#include<iostream>
using namespace std;
vector<int> v = { 3, 2, 5, 2 };
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
for ( int i=0; i < v.size(); i++ ) {
    cout << v[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

C'est un peu lourd, et sujet à erreurs. Surtout, cela ne se
généralisera pas aux ensembles! (pourquoi?).

+++ {"slideshow": {"slide_type": "fragment"}}

À la place nous allons littéralement écrire «pour toute `valeur` dans
`v` faire ...» :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
for ( auto valeur: v ) {
    cout << valeur << endl;
} 
```

+++ {"slideshow": {"slide_type": "fragment"}}

C'est l'équivalent du `for valeur in v:` de Python.
Et cela fonctionnera tout aussi bien pour toute autre collection :

```{code-cell}
#include<set>
set<int> s = { 3, 2, 5, 2 };
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
for ( auto valeur: s ) {
    cout << valeur << endl;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
tags: []
---
multiset<int> m = { 3, 2, 5, 2 };
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
for ( auto valeur: m ) {
    cout << valeur << endl;
}
```

+++ {"slideshow": {"slide_type": "slide"}, "tags": []}

:::{prf:example}
Quelle est la valeur de `m` après l'instruction suivante?
:::

```{code-cell}
:tags: []

#include<vector>
using namespace std;
vector<int> m = { 3, 2, 5, 2 };
```

```{code-cell}
:tags: []

for ( auto valeur: m ) {
    valeur = 1;
}
```

```{code-cell}
:tags: []

m
```

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{attention}
Pour être complètement précis, `valeur` ne parcourt pas les valeurs de la collection,
mais des copies de celles-ci. Aussi, une affectation `valeur=...` ne change
pas le tableau d'origine.

Vous verrez au second semestre comment changer cela lorsque souhaitable,
en utilisant une **référence**.
:::

+++ {"slideshow": {"slide_type": "slide"}}

### Digression : à propos de `auto` ♣

Vous vous demandez peut-être quelle est la
signification de `auto`?

On est en train de déclarer une nouvelle variable.
Il faut donc préciser son type. On pourrait très
bien mettre `int` comme type puisque l'on manipule
des collections d'entiers :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
for ( int valeur: v ) {
    cout << valeur << endl;
}
```

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

Mais c'est redondant.

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition} `auto`
***auto*** est un type spécial qui indique à C++ de
sélectionner automatiquement le type adéquat en
fonction du contexte. On appelle cela de
l'[inférence de type](https://fr.wikipedia.org/wiki/Inf%C3%A9rence_de_types).
:::

```{code-cell}
---
slideshow:
  slide_type: fragment
---
auto i = 1;
i
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
auto pi = 3.14;
pi
```
