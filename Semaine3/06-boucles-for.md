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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a9947d12471d8987d4636c046b2c1b9b", "grade": false, "grade_id": "cell-6b385bea40435793", "locked": true, "schema_version": 3, "solution": false}}

# TP : les boucles `for`

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e710248dddd457100fdd80d5dd7e949b", "grade": false, "grade_id": "cell-013e3488802326ac", "locked": true, "schema_version": 3, "solution": false}}

## Exercice : comptons!

- Exécutez les cellules suivantes et observez l'affichage produit :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: be1ba868c2cabb1408d65197c355a654
  grade: false
  grade_id: cell-d3c2a1007784aad7
  locked: true
  schema_version: 3
  solution: false
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
  checksum: 572662649933b2253b0deab4f69e46e6
  grade: false
  grade_id: cell-d1f65b41ee196d6e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
for ( int i = 0; i < 10; i++ ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c21e98be462afd3c5b56e7b38a52c085", "grade": false, "grade_id": "cell-b85bc1dcbd057af3", "locked": true, "schema_version": 3, "solution": false, "task": false}}

 * Remplacez `int i = 0` par `int i = 5` ci-dessous et exécutez;
   observez ce qui change :

```{code-cell}
for ( int i = 5; i < 10; i++ ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "231f0e44307311e87795b357cb078df4", "grade": false, "grade_id": "cell-b85bc1dcbd057af4", "locked": true, "schema_version": 3, "solution": false, "task": false}}

 * Remplacez `i < 10` par `i <= 10` ci-dessous et exécutez; observez
   ce qui change :

```{code-cell}
for ( int i = 0; i <= 10; i++ ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e1b5a5d6ed37e97d493f527dd3f4c644", "grade": false, "grade_id": "cell-b85bc1dcbd057af2", "locked": true, "schema_version": 3, "solution": false, "task": false}}

 * Remplacez `i++` par `i = i + 2` ci-dessous et exécutez; observez ce
   qui change :

```{code-cell}
for ( int i = 0; i < 10; i+=2 ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "32d6be169162aaa9e6c9a3bfd1d12f4e", "grade": false, "grade_id": "cell-497b9571a6608f4d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

**Rappel :** l'instruction `i++` est une écriture simplifiée pour `i =
i + 1`.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4fa8b28e792df78ae76cfea8a56df21a", "grade": false, "grade_id": "cell-64e23e96bac664e7", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Copiez l'instruction `for` ci-dessous dans la cellule suivante, et
  remplacez les trois "?" par les valeurs appropriées pour afficher
  les entiers pairs entre 0 et 20 (0,2,4,...,20) :

  ```
    for (int i = ?; i <= ?; i = ? ) {
        cout << i << endl;
    }
  ```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 23e3c19a0ffbe060c2b3ed98d21f1739
  grade: true
  grade_id: cell-197e8a13ab933d54
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
for (int i = 0; i <= 20; i += 2 ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "84a72f49f4d7fbccea79a41acd9a6626", "grade": false, "grade_id": "cell-8f27451dcf8a9962", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Écrivez des boucles `for` qui affichent les nombres suivants dans
  l'ordre donné :

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3fbdc4629503778839298213621c515a", "grade": false, "grade_id": "cell-dc66ba064648240a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

`0, 3, 6, 9, 12` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 4edf21fa7a5a8ff511b104b459a93479
  grade: true
  grade_id: cell-0403b0717ee75f12
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
for (int i = 0; i <= 12; i += 3 ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e1587891519fbb21fc5bda1d2ed5002d", "grade": false, "grade_id": "cell-d467a5322af6c861", "locked": true, "schema_version": 3, "solution": false, "task": false}}

`20, 21, 22, 23, 24, 25` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 3aad3e9c60cd34fa36fba040c65aacab
  grade: true
  grade_id: cell-bb29f7c60e0890ef
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
for (int i = 20; i <= 25; i++ ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7aaec7f6bd07ef5b17880573ebd9b08b", "grade": false, "grade_id": "cell-27a6a431fe02596d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

`10, 9, 8, 7, 6, 5, 4, 3, 2, 1` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 6d58a40c85ea1eba2f98acc510848bc1
  grade: true
  grade_id: cell-01de16c794abf858
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
for (int i = 10; i >= 1; i-- ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "2441a818dd5ac5dc1fcecfe782e71373", "grade": false, "grade_id": "cell-117a4ab9b881f533", "locked": true, "schema_version": 3, "solution": false, "task": false}}

`2, 4, 8, 16, 32` :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: d7b00bf1a2accb074654a68c14539009
  grade: true
  grade_id: cell-82fe8beb79812aba
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
for (int i = 2; i <= 32; i+=i ) {
    cout << i << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1898e1be264c3f2d31312927984ef1a5", "grade": false, "grade_id": "cell-ed97db4d86ee7080", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Exercice: accumulons !

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7b728e724aaabd12e80586465918a557", "grade": false, "grade_id": "cell-560788172824cc61", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Observez les cellules suivantes et devinez la valeur finale de la
  variable `c`; puis exécutez pour vérifier.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 659b22ff1f8d5464aa51748a285f8584
  grade: false
  grade_id: cell-fda4a5905295a758
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int c = 0;
for (int i = 0; i < 6; i++) {
    c = i + c;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fe13effafcc7c010151961c567e3b488
  grade: false
  grade_id: cell-f75c84eb6d116fc4
  locked: true
  schema_version: 3
  solution: false
  task: false
---
c
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "83fd1cdfb33ed0cef21e5d243d0041cf", "grade": true, "grade_id": "cell-b87dd082a29be4b9", "locked": false, "points": 0, "schema_version": 3, "solution": true, "task": false}}

Entre `c` et `i` quelle variable sert de compteur? d'accumulateur?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5d3bdbfb35e0ddbc38ade8e6b708b170", "grade": false, "grade_id": "cell-742f622bc7056e10", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Recopiez la boucle ci-dessous puis modifiez la condition d'arrêt
  pour que la variable `c` soit égale à $36$ après l'exécution :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: fb1856ce5b74752ba0904f486c7728a2
  grade: false
  grade_id: cell-9c0385060494fe0c
  locked: false
  schema_version: 3
  solution: true
  task: false
---
c = 0;
for (int i = 0; i <= 8; i++) {
    c = c + i;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b9c2f4f87fca9eca5cf1636822202f13
  grade: false
  grade_id: cell-27c0da7d14f62d91
  locked: true
  schema_version: 3
  solution: false
  task: false
---
c   // doit valoir 36
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e89d5cc15ae38c27122433a526304ca6", "grade": false, "grade_id": "cell-a92593ec6373f39d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

La cellule suivante contient des tests automatisés; nous reviendrons
dessus plus en détails par la suite; pour le moment, vous pouvez juste
exécuter la cellule et vérifier qu'il n'y a pas de message d'erreur.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1ab7066d9663bb6c7a2793d3b9bb8ac9
  grade: true
  grade_id: cell-bf26103d9c19d6f5
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( c == 36 )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "efe58891ecab64d098531b9d2257647b", "grade": false, "grade_id": "cell-4e242b4c7dd64021", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- En vous inspirant de l'exemple ci-dessus, écrivez ci-dessous un
  programme qui calcule la valeur de $n! = 1\times 2 \times \cdots
  \times n$, en utilisant une variable `f` comme accumulateur :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 939f02f3749f1aea9269affa291c6114
  grade: false
  grade_id: cell-b3947d8539dfc764
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int n = 5;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 1a768505610f416b790ede0277e6dea5
  grade: false
  grade_id: cell-c0739002bc408396
  locked: false
  schema_version: 3
  solution: true
  task: false
---
int f = 1;
for (int i = 2; i<=n; i++) {
    f *= i;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a4c08a39cdafca60b0c93e44e39d29bb
  grade: false
  grade_id: cell-a7fa6c68f7a8f078
  locked: true
  schema_version: 3
  solution: false
  task: false
---
f // 120 pour n = 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0dfdf15daccbdf1cc615e5055811666b
  grade: true
  grade_id: cell-70156efdecd752af
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( f == 120 )
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7fc13ec8962d98be9b1e7401f385e1d4", "grade": false, "grade_id": "cell-262927f9eba5a9ae", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Reprendre votre programme pour le mettre sous la forme d'une
  *fonction* qui calcule $n!$ :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2bf9af38b4437ae9eed5f301a2a9b8f2
  grade: false
  grade_id: cell-59d27e7e46c6be00
  locked: false
  schema_version: 3
  solution: true
---
int factorielle(int n) {
    int f = 1;
    for (int i = 2; i<=n; i++) {
        f *= i;
    }
    return f;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7cd2c89c5cee52601afeb47970ef1540", "grade": false, "grade_id": "cell-bbc3a5eababe0ebd", "locked": true, "schema_version": 3, "solution": false, "task": false}}

L'appel suivant à votre fonction devrait renvoyer 120 :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 445e07e19db57505b5f02b0cc963cea9
  grade: false
  grade_id: cell-20fcc91fff7098df
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(5)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b5877df5b8723ba8dd440a2ece1c4c2a", "grade": false, "grade_id": "cell-57835c5482344135", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Vérifiez votre fonction grâce aux tests suivants (ils doivent tous
afficher `true`) :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 73cb9df6f9be087c9cb68d068d7e2472
  grade: false
  grade_id: cell-e8bde338e8e91293
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(5) == 120
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 428ca5eb393e8b981498cd1dee91e3c0
  grade: false
  grade_id: cell-0f480f455c001cb4
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(6) == 720
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fad43258d645e4c30365b17a0325e8c2
  grade: false
  grade_id: cell-c0e7b253d4de674e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(10) == 3628800
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 85affde691cbc8e7b5c4ef7ef7e3ff15
  grade: false
  grade_id: cell-1ee3df1dc7a458a7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(1) == 1
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 55b8cb46f885312bfcba1d860c798184
  grade: false
  grade_id: cell-142a1c4939f30f88
  locked: true
  schema_version: 3
  solution: false
  task: false
---
factorielle(0) == 1 // convention mathématique
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "37b8419fcd77a3705d3f917364790526", "grade": false, "grade_id": "cell-a49ebc122273ee08", "locked": true, "schema_version": 3, "solution": false, "task": false}}

Tests automatisés :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cdd0900d6658c2a406e4feb9c4fc88f3
  grade: true
  grade_id: cell-a5be78a5a5a25142
  locked: true
  points: 2
  schema_version: 3
  solution: false
  task: false
---
CHECK( factorielle(0) ==   1 );
CHECK( factorielle(1) ==   1 );
CHECK( factorielle(2) ==   2 );
CHECK( factorielle(3) ==   6 );
CHECK( factorielle(4) ==  24 );
CHECK( factorielle(5) == 120 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "80afe207cbad29e0d0829dfbf4ee5ae4", "grade": false, "grade_id": "cell-1fe179818c6002ac", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Utilisation de la boucle for dans Laby

- Relevez le défi Laby ci-dessous si vous ne l'avez pas encore fait en
  Semaine 1 :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 10d050a6ba96c43f9d67257dbfae88ca
  grade: false
  grade_id: cell-ee3432e66e9fe991
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY("counting-the-rocks")
```

```{code-cell}
void enleve_caillou() {
    prend();
    avance();
    gauche();
    gauche();
    pose();
    droite();
    droite();
}
```

```{code-cell}
void go_for_it(int Nbr) {
    for (int i=0; i<Nbr; i++) {
        if (regarde() == Caillou) {
            enleve_caillou();
        }
        else {
            avance();
        }
    }
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: c3a9b016a860f30abb2b7212dc0e99da
  grade: false
  grade_id: cell-dc0eba466ac0f400
  locked: false
  schema_version: 3
  solution: true
  task: false
---
debut();
go_for_it(8);
gauche();
go_for_it(2);
gauche();
go_for_it(2);
droite();
go_for_it(4);
droite();
go_for_it(6);
gauche();
go_for_it(2);
ouvre();
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 54b0a770261b037c31cd1ae3e9742d63
  grade: true
  grade_id: cell-f81330eca20c0208
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( a_gagne() );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cecea7980c2484ef6782adb0e15166ed", "grade": false, "grade_id": "cell-fd0933aaa600036b", "locked": true, "schema_version": 3, "solution": false, "task": false}}

-  ♣ Écrivez une fonction `carre(int L)` qui prend en paramètre un
   entier L, et qui fait faire à la fourmi une trajectoire carrée de
   côté L cases. La fourmi doit revenir à la case de départ à la fin
   de la fonction.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a925773535b684f1f0536fa900e9bf55
  grade: false
  grade_id: cell-b0d580c556865d95
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <laby/global_fr.hpp>
LABY_BAR(
u8"o o o o o o o o o o o o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o . . . . . . . . . . o\n"
u8"o ↑ . . . . . . . . . o\n"
u8"o o o o o o o o o o o o\n"
)
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: dc45e85d556613b04fac1e73d781b0fc
  grade: true
  grade_id: cell-bf212efeb0472746
  locked: false
  points: 0
  schema_version: 3
  solution: true
  task: false
---
// Entrée : un entier L, correspondant à la longeur d'un côté de la trajectoire.
// Sortie : aucune, déplace la fourmi selon un carré de longueur L
void carre(int L) {
    if (L<1) { return; }
    for (int j=0; j<4; j++) {    
        for (int i=1; i<L; i++) {
            avance();
        }
        droite();
    }

}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e1746b23a09cab49c178ab5325a69843
  grade: false
  grade_id: cell-b7280173f444a974
  locked: true
  schema_version: 3
  solution: false
  task: false
---
debut();
carre(0) // La fourmi ne fait rien
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a0d6e50de8c0abbacc5ee7168b567550
  grade: false
  grade_id: cell-61f6cbe5090c44f7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
debut();
carre(1) // La fourmi doit faire un tour sur elle-même
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fd99be855a417a1d5927aef996f3e640
  grade: false
  grade_id: cell-cd855fcd1a51f005
  locked: true
  schema_version: 3
  solution: false
  task: false
---
debut();
carre(5) // la fourmi doit parcourir un carré de longueur 5 cases
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7db3b4ffb2b676de5ed4d914d8ac574b", "grade": false, "grade_id": "cell-49a7205ebd424a67", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Bilan

Dans cette feuille, vous avez mis en pratique la boucle `for` pour
**compter** et pour **accumuler**. Vous avez maintenant les outils
requis pour passer à la suite du TP.
