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

# État d'un fichier (ou d'un flux)

+++ {"slideshow": {"slide_type": "slide"}}

Jusqu'ici nous avions principalement fait du calcul.  Dans ces
derniers, les situations exceptionnelles sont relativement rares :
divisions par zéro, préconditions, ...

Avec les manipulations de fichiers, nos programmes commencent à
interagir avec leur environnement extérieur, environnement que nous ne
contrôlons pas forcément. Il va falloir faire face à des situations
exceptionnelles ou entâchées d'inconnues :

- le fichier existe-t-il?
- quelle longueur fait-il?
- est-il écrit correctement?
- y a-t-il suffisament de place sur mon disque?

De ce fait, les opérations peuvent échouer. 

Dans cette feuille, nous allons voir comment détecter ces échecs pour
pouvoir ensuite les gérer. Cela utilisera la notion d'**état d'un
fichier**.

+++ {"slideshow": {"slide_type": "slide"}}

## Exemple : afficher un annuaire contenu dans un fichier

+++ {"slideshow": {"slide_type": "fragment"}}

Revenons à notre annuaire; celui-ci est stocké dans un fichier
[annuaire.txt](annuaire.txt) dont voici le contenu :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
!cat annuaire.txt
```

+++ {"slideshow": {"slide_type": "fragment"}}

Pour l'afficher, nous pouvons mettre en pratique ce que nous venons de
voir :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
#include <fstream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
ifstream annuaire;
annuaire.open("annuaire.txt");
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string nom;
string tel;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
for ( int i = 0; i < 4 ; i++ ) {
    annuaire >> nom;
    annuaire >> tel;
    cout << nom << ": " << tel << endl;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
annuaire.close();
```

+++ {"slideshow": {"slide_type": "notes"}}

Mais il y a une **inconnue** sur le fichier : combien contient-il
d'entrées?

Notre programme tel quel ne fonctionnera que si le fichier contient
exactement quatre entrées.

+++

:::{admonition} Question
Le code ci-dessus est-il satisfaisant? Pourquoi?
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{attention}
Au lieu de lire un nombre fixé d'entrées, nous voudrions lire les
entrées une à une tant que la lecture se passe bien.
:::

+++ {"slideshow": {"slide_type": "slide"}}

### État d’un fichier

+++ {"slideshow": {"slide_type": "fragment"}}

:::{prf:definition}
Une variable de type fichier peut être dans un *****bon état***** :

-   «jusqu’ici tout va bien»

ou un *****mauvais état***** :

-   fichier non trouvé à l’ouverture, problème de permissions
-   lecture ou écriture incorrecte
-   fin du fichier atteinte
-   plus de place disque
-   etc.
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe
``` c++
        if ( fichier ) { ...
```
``` c++
        if ( fichier >> i ) { ...
```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

-   le fichier est-il en bon état?
-   la lecture s’est elle bien passée?
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Remarque

Si un fichier n'est pas en bon état, il est bien entendu
possible de demander plus d'informations au système pour en déterminer
la cause. Pour ce semestre, le test de bon état sera suffisant pour
nos besoins.

:::

+++ {"slideshow": {"slide_type": "slide"}}

:::{prf:example} Afficher un annuaire contenu dans un fichier

Voici notre programme d'affichage d'annuaire réécrit pour lire dans le
fichier tant que le fichier est en bon état.  C'est-à-dire tant que la
lecture de l'entrée se passe bien.

:::

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
#include <fstream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
ifstream annuaire;
annuaire.open("annuaire.txt");
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
string nom;
string tel;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
while ( annuaire >> nom  and  annuaire >> tel ) {
    cout << nom << ": " << tel << endl;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
annuaire.close();
```

+++ {"slideshow": {"slide_type": "slide"}}

### Bonne pratique : vérifier l’état d’un fichier

+++ {"slideshow": {"slide_type": "fragment"}}

L'autre inconnue est : le fichier existe-t-il?

+++ {"slideshow": {"slide_type": "fragment"}}

:::{hint} Bonne pratique

Toujours vérifier l'état d'un fichier après toute opération pouvant
échouer, et notamment l'ouverture

:::

+++ {"tags": []}

Exemples :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <iostream>
#include <fstream>
using namespace std;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
ifstream fichier;
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
fichier.open("annuaire.txt"); // Un fichier existant
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
if ( not fichier ) {
    cout << "Erreur à l'ouverture" << endl;
}
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
fichier.close();
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
fichier.open("oups.txt");    // Un fichier non existant
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
if ( not fichier ) {
    cout << "Erreur à l'ouverture" << endl;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{hint} Bonne pratique
Pour mieux signaler cette situation exceptionnelle, il est recommandé
d'utiliser les **exceptions**, que nous avons introduites lors du
[cours précédent](../Semaine7/cours-exceptions.md).
:::

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include <stdexcept>
```

```{code-cell}
---
slideshow:
  slide_type: fragment
---
if ( not fichier ) {
    throw runtime_error("Erreur à l'ouverture du fichier");
}
```

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

Lorsque l'on manipule des fichiers, les opérations sont succeptibles
d'échouer. Dans cette feuille, nous avons vu que la notion d'**état de
fichier** permet de détecter de tels échecs pour les traiter. Il est
fortement recommandé de **systématiquement vérifier l'état du fichier
après toute opération pouvant échouer**, et tout particulièrement
après l'ouverture d'un fichier, et de **signaler un tel échec au moyen
d'une exception**.

La notion d'état d'un fichier peut aussi être mise à profit avec
l'idiome «lire dans un fichier tant que la lecture se passe bien».

