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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c8dce4e85941d516ab5cc4d12801504c", "grade": false, "grade_id": "cell-49fef9fe78b2c65a", "locked": true, "schema_version": 3, "solution": false}}

# TP : tableaux 2D

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 672d3dbda55973af9935f27ad79ddc0a
  grade: false
  grade_id: cell-2567ccefc2e87875
  locked: true
  schema_version: 3
  solution: false
---
#include <iostream>
#include <vector>
using namespace std;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dee5684749277fb063302880dfd95a30", "grade": false, "grade_id": "cell-c7d94e0bcb88916d", "locked": true, "schema_version": 3, "solution": false}}

## Exercice 1 : construction pas à pas d'un tableau 2D: les quatre étapes
- Déclarer un tableau d'entiers `t` à deux dimensions; donc de type `vector<vector<int>>`:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: ae660ec8dfa7809895e1a0a65fd0c4ca
  grade: false
  grade_id: cell-d8ced5bf77b8978e
  locked: false
  schema_version: 3
  solution: true
---
vector<vector<int>> t;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f08226158fdc07d1a6475caacca58730", "grade": false, "grade_id": "cell-da8fd6dd0f43ce24", "locked": true, "schema_version": 3, "solution": false}}

- Remarquer qu'il est vide:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 554d2b436b90fb927c1a455e533e12c1
  grade: false
  grade_id: cell-3302ce096403f565
  locked: true
  schema_version: 3
  solution: false
---
t
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 3f1052c671c3ab1e84c025bdd73d7b6f
  grade: false
  grade_id: cell-d47219e64575717c
  locked: true
  schema_version: 3
  solution: false
---
t.size()
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3658cb9e28ae8d4f42eb5c8e0b71ec10", "grade": false, "grade_id": "cell-b2ad1967e86c68c7", "locked": true, "schema_version": 3, "solution": false}}

- On alloue `t` pour qu'il ait trois lignes:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 89cf5a8db78609d1af70e5d14604281d
  grade: false
  grade_id: cell-0c5961ebe84ab65d
  locked: true
  schema_version: 3
  solution: false
---
t = vector<vector<int>>(3);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "495cc86c033b37f19fac67cf6040398c", "grade": false, "grade_id": "cell-78c8cbf17b8f2706", "locked": true, "schema_version": 3, "solution": false}}

- Vérifions que `t` a trois lignes vides:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: edda7b81c2e4b87a56d5fde4b5a581e3
  grade: false
  grade_id: cell-83759e626a55d7b4
  locked: true
  schema_version: 3
  solution: false
---
t
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f5be09a3034ed7db1896cb84733b86c8", "grade": false, "grade_id": "cell-b3ed557f6d73677a", "locked": true, "schema_version": 3, "solution": false}}

- On alloue la première ligne pour qu'elle ait deux éléments

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a6c346beb70dc128035355607db86467
  grade: false
  grade_id: cell-c1fe4796c0b0b6e2
  locked: true
  schema_version: 3
  solution: false
---
t[0] = vector<int>(2);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ebce5a1e30fefb2c820fe8bade8202fa", "grade": false, "grade_id": "cell-94417f9d100f7816", "locked": true, "schema_version": 3, "solution": false}}

- Allouer de même les deux autres lignes:

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 14f353c38657f607b7146252b4d9be10
  grade: false
  grade_id: cell-d5059f8ea79f333d
  locked: false
  schema_version: 3
  solution: true
---
t[1] = vector<int>(2);
t[2] = vector<int>(2);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3394f27546d5ddbdfe85320baa79138b", "grade": false, "grade_id": "cell-4b45129d51f9a85d", "locked": true, "schema_version": 3, "solution": false}}

- La valeur de quelle ligne et quelle colonne est elle changée par l'affectation suivante?

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: a76f8d9f59f7055445f047fb2a4323b1
  grade: false
  grade_id: cell-a1b30da86e24ccdc
  locked: true
  schema_version: 3
  solution: false
---
t[0][1] = 1
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ba86b04a51c24f09906f10fff34c1db8", "grade": false, "grade_id": "cell-d67aac31a057050c", "locked": true, "schema_version": 3, "solution": false}}

- Vérifier:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 01847eb8b7e9acfadd405663e79d1edc
  grade: false
  grade_id: cell-a440b46422e51895
  locked: true
  schema_version: 3
  solution: false
---
t
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fae1377d731e163e1d645329a71cf1b2", "grade": false, "grade_id": "cell-3bc487275e9c04f1", "locked": true, "schema_version": 3, "solution": false}}

- Mettre la valeur 42 en troisième ligne et première colonne

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 8500e16f92f093af34d966ee174acd26
  grade: false
  grade_id: cell-108edeafacf3bf2a
  locked: false
  schema_version: 3
  solution: true
---
t[2][0] = 42
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ca2d862c42886c3618c2ed85e5a3dc6a", "grade": false, "grade_id": "cell-21f981b08a878c4d", "locked": true, "schema_version": 3, "solution": false}}

- Vérifier:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 04169172b4f3ea600f6ebec4b835c49c
  grade: false
  grade_id: cell-f454609688f512a1
  locked: true
  schema_version: 3
  solution: false
---
t
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 51842d3ce6d164328a6788c427808029
  grade: true
  grade_id: cell-533cddc9734026b0
  locked: true
  points: 1
  schema_version: 3
  solution: false
  task: false
