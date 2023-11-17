---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++11
  language: C++11
  name: xcpp11
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "43d23679145e9d51ddb804b2a82a4f73", "grade": false, "grade_id": "cell-d4b2926be37fb2cd", "locked": true, "schema_version": 3, "solution": false}}

# TP : tableaux : implantation de fonctions classiques

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: bc145e976e46a66a2972e80fd4caaaf5
  grade: false
  grade_id: cell-6e68192042ab603d
  locked: true
  schema_version: 3
  solution: false
---
#include <iostream>
#include <vector>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "00a38af4be996d50915514bc64b26cd8", "grade": false, "grade_id": "cell-1bfca8f35865791d", "locked": true, "schema_version": 3, "solution": false}}

## Exercice: fonctions max et min
On a vu en TD comment calculer le maximum d'un tableau d'entiers. On va maintenant aborder des variantes, comme calculer le maximum d'un tableau de chaînes de caractères. On appellera nos fonctions `monMax` et `monMin` afin d'éviter des conflits avec les fonctions préexistantes de C++.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9a7f045cd03709967e67366e35705b0d", "grade": false, "grade_id": "cell-1bfca8f35865791e", "locked": true, "schema_version": 3, "solution": false}}

Comme les exemples suivants l'illustrent, la comparaison de deux chaînes de caractères se fait -- en C++ comme dans la plupart des langages -- selon l'ordre *lexicographique* (celui du dictionnaire):

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a3593d52bbe14f5b36e13a9cb10f1356
  grade: false
  grade_id: cell-aeced620083c618f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
string("alice") < string("bob")
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 18f96c079c614bb30204de3172544b19
  grade: false
  grade_id: cell-8ce769104565ac9f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
string("alice") < string("alain")
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d33284f86d9c88f440155caee272f902", "grade": false, "grade_id": "cell-1bfca8f35865791f", "locked": true, "schema_version": 3, "solution": false}}

