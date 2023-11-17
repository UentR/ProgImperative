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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e4ed54f9374fe785a849796811edb0f1", "grade": false, "grade_id": "cell-b78562ee2ff6d72c", "locked": true, "schema_version": 3, "solution": false}}

# TP : variables et affectations

Dans la feuille précédente, nous avons effectué des calculs et observé
les résultats (type, valeur). Pour écrire des programmes, nous aurons
besoin de **stocker les résultats intermédiaires dans des variables**
pour en réutiliser les valeurs.

## Exercice 1

- Exécutez la cellule suivante :

```{code-cell}
int a;
a = 3;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ba6652be5c55c029961aaa50cb81d6b9", "grade": false, "grade_id": "cell-77b23801c7675aeb", "locked": true, "schema_version": 3, "solution": false}}

Une fois que la variable `a` a été ***déclarée*** (`int a;`) et qu'on
lui a ***affecté*** une valeur (`a = 3`), on peut afficher ou
réutiliser cette valeur :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fee5830b8aede03bdf41f0db12f9fc19
  grade: false
  grade_id: cell-cb019a2142f5c180
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0a7b5f91e93c4c924efdde3a9c0ea28e
  grade: false
  grade_id: cell-001bb0d2577daa8b
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a + 1
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 614b58ab1299f4d79e8ddcd5ad514017
  grade: false
  grade_id: cell-8830572316055e34
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a + a + a
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ceaa22003ffdddbe5a24c2bb58b0836c", "grade": false, "grade_id": "cell-69cecfe5105b306d", "locked": true, "schema_version": 3, "solution": false, "task": false}}

On peut aussi modifier la valeur de `a` :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: fdff95e0a32bac31d137441fae8be11d
  grade: false
  grade_id: cell-feb1fac9b27cedcf
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a = 5;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d74c1bb7fc965c0b5c1c8009638608f3
  grade: false
  grade_id: cell-17a1af4fbfa578ce
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5a93e22553675b75564e9e456d740448
  grade: false
  grade_id: cell-66c91df51588842e
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a = a + 1;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 215bcd1733f78d667ea804052a5fce82
  grade: false
  grade_id: cell-f93c662745eac3cc
  locked: true
  schema_version: 3
  solution: false
  task: false
---
a
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "834f5df4982133662574ade48a23d255", "grade": false, "grade_id": "cell-67887572028175dc", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Que se passe-t-il si l'on exécute à nouveau la dernière cellule? Si
  on exécute alternativement les deux dernières cellules?

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bbb11d6c9985a3ebc219d1fc62693525", "grade": false, "grade_id": "cell-11418469192f043e", "locked": true, "schema_version": 3, "solution": false}}

## Quelques remarques sur Jupyter

L'ordre dans lequel vous exécutez les cellules est important, la
variable contient la **dernière valeur que vous lui avez
attribuée**. L'ordre d'exécution des cellules est indiqué entre
crochets dans la marge de gauche.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "398c703c716b88f225bcae0f95ba5715", "grade": false, "grade_id": "cell-11418469192f043f", "locked": true, "schema_version": 3, "solution": false}}

Vous aurez noté que certaines cellules finissaient par «;», d'autres
non.

### Exercice 2

- Exécutez les cellules suivantes et observez le résultat :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: dd0aa0094b5e584ca8a31ef372270dfc
  grade: false
  grade_id: cell-3c981205fdf5c2ad
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 + 1
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8c5186bab6e5dea35f1c042c728da4a7
  grade: false
  grade_id: cell-1ca515e4663fceff
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 + 1;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a8da5cfabb98bfff0cacb60780a1bce9
  grade: false
  grade_id: cell-14ff22d2652ac945
  locked: true
  schema_version: 3
  solution: false
  task: false
---
1 + 1;
2 + 2
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a241d96474a7be331015009524932b2b", "grade": false, "grade_id": "cell-11418469192f043g", "locked": true, "schema_version": 3, "solution": false}}

En général, toute *instruction* C++ doit se terminer par un «;». Par
convention pour C++ dans Jupyter, si la dernière instruction d'une
cellule est une *expression* (elle a une valeur) et si l'on omets le
«;», alors cette valeur est affichée, avec son type.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1b10baba9e56f1d65b5987d2fceb2b75", "grade": false, "grade_id": "cell-51cce273e81a7bb6", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Retour sur les variables

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "636d73718d93878465ab2e3c929934c0", "grade": false, "grade_id": "cell-36f8f65940be42e9", "locked": true, "schema_version": 3, "solution": false}}

### Exercice 3

Les cellules suivantes déclarent deux variables `r` et `pi`. Vous
noterez qu'une valeur est affectée à `pi` dans la foulée, en mettant
la déclaration et l'affectation sur la même ligne :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 21ab90495a9e1454b6f8d02225c1e49b
  grade: false
  grade_id: cell-6d21b67b8f0160bc
  locked: true
  schema_version: 3
  solution: false
---
double pi = 3.1415;
double r;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f115e46467180823a68878709f74eec2", "grade": false, "grade_id": "cell-91058b910f815221", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Utilisez ces variables pour calculer l'aire et le périmètre d'un
  disque de rayon `r` pour les différentes valeurs données
  ci-dessous. Pour simplifier, vous pourrez considérer que la variable
  `pi` contient la valeur exacte du nombre bien connu. Utilisez les
  cellules vides pour faire vos calculs. N'oubliez pas d'exécuter
  aussi les cellules qui changent la valeur de `r`.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4b56524e61ead946e966a61bfe137c13
  grade: false
  grade_id: cell-36b8bae3af9f71aa
  locked: true
  schema_version: 3
  solution: false
---
r = 5;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "63649581bd9bc2641d2b05d96360d216", "grade": false, "grade_id": "cell-ac377dc636c17e35", "locked": true, "schema_version": 3, "solution": false}}

Aire :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 2fc60601c84ce635c4f34a54031d1b49
  grade: false
  grade_id: cell-c99afbf62e837109
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '78.5375

    type: double'
---
pi*r*r
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e0169a4406266e6351e6223e044c1a0e", "grade": false, "grade_id": "cell-ecae8424fb68b04b", "locked": true, "schema_version": 3, "solution": false}}

Périmètre :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: ad3ada79f9732390682ed5db98f1f47e
  grade: false
  grade_id: cell-d382e01e1d7d9147
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '31.415

    type: double'
---
2*pi*r
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8306dbab487059781a611cb5951e0ca3
  grade: false
  grade_id: cell-9a35ab21a5662c0e
  locked: true
  schema_version: 3
  solution: false
---
r = 2.5;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c7ac2422ed61db78e4cefe521894f1a4", "grade": false, "grade_id": "cell-9bcdb6ed085c381b", "locked": true, "schema_version": 3, "solution": false}}

Aire :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: fbc351028477cd02876466da6d5b32da
  grade: false
  grade_id: cell-6af902a046062f5f
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '19.6344

    type: double'
---
pi*r*r
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c4d742f40f5c79fd2a556a06b1bf6e4e", "grade": false, "grade_id": "cell-801dfeea6ca8176e", "locked": true, "schema_version": 3, "solution": false}}

Périmètre :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: b36302b28576efdc1d3dc4f284e90d25
  grade: false
  grade_id: cell-d525fdb0f7f4a3f6
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '15.7075

    type: double'
---
2*pi*r
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d63d00ab1644881330eece81b82690c7
  grade: false
  grade_id: cell-be5d7b2e92bbc466
  locked: true
  schema_version: 3
  solution: false
---
r = 10;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c9121c9bc9c950b8ffc8fb77547c6d47", "grade": false, "grade_id": "cell-5c2043feb2b5ee9a", "locked": true, "schema_version": 3, "solution": false}}

Aire :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: f8257a8af89ad22d0aca8138e95383b9
  grade: false
  grade_id: cell-3b07ae4aadece3b1
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '314.15

    type: double'
---
pi*r*r
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "da69e4857c100b745977c290c56cc528", "grade": false, "grade_id": "cell-7a1dfca8d4b36e75", "locked": true, "schema_version": 3, "solution": false}}

Périmètre :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 807b39c8755f72e103a7df7c3911a993
  grade: false
  grade_id: cell-43dcdfdaac13d375
  locked: false
  schema_version: 3
  solution: true
ordo_solution:
  text/plain: '62.83

    type: double'
---
2*pi*r
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3aec28a798387a281aa812f19bd3f678", "grade": false, "grade_id": "cell-2b028b9f5cbf1a95", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 4

Les cellules suivantes définissent deux variables `b` et `c` :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7f89aca42a78ecf5618433b0949f3234
  grade: false
  grade_id: cell-5f25dd0c5b2575d2
  locked: true
  schema_version: 3
  solution: false
---
int b, c;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 25f4bd23b50ecc22b1f51f4947e60349
  grade: false
  grade_id: cell-c60f20281517629f
  locked: true
  schema_version: 3
  solution: false
---
b = 5;
c = 8;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1c6277a8e8dbdba9d76e456c07867f51", "grade": false, "grade_id": "cell-e9b1884cc2aaecf1", "locked": true, "schema_version": 3, "solution": false}}

Dans les cellules vides ci-dessous, écrivez un programme qui *échange
les valeurs* des deux variables, comme dans le TD 1. Votre programme
pourra déclarer de nouvelles variables et utiliser des affectations,
mais sans écrire les nombres à la main bien sûr, ce serait tricher.

**Indication :**
- Une cellule peut contenir plusieurs instructions (comme ci-dessus)
  séparées par des points-virgules `;`.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: fd990e3f9bc7a4d8ce3bef9df16ce830
  grade: false
  grade_id: cell-054289e2e6184e6c
  locked: false
  schema_version: 3
  solution: true
---
int Temp = b;
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 44a825ca523567f1309e31b9dbce0e49
  grade: false
  grade_id: cell-0c01da91c9e5a5d1
  locked: false
  schema_version: 3
  solution: true
---
b = c;
c = Temp;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a0748f5ce7e06cd19500daa5395bef43
  grade: false
  grade_id: cell-84a2a3a6c8bc8087
  locked: true
  schema_version: 3
  solution: false
ordo_solution:
  text/plain: '8

    type: int'
---
b // doit afficher 8 (ancienne valeur de c)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 417ab1d925007b97a1991322b0608381
  grade: false
  grade_id: cell-033b5743ea66933d
  locked: true
  schema_version: 3
  solution: false
ordo_solution:
  text/plain: '5

    type: int'
---
c // doit afficher 5 (ancienne valeur de b)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5a4b0fe380c84a45c8cb0fd199a72dbb
  grade: true
  grade_id: cell-1bd7d603649344f2
  locked: true
  points: 2
  schema_version: 3
  solution: false
---

```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9b3bcf2875083ea0f70fdc4144ce23c5", "grade": false, "grade_id": "cell-34adf2e9f2f58483", "locked": true, "schema_version": 3, "solution": false}}

