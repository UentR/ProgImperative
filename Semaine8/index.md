---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d6b46a0a95cd43ae80dbc181dc125671", "grade": false, "grade_id": "cell-10", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# Semaine 8 : fichiers et flux de données

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e91144c7864a653c34cf89f2e5ad772d", "grade": false, "grade_id": "cell-20", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## <a name=Cours/>[Cours](cours.md)
- Cours : [fichiers](cours-fichiers.md)
- Cours : [état d'un fichier](cours-etat-fichier.md)
- Cours : [lecture au clavier](cours-lecture-clavier.md)
- Cours : [lecture et écriture dans des chaînes de caractères](cours-flux-chaines-de-caracteres.md)
- Cours : [flux de données](cours-flux.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dbf5500bedb753c425b378e4748347d6", "grade": false, "grade_id": "cell-30", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## [TD : fichiers et images numériques](TD.md)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bf4d86ed29ba34ce66bdbc753d794093", "grade": false, "grade_id": "cell-40", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## TP

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9dd26fe469908352fac43de3f823d14a", "grade": false, "grade_id": "cell-50", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 1 : écrire dans un fichier - 20 minutes

+++

::::{hint} Rappels

-   Pour exécuter un programme, il faut d’abord avoir compilé le
    fichier `.cpp` avec la commande `clang++` puis lancer l’exécutable
    créé par la compilation. Consulter au besoin les instructions des
    TP précédents.
-   Pensez à organiser votre espace de travail et à ajuster la taille
    des caractères (avec <kbd>Ctrl</kbd>-<kbd>+</kbd> et
    <kbd>Ctrl</kbd>-<kbd>-</kbd>) pour avoir une vue confortable
    simultanée de tous les éléments requis : consignes, code,
    terminal.

    :::{figure} https://nicolas.thiery.name/Enseignement/Info111/media/screencast-espace-de-travail-compilation.gif
    Vidéo: organiser son espace de travail avec JupyterLab
    :::


::::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "788d8e3332d2a55115dbe62781b8625f", "grade": false, "grade_id": "cell-60", "locked": true, "schema_version": 3, "solution": false, "task": false}}

1.  Consultez le fichier [fichier-ecriture.cpp](fichier-ecriture.cpp).

2.  Essayez de deviner ce que fait ce programme.

3.  Exécutez ce programme.
    
4.  Trouvez le fichier `.txt` qui a été créé à l’exécution et l’ouvrir
    avec un éditeur de texte. Que contient-il?

5.  Copiez le contenu de [fichier-ecriture.cpp](fichier-ecriture.cpp)
    dans [fichier-ecriture-v2.cpp](fichier-ecriture-v2.cpp), et
    adaptez le pour qu’à l’exécution il écrive un fichier nommé
    `essai.txt` contenant le texte «17 fois 23 vaut» suivi de la
    valeur de ce nombre (valeur que le programme calcule par
    lui-même).

6.  Exécutez ce programme puis ouvrez le fichier `essai.txt` afin de
    vérifier son contenu.

7.  Lisez et essayez à nouveau les exemples du cours [lecture depuis
    le clavier](cours-lecture-clavier.md).

8.  En vous en inspirant, complétez le programme [cin.cpp](cin.cpp)
    pour que, à l’exécution, il demande à l’utilisateur d’entrer deux
    entiers, puis qu’il écrive un fichier nommé `multiplication.txt`
    contenant un texte similaire au fichier `essai.txt` de la question
    précédente, avec 17 et 23 remplacés respectivement par les deux
    entiers choisis par l’utilisateur.
    
    :::{note}
    
    Pour faire des affichages à l’écran et pour faire saisir des
    données depuis le clavier, il faut inclure la bibliothèque
    `iostream` en écrivant `#include <iostream>`. Pour lire et écrire
    dans un fichier de texte, il faut inclure la bibliothèque
    `fstream` en écrivant `#include <fstream>`

    :::

9.  Exécutez le programme puis ouvrez le fichier `multiplication.txt`
    pour vérifier son contenu.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cb2c18e19c408b69d4d8589c8f7649cd", "grade": false, "grade_id": "cell-70", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 2 : ouvrir le smiley - 5 minutes

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d663ac278d9f0e11ecad5a893da72d3b", "grade": false, "grade_id": "cell-80", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Le fichier [media/smiley.pbm](media/smiley.pbm) (dans le répertoire
`media` donc!) contient l’image en noir et blanc du TD.