1. Implanter la fonction `monMax` dont la documentation est donnée ci-dessous, qui prend en entrée un tableau d'entiers et renvoie le plus grand.  
   **Indication:** Si besoin, inspirez vous de la fonction `mystere` de l'exercice 2 du TD (mais le mieux est de savoir le faire seul).

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 24bc8bf6edc45019a94c3bb0e00531c3
  grade: false
  grade_id: cell-3e0896eeb8fa63a1
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Maximum d un tableau d entiers
 * @param t un tableau d entiers
 * @return l élément le plus grand du tableau
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: de87ffa355d73f7c4ffb04023a291a79
  grade: false
  grade_id: cell-ea160bfe473bd50f
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int monMax(vector<int> t) {
    int Max = t[0];
    for (int i : t) {
        if (i > Max) { Max = i; }
    }
    return Max;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3ca00e0de4fdcd86938e0079fa76eca4", "grade": false, "grade_id": "cell-042fe17d7e36a862", "locked": true, "schema_version": 3, "solution": false}}

- Vérifier que la fonction se comporte comme prévu :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 70919d4aa4d193793a62ef56c10a617a
  grade: false
  grade_id: cell-0c6b3a31d3b84fe6
  locked: true
  schema_version: 3
  solution: false
---
monMax( { 5, -1, 3, 7, -4, 8, 4 } )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fb95922771d748eb2a89d3d91d9ac6e6
  grade: true
  grade_id: cell-fafebe681c8d29f6
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( monMax( { 5 }) == 5 );
CHECK( monMax({ 5, -1, 3, 7, -4, 8, 4 }) == 8 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0e6dc4555fcbdb2a53def0cf52674b51", "grade": false, "grade_id": "cell-4741ac671c75af58", "locked": true, "schema_version": 3, "solution": false}}

2. Écrire la documentation puis implanter la fonction `monMin` qui prend en entrée un tableau de chaînes de caractères et renvoie la plus petite pour l'ordre lexicographique  :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: e88291729c028010a0c016ea074a152b
  grade: false
  grade_id: cell-4442f84c4f5d4d31
  locked: true
  schema_version: 3
  solution: true
  task: false
---
/** Minimum d un tableau d entiers
 * @param t un tableau d entiers
 * @return l élément le plus petit du tableau
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: cf1ff8013ba4514e40d32140cca8c00e
  grade: false
  grade_id: cell-af307c8be3808867
  locked: false
  schema_version: 3
  solution: true
  task: false
---
string monMin(vector<string> t) {
    string Min = t[0];
    for (string i : t) {
        if (i < Min) { Min = i; }
    }
    return Min;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cfec5eae87c6025958936ef8748ebb51
  grade: false
  grade_id: cell-6bc8dac069906344
  locked: true
  schema_version: 3
  solution: false
---
monMin( { "bonjour", "allo", "xylophone", "fonction", "schtroumpf" } )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "6535192a6d1b4562323382189e311110", "grade": false, "grade_id": "cell-513feee389fc298c", "locked": true, "schema_version": 3, "solution": false}}

- Le test précédent était manuel. Transformer le en test automatique équivalent, en utilisant `CHECK` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: e68a51f5ca354d520af9760f8b4332de
  grade: true
  grade_id: cell-fafebe681c8d29f5
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
CHECK( monMin({ "bonjour", "allo", "xylophone", "fonction", "schtroumpf" }) == "allo" )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1a3e6650e34d957cfb90b6eab5236d60
  grade: true
  grade_id: cell-fafebe681c8d29f7
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( monMin( { "coucou"}) == "coucou" );
CHECK( monMin( { "ok", "bonjour", "quarante-deux", "info-111"}) == "bonjour" );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b01f145e4df05736295edc27257aa273", "grade": false, "grade_id": "cell-52317b5fdd376ce4", "locked": true, "schema_version": 3, "solution": false}}

## Exercice
Compléter chacune des fonctions suivantes:
- Si il n'y a pas de documentation, l'écrire;
- Si la fonction est vide, l'implanter;
- S'il n'y a pas de tests automatiques, en rajouter en utilisant `CHECK`.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "131e5b01d1ffeba006a534ccd0c3bc9f", "grade": false, "grade_id": "cell-63b9197623b6b801", "locked": true, "schema_version": 3, "solution": false}}

### Fonction `estPositif` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c0f0f0ccb263d74d60e6fb83ba4805e1
  grade: true
  grade_id: cell-debdc6508741f20e
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
/** Verifie que tout les éléments d un tableau sont positifs
 * @param t un tableau de flottant
 * @return boolean si tous positifs
 **/
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7a004f22049f53543173e16fc67ce4af
  grade: false
  grade_id: cell-33bf8e417e2812b7
  locked: true
  schema_version: 3
  solution: false
---
bool estPositif(vector<float> tab) {
    for(int i=0; i < tab.size(); i++){
        if ( tab[i] < 0. ) {
            return false;
        }
    }
    return true;
 }
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f5628810e05177f5bf3f3cfd0c393a01", "grade": false, "grade_id": "cell-3a277652a240e91d", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 382b4ab3afc09435e81928751ab91f1a
  grade: true
  grade_id: cell-062f931267232e58
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
CHECK( estPositif({8, -2, 9, 6}) == false);
CHECK( estPositif({8, 9, 6}) == true)
CHECK( estPositif({8, 0, 9, 6}) == true)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ac2ec6ba9a0df67bbe5d59fc0cb7ca38", "grade": false, "grade_id": "cell-df085b43fa0381c1", "locked": true, "schema_version": 3, "solution": false}}

### Fonction `incremente`

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bf5679d11752aefedf650a9480811599", "grade": false, "grade_id": "cell-4363bf80b8d9aa5a", "locked": true, "schema_version": 3, "solution": false}}

La fonction suivante renvoie un tableau. En principe on devrait mettre
`vector<int>` comme type de retour. Pour contourner un [bug dans
cling](https://github.com/QuantStack/xeus-cling/issues/40) (corrigé
dans la version de développement), on va mettre le type `tableau` à la
place, après avoir défini ce type comme un alias pour `vector<int>`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9b78a3cf33b885d84a5c07b401479197
  grade: false
  grade_id: cell-d653784ca8d89a83
  locked: true
  schema_version: 3
  solution: false
---
using tableau = vector<int>;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7409977a6728987bd9154d60fb86eda7
  grade: false
  grade_id: cell-ab607ee890a8bbc7
  locked: true
  schema_version: 3
  solution: false
---
/** Fonction incremente
 * @param t un tableau d entiers
 * @return un tableau d entiers obtenu en incrémentant de 1 chaque valeur de t
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 08d8437c046a1f9f6d6ce695342a0950
  grade: false
  grade_id: cell-9533dd4bd5e8f03e
  locked: false
  schema_version: 3
  solution: true
---
tableau incremente(vector<int> t) {
    for (int i=0; i<t.size(); i++) {
        t[i]++;
    }
    return t;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1be3595a79b0771c8b497596c2b34648", "grade": false, "grade_id": "cell-64691ddf7c606c63", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0a99505ea7ae8a3dfcd50f4b09897609
  grade: true
  grade_id: cell-ba30493ce4355891
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( incremente({5,1,3}) == vector<int>({6,2,4}) )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76cc62c618830814625b941b5dd4f959", "grade": false, "grade_id": "cell-81f3613904343fdf", "locked": true, "schema_version": 3, "solution": false}}

### Fonction `egale`

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: efe2b35dfef563d227b13523b4a07a0a
  grade: false
  grade_id: cell-14df823ac6c1e12f
  locked: true
  schema_version: 3
  solution: false
---
/** Teste si deux tableaux sont égaux (même longueur, mêmes valeurs)
 * @param t1: un tableau d entiers
 * @param t2: un tableau d entiers
 * @return true si les deux tableaux sont égaux, false sinon
 **/
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 164865f7e2fb62e5fb727cc285bdb5f1
  grade: false
  grade_id: cell-1818d5b14943aef6
  locked: true
  schema_version: 3
  solution: false
---
bool egale(vector<int> t1, vector<int> t2) {
    if( t1.size() != t2.size() ) {
        return false;
    }
    for ( int i=0; i < t1.size(); i++ ) {
        if ( t1[i] != t2[i] ) {
            return false;
        }
    }
    return true;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1eecca385c4f905118b128648774c624", "grade": false, "grade_id": "cell-7864b28ad24a0055", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 8825e7209dde01aadd6542bb3c8f27f5
  grade: true
  grade_id: cell-707f9bfaeb851c40
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
CHECK(egale({0, 0, 0, 5, -5}, {0, 0, 0, -5, 5}) == false);
CHECK(egale({0, 5, -5}, {0, 0, 0, 5, -5}) == false);
CHECK(egale({0, 5, -5}, {-0, 5, -5}) == true);
CHECK(egale({0, 0, 0, 5, -5}, {0, 0, 0, 5, -5}) == true);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "682dba0efb53ea988a0aa1a3c536f1f3", "grade": false, "grade_id": "cell-32b55993ea00e47f", "locked": true, "schema_version": 3, "solution": false}}

### Fonction `produitTableau`
Implanter la fonction documentée ci-dessous.  
**Indication:** Inspirez-vous de la fonction `somme` du cours.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b5c8236041e7a179fb0b7fe39cb5bc54
  grade: false
  grade_id: cell-0c42b5670eb5b699
  locked: true
  schema_version: 3
  solution: false
---
/** renvoie le produit de tous les éléments d un tableau d entiers
 * @param t un tableau d entiers
 * @return le résultat du calcul de t[0] * t[1] * t[2] * ... 
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 3cde6f1a6f7fd4b1429e953d1f010421
  grade: false
  grade_id: cell-5d59bb3774333584
  locked: false
  schema_version: 3
  solution: true
---
float produitTableau(vector<float> t) {
    float Result = 1;
    for (float i : t) {
        Result *= i;
    }
    return Result;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 08653119cee2d84bd4d5146e6d819305
  grade: false
  grade_id: cell-a254241c461c5329
  locked: true
  schema_version: 3
  solution: false
  task: false
---
produitTableau({2, 3, 4}) // doit valoir 24
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 909154dc7330095a4f9140c1a6ab944e
  grade: false
  grade_id: cell-74019ad247e334d2
  locked: true
  schema_version: 3
  solution: false
  task: false
---
produitTableau({0, 10, 100}) // doit valoir 0
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7476942bcb37f27c0b2c73225a09d012", "grade": false, "grade_id": "cell-1738e8d3c0e7cd67", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c0388550314fedf8406cfa9614081c35
  grade: true
  grade_id: cell-bb243e0519279291
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
CHECK(produitTableau({1,2,3,4,5,6,7,8}) == 40320);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "70f16f838ebe1dbb4a49f0d57ec8e64f", "grade": false, "grade_id": "cell-942637f4b6c5a177", "locked": true, "schema_version": 3, "solution": false}}

### Fonction `plusDeVrai`

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3d7f8bd3615fa1550775a3976d5e6de6
  grade: false
  grade_id: cell-37ae989ef3121854
  locked: true
  schema_version: 3
  solution: false
---
/** Teste si un tableau contient plus de `true` que de `false`
 * @param tab un tableau de booleen
 * @return true si le tableau contient plus de `true`, `false` sinon
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 84a1364ac1c1312965389cb4d5480085
  grade: false
  grade_id: cell-ded0f8d9532da499
  locked: false
  schema_version: 3
  solution: true
---
bool plusDeVrai(vector<bool> tab) {
    int Nbr = 0;
    for (bool i : tab) {
        if (i) { Nbr++; }
        else { Nbr--; }
    }
    return (Nbr>0);
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "38fabf799d9626bce91a755e37b22cee", "grade": false, "grade_id": "cell-e58af629f6da0c95", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 45a8c20fa15e440747eff6165011ded6
  grade: true
  grade_id: cell-2b2e37a9334a4897
  locked: false
  points: 1
  schema_version: 3
  solution: true
---
CHECK(plusDeVrai({false, true, true}));
CHECK(plusDeVrai({0, true, true}));
CHECK(plusDeVrai({0, 1, 1}));
CHECK(not plusDeVrai({false, 0, true}));
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2ead069e477e4b30ed93dede12938a56
  grade: true
  grade_id: cell-2b2e37a9334a4898
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---

```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "60a5b30d314793c2cc2878d041d32fff", "grade": false, "grade_id": "cell-410bbb292f2908ee", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### Fonction `contient`

La fonction `contient` prend en argument un tableau et un entier et
renvoie vrai si le tableau contient l'entier, faux sinon.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: e0d38d5a83c82a625f74ad9d4100c597
  grade: true
  grade_id: cell-69642dc56e20e981
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
/** Teste si un tableau contient un entier
 * @param tab un tableau de int
 * @param Nbr un int
 * @return true si le tableau contient Nbr, `false` sinon
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 4aca5329cab753932f6d674cfb9f8977
  grade: false
  grade_id: cell-69642dc56e20e982
  locked: false
  schema_version: 3
  solution: true
---
bool contient(vector<int> tab, int Nbr) {
    for (int i : tab) {
        if (Nbr == i) { return true; }
    }
    return false;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b836b814c7acd18b3824279b3e8ecc24", "grade": false, "grade_id": "cell-29ae6b767bde2ea9", "locked": true, "schema_version": 3, "solution": false}}

Tests:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 72fd559a992c509b2d953d3884597a38
  grade: true
  grade_id: cell-3575477879f79483
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK(     contient( { 5, -1, 8, 4 }, 8) );
CHECK( not contient( { 1, 2 }, 42)       );
```