## Affectations et types

Tout à l'heure, nous avons exploré différents types de valeurs et nous
venons de voir comment déclarer une variable pouvant contenir un
certain type. Mais que se passe-t-il lorsque l'on affecte une valeur
du mauvais type à une variable?

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "76471a0ab1e0cfeac3e2abcb6c53cfe3", "grade": false, "grade_id": "cell-f81a9bffcf2e6811", "locked": true, "schema_version": 3, "solution": false}}

### Exercice 5

- Faites-vous une opinion en observant le résultat des affectations
  suivantes :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8368cad476d6516dbea29b439b81c08b
  grade: false
  grade_id: cell-c6a5c1361e8a71f0
  locked: true
  schema_version: 3
  solution: false
  task: false
---
int v1;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0dac43a47070505a81b9154cf313cb1b
  grade: false
  grade_id: cell-aad302a69e2794c9
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v1 = 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 11e278ab0cb8e547ffcaa849dd88faab
  grade: false
  grade_id: cell-81f6d9263306f1fc
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v1 = 2.5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e510bd0d66eaf1fe4ba198ebab324783
  grade: false
  grade_id: cell-99247d901236707c
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v1 = false
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ab6718d91052a12b1aec7e3d4c2adab3
  grade: false
  grade_id: cell-aad3ff4ab68c3c99
  locked: true
  schema_version: 3
  solution: false
  task: false