-   Ouvrez ce fichier d’abord avec un éditeur de texte.

-   Ouvrez ce même fichier avec un logiciel de vision d’images. Pour
    cela, depuis Jupyter, vous pouvez utiliser la cellule ci-dessous :

```{code-cell} ipython3
from open_ppm import open_ppm                # importe la commande open_ppm fournie
im = open_ppm("media/smiley.pbm")            # charge l'image
im.resize((256*im.width // im.height, 256))  # affiche l'image avec une taille donnée
```

:::{admonition} Pour les curieux
:class: dropdown

Python et Jupyter ne savent pas manipuler nativement les fichiers aux
formats PBM, PGM ou PPM non compressés. La commande
`open_ppm('xxx.ppm')` fournie dans le fichier
[open_ppm.py](open_ppm.py) commence par utiliser l'utilitaire
`convert` de `ImageMagick` avec `convert xxx.ppm xxx.png` pour
convertir l'image en format PNG.

:::

Alternativement :
-   Sous Windows, vous pouvez utiliser l’application `irfanview`.
-   Sous Linux, vous pouvez utiliser l’application `xviewer` :
    utilisez «Control +» et «Control -» pour zoomer /
    dezoomer. Vous remarquerez que l’image est lissée / floutée. Allez
    dans le menu «Edit -> Preferences» et décochez «Smooth images when
    zoomed in» pour mieux voir les pixels.

