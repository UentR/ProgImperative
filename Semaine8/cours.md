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

# Fichiers et flux

+++ {"slideshow": {"slide_type": "fragment"}}

## Prélude

+++ {"slideshow": {"slide_type": "slide"}}

### Annonces
% +++ {"slideshow": {"slide_type": "slide"}}
% 
% ### Annonces
%
% +++ {"slideshow": {"slide_type": "slide"}}
%  
% <img src="https://www.fetedelascience.fr/sites/default/files/styles/article_big/public/2020-08/Duras%20-%20Jonglerie%20musicale%20-%20Philippe%20Cibile%201.jpg?itok=fgTVk-pQ" style="width:30%; float: right;">
%  
% #### Conférence spectacle : «Jonglerie Musicale et Combinatoire»
%  
% - Jeudi 10 novembre, 11h00-12h10, 336-H5  
%   (créneau d'amphi Introduction à l'informatique)  
% - Florent Hivert et Vincent Delavenère
%  
% +++ {"slideshow": {"slide_type": "fragment"}}
%  
% [<img src="https://Nicolas.thiery.name/osmose-2022.jpg" style="width:30%; float: right;">](https://Nicolas.thiery.name/osmose-2022.jpg)
%  
% #### Concert de l'ensemble vocal Osmose
%  
% - Dimanche 13 novembre, 16h-17h30, Orsay
% - Bach, Zelenka, ...

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{admonition} Bêta test brevet IA
- Ce soir, 16h, salle 209
- Il reste quelques places
:::

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{admonition} Tutorat
- Ce soir, 16h, salle du BIP
- Qui prévoit d'y aller?
:::

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{admonition} Projet
- Sujets disponibles au téléchargement en cours de semaine
:::

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

:::{admonition} Correction examen
- Bien avancé
:::

+++ {"slideshow": {"slide_type": "slide"}}

### Résumé des épisodes précédents

+++ {"slideshow": {"slide_type": "fragment"}}

**Manipulation de collections de données**

**Fil conducteur :** Implantation d'un annuaire

+++ {"slideshow": {"slide_type": "fragment"}}

-   Tableaux : valeurs composites homogènes: `vector<...>`
-   Sémantique, modèle mémoire avec pile et tas
-   Généralisations: collections, tableaux 2D
-   La boucle «pour tout» : `for ( auto valeur: collection ) { ... }`

+++ {"slideshow": {"slide_type": "fragment"}}

**<div style="color: red; text-align: center;">Pourquoi aller plus loin?</div>**

+++ {"slideshow": {"slide_type": "fragment"}}

**<div style="color: red; text-align: center;">Pour passer à l'échelle!</div>**

+++ {"slideshow": {"slide_type": "slide"}}

### Étude de cas : afficher un annuaire

+++ {"slideshow": {"slide_type": "fragment"}}

Revenons sur le programme que nous avions écrit pour afficher un annuaire :

```{code-cell}
---
slideshow:
  slide_type: fragment
---
#include<vector>
#include<iostream>
using namespace std;

vector<string> noms = {
    "Jeanne", 
    "Franck", 
    "Marie", 
    "Joël"
};
vector<string> telephones = {
    "04 23 23 54 56", 
    "03 23 42 34 26", 
    "06 52 95 56 06",
    "07 23 63 92 38"
};

for (int i=0; i < noms.size(); i++) {
    cout << noms[i] << " " << telephones[i] << endl;
}
```

+++ {"slideshow": {"slide_type": "notes"}}

Imaginons maintenant que le carnet de contacts sur nos téléphones
adopte la même approche. Les données étant une partie intégrante
du programme, nous devrions chacun avoir un programme différent,
alors que seules les données changent d'une personne à l'autre.

De plus, toute modification dans l'annuaire est volatile :
toute modification qui a pu avoir lieu pendant l'exécution
du programme (par exemple l'ajout d'un contact) est perdue
au moment où celui-ci s'arrête.

+++ {"slideshow": {"slide_type": "slide"}}

Nous avons besoin :
- d'une séparation claire entre programme et données;
- d'un stockage persistant des données.

+++ {"slideshow": {"slide_type": "fragment"}}

C'est ce que les **fichiers** vont nous apporter. 

On voudrait pour notre annuaire avoir :

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un fichier `annuaire.txt` :

    ``` default
    Jean-Claude 0645235432
    Albane      0734534534
    Djamila     +1150343234
    Tibo        0634534534
    ```

-   Un programme

+++ {"slideshow": {"slide_type": "fragment"}}

Reste à définir la notion de fichier et à voir comment les manipuler en C++.

+++ {"slideshow": {"slide_type": "slide"}}

### Au programme

- Cours : [fichiers, lecture, écriture](cours-fichiers.md)
- Cours : [état d'un fichier](cours-etat-fichier.md)
- Cours : [lecture au clavier](cours-lecture-clavier.md)
- Cours : [lecture et écriture dans des chaînes de caractères](cours-flux-chaines-de-caracteres.md)
- Cours : [flux de données](cours-flux.md  )

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé du cours

+++ {"slideshow": {"slide_type": "fragment"}}

### Nous avons vu

-   Comment lire et écrire dans des fichiers en C++

+++ {"slideshow": {"slide_type": "fragment"}}

-   Un concept uniforme pour lire et écrire : les **flux**

    -   Entrée et sortie standard d’un programme : `cin`, `cout`
    -   Fichiers : `ifstream`, `ofstream`
    -   Chaînes de caractères : `istringstream`, `ostringstream`

+++ {"slideshow": {"slide_type": "fragment"}}

### Rappel des annonces
- Projet: première séance la semaine prochaine; avancez d'ici là!
- Bureau d'Intervention Pédagogique: maths, physique ET informatique
- Béta-test Brevet IA 16h salle 209