---
double v2;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7ca0ec23af4630a9c8ddfd7f60304eb4
  grade: false
  grade_id: cell-6764f63ae84baff7
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v2 = 5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 638f3e82aad7ae20b2a6f19b25de31da
  grade: false
  grade_id: cell-d7b67f8a693dbd5a
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v2 = 5.3
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5b1496172e14d9da1582fc56b64b8792
  grade: false
  grade_id: cell-affbe7ff2805f4e9
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v2 = true
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d7ff4725ffeda12fc091687b1625bea5
  grade: false
  grade_id: cell-6df3d448966350a3
  locked: true
  schema_version: 3
  solution: false
  task: false
---
bool v3;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3da733ce5e09d780fcb01919e30576d3
  grade: false
  grade_id: cell-523ce03309e05c43
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v3 = 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: be3033a8b0a25ba327fb284c6837d4fb
  grade: false
  grade_id: cell-737e6ebdf0d644f9
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v3 = 0
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 515f178cfc192b1bb48715cf45890c09
  grade: false
  grade_id: cell-06d4a669f9f8d504
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v3 = 1.5
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5ff50d1529ad5c7ee9820be9e29286a9
  grade: false
  grade_id: cell-80c1c116570040af
  locked: true
  schema_version: 3
  solution: false
  task: false