### Exercice 3 : petit damier - 15 minutes

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6306697bfa8cd2f7698a6961377db9f9", "grade": false, "grade_id": "cell-90", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Utilisez un éditeur de texte pour écrire à la main un *fichier*
    `damier.pbm` contenant une image au format PBM
    ([*Portable Bit Map*](http://fr.wikipedia.org/wiki/Portable_bitmap))
    de taille 10x10 représentant un damier:

    :::{image} media/damier_svg.png
    :width: 10%
    :alt: un damier
    :::

-   Visualisez le résultat, par exemple avec :

```{code-cell} ipython3
from open_ppm import open_ppm
im = open_ppm("damier.pbm")
im.resize((256*im.width // im.height, 256))
```

#### Tests automatiques

```{code-cell} ipython3
assert im.size == (10, 10)
```

```{code-cell} ipython3
import numpy as np
M = np.array(im, dtype=int)
assert np.all(M[1:,:] + M[:-1,:] == 1), "l'image n'est pas un damier horizontalement"
assert np.all(M[:,1:] + M[:,:-1] == 1), "l'image n'est pas un damier verticalement"
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "65237cca3ba3cf9fb579a874a7f3f6b1", "grade": false, "grade_id": "cell-100", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 4 : grand damier

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "792992fb2ce3f4d9bf342c4bee84e65a", "grade": false, "grade_id": "cell-110", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Complétez le **programme C++** [damier.cpp](damier.cpp) qui, lorsqu’on
l’exécute, écrit un fichier image `damier-automatique.pbm` comme le
précédent, mais cette fois pour un damier 100x100.

Visualisez et vérifiez au fur et à mesure le résultat avec :

```{code-cell} ipython3
im = open_ppm("damier-automatique.pbm")
im.resize((512*im.width // im.height, 512))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8150bc8b45aed59b3f82be849ea3846b", "grade": false, "grade_id": "cell-120", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{hint} Indications

-   Vous pouvez vous inspirer de [fichier-ecriture.cpp](fichier-ecriture.cpp).
-   Commencez par un programme pour un damier 10x10 avant de passer à
    100x100.
-   *Si le fichier produit ne donne pas l’image attendue, ouvrez-le
    avec un éditeur de texte pour mieux comprendre ce qu’il se passe
    et aider au débogage. Vous pouvez aussi, si cela vous aide, faire
    dans un premier temps des affichages à l’écran avec `cout`, puis
    écrire dans le fichier dans un deuxième temps.*
:::

+++

#### Tests automatiques

```{code-cell} ipython3
assert im.size == (100, 100), "l'image produite n'est pas de taille 100x100"
```

```{code-cell} ipython3
import numpy as np
M = np.array(im, dtype=int)
assert np.all(M[1:,:] + M[:-1,:] == 1), "l'image n'est pas un damier horizontalement"
assert np.all(M[:,1:] + M[:,:-1] == 1), "l'image n'est pas un damier verticalement"
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fec81568499bca600d3cae6fb9dc41c0", "grade": false, "grade_id": "cell-130", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 5 : dégradé de gris

Pour créer une image avec des nuances de gris, il faut enregistrer un
fichier de texte au format PGM ([Portable Gray Map](http://fr.wikipedia.org/wiki/Portable_graymap)). Ce fichier doit
contenir des nombres entre 0 et une valeur maximale (au choix) qui
représenteront les différentes nuances de gris.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ffbececdeb470659c27cfea116e0ff0c", "grade": false, "grade_id": "cell-140", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Écrivez à la main, dans un éditeur de texte, un fichier `essai.pgm`
    représentant une image de 10 pixels par 10 pixels, contenant
    différentes nuances de gris de votre choix. Ouvrez ce fichier avec
    un logiciel de visualisation d’images pour voir le résultat.

```{code-cell} ipython3
open_ppm("essai.pgm").resize((256*im.width // im.height, 256))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b14b41766d2a82f0079f54888ea5e003", "grade": false, "grade_id": "cell-150", "locked": true, "schema_version": 3, "solution": false, "task": false}}

3.  Implantez un programme [degrade.cpp](degrade.cpp) qui écrit un
    fichier contenant une image `degrade.pgm` de taille 128 par 128,
    avec un dégradé de gris comme celui-ci :

    :::{image} media/degrade.png
    :width: 20%
    :alt: un dégradé de gris
    :::

```{code-cell} ipython3
open_ppm("degrade.pgm").resize((512*im.width // im.height, 512))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3e9a95690ff0ed2f03fa8a30dd25653b", "grade": false, "grade_id": "cell-160", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-   Répétez, avec une image de taille 100x100

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9c9224e94d136176282b95357c8edd88", "grade": false, "grade_id": "cell-170", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 6 : inversion d’image

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f3fa5bea0ea3429d63f52fd66e7d3369", "grade": false, "grade_id": "cell-180", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Implantez un programme [videoInverse.cpp](videoInverse.cpp)
qui lit un fichier contenant une image au format
PGM (par exemple le fichier `media/image.pgm` fourni), et écrit un fichier
contenant la même image en vidéo inverse (clair remplacé par sombre et
réciproquement).

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2a4cc77ee0d0dcd169aad954bff7fd0a", "grade": false, "grade_id": "cell-190", "locked": true, "schema_version": 3, "solution": false, "task": false}}

:::{hint} Indication Implantez une fonction

``` c++
    /** Image en vidéo inverse
     * @param image1: le nom du fichier contenant l'image à lire
     * @param image2: le nom du fichier pour l'image à écrire
     **/
    void videoInverse(string image1, string image2);
```
:::

```{code-cell} ipython3
open_ppm("imageInv.pgm").resize((512*im.width // im.height, 512))
```

```{code-cell} ipython3
open_ppm("media/image.pgm").resize((512*im.width // im.height, 512))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8e4c6932227912a0021029a54216d0ec", "grade": false, "grade_id": "cell-200", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Exercice 7 : dégradé circulaire de rouge ♣

```{code-cell} ipython3
open_ppm("degrade-circulaire.ppm").resize((256*im.width // im.height, 256))
```

```{code-cell} ipython3
open_ppm("media/drapeau.ppm").resize((256*im.width // im.height, 256))
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d851a2059cf8bba5199c7f1a66af3656", "grade": false, "grade_id": "cell-210", "locked": true, "schema_version": 3, "solution": false, "task": false}}

1.  Implantez un programme [degrade-circulaire.cpp](degrade-circulaire.cpp)
    qui écrit un fichier contenant une image
    `degrade-circulaire.ppm` au format PPM de taille 255 par 255, avec
    un dégradé circulaire de rouge:  

    :::{image} media/degrade-circulaire.png
    :width: 20%
    :alt: un dégradé circulaire
    :::

2.  Répétez, avec une image de taille 100x100.

```{code-cell} ipython3

```
