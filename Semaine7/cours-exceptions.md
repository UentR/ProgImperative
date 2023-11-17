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

# Signaler et gérer les situations exceptionnelles : les exceptions

+++ {"slideshow": {"slide_type": "skip"}}

Occasionnellement, un programme, ou plus généralement une fonction,
peut rencontrer une situation *exceptionnelle* : c'est-à-dire une
situation qui n'est pas prévue dans les entrées normales. Que faire
dans ce cas? Continuer comme si de rien était pourrait amener toutes
sortes de catastrophes. Renvoyer une valeur arbitraire risquerait
de passer inaperçu par l'utilisateur du programme ou de la fonction.

On souhaite donc arrêter l'exécution de la fonction, en **signalant**
qu'une situation exceptionnelle s'est produite.

+++ {"slideshow": {"slide_type": "slide"}}

## Exemple : gestion d’entrées invalides

+++ {"slideshow": {"slide_type": "fragment"}}

Nous avons vu précédemment la fonction factorielle récursive :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3f4bc4030002f09d5a5163b636fb8e79
  grade: false
  grade_id: cell-f2845efb4e8c1193
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
tags: []
---
int factorielle(int n) {
    if ( n == 0 ) return 1;
    return n * factorielle(n-1);
}
```

```{code-cell}
---
slideshow:
  slide_type: null
tags: []
---
factorielle(4)
```

+++ {"slideshow": {"slide_type": "fragment"}}

Que se passerait-il si on calculait `factorielle(-1)`?

+++ {"slideshow": {"slide_type": "skip"}}

Cela
appellerait `factorielle(-2)` qui à son tour appellerait
`factorielle(-3)`, et ainsi de suite. Jusqu'à ce que le programme
plante. Allez-y, essayez pour voir ci-dessus. Et tenez-vous prêt à
redémarrer le noyau!

+++ {"slideshow": {"slide_type": "fragment"}}

L'entrée `-1` n'est pas prévue par la fonction. C'est une situation
**exceptionnelle** que l'on souhaiterait **signaler** immédiatement et de
façon plus informative que par un simple plantage.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c992370f41ff375f18fea455563761f4
  grade: false
  grade_id: cell-b58dbae0de2d20f7
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
#include <stdexcept>
using namespace std;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9c4c4cd979917145641212c11850ef0d
  grade: false
  grade_id: cell-a51e9e5f2d9ab521
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
tags: []
---
int factorielle(int n) {
    if ( n  < 0 ) throw invalid_argument("n doit être positif");
    if ( n == 0 ) return 1;
    return n * factorielle(n-1);
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 6d03feff4512fe90d111e9bbeb8de3b5
  grade: false
  grade_id: cell-f07aa79d9ed20984
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
tags: []
---
factorielle(4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f85e6d5d6548ecff051bb8718cef1dae
  grade: false
  grade_id: cell-306f3e20bff2186c
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: null
tags: []
---
factorielle(-1)
```

+++ {"slideshow": {"slide_type": "skip"}}

Maintenant, l'utilisateur est satisfait : l'exécution
de `factorielle` s'est immédiatement arrêté, avec un
message d'erreur explicite sur le problème rencontré.

+++ {"slideshow": {"slide_type": "skip"}}

Nous allons maintenant expliquer les différents
éléments utilisés : `throw` (lancer), `invalid_argument` et
la bibliothèque `stdexcept`.

+++ {"slideshow": {"slide_type": "slide"}}

## Signaler une exception

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