---
v3 = false
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4923e17a17c544bb30b2686935688687", "grade": false, "grade_id": "cell-a5106c0a703afcee", "locked": true, "schema_version": 3, "solution": false}}

Vous remarquez que, lorsque les types sont suffisament proches, les
valeurs sont converties automatiquement au moment de
l'affectation. Dans les autres cas, l'affectation déclenche une
erreur.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c89964f3bf3795f7bec68d75ee4e7ee4", "grade": false, "grade_id": "cell-4edc9c17698dd130", "locked": true, "schema_version": 3, "solution": false}}

### Exercice 6

Pour chaque expression ci-dessous, déclarez une variable **du bon
type** et affectez-lui le résultat, puis affichez le contenu de la
variable pour le vérifier.

**Exemple :**

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 25eafdd02a1ad64b706211bd130d4a8e
  grade: false
  grade_id: cell-015c0695f0c9e26c
  locked: true
  schema_version: 3
  solution: false
---
1 + 2
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ad7a74816b419c51dcd355ece119422d
  grade: false
  grade_id: cell-06a91ae7c8417a4c
  locked: true
  schema_version: 3
  solution: false
---
int i = 1 + 2;
i
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0a7b577bfda0b4a0fd3d6c752d19866a", "grade": false, "grade_id": "cell-4dbcd55e901230ff", "locked": true, "schema_version": 3, "solution": false}}

À vous de faire comme dans l'exemple avec les expressions ci-dessous :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: adc648f4fcd2a577cc05d0be2ec0bda5
  grade: false
  grade_id: cell-51887552dc9d6af2
  locked: true
  schema_version: 3
  solution: false
---
2.3*9 + 5
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 8fbb91b51e55e8000727d4128148a148
  grade: false
  grade_id: cell-cc56a59bc6dcf4c2
  locked: false
  schema_version: 3
  solution: true
---
int i = 2.3*9+5;
i
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: d46a5e4f1dea31ff2408ae0dff3bd74e
  grade: false
  grade_id: cell-d20289b033bf354b
  locked: true
  schema_version: 3
  solution: false
---
45/2 + 8 + 6
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 5f177b186fcf2806b1d53a7f1818cbf7
  grade: false
  grade_id: cell-7a9392df96472f0b
  locked: false
  schema_version: 3
  solution: true
---
int i = 45/2 + 8 + 6;
i
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 52823a6ea04871547296b080b77843e9
  grade: false
  grade_id: cell-b5d8285e37ecdd1c
  locked: true
  schema_version: 3
  solution: false
---
9 == 3*3
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 338eddd0b33c3e0095c020509dbf8983
  grade: false
  grade_id: cell-cb28c000ca6f75bd
  locked: false
  schema_version: 3
  solution: true
---
bool i = 9==3*3;
i
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: cf9482805dca18bdaec39c3069fd2028
  grade: false
  grade_id: cell-4269879c75c2237f
  locked: true
  schema_version: 3
  solution: false
---
true and 8 > 10
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 9a1b310af950e465ae63410d3b7287c5
  grade: false
  grade_id: cell-2e94206797747f78
  locked: false
  schema_version: 3
  solution: true
---
bool i = true and 8>10;
i
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d95f6ef892f20fd0c87e84b80cc08b41", "grade": false, "grade_id": "cell-6e834cd22ecc144b", "locked": true, "schema_version": 3, "solution": false}}

Avec cette feuille, nous avons fini notre première exploration des
données en C++ : calculer des valeurs avec des expressions, comprendre
les types de ces valeurs et leur influence, stocker les résultats dans
des variables. Dans la feuille suivante, vous aborderez les conditions
et les fonctions.

Vous pouvez maintenant fermer cette feuille; utilisez pour cela le
raccourci clavier <kbd>Ctrl</kbd>+<kbd>Maj</kbd>+<kbd>Q</kbd>.
