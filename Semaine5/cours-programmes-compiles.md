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

# Premiers programmes compilés en C++

+++ {"slideshow": {"slide_type": "notes"}}

::::{admonition} Objectif pédagogique

Jusqu'à présent, vous avez programmé dans des carnets Jupyter. Ces
carnets sont conçus pour du calcul interactif, où l'utilisateur
manipule quelques lignes de code s'intégrant dans un texte narratif,
comme dans ces notes de cours. Cela se prête très bien aux premiers
pas en programmation. En revanche, pour écrire de plus gros
programmes, les carnets Jupyter ne sont plus adaptés [^1]. Il est
alors souhaitable de passer à des **programmes compilés**. C'est en
fait l'usage le plus courant de `C++`.

[^1]: Les calculs
eux-même peuvent être massifs: Jupyter est ainsi utilisé au CERN
pour certaines analyses interactives de téraoctets de données
provenant d'expériences de physique des particules au moyen
de bibliothèques comme [`ROOT`](https://fr.wikipedia.org/wiki/ROOT).

Cette semaine, vous allez compiler vos premiers programmes `C++`.
Dans les semaines qui viennent, nous allons progressivement basculer
d'un usage majoritairement dans des carnets interactifs à un usage
majoritairement en compilé, tout particulièrement pour le projet.

::::

+++ {"slideshow": {"slide_type": "slide"}}

## Premier exemple

Votre répertoire `ProgImperative/Semaine5/`
contient un fichier [max.cpp](max.cpp), dont voici
le contenu (ignorer le `%% file max.cpp`) :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
%%file max.cpp
#include <iostream>
using namespace std;

float max(float a, float b) {
    if ( a >= b ) {
        return a;
    } else {
        return b;
    }
}

int main() {
    cout << max(1.5, 3.0) << endl;
    cout << max(5.2, 2.0) << endl;
    cout << max(2.3, 2.3) << endl;

    return 0;
}
```

+++ {"slideshow": {"slide_type": "fragment"}}

C'est un programme indépendant. Il n'est pas directement
compréhensible par un ordinateur ; il faut au préalable le
transformer : cette opération s'appelle la **compilation**.
Dans ce cours, nous allons utiliser le compilateur `clang++`,
avec la commande suivante dans le terminal :
```
clang++ max.cpp -o max
```

<!-- +++

Lançons cette commande directement depuis cette feuille (voir [commandes-terminal-dans-jupyter](commandes-terminal-dans-jupyter.md)).

```{code-cell}
! g++ max.cpp -o max
```
!-->

+++ {"slideshow": {"slide_type": "fragment"}}

Exécuter cette commande produit un fichier `max` qui, lui, est en
binaire : il illisible pour un humain, mais directement exécutable par
l'ordinateur. Nous pouvons l'exécuter depuis un terminal avec
```
./max
```

<!--
```{code-cell}
! ./max
```
!-->

+++ {"slideshow": {"slide_type": "slide"}}

### Syntaxe et sémantique; fonction `main`

Revenons au fichier [max.cpp](max.cpp). Vous remarquerez qu'il y a
plusieurs fonctions, mais aucune instruction en dehors de ces
fonctions. Si on regarde l'affichage, on constate que la fonction
`main` a été appellée (et qu'elle a appelé à son tour la fonction
`max`). Il est temps d'expliquer tout cela en détail.

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Syntaxe

Un programme à compiler est composé d'un fichier avec extension `.cpp` contenant :
- Éventuellement un entête : inclusion de bibliothèque, déclaration de variables, ...
- Une ou plusieurs fonctions  
    Une de ces fonctions doit s'appeler `main` (*fonction principale*).
    Elle ne prend pas de paramètre et renvoie un entier :
    ```c++
    int main () {
        ...
        return 0;
    }
    ```
:::

+++ {"slideshow": {"slide_type": "fragment"}}

:::{admonition} Sémantique

-   Au lancement du programme, la fonction `main` est exécutée
-   Convention : la fonction renvoie :
    -   0 si l'exécution du programme s'est déroulée normalement
    -   Un entier différent de 0 en cas d'erreur  
        Cet entier indique quel genre d'erreur s'est produite

:::

+++ {"slideshow": {"slide_type": "skip"}}

Si vous travaillez sur ce cours de façon autonome, cela peut être un
bon moment de vous entraîner sur la feuille d'exercice
[`Programmes compilés`](programmes-compiles.md) du TP.

+++ {"slideshow": {"slide_type": "slide"}}

## La fonction `main` : paramètres ♣

Les commandes du terminal, telles que `cd` ou `mkdir` peuvent prendre
des paramètres. Par exemple ici on passe les paramètres `fetch` et
`Semaine5` à la commande `info-111` :
```
info-111 fetch Semaine1
```

On peut souhaiter de même écrire en `C++` des programmes qui prennent
des paramètres sur la ligne de commande.

+++ {"slideshow": {"slide_type": "fragment"}}

**Exemple :**

1. Copiez le programme suivant dans un fichier `bonjour-nom.cpp` :

    ```c++

    #include <iostream>
    using namespace std;

    int main(int argv, char ** args) {
        string nom1 = args[1];
        string nom2 = args[2];

        cout << "Bonjour " << nom1 << "!" << endl;
        cout << "Bonjour " << nom2 << "!" << endl;
        return 0;
    }
    ```

+++ {"slideshow": {"slide_type": "fragment"}}

2. Compilez-le
3. Éxecutez le sous la forme :

	```
    ./bonjour-nom Jean Paul
	```

4. Observez le résultat ; cela devrait être :

   ```
   Bonjour Jean!
   Bonjour Paul!
   ```

+++ {"slideshow": {"slide_type": "fragment"}}

:::{hint} Explications

Les trois premières lignes ne sont pas très compréhensibles, n'est-ce
pas?  pour le moment, vous pouvez prendre ces lignes comme des
incantations magiques.

Très brièvement : cela provient du `C` dont hérite `C++`. Il se trouve
qu'il n'y a pas en `C` de chaîne de caractères à proprement parler ;
on les émule avec des *pointeurs sur des caractères* : `char *`. De
même pour les tableaux. Ensuite :

- `argv` contient le nombre de paramètres sur la ligne de commande : ici 2
- `**args` contient les paramètres eux-même

Tout cela vous sera expliqué en détail au second semestre.

:::

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé

Nous avons vu comment compiler un programme `C++` et le rôle
de la fonction `main`. C'est tout ce que vous avez besoin de
savoir pour cette semaine. Nous reviendrons sur le rôle de la
compilation plus tard dans le semestre.