```
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

-   Une situation exceptionnelle que je ne sais pas gérer s’est
    produite.
-   Je m’arrête immédiatement et je préviens mon «chef» (l'utilisateur
    ou la fonction appelante).
-   On dit qu’on **signale une exception**.
-   La situation est décrite par l'exception `e`  
    `e` est un objet quelconque; par exemple une **exception standard**.
-   Si à son tour mon «chef» ne sait pas gérer, il prévient son «chef».
-   …
-   Si personne ne sait gérer, *le programme s’arrête*.
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Quelques exceptions standard

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

Les erreurs dans les programmes peuvent être classifiée
en plusieurs types classiques; ci-dessus, il s'agissait
d'un «argument invalide». Dans d'autre cas, cela peut
être un problème d'allocation, une erreur arithmétique,
etc. Cette classification aide le lecteur et l'utilisateur
à mieux analyser les erreurs et, par exemple, décider du
comportement à adopter face à l'une d'elle.

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

Pour cela, la bibliothèque standard `stdexcept` fournit
plusieurs types d'***exceptions standard*** qui forment
une hiérarchie avec, tout en haut, le type le moins
spécifique `exception`.

+++ {"slideshow": {"slide_type": null}, "tags": []}

(exceptions_standard)=
:::{admonition} Quelques exceptions standard
-   `exception`
-   `runtime_error`
-   `invalid_argument`, `out_of_range`, `length_error`
-   `logic_error`, `bad_alloc`, `system_error`
-   ...
:::

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{exercise}
Essayez de deviner le rôle de chacune des exceptions standard ci-dessus
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Gestion d’exception

+++ {"slideshow": {"slide_type": "fragment"}}

### Exemple 1 : ouvrir accidentellement un fichier inexistant depuis une application

Imaginez que vous utilisiez votre traitement de texte, et que
vous lui demandiez d'ouvrir un fichier qui n'existe pas.
Pour la fonction en charge d'ouvrir ce fichier, c'est une
situation exceptionnelle. Pour autant, serait-il acceptable que
le traitement de texte plante avec juste un petit message
«fichier inexistant»?

+++ {"slideshow": {"slide_type": "fragment"}}

Non : pour un traitement de texte, ce n'est pas une situation
exceptionnelle. Il sait gérer : prévenir l'utilisateur que
le fichier n'existe pas, puis continuer normalement.

+++ {"slideshow": {"slide_type": "fragment"}}

**Une situation peut-être exceptionnelle pour une fonction, sans
qu'elle le soit pour son «chef»**.

+++ {"slideshow": {"slide_type": "fragment"}}

Il nous faut donc un mécanisme par lequel le «chef» puisse prendre la main et gérer la situation.

+++ {"slideshow": {"slide_type": "fragment"}}

### Exemple 2

Nous allons considérer un scénario similaire, en plus simple : un
programme qui demande un nombre $n$ à l'utilisateur et affiche la
factorielle de ce nombre.  Pour ce programme, ce n'est pas
exceptionnel que l'utilisateur fasse des bêtises en saisissant une
valeur invalide. Le programme sait gérer, en affichant un petit
message avant de continuer.

Voilà comment cela s'écrit. Pour que tout soit au même endroit, nous rappelons
d'abord la définition de la fonction factorielle.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 343bcc0439e37089f40288c7827a2353
  grade: false
  grade_id: cell-ce7bab8e19b5c2c9
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
#include <stdexcept>
using namespace std;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a86563cd90f9f13922cfacfefeb690ab
  grade: false
  grade_id: cell-77f927ef9fe02810
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
int factorielle(int n) {
    if ( n  < 0 ) throw invalid_argument("n doit être positif");
    if ( n == 0 ) return 1;
    return n * factorielle(n-1);
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 879dc044770e4ea8109329e9e4100e51
  grade: false
  grade_id: cell-297c4f2f3e944b2c
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
#include <iostream>
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3ab75cd8339f115484eb7b718fae3db9
  grade: false
  grade_id: cell-42039d542c5acba6
  locked: true
  schema_version: 3
  solution: false
  task: false
slideshow:
  slide_type: fragment
---
int n;
cout << "Veuillez saisir un nombre entier positif:" << endl;
cin >> n;
try {
    int f = factorielle(n);
    cout << "Factorielle n vaut " << f << endl;
} catch (invalid_argument & e) {
    cout << "Valeur de n invalide: " << n << endl;
}
cout << "Je continue ..." << endl;
```

+++ {"slideshow": {"slide_type": "skip"}}

Les deux éléments nouveaux sont `try` (essayer) et `catch` (rattraper l'erreur).
En voici la signification.

+++ {"slideshow": {"slide_type": "slide"}}

## Gestion des exceptions ♣

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

``` c++
    try {
        bloc d instructions;
    } catch (type & e) {
        bloc d instructions;
    }
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

-   Exécute le premier bloc d’instructions
-   Si le bloc signale une exception de type `type`, ce n’est pas grave, je
    sais gérer :
    -   L’exécution du premier bloc d’instruction s’interrompt
    -   Le deuxième bloc d’instructions est exécuté
:::

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

- Nous avons vu comment **signaler une situation exceptionnelle**
  (communément appellée erreur) lors de l'exécution d'un programme
  ou d'une fonction.

  Cela se fait avec `throw e` où `e` est une **exception**.
  Cette dernière est typiquement construite avec l'un des types d'exceptions
  de la bibliothèque standard `stdexcept`.

+++ {"slideshow": {"slide_type": "fragment"}}

- Les fonctions appelantes peuvent alors **gérer cette exception**,
  à l'aide de `try ... catch ...`.
  Si aucune d'entre elles ne gère l'exception, alors le programme s'arrête.

+++ {"slideshow": {"slide_type": "fragment"}}

Il y aurait bien d'autres choses à dire sur les exceptions, mais cela
sera suffisant pour notre usage ce semestre.

