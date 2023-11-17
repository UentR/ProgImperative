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
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "89698a7d6552b3188af9704712e2a985", "grade": false, "grade_id": "cell-8debedfea96381b5", "locked": true, "schema_version": 3, "solution": false}}

# TP : le jeu de Yams

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "975812aa49a8c47d91612ddf23aa41d9", "grade": false, "grade_id": "cell-6c2c32f5e76ffb43", "locked": true, "schema_version": 3, "solution": false}}

:::{admonition} Rappels d'utilisation des tableaux

- **Déclarer** un tableau d'entiers `tab` :
    ```c++
    vector<int> tab;
    ```
- **Allouer** 5 cases au tableau `tab` :
    ```c++
    tab = vector<int>(5);
    ```
- **Initialiser** ses cases :
    ```c++
    tab[0] = 42; tab[1] = 3; ... ; tab[4] = 36;
    ```

- **Déclarer**, **allouer** et **initialiser** en une seule instruction :
    ```c++
    vector<int> tab = {25,-3,10,7};
    ```

- Il est également possible de construire un tableau sans lui donner
  de nom pour le passer à une fonction de la manière suivante :
    ```c++
    maFonction({17,9,-3,42});
    ```
:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a7918f75f740df20c5064a2efcd7b1f7", "grade": false, "grade_id": "cell-e8fa588409cbc545", "locked": true, "schema_version": 3, "solution": false}}

:::{admonition} Astuce
:class: tip

Lorsque vous avez besoin de redémarrer le noyau, utilisez le menu
`Noyau > Redémarrer le noyau et exécutez jusqu'à la cellule selectionnée`.

Ainsi vous disposez d'un environnement d'exécution propre avec toutes
les fonctions précédentes bien définies, ainsi que les instructions
d'initialisation qui suivent.

:::

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 07655687e27257a54630534c6ac62c15
  grade: false
  grade_id: cell-214aa5a1f7ccaa00
  locked: true
  schema_version: 3
  solution: false
---
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

using tableau = vector<int>;

// Initialisation de la fonction rand (pour les nombres aléatoires) :
srand(time(0));
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c41c8f0241a2649e0b62694e273a9e84", "grade": false, "grade_id": "cell-e8fa588409cbc546", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 1 : Reconnaître les yam's

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bbe82a28d45d9dc4875a7e1822472bcd", "grade": false, "grade_id": "cell-b61f9d53913e9c53", "locked": true, "schema_version": 3, "solution": false}}

### `pointsFigureYams`

Complétez la documentation de la fonction `pointsFigureYams` ébauchée dans
la cellule suivante, puis implémentez cette fonction dans la cellule d'après.
Pour rappel, la fonction `pointsFigureYams` doit vérifier si les cinq valeurs
de dés fournies forment un yam's ou non. Si un yam's est trouvé on renvoie
le score correspondant (somme des dés + 60), sinon on renvoie 0.

