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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "9a108efaad4f71c09addc6250d7a8305", "grade": false, "grade_id": "cell-a1cea05ac1387514", "locked": true, "schema_version": 3, "solution": false}}

# TP : implanter la fonction exponentielle (1/5)

**Imaginez que vous développez la nouvelle librairie de fonctions
mathématiques du `C++`.** Au départ, les seules opérations auxquelles
vous avez le droit sont les *opérations arithmétiques usuelles* telles
que `+` `*` `/` `%`. Notre but aujourd'hui est d'écrire la fonction
qui calcule $e^x$.

Pour cela, on utilise la définition de $e^x$ en tant que *série*
(somme infinie) :

$$e^x = \sum_{n=0}^{+\infty} \frac{x^n}{n!} = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} +\cdots+\frac{x^n}{n!}+\cdots$$

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f0d42634ab9ca83d45c5b79c12199e24", "grade": false, "grade_id": "cell-670b85df3798f432", "locked": true, "schema_version": 3, "solution": false}}

On remarque que l'on a besoin en particulier de calculer $x^n$ ainsi
que $n!$. Ce sera l'objet de la première partie. Dans la deuxième
partie, on calculera une approximation de la fonction exponentielle
en la tronquant à un nombre fixé de termes; par exemple : $e^x \simeq
1+\frac{x^2}{2!}+\frac{x^3}{3!}$

La précision d'une telle approximation dépend beaucoup de la valeur de
$x$. Dans la partie 4 on utilisera une méthode *adaptative* : on
fixera cette fois la précision relative souhaitée et on calculera
autant de termes que nécessaire pour atteindre cette précision. Pour
cela on aura préalablement défini -- et implanté ! -- dans la partie 3
ce que l'on entend par précision relative.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5687d16fdbe6452ac56a1f2d1089eaf5", "grade": false, "grade_id": "cell-8ce9f4aa74ff1ade", "locked": true, "schema_version": 3, "solution": false}}

## Partie 1 : fonctions puissance et factorielle

Le but de cette partie est d'écrire les fonctions `factorielle` et
`puissance` (vues en TD) et de vérifier que l'on obtient bien les
résultats attendus. Complétez la fonction `factorielle` ci-dessous
puis vérifiez les résultats des cellules suivantes :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 21526c2fcff411507738fc6eba00ba69
  grade: false
  grade_id: cell-26599ba8b0db5d2c
  locked: false
  schema_version: 3
  solution: true
---
/** Factorielle
 * @param n un entier positif ou nul
 * @return la valeur n! en tant que double
**/
double factorielle(int n) {
    if (n<=1) { return 1; }
    return n * factorielle(n-1);
}
```

```{code-cell}
factorielle(5)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 77b5b29ad8316807bdc9188ac65ef447
  grade: true
  grade_id: cell-b141e2a8fe5b4d49
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( factorielle(0) == 1   );   // Par convention mathématique
CHECK( factorielle(3) == 6   );
CHECK( factorielle(4) == 24  );
CHECK( factorielle(5) == 120 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "b59162ad5f5799af04bb59d5b434e7fc", "grade": false, "grade_id": "cell-4034b50f9054165a", "locked": true, "schema_version": 3, "solution": false}}

Vérifiez l'ordre de grandeur du calcul suivant. Si la valeur est
aberrante, vérifiez l'utilisation du type `double` à toutes les étapes
du calcul.

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5baea162ffe9ed953e12e730886f2cce
  grade: false
  grade_id: cell-248a410c27f82b9c
  locked: true
  schema_version: 3
  solution: false
---
factorielle(100)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "8eccb9ea0f3568cf4deebb4faadf2c7d", "grade": false, "grade_id": "cell-1a440314756d1d38", "locked": true, "schema_version": 3, "solution": false}}

Complétez la fonction `puissance` ci-dessous puis vérifiez les
résultats des cellules suivantes :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 1bcd9f47c0416f26cfe5aba5e5b52c85
  grade: false
  grade_id: cell-98509d177b22e222
  locked: false
  schema_version: 3
  solution: true
---
/** Puissance
 * @param x un nombre de type double
 * @param n un entier positif ou nul
 * @return le nombre x^n de type double
**/
double puissance(double x, int n) {
    if (n==0) { return 1; }
    else if (n==1) { return x; }
    return x * puissance(x, n-1);
}
```

```{code-cell}
puissance(2, 4)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 5649e332a8cfaca594c48b6062cc74f6
  grade: true
  grade_id: cell-0c4baef17dc81ab9
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( puissance(1,  10) == 1     );
CHECK( puissance(2,   5) == 32    );
CHECK( puissance(1.5, 3) == 3.375 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "cfa29c534b225e97d8adac637fe4c097", "grade": false, "grade_id": "cell-471123af8e648bfb", "locked": true, "schema_version": 3, "solution": false}}

Ajoutez des tests (toujours avec `CHECK`) pour vérifier les cas
limites : vérifiez (pour une valeur de $x$ de votre choix) que $x^0$
vaut $1$, que $0^r$ vaut $0$ pour $r$ non nul, et que $0^0$ vaut $1$ :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 7e9f5a944f5b0ed48af66073f167a640
  grade: false
  grade_id: cell-a852e5dd3d8aeab1
  locked: false
  schema_version: 3
  solution: true
---
CHECK( puissance(0,  10) == 0     );
CHECK( puissance(2,   0) == 1    );
CHECK( puissance(0, 0) == 1 );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "84b6e4ae3f85fd830f0cca98d917902d", "grade": false, "grade_id": "cell-b9ac4bd82bc4f381", "locked": true, "schema_version": 3, "solution": false}}

## Bilan de la partie 1

Vous avez maintenant les prérequis pour implanter la fonction exponentielle.
Vous pouvez maintenant passer à la [partie 2](02-exponentielle2.md).

```{code-cell}

```