---
CHECK( t[2][0] == 42 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b251d2c41cb1ecfa69d0b34602241725", "grade": false, "grade_id": "cell-ccaa9da2e9688a7a", "locked": true, "schema_version": 3, "solution": false, "task": false}}

## Digression : alignement vertical dans les affichages

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "350f8c749f700ffa2395f00d4c954f2a", "grade": false, "grade_id": "cell-7f2fc097b15e0c28", "locked": true, "schema_version": 3, "solution": false}}

Pour afficher joliment un tableau, on doit gérer l'alignement vertical des colonnes. Cela peut se faire en `C++` avec `setw` qui réserve un certain nombre de caractères pour l'affichage d'un nombre. Pour utiliser `setw`, il faut au préalable charger la bibliothèque `iomanip`:

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 224d6f61ac0010ce734b5b4b5df1ab21
  grade: false
  grade_id: cell-ebc1fcab989b602f
  locked: true
  schema_version: 3
  solution: false
  task: false
---
#include <iomanip>
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e228d8f2f89ee5ef2b8274c1f4bd3349", "grade": false, "grade_id": "cell-1f7c930798717da4", "locked": true, "schema_version": 3, "solution": false, "task": false}}

- Exécuter plusieurs fois le code suivant en variant le paramètre de `setw`:

```{code-cell}
cout << "|" << setw(3) << 12 << "|" << endl;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3224d1c156920089ff42529b15048575", "grade": false, "grade_id": "cell-53def89c5c3c8061", "locked": true, "schema_version": 3, "solution": false, "task": false}}

 - Exécuter plusieurs fois le code suivant en variant le paramètre de `setw`:

```{code-cell}
for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ )
        cout << setw(4) << i + j << " ";
    cout << endl;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "3b7bee3d9f4233b9a61b1f7709cfc00e", "grade": false, "grade_id": "cell-7f2fc097b15e0c27", "locked": true, "schema_version": 3, "solution": false}}

## Exemple de construction et d'affichage d'un plus gros tableau 2D

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 01f38e63c00962743a44610c944ca52a
  grade: false
  grade_id: cell-4e524db141414a9d
  locked: true
  schema_version: 3
  solution: false
---
int L = 10;
int C = 10;
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "43a80f6818f5944b811f0853cfb63d38", "grade": false, "grade_id": "cell-888210490a59804e", "locked": true, "schema_version": 3, "solution": false}}

- Les cellules suivantes construisent un tableau à deux dimensions et l'affichent. Annoter chaque cellule avec un commentaire précisant quelle étape de la construction elle effectue (initialisation, allocation des lignes, déclaration, allocation; dans quel ordre?)

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "520496182167cd006a23c6f0e60ba798", "grade": true, "grade_id": "cell-98119b3d30ed0540", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e7d165eeb949a9caf6965615f88cc269
  grade: false
  grade_id: cell-a648420d522a3b1c
  locked: true
  schema_version: 3
  solution: false
---
vector<vector<int>> tableMultiplication;
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "50c160974d4d118cd0c933fcd7a401f5", "grade": true, "grade_id": "cell-e9f33dc1f3766dee", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 55b8a2c286bc0c46893985e99b36997d
  grade: false
  grade_id: cell-1d0b9b36a23d8904
  locked: true
  schema_version: 3
  solution: false
---
tableMultiplication = vector<vector<int>>(L);
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4d48be3e3950500d65159a7d363615e3", "grade": true, "grade_id": "cell-85e2f72b41250dda", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: f3f88883d553c60ccdfdf66a93373f5a
  grade: false
  grade_id: cell-4dd6126bbf0db299
  locked: true
  schema_version: 3
  solution: false
---
for ( int i = 0; i < L; i++ ) {
    tableMultiplication[i] = vector<int>(C);
}
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fbb6e43bb145d76e9257c62fc13c59d5", "grade": true, "grade_id": "cell-55d9f39f6158d87b", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 844ac8de35727754bcddebfacd1dc8d8
  grade: false
  grade_id: cell-b3d7a3efc7008ad7
  locked: true
  schema_version: 3
  solution: false
---
for ( int i = 0; i < L; i++ ) {
    for ( int j = 0; j < C; j++ ) {
        tableMultiplication[i][j] = i * j;
    }
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4b06ac74aa29a3c9b315102ee1c83fc5
  grade: false
  grade_id: cell-fbee56c85ea3fae9
  locked: true
  schema_version: 3
  solution: false
---
tableMultiplication[6][9]
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cabaaba3d0a164335e863737760ed364", "grade": false, "grade_id": "cell-529023907bf92556", "locked": true, "schema_version": 3, "solution": false}}

Affichage direct par Jupyter :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 2349a8a57965980229c32691ffa56d89
  grade: false
  grade_id: cell-527ef708f4aa8be7
  locked: true
  schema_version: 3
  solution: false
---
tableMultiplication
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "4fe4d0ee724505a200d906a53b5ccad9", "grade": false, "grade_id": "cell-fd97830ca86da056", "locked": true, "schema_version": 3, "solution": false}}

Joli affichage :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 4bde63a50106c50ddb6edc17d70a5a34
  grade: false
  grade_id: cell-93b82e487af3eb2b
  locked: true
  schema_version: 3
  solution: false
---
for ( int i = 0; i < L; i++ ) {
    for ( int j = 0; j < C; j++ ) {
        cout << setw(2) << tableMultiplication[i][j] << " ";
    }
    cout << endl;
}
```

```{code-cell}

```