```{code-cell}
/** Fonction pointsFigureYams
 * @param des
 * @return 
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: a239d59a94d368ba3cf60c749ee38dcc
  grade: false
  grade_id: cell-e5c12aeafec7d057
  locked: false
  schema_version: 3
  solution: true
---
int pointsFigureYams(vector<int> des) {
    for (int i=0; i<des.size()-1; i++) {
        if (des[i] != des[i+1]) return 0;
    }
    return des[0] * 5 + 60;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b55dec5877d63d1c3d49854d66f644e4", "grade": false, "grade_id": "cell-d707ce6b51bc390f", "locked": true, "schema_version": 3, "solution": false}}

La cellule suivante fournit deux tests pour la fonction `pointsFigureYams`.
Dans la cellule qui la suit, écrivez aux moins deux autres tests, puis exécutez
les deux cellules pour vérifier que votre fonction `pointsFigureYams` a bien
le comportement attendu.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 595f161425c869ff50a6dbf5e138c984
  grade: true
  grade_id: cell-901b2df503fc5c9f
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( pointsFigureYams({1,1,1,1,1}) == 65 );
CHECK( pointsFigureYams({2,1,1,1,1}) ==  0 );
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 81dd1af969eac8d79aba2458cd08350a
  grade: true
  grade_id: cell-901b2df503fc5c9e
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9b6bd33be413bf8c67a5c6a1597daff2", "grade": false, "grade_id": "cell-a6a573fb11d8cc17", "locked": true, "schema_version": 3, "solution": false}}

### Compilation et tests en dehors de Jupyter

:::{hint} Recommandation
   
Faites avec soin les questions de compilation pour vous y entraîner :
cela vous servira pour la suite du semestre et notamment pour le
projet qui sera entièrement sous forme compilée.

:::

-   Ouvrez le fichier [`yams.cpp`](yams.cpp).
-   Copiez-collez votre fonction `pointsFigureYams` à un endroit adapté.
-   Insérez la ligne suivante à l'endroit indiqué dans la fonction `main` :

	```
	cout << pointsFigureYams({1,1,1,1,1}) << endl;
	```

-   **Enregistrez** votre fichier `yams.cpp`.
-   **Ouvrez un terminal**
-   **Compilez** votre fichier `yams.cpp` en lançant, depuis le
    répertoire `Semaine6`, la commande :

    ```
    clang++ yams.cpp -o yams
    ```

    :::{attention}
	- En salle de TP : pour avoir accès à `clang++`, nous vous
	  recommadons d'utiliser le terminal intégré dans JupyterLab afin
	  d'être dans le bon environnement logiciel.
	- La commande doit être lancée dans le répertoire contenant
	  `yams.cpp`. Si nécessaire, déplacez vous y avec la commande `cd`
	  (par exemple `cd ~/ProgImperative/Semaine6`).
    - Pour alterner efficacement entre ce document contenant les
      consignes, l'éditeur de fichier contenant `yams.cpp` et le
      terminal, nous vous recommandons de disposer les onglets
      correspondants de sorte qu'ils soient tous visibles
      simultanément (voir la [feuille
      Jupyter](../Semaine5/00-jupyter-interface.md) de la semaine
      dernière.
	:::

-   **Exécutez** le programme ainsi généré à l'aide de la commande
    `./yams`. Votre terminal doit afficher 65.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0532f401e245e385d88d0cf6719060bb", "grade": false, "grade_id": "cell-d46bda39ffdb9b6b", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 2 : Utilitaires

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ee1c34a7ee8f3e3cd1bf5827f8c68667", "grade": false, "grade_id": "cell-d87cf79a3fac5afe", "locked": true, "schema_version": 3, "solution": false}}

Dans cet exercice, vous allez implanter plusieurs utilitaires qui
pourront ensuite être combinés pour reconnaître les yams, les autres
figures, et implanter le jeu lui-même.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "066a49da6da08ff81a00b26bba18311e", "grade": false, "grade_id": "cell-d87cf79a3fac5aff", "locked": true, "schema_version": 3, "solution": false}}

### `aleaInt`

La fonction `aleaInt(int a, int b)` proposée ci-dessous permet de
tirer au hasard un nombre entier compris entre `a` et `b` :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2248a0ced8e5c31284216e49736847d0
  grade: false
  grade_id: cell-ef2774917880c42d
  locked: true
  schema_version: 3
  solution: false
---
/** Fonction aleaInt
 * @param a un entier représentant le minimum du nombre aléatoire généré
 * @param b un entier représentant le maximum du nombre aléatoire généré
 * @return un entier aléatoire n tel que a <= n <= b
 **/
int aleaInt(int a, int b) {
    return rand() % (b - a + 1) + a;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e74eee5c839a74c92d9c6d40cd700da1", "grade": false, "grade_id": "cell-04090934b5186301", "locked": true, "schema_version": 3, "solution": false}}

### `lanceDes`

Complétez la documentation de la fonction `lanceDes` puis
implémentez-la dans la case suivante en utilisant `aleaInt`. Pour
rappel, la fonction `lanceDes` doit renvoyer un tableau contenant 5
valeurs tirées aléatoirement entre 1 et 6. *(Comme la semaine
dernière, pour contourner un bug dans cling on va mettre le type
`tableau` à la place de `vector<int>`.)*

```{code-cell}
/** Fonction lanceDes
 * @return 
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 48f127b611c31e894f642b108725334e
  grade: false
  grade_id: cell-2400cc6d2f03939a
  locked: false
  schema_version: 3
  solution: true
---
tableau lanceDes() {
    vector<int> Des = vector<int>(5);
    for (int Idx=0; Idx<5; Idx++) {
        Des[Idx] = aleaInt(1, 6);
    }
    return Des;
}
```

Comme `lanceDes` renvoie des valeurs aléatoires, c'est un peu plus
difficile de la tester. Exécutez **à plusieurs reprises** la cellule
suivante :

```{code-cell}
lanceDes()
```

On vérifie qu'elle renvoie toujours un tableau de longueur $5$ :

```{code-cell}
CHECK( lanceDes().size() == 5 )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "08e04178c84e12566d16cf833b49d3ea", "grade": false, "grade_id": "cell-eb7b5f0550c1d0c2", "locked": true, "schema_version": 3, "solution": false}}

### `afficheDes`

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1d0edfa6d5fd1989a58f472d35a671ad", "grade": false, "grade_id": "cell-174a3e007c306a19", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Pour afficher le contenu d'une variable, notamment dans un programme
compilé, vous avez maintenant l'habitude d'utiliser `cout`. Cependant,
par défaut, `cout` ne permet pas d'afficher un tableau. Vous pouvez
le constater en décommentant la deuxième ligne de la cellule ci-dessous
(enlever les `// ` en début de ligne) et en exécutant la cellule.
Remettez ensuite la deuxième ligne en commentaire et redémarrez le noyau.

```{code-cell}
vector<int> t = {5,-13,0,27};
// cout << t << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cf9d989bfa0d69632a70380b77266ccd", "grade": false, "grade_id": "cell-174a3e007c306a20", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Aussi, pour pouvoir afficher le contenu d'un tableau de dés, on va
écrire une fonction `afficheDes`.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1b058249e83f4ee2fe71d5189cbd0b19", "grade": false, "grade_id": "cell-eb7b5f0550c1d0c3", "locked": true, "schema_version": 3, "solution": false}}

Complétez la documentation de la fonction `afficheDes` puis
implémentez-la dans la cellule suivante.  Pour rappel, cette fonction
doit afficher les valeurs des dés qui lui sont donnés en entrée.

```{code-cell}
/** Fonction afficheDes
 * @param
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2fe4db4fef2cb949b25517220b03c71a
  grade: true
  grade_id: cell-c71cd541b0d5a957
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
void afficheDes(vector<int> Des) {
    for (int i=0; i<Des.size(); i++) {
        cout << Des[i] << "; ";
    }
    cout << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f4e4c8f8dc950b9a18151237221fd4f3", "grade": false, "grade_id": "cell-273053de1f48bf92", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Pour tester votre fonctions `afficheDes`, exécuter la cellule suivante
et vérifier l'affichage obtenu.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 39325c93ecb96507a91ade1334085127
  grade: false
  grade_id: cell-0ce10c221f01679f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
afficheDes({4, 21, -1, 2});
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76a607177f174ad31cdb81117783cf6d", "grade": false, "grade_id": "cell-d32e8ca14d28aec7", "locked": true, "schema_version": 3, "solution": false}}

### compteDes

Après avoir complété sa spécification, implémentez la fonction
`compteDes` vue en TD.

```{code-cell}
/** Fonction compteDes
 * @param 
 * @return 
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 77e3215fc787c8bdea6d9dbbb0b258e5
  grade: false
  grade_id: cell-cb4ed8a6d66b01c6
  locked: false
  schema_version: 3
  solution: true
---
tableau compteDes(vector<int> des) {
    vector<int> Count = vector<int>(6);
    for (int Idx=0; Idx<5; Idx++) {
        Count[des[Idx]-1]++;
    }
    return Count;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d426423d27075adc1df2f3c9deeeb293", "grade": false, "grade_id": "cell-e86e97430fbdc657", "locked": true, "schema_version": 3, "solution": false}}

Vérifiez que votre fonction `compteDes` est correcte à l'aide des
tests suivants vus en TD :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 640c53349bdcbbf4ca2a5f69b3b51f49
  grade: true
  grade_id: cell-fb46c8bc8918289e
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( compteDes({1,1,1,1,1}) == vector<int>({5, 0, 0, 0, 0, 0}) );
CHECK( compteDes({2,2,2,2,2}) == vector<int>({0, 5, 0, 0, 0, 0}) );
CHECK( compteDes({3,3,3,3,3}) == vector<int>({0, 0, 5, 0, 0, 0}) );
CHECK( compteDes({4,4,4,4,4}) == vector<int>({0, 0, 0, 5, 0, 0}) );
CHECK( compteDes({5,5,5,5,5}) == vector<int>({0, 0, 0, 0, 5, 0}) );
CHECK( compteDes({6,6,6,6,6}) == vector<int>({0, 0, 0, 0, 0, 5}) );
CHECK( compteDes({1,2,3,4,5}) == vector<int>({1, 1, 1, 1, 1, 0}) );
CHECK( compteDes({2,2,6,2,2}) == vector<int>({0, 4, 0, 0, 0, 1}) );
CHECK( compteDes({4,1,4,1,1}) == vector<int>({3, 0, 0, 2, 0, 0}) );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "66f550be9d5b45b1a858b2e758e08486", "grade": false, "grade_id": "cell-374ed3ce37f10dd5", "locked": true, "schema_version": 3, "solution": false}}

### chercheDansTableau

Au tour maintenant de `chercheDansTableau` qui étant donné un entier
et un tableau cherche si cet entier est présent ou non dans le
tableau, renvoie son indice s'il est présent, et renvoie -1 sinon.

```{code-cell}
/** Fonction chercheDansTableau
 * @param 
 * @param 
 * @return 
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: a39e503a37eacc4d0d6f85a4a5129a76
  grade: false
  grade_id: cell-ba94d696690fcdcd
  locked: false
  schema_version: 3
  solution: true
---
int chercheDansTableau(int Target, vector<int> Tab) {
    for (int Idx=0; Idx<Tab.size(); Idx++) {
        if (Target == Tab[Idx]) return Idx;
    }
    return -1;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a7f7bab9d37c80e1521d1515eeeb1ae8", "grade": false, "grade_id": "cell-089973920882695d", "locked": true, "schema_version": 3, "solution": false}}

Complétez les tests de la cellule suivante et exécutez-les pour
vérifier que votre fonction `chercheDansTableau` est correcte :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3ab959c112b46e31a3b34fda74b09a72
  grade: true
  grade_id: cell-91db74d6de43eef4
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( chercheDansTableau( 3, {42,5,3,6,7}) ==  2);
CHECK( chercheDansTableau(56, {42,3,5,6,7}) == -1);
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2321d57e0d69ee1247f263c52cc48af1
  grade: true
  grade_id: cell-91db74d6de43eef5
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "526a734eaef28eaa89efe5e177af1c1e", "grade": false, "grade_id": "cell-76cb66dd2a5989a3", "locked": true, "schema_version": 3, "solution": false}}

### main

Écrivez ci-dessous les instructions pour :
- tirer 5 dés aléatoirement et stocker le résultat dans la variable
  `des`;
- afficher le résultat du tirage;
- afficher le nombre de points obtenus en cherchant un yam's dans ce
  tirage.

Testez votre chance en exécutant plusieurs fois la cellule!

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ca74112e18e554414131989a73364ef9
  grade: false
  grade_id: cell-fc92242a65bb244c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
vector<int> des;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: f6f3fc2899eb561f67a1c0e6784d76b2
  grade: false
  grade_id: cell-6d6243145c1a53a7
  locked: false
  schema_version: 3
  solution: true
---
des = lanceDes();
afficheDes(des);
cout << pointsFigureYams(des);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8263cd72546ce5817e62df1795231e58", "grade": false, "grade_id": "cell-6258bcc27bfdbca7", "locked": true, "schema_version": 3, "solution": false}}

### Compilation et tests en dehors de Jupyter

- Ouvrez votre fichier [yams.cpp](yams.cpp).
- Copiez-collez les fonctions `afficheDes`, `lanceDes`, `compteDes` et
  `chercheDansTableau` à un endroit adapté.
- Remplacez la ligne d'affichage contenue dans la fonction `main` par
  le code des deux cellules précédentes.
- **Enregistrez** votre fichier [`yams.cpp`](yams.cpp)
- **Compilez**-le à l'aide de la commande `clang++ yams.cpp -o yams`
- **Exécutez** le programme ainsi généré : `./yams`. Le résultat
  est-il bien celui attendu ? Si votre programme tire toujours la même
  série de dés, que manque-t-il dans la fonction `main`, qui était
  bien présent dans la première cellule de code, en haut de cette page ?

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d0dd5a205646a423e8f704efde08198b", "grade": false, "grade_id": "cell-2f1b88aea00c9cca", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 3 : Les autres figures

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1906a04cc8d3a8a6e6cd0a37cd77fcc5", "grade": false, "grade_id": "cell-203be4570bd190bd", "locked": true, "schema_version": 3, "solution": false}}

### `pointsFigureBrelan`

Voici une fonction `pointsFigureBrelan` un peu différente de celle vue en TD :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 75b89f5b40c8a6fe4de1eff16062e8a6
  grade: false
  grade_id: cell-e0e0e9091c124592
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigureBrelan
 * @param des un tableau de 5 entiers (les dés)
 * @return 0 si aucun brelan est trouvé, la somme des dés formant le brelan + 10 sinon
 **/
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e240dfabb991be369a6b7a58247c1d33
  grade: false
  grade_id: cell-c9713a5cdc3e9d24
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int pointsFigureBrelan(vector<int> des) {
    vector<int> compte = compteDes(des);
    
    int valeur = (chercheDansTableau(3, compte) + 1)
               + (chercheDansTableau(4, compte) + 1)
               + (chercheDansTableau(5, compte) + 1);

    if (valeur > 0) {
        return (valeur * 3) + 10;
    } else {
        return 0;
    }
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8b05089e47854762204f3d604502c25c", "grade": false, "grade_id": "cell-d1fdee8dffebbc7c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Analysez son fonctionnement puis écrivez quelques tests pour vérifier
qu'elle se comporte comme prévu :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: e8643f77b3713acedc6f319d4ad3aa3a
  grade: true
  grade_id: cell-f542f957d93223ad
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
// REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "06675f9b3f206a22addec8ec1b58e3b7", "grade": false, "grade_id": "cell-8e9ded0c351723a8", "locked": true, "schema_version": 3, "solution": false, "task": false}}

### `pointsFigureCarre` & `pointsFigureFull`

Sur le même modèle, donnez deux fonctions `pointsFigureCarre` et
`pointsFigureFull` répondant aux documentations ci-dessous.  Rappel :
full : 3 dés identiques et 2 dés identiques, carré : 4 dés identiques.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4513944e61cff58b4c4c462e3e5ee110
  grade: false
  grade_id: cell-a5b3fd2f1ed74d99
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigureCarre
 * @param des un tableau de 5 entiers (les dés)
 * @return 0 si aucun carre (4 dés identiques) est trouvé, la somme des dés formant le carré + 30 sinon
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 3221cab684a13611c1739669a8999393
  grade: false
  grade_id: cell-ee9ea92251796b50
  locked: false
  schema_version: 3
  solution: true
---
int pointsFigureCarre(vector<int> Des) {
    vector<int> Count = compteDes(Des);

    for (int Idx=0; Idx<6; Idx++) {
        if (Count[Idx] == 4) return (Idx+1)*4 + 30;
    }
    return 0;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c5a5f6417b7ef1525ea34145ddd3cf01
  grade: false
  grade_id: cell-ee350756a6f1c8e6
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigureFull,
 * @param des un tableau de 5 entiers contenant les valeurs des dés
 * @return 0 si pas de full, somme des dés composant le full + 20 si full il y a
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 61de344396823272dd4ca92c8aedeadc
  grade: false
  grade_id: cell-351f844238b00999
  locked: false
  schema_version: 3
  solution: true
---
int pointsFigureFull(vector<int> Des) {
    vector<int> Count = compteDes(Des);

    int Three = chercheDansTableau(3, Count) + 1;
    int Two = chercheDansTableau(2, Count) + 1;
    
    bool Full = Three * Two;


    if (Full) {
        return 3*Three + 2*Two + 20;
    }
    return 0;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a98ec7ebf5ef1bdd7e48916ea4352b2d", "grade": false, "grade_id": "cell-e9ed1239c05d3a53", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Testez-les :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b95ae127e91ec9c3d5cd62c6e4a5b181
  grade: true
  grade_id: cell-a7740a7033a46a89
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( pointsFigureFull({4,4,4,1,1}) == 34 );
CHECK( pointsFigureFull({1,1,4,4,5}) ==  0 );

CHECK( pointsFigureCarre({4,4,4,4,1}) == 46 );
CHECK( pointsFigureCarre({4,4,4,2,5}) ==  0 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "82064bb2053ed96ba911ef68fe589636", "grade": false, "grade_id": "cell-2775b19eb90e3da1", "locked": true, "schema_version": 3, "solution": false}}

### `pointsFigure`

Nous vous donnons la fonction `pointsFigure` vue en TD qui a pour but
de chercher la figure choisie par l'utilisateur (via une chaîne de
caractères) et de renvoyer le nombre de points ainsi obtenu.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 6d045daa864ad61ccecfa5da2c44ce69
  grade: false
  grade_id: cell-452384d8a308fc1f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigure,
 * @param des un tableau de 5 entiers contenant les valeurs des dés
 * @param figure une chaine de caractères contenant le nom de la figure a chercher
 * @return 0 si figure introuvable ou inconnue, le score correspondant sinon
 **/
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d7ddfdf7a1a7dcba30dc325408e17103
  grade: false
  grade_id: cell-328296671f32464d
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int pointsFigure(vector<int> des, string figure) {
    if        ( figure == "brelan" ) {
      return pointsFigureBrelan(des);
    } else if ( figure == "full"   ) {
        return pointsFigureFull(des);
    } else if ( figure == "carre"  ) {
        return pointsFigureCarre(des);
    } else if ( figure == "yams"   ) {
        return pointsFigureYams(des);
    } 
    return 0;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "64491c0fc491361173f2cec441a30676", "grade": false, "grade_id": "cell-9957e2bdc6fd8707", "locked": true, "schema_version": 3, "solution": false}}

