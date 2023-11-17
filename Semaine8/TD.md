---
exports:
- format: pdf
  output: TD.pdf
  template: ../../template/TD
- format: tex
  output: TDmd.tex
  template: ../../template/TD
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# TD 8 : fichiers et images numériques

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7e93183db2098bd29ed78995489a1978", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 : Fichiers

On considère la fonction `mystere` suivante, avec un exemple d'appel :

:::{literalinclude} manipulation-fichiers-correction.cpp
:start-after: BEGIN mystere
:end-before: END mystere
:::

:::{literalinclude} manipulation-fichiers-correction.cpp
:start-after: BEGIN mystere2
:end-before: END mystere2
:::

Le fichier `truc.txt` contient les premières lignes suivantes :

```
Henry 4
Messi 2
Ronaldo 3
Xavi 2
```

1.  Expliquez ce que fait la fonction `mystere`. Précisez le format
    que doit avoir le fichier. Choisissez des noms plus informatifs
    pour cette fonction et ses variables, et écrivez sa documentation.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  Changez la fonction pour que chaque ligne de la sortie soit de la
    forme :

              Nom : Alfred, note sur 10 : 7, note sur 20 : 14

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a55b7a2f963216c6cf84332e9d0848f2", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : Fichiers

1.  Implantez les deux fonctions suivantes :

    :::{literalinclude} manipulation-fichiers-correction.hpp
    :start-after: BEGIN moyenne
    :end-before: END moyenne
    :::

    :::{literalinclude} manipulation-fichiers-correction.hpp
    :start-after: BEGIN lit_notes
    :end-before: END lit_notes
    :::

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  Lorsque cela est possible, écrivez un test.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

3.  $\clubsuit$ Comment pourrait-on tester la fonction du premier exercice?

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

{latexonly}`\clearpage`

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8756bd503be6888fbf08518a31a64f63", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

{latexonly}`\enlargethispage{6ex}`

::::{admonition} Exercice 3 : Images numériques

Pour manipuler informatiquement une image analogique (continue), on
doit la numériser, c'est à dire l'encoder sous forme d'une image
numérique (discrète). Il en existe deux grandes catégories :

-   Les images vectorielles : une image y est encodée par une
    combinaison de primitives géométriques (lignes, disques, ...)
    auxquelles sont appliquées des transformations.
    En savoir plus : <https://fr.wikipedia.org/wiki/Image_vectorielle>

-   Les images matricielles, ou « carte de points » (de l'anglais
    bitmap): une image y est constituée d'une matrice -- ou tableau ou
    grille -- où chaque case -- appellée pixel -- possède une couleur
    qui lui est propre. Il s'agit donc d'une juxtaposition de carrés
    de couleur formant, dans leur ensemble, une image.
    En savoir plus : <https://fr.wikipedia.org/wiki/Image_matricielle>

    ![Un exemple d'image matricielle](media/DigitalPicture.jpg) 
	%{height="5cm"}

1.  **Images en noir et blanc**.
    Le fichier suivant contient une image en noir et blanc au format
    PBM (*Portable Bit Map*). Devinez comment fonctionne ce format de
    fichier et dessinez l'image correspondante.

    :::{literalinclude} media/smiley.pbm
    :::

    **Indications :** La première ligne précise le format du fichier
    (texte, image noir et blanc); la deuxième est un commentaire; tout
    le reste a un rôle!
    Voir <https://fr.wikipedia.org/wiki/Portable_bitmap>
    pour plus d'informations sur ce format de fichier.

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

2.  **Images en couleur**.
    Le fichier suivant contient une image en couleur au format PPM
    (*Portable Pix Map*). Devinez comment fonctionne ce format de
    fichier et dessinez l'image correspondante.

    :::{literalinclude} media/drapeau.ppm
    :::

    **Indication :** Quelles sont les trois couleurs primaires
    usuelles (pour les écrans)?

    % REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d17cf2f784f3bed69086d1a67b2cdf33", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 : $\clubsuit$

Implantez les fonctions suivantes :

:::{literalinclude} manipulation-fichiers-correction.hpp
:start-after: BEGIN word_count
:end-before: END word_count
:::

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

:::{literalinclude} manipulation-fichiers-correction.hpp
:start-after: BEGIN line_count
:end-before: END line_count
:::

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

:::{literalinclude} manipulation-fichiers-correction.hpp
:start-after: BEGIN cat
:end-before: END cat
:::

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

:::{literalinclude} manipulation-fichiers-correction.hpp
:start-after: BEGIN copy
:end-before: END copy
:::

**Indication :** la bibliothèque standard fournit la fonction
suivante :

``` c++
/** lit une ligne d'un flux et la stocke dans une chaîne de caractères
 *  @param f un flux entrant
 *  @param s une chaîne de caractères
 *  @return le flux entrant
 **/
istream getline(istream &f, string &s);
```

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "823b47cafe460650c714c2c84daa3a4e", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : $\clubsuit$

Devinez ce que fait la fonction `mystereEpais` suivante et écrire un
test :

:::{literalinclude} manipulation-fichiers-correction.cpp
:start-after: BEGIN mystereEpais
:end-before: END mystereEpais
:::

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

{latexonly}`\clearpage`

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1320618450fde0e0ff505b92d9327517", "grade": true, "grade_id": "60", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 6 : $\clubsuit$

On dispose de trois fichiers texte nommés `note1.txt`, `note2.txt`, et
`note3.txt`. Dans chacun d'eux, chaque ligne contient trois
informations, séparées par des espaces : le nom d'un-e étudiant-e, son
groupe, une note. Les trois fichiers pourraient par exemple
correspondre aux notes dans trois matières pour une même promotion.

Écrivez un programme qui:

1.  Fusionne ces trois fichiers en un seul fichier `notes.txt` dont
    chaque ligne aura cinq informations séparées par des espaces :
    `<nom> <groupe> <note1> <note2> <note3>`. On vérifiera au passage
    que les trois fichiers de départ contiennent exactement les mêmes
    noms d'étudiant-es et dans le même ordre.

2.  Crée un fichier par groupe, qui indiquera, pour chaque étudiant-e
    de ce groupe, sa note moyenne (moyenne des trois notes), au format
    `<nom> <note_moyenne>`.  Les fichiers seront nommés
    `groupeB5.txt`, `groupeA1.txt`, `groupeC3.txt`.  Ce programme doit
    pouvoir fonctionner quel que soit le nombre de groupes et quels
    que soient les noms de ces groupes.

% REMPLACEZ CETTE LIGNE PAR VOTRE RÉPONSE

::::

