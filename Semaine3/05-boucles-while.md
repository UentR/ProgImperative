---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c53a8dcf39efb7bb8694bf52421e6807", "grade": false, "grade_id": "cell-fb970bd64e60242c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : les boucles `while`

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c3a36f6de89f06a297adac3c079cef50", "grade": false, "grade_id": "cell-5878847ca43abeac", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Dans cette feuille, vous allez mettre en pratique la boucle `while`.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fe5b0f8f84185467dc22cff63440dc50", "grade": false, "grade_id": "cell-846152f36fa6d1b5", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 1 : première boucle while

- Exécutez les cellules suivantes :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3a487892e8a1f743a8533b895f2728bf
  grade: false
  grade_id: cell-1880f11656147b47
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iostream>
using namespace std;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7115d54d63ae4c5ddc8c44b02a63f891
  grade: false
  grade_id: cell-e39d736d09f14238
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int a,i;
```

```{code-cell}
a = 35; a = 2; a = 1; a = 16;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a698003883efc6c36f5eea7b6b47f90e
  grade: false
  grade_id: cell-1fb1753a1b1cdb1a
  locked: true
  schema_version: 3
  solution: false
  task: false
---
i = 1;
while ( i < a ) {
    cout << i << endl;
    i = i*2;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "09fc297fd30ac05570fa88c29d476a92", "grade": false, "grade_id": "cell-12d88166a3fd3c9b", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Modifiez la valeur de `a` ci-dessus pour obtenir :
 * Exactement 1 affichage
 * Exactement 0 affichage
 * Exactement 4 affichages

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "817c949cc2d97d54c3defa25905a02f1", "grade": false, "grade_id": "cell-6e951de52f28c316", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 2 : Panique dans le noir

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "50ef2c024cb6398232374a2374a14b69", "grade": false, "grade_id": "cell-bab25da16aa4455a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Notre fourmi est perdue dans un labyrinthe plongé dans le noir.
Elle panique! Avant chaque pas, elle tourne aléatoirement
vers la gauche ou vers la droite. Va-t-elle trouver la sortie?

À vous de le découvrir en programmant ce comportement de la fourmi!

Pour simuler le noir, nous avons écrit une fonction qui place la porte
de façon aléatoire. Exécutez les deux cellules suivantes. À chaque
création du labyrinthe, la porte est placée dans un endroit
différent. Le même programme doit toujours fonctionner !

**Indications**:
- Vous pouvez utiliser la condition `regarde() != Sortie`;
- Pour tirer à pile ou face si la fourmi va tourner à gauche ou à droite,
  vous pouvez utiliser la fonction `rand()` qui renvoie un nombre
  entier aléatoire. Du coup, avec `rand() % 2` vous obtenez un
  entier qui vaut aléatoirement `0` ou `1`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 265181405b0bb8a9de8345ccc839e8ea
  grade: false
  grade_id: cell-96abe956c089977b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
std::string porteAleatoire() {
    std::string s = u8"o o o o o o o\n";
    s += u8"o → . . . . o\n";
    int col = rand() % 5;
    int ligne = rand() % 4;
    for ( int i = 0; i < 4; i++ ) {
        s += "o ";
        for ( int j = 0; j < 5; j++ ) {
            if ( i == ligne and j == col ) {
                s += "x ";
            } else {
                s += ". ";
            }
        }
        s += "o\n";
    }
    s += u8"o o o o o o o\n";
    return s;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c5be1c4f642bf8d1db01dc5986ba0352
  grade: false
  grade_id: cell-11ff4ac8db53cf33
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(porteAleatoire())
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 7e42f16ed8dbadbfe5378f20e252a74e
  grade: false
  grade_id: cell-9ae17b16e4c34584
  locked: false
  schema_version: 3
  solution: true
  task: false
---
debut();
bool Gauche;
while (regarde() != Sortie) {
    Gauche = rand() % 2;
    if (Gauche) {
        gauche();
    } else {
        droite();
    }
    avance();
}
ouvre()
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 22893d8c7fed9755602a9d11f26c0db6
  grade: true
  grade_id: cell-55ee502565fe62bd
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_gagne() );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3c67ae8f27cd83f45c72298762739fe9", "grade": false, "grade_id": "cell-dfe882b2f3d4d4fd", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 3 : division euclidienne par soustraction

- Observez les cellules suivantes et **donnez des valeurs à $b$ et $c$
  avec $b > c$ telles que, à la fin de la boucle, on ait $b=3$** :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a8a8a6e86127c3ab2edca5dd5870435a
  grade: false
  grade_id: cell-8fe0bd78375ff270
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int b,c;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 058fa33a1e50b4d1172c817f879bb453
  grade: false
  grade_id: cell-66fc1e139a8a5e29
  locked: false
  schema_version: 3
  solution: true
  task: false
---
b = 241;
c = 17;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ef5726df15029b800487808d1095914a
  grade: false
  grade_id: cell-53c2eeeab2fe5530
  locked: true
  schema_version: 3
  solution: false
  task: false
---
while ( b >= c ) {
    b = b - c;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: dd172c95c536db0cc5d3fd5d9bbd4636
  grade: false
  grade_id: cell-92488e51123a90d6
  locked: true
  schema_version: 3
  solution: false
  task: false
---
b
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e04c34554c9b0ac165d2aec7b919fd12", "grade": false, "grade_id": "cell-7ac80b6a48ea28c7", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Test automatique (ne doit rien afficher) :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 71b1c2b15a199007f5c7bc7182ade695
  grade: true
  grade_id: cell-9745ecb4ba87d5c8
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( b == 3 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "83f66a8afdf753f439384610ef299ea3", "grade": false, "grade_id": "cell-c0b607a1647b25f7", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Modifiez la cellule ci-dessous pour que la variable $k$ compte le
  nombre d'exécutions de la boucle;
- Donnez des valeurs à $b$ et $c$ telles que l'on ait $b=3$ et $k=5$ à
  la fin de la boucle.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9596cd287205a7734fb8cd0eac758afa
  grade: false
  grade_id: cell-59f25e846a1dc7ca
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int k;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 3677bc16f9eeeb82fd7abbb9988955be
  grade: true
  grade_id: cell-9df75cb01e7efbf3
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
k = 0;
c = 42;
b = c*5 + 3;
while ( b >= c ) {
    b = b - c;
    k++;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 774ff7faa8a493cb789267f2a95100ec
  grade: false
  grade_id: cell-95b7aee0b39f4c13
  locked: true
  schema_version: 3
  solution: false
  task: false
---
b     // doit afficher 3
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9e3a47790361920c8f53b91ceff4db5b
  grade: false
  grade_id: cell-ba01ba70e0237af3
  locked: true
  schema_version: 3
  solution: false
  task: false
---
k     // doit afficher 5
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2cb59c6695ef2d30461236208264b684", "grade": false, "grade_id": "cell-e119e376c9c336b2", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Tests automatiques :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7a7282f5aff9877aa39e9f7358c0f822
  grade: true
  grade_id: cell-0e30a8050f77f2eb
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( b == 3 );
CHECK( k == 5 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76ca61e7772c458f9c1e9beee22de695", "grade": false, "grade_id": "cell-c30e45ce73de8c5f", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 4 : suite de Syracuse

- Exécutez, sans les modifier, les deux cellules ci-dessous puis trois
  fois la troisième cellule :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 79ef295eee2ad7246fe0db3bd12ef7a1
  grade: false
  grade_id: cell-37930a4a3f765bc0
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iostream>
using namespace std;
int d;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b4b0993f8781bad673e10969dda4e512
  grade: false
  grade_id: cell-673069e18045ce2f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
d = 5;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 0885d150f4b6a37e20b3e924bbe66879
  grade: true
  grade_id: cell-1a8c990096f29a33
  locked: false
  points: 1
  schema_version: 3
  solution: true
  task: false
---
while (d!=1) {
    if ( d % 2 == 0) {
        d = d / 2;
    } else {
        d = 3 * d + 1;
    }
    cout << d << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8c21560d6d1636b157111b1dc833435f", "grade": false, "grade_id": "cell-84f1ecf621ccd00b", "locked": true, "schema_version": 3, "solution": false, "task": false}}

  Vous noterez que lorsque le nombre $d$ est pair, on le divise
  par 2. Lorsqu'il est impair, on le multiplie par 3 et on ajoute 1.

- Modifiez la cellule pour que l'on répète cette action tant que le
  nombre $d$ est supérieur à 1. On veut afficher la valeur de $d$ à
  chaque fois. Si votre code est correct, il doit afficher 16 8 4 2 1
  (en partant de d=5).

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8f7b26773599d8e8fdc0fbedd8dc4f7b", "grade": false, "grade_id": "cell-615fbe353a6d1b8c", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 5

- Obervez la fonction suivante et essayez de comprendre ce qu'elle
  calcule en lisant le code et en essayant plusieurs valeurs d'appel :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c54dbcf8aa8957f2002363da54671620
  grade: false
  grade_id: cell-a51788cc6416fa31
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int mystere(int n) {
    int k = 1;
    while ( k*k < n ) {
        k = k + 1;
    }
    return k;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ec25272108adf74b8dd72b5afdb38ef4
  grade: false
  grade_id: cell-7b9003dc6876c16b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
mystere(5)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0e2b06ef0bcc755c6e33c93bc5a530c3", "grade": false, "grade_id": "cell-10317126f8f312ef", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Déterminez une valeur de n tel que la valeur renvoyée soit 6 :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: f3a042a81eb2f9302ca50f2ef2d90f13
  grade: false
  grade_id: cell-9cb5ab15e3094248
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int n;
n = 26;
mystere(n)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: feb896bd3965bbc5fd668ef9080269cc
  grade: true
  grade_id: cell-fa730d72ecca5079
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( mystere(n) == 6 )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "09729907658420286d88627f583ee1f2", "grade": false, "grade_id": "cell-1da5f39e2279ad35", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Bilan

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "11992cd19efe9ccec624f6c4df849d40", "grade": false, "grade_id": "cell-fe36a3aa0aa7120f", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Passez maintenant à la
[feuille d'exercices sur les boucles `for`](06-boucles-for.md).
Vous pourrez, par la suite, aborder l'exercice plus avancé
ci-dessous.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3fd4ad5fec847ad8143f8514a42203bf", "grade": false, "grade_id": "cell-74d2f63d4e5fb7e7", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice 6 ♣

- Complétez le code de la fonction suivante pour qu'elle détermine si
  $n$ est un carré parfait. Dans ce cas, elle doit renvoyer `true`;
  sinon elle doit renvoyer `false`.

  **Rappel**: un *carré parfait* est un nombre qui peut s'écrire
  $k\times k$ avec $k$ un entier. Par exemple $16$ est un carré
  parfait car $16 = 4 \times 4$, mais $20$ n'est pas un carré parfait.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 8c120429aa7eed16aac2e7a01b6492ab
  grade: false
  grade_id: cell-adfbc5fdcab735d4
  locked: false
  schema_version: 3
  solution: true
  task: false
---
bool carreParfait(int n) {
    int k;
    k = 0;
    while (k*k < n) {
        k++;
    }
    return (k*k == n);
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cc58dd6214e34fcd0fc5218e4ab27a44", "grade": false, "grade_id": "cell-db645b450cb57c41", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Essayez votre fonction sur les exemples suivants :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 714077d82835c9f8fc2aeaf5daf989c1
  grade: false
  grade_id: cell-0360eb6fa7a5c845
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carreParfait(16)  // doit renvoyer true
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d9dcf97f1d749d3a4fc8c358da9bcecf
  grade: false
  grade_id: cell-e18681ca4661fd4d
  locked: true
  schema_version: 3
  solution: false
  task: false
---
carreParfait(20)  // doit renvoyer false
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c3420bf1c3e708c0ed182d4f8bb0445a", "grade": false, "grade_id": "cell-2010b81e2fd4b599", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Vérifiez que votre fonction passe les tests automatiques suivants :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 9459476ae3cb296a15114370a59c51d3
  grade: true
  grade_id: cell-435a1b0f1a805763
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( carreParfait(0) );
CHECK( carreParfait(1) );
CHECK( not carreParfait(2) );
CHECK( not carreParfait(50) );
CHECK( carreParfait(100) );
CHECK( not carreParfait(250) );
```

```{code-cell}

```