### Compilation et tests en dehors de Jupyter

- Ouvrez votre fichier [`yams.cpp`](yams.cpp).
- Copiez-collez les fonctions `aleaInt`, `pointsFigureCarre` et
  `pointsFigureFull`, `pointsFigureBrelan` et `pointsFigure` à un
  endroit adapté.
- **Enregistrez** votre fichier [`yams.cpp`](yams.cpp).
- **Vérifiez qu'il compile toujours** à l'aide de la commande
  `clang++ yams.cpp -o yams`
- *Exécuter le programme tel quel ne changera rien à l'exécution
  précédente car nous n'avons pas modifié la fonction **main** ;
  c'est ce que nous allons faire dans la partie suivante.*

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3c9083344587ac4c73ed891380bb5f1a", "grade": false, "grade_id": "cell-217bb315221f2bcb", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 4 : La boucle de jeu

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5b893c400d62d087f93ace658ecd374d", "grade": false, "grade_id": "cell-d0fe9b8212280dc6", "locked": true, "schema_version": 3, "solution": false}}

La boucle de jeu, infinie, se décompose de la façon suivante.

> ### Avant la boucle
>
> - Déclaration des variables permettant de stocker la valeur des
>   **dés**, le **score** et la **reponse** écrite du joueur.
>
> ### Pendant la boucle
>
> - On lance les dés et on stocke le résultat dans la variable
>   appropriée.
> - On affiche le résultat du lancer à l'utilisateur et on demande
>   quelle figure il choisit.
> - On boucle tant que l'utilisateur donne une réponse qui n'est ni
>   une figure (**brelan**, **full**, **carre**, **yams**) ni
>   **exit**.
> - Si l'utilisateur a répondu **exit** on sort de la boucle
>   principale avec l'instruction **return 0;**
> - Sinon, c'est que l'utilisateur a donné le nom d'une figure, on
>   appelle donc **pointsFigure** de façon à récupérer le nombre de
>   points correspondant à cette figure et à ce lancer de dés. On
>   ajoute ces points au score du joueur, et on affiche le résultat au
>   joueur.

Complétez la fonction `main` ci-dessous :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: ebfdc7c8981f83f39ef461b120a8f7fc
  grade: false
  grade_id: cell-b7f9ac24211d8b2d
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int main() {
    // Initialisation de la fonction rand (pour les nombres aléatoires).
    srand(time(0));

    // AVANT LA BOUCLE PRINCIPALE
    vector<int> des;
    int score = 0;
    string reponse = "";

    // BOUCLE PRINCIPALE
    while ( true ) {
        des = lanceDes();

        afficheDes(des);
        cout << "Quelle figure voulez-vous chercher ?" << endl;

        // On boucle tant que la réponse de l'utilisateur n'est pas parmi
        // "brelan", "carre", "full", "yams" et "exit".
        do {
            // L'instruction suivante attend que le joueur entre du texte au clavier
            // et stocke sa réponse dans la chaine de caractères "reponse"
            cin >> reponse;
        } while ( reponse != "brelan"
            and reponse != "full" 
            and reponse != "carre" 
            and reponse != "yams" 
            and reponse != "exit" );

        // Si la réponse est "exit", on annonce la fin du jeu, on affiche le score et on termine.
        if ( reponse == "exit" ) { 
            cout << score << endl;
            return 0; 
        }

        score += pointsFigure(des, reponse);
    }
    // FIN DE LA BOUCLE PRINCIPALE
    return 0;
}
```

puis testez-la :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d04e9622c7306e5bfad4261a1d0df534
  grade: false
  grade_id: cell-452384d8a308fc1g
  locked: true
  schema_version: 3
  solution: false
  task: false
---
// Cette incantation magique court-circuite l'appel à `main` -- qui
// requiert des interactions -- dans la correction automatique
#include <cstdlib>
if ( not getenv("NBGRADER_EXECUTION") )
  main()
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fd9cbec81d028165b386741a386de75e", "grade": false, "grade_id": "cell-b9e9ca23583105bc", "locked": true, "schema_version": 3, "solution": false}}

### Compilation et test en dehors de Jupyter

Complétez [`yams.cpp`](yams.cpp) afin de pouvoir jouer en l'exécutant
(après l'avoir compilé) depuis votre terminal.

**Indication :** Si jamais vous entrez dans une boucle infinie,
vous pouvez stopper votre programme à tout moment en pressant les touches
<kbd>Ctrl</kbd><kbd>C</kbd>

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "577b72747a34c0ebc8c2c0358392d20b", "grade": false, "grade_id": "cell-d1ac5129b5c6f068", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 5 : ♣ De la suite dans les idées

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "704f401d84ca60a7cc4f6a23f5f76f68", "grade": false, "grade_id": "cell-0bb931cc66d8c75a", "locked": true, "schema_version": 3, "solution": false}}

Dans le jeux de Yam's complet d'autres figures sont reconnues comme la
Grande Suite (5 dés qui se suivent comme 2,3,4,5,6) et la Petite Suite
(4 dés qui se suivent comme 2,3,4,5). Attention, l'ordre des dés n'a
pas d'importance, les dés 2,4,3,1,5 forment donc une grande suite,
même s'ils sont dans le désordre !

Donnez deux fonctions répondant aux spécifications ci-dessous et
vérifier que vos implémentations passent les tests :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 085a6644105bf3e85de3cc764d0700e5
  grade: false
  grade_id: cell-ae6ac015ffb2c632
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigureGrandeSuite
 * @param des un tableau de 5 entiers (les dés)
 * @return 0 si aucune grande suite (5 dés qui se suivent) n est trouvée,
 *   et sinon la somme des dés formant la grande suite + 50
 **/
```

```{code-cell}
#include <set>
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: f65cad6b0d9f30817d24495c1ae61d80
  grade: false
  grade_id: cell-b61d5e0e0254a652
  locked: false
  schema_version: 3
  solution: true
---
int pointsFigureGrandeSuite(vector<int> Des) {
    set<int> Unique(Des.begin(), Des.end());
    if (Unique.count(2) && Unique.count(3) && Unique.count(4) && Unique.count(5)) {
        if (Unique.count(6)) return 70;
        else if (Unique.count(1)) return 65;
    }
    return 0;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 91b96cce09f0848f91b89b6b71bb15a5
  grade: true
  grade_id: cell-7b2e9d66e5e91143
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( pointsFigureGrandeSuite({4,3,2,1,5}) == 15+50 );
CHECK( pointsFigureGrandeSuite({2,3,4,5,6}) == 20+50 );
CHECK( pointsFigureGrandeSuite({2,3,4,5,2}) ==     0 );
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1ba42e77819a999625bc429d38b08b92
  grade: false
  grade_id: cell-9c53aa2f27303d0b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
/** Fonction pointsFigurePetiteSuite
 * @param des un tableau de 5 entiers (les dés)
 * @return 0 si aucune petite suite (4 dés qui se suivent) n est trouvée, 
 *   la somme des dés formant la petite suite  + 40 sinon
 **/
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 07ba64f6cde13930e3721da6943a1a29
  grade: false
  grade_id: cell-0d76bd6bdf1fba46
  locked: false
  schema_version: 3
  solution: true
---
int pointsFigurePetiteSuite(vector<int> Des) {
    set<int> Unique(Des.begin(), Des.end());
    if (Unique.count(3) && Unique.count(4)) {
        if (Unique.count(5)) {
            if (Unique.count(6)) return 58;
            else if (Unique.count(2)) return 54;
        }
        else if (Unique.count(2) && Unique.count(1)) return 50;
    }
    return 0;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2bef1e17cc8130509aea8f3f04eb9150
  grade: true
  grade_id: cell-27757a711ef348de
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( pointsFigurePetiteSuite({2,3,4,5,2}) == 14+40 );
CHECK( pointsFigurePetiteSuite({3,3,4,5,6}) == 18+40 );
CHECK( pointsFigurePetiteSuite({2,3,4,2,2}) == 0 );
CHECK( pointsFigurePetiteSuite({2,3,2,5,4}) == 14+40 );
CHECK( pointsFigurePetiteSuite({2,6,4,5,3}) == 18+40 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7ca9dbe16c92e9132bc4ff3053a50f3e", "grade": false, "grade_id": "cell-11e28f7da9b9115e", "locked": true, "schema_version": 3, "solution": false}}

Modifiez maintenant la boucle de jeu réalisée un peu plus haut afin de
prendre en compte ces deux nouvelles figures. Testez-la en exécutant
les cellules dans le bon ordre.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "731cdf5574ee30ec15b567b2e4e2dae7", "grade": false, "grade_id": "cell-40b367fc26d3b2d2", "locked": true, "schema_version": 3, "solution": false}}

### Compilation et tests en dehors de Jupyter

- **Ajoutez à votre fichier `yams.cpp` les fonctions que vous venez de
  réaliser.**
- Modifiez la fonction **main** en conséquence.
- **Compilez** votre programme et **testez-le** en l'exécutant.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "15d789fc208e2efd47f3f46535c2b889", "grade": false, "grade_id": "cell-40b367fc26d3b2d4", "locked": true, "schema_version": 3, "solution": false}}

## Tests

Cette section vérifie que le programme `yams` compile et s'exécute
sans erreur immédiate. Les commandes suivantes ne devraient pas
déclencher d'erreur.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: bb6b37bd0c9cd9fd7d30a0f3fb81ea55
  grade: true
  grade_id: cell-c65547ba2649c19d
  locked: true
  points: 0
  schema_version: 3
  solution: false
  task: false
---
CHECK( not system("clang++ yams.cpp -o yams") )
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 81202b0215b7cf81e704262a9d2c39c1
  grade: true
  grade_id: cell-f04beda30d66b347
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( not system("echo exit | ./yams") )
```

```{code-cell}

```
