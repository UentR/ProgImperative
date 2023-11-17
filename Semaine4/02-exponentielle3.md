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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1ca90f09fc87538c759d09fbe1217009", "grade": false, "grade_id": "cell-ffce5d69407bd085", "locked": true, "schema_version": 3, "solution": false}}

# TP : implanter la fonction exponentielle (3/5)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5b33eadecb8f019fd1fe4a6fba69aaaf", "grade": false, "grade_id": "cell-ba70cc528a726649", "locked": true, "schema_version": 3, "solution": false}}

## Partie 3 : comparaison de nombres flottants et précision relative

Sur les nombres flottants (`float` ou `double`) l'opérateur `==` n'est
pas toujours très fiable à cause des erreurs d'arrondis :

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 1e636b99e82d325870440aed2894f08c
  grade: false
  grade_id: cell-357388e8811e8887
  locked: true
  schema_version: 3
  solution: false
---
1.0 + 1e20 - 1e20 == 1e20 - 1e20 + 1.0
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "5941c1b42b9e0d9fa966b932ef4fc3f5", "grade": true, "grade_id": "cell-2ba595671ff56d54", "locked": false, "points": 1, "schema_version": 3, "solution": true}}

Exécutez les cinq cellules suivantes. Que constatez-vous ?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0aa154808a718050f75784ffd1e85186
  grade: false
  grade_id: cell-9822d857d4e81d79
  locked: true
  schema_version: 3
  solution: false
---
double a,b;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: c20e8d87557a1145821afa8bdbd569fa
  grade: false
  grade_id: cell-d98a79aa643b191e
  locked: true
  schema_version: 3
  solution: false
---
a = 16;
b = 15.99999999999;
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e91e01eba95383e91c63ae2b9fbf812d
  grade: false
  grade_id: cell-14c516a6791b2309
  locked: true
  schema_version: 3
  solution: false
---
a
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: b80af210b01b89dea73d35fcd75ac953
  grade: false
  grade_id: cell-e1b28a8439e86689
  locked: true
  schema_version: 3
  solution: false
---
b
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: eb4acdc9ae85cfdafcb2d462375eccbb
  grade: false
  grade_id: cell-659691632843cfcb
  locked: true
  schema_version: 3
  solution: false
---
(a == b)
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c7fbfc0bc3a59294194c9a681536131e", "grade": false, "grade_id": "cell-5017bdc388a2f6c4", "locked": true, "schema_version": 3, "solution": false}}

### Définition : *précision relative*

Chaque fois que l'on veut comparer deux nombres flottants, il faut
spécifier avec quelle **précision** on veut les comparer. 

Le plus simple est de fixer un seuil de **précision absolue** $\eta$,
c'est-à-dire la différence de valeur en dessous de laquelle on
considère que deux nombres sont égaux : $x \simeq y$ si $|x - y| <
\eta$.

Cependant, cette valeur de précision absolue peut être difficile à
fixer, surtout quand les valeurs sont très variables en ordre de
grandeur. Par exemple, si l'on considère des hauteurs de pics
montagneux, on pourrait largement se satisfaire d'être précis à la
dizaine de mètres ($\eta = 10^1$m) près. En revanche si l'on compare
des tailles de personnes, on aimerait pouvoir être précis au
centimètre ($\eta = 10^{-2}$m). On aurait donc besoin de précisions
absolues totalement différentes selon l'ordre de grandeur des
valeurs. 

En fait c'est le plus souvent le nombre de chiffres significatifs en
commun qui est pertinent à mesurer. Formellement, on utilise alors une
**précision relative**. Si on veut comparer $x$ et $y$ avec une
précision relative de l'ordre de cinq chiffres significatifs, on
prendra $\varepsilon=10^{-5}=0,00001$, et on dira que $x$ est égal à
$y$ à $\varepsilon$ près si :

$$ |x - y| < \varepsilon|x| \qquad \text{et} \qquad |x - y| < \varepsilon |y|$$

Moralement : la différence entre $x$ et $y$ est négligeable devant $x$
et devant $y$.

Ce concept est particulièrement pertinent dans notre cas, car
l'exponentielle donne des valeurs d'ordres de grandeur très
différents : $e^1 \simeq 10^0$, $e^5 \simeq 10^2$, $e^{10} \simeq
10^5$ ...

:::{admonition} Exercice

Dans chacun des exemples suivants, est-ce que $x\simeq y$ avec une
précision relative $\varepsilon=0.1$? une précision relative
$\varepsilon=0.01$?

- $x=1.22$, $y=1.24$
- $x=1220$, $y=1240$
- $x=0.0122$, $y=0.0124$
- $x=0$, $y=0.01$

:::

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ec190bccc8388970226c6788b69d462c", "grade": false, "grade_id": "cell-55c9c5c79654d21b", "locked": true, "schema_version": 3, "solution": false}}

### Implantation

Implantez les deux fonctions suivantes dont on vous donne la documentation :
- `abs` mais qui prend cette fois en paramètre un `double` et retourne
   un `double`
- `egal` qui prend en paramètres les nombres $x$, $y$ et $\varepsilon$.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 6a840af6379e2f23d6c794085ae457c8
  grade: false
  grade_id: cell-aa46c278f72ba400
  locked: false
  schema_version: 3
  solution: true
---
/** Valeur absolue pour type double
 * @param x un nombre de type double
 * @return la valeur absolue de x
**/
double abs(double x) {
    if (x<0) { return -x; }
    return x;
}
```

```{code-cell}
abs(-1.5)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 7f53fec20e48a1316dcfdd00e15f8439
  grade: true
  grade_id: cell-abf252519d9a3950
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( abs(-1.5) == 1.5 );
CHECK( abs( 2.2) == 2.2 );
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: dc8b3cf708954ea90905cd962a3ba92a
  grade: false
  grade_id: cell-f6efe81b76dfe516
  locked: false
  schema_version: 3
  solution: true
---
/** Égalité entre deux flottants avec précision relative
 * @param x un nombre de type double
 * @param y un nombre de type double
 * @param epsilon un nombre de type double
 * @return true si la valeur absolue de x - y est plus petite que epsilon * |x| et que epsilon * |y|
**/
bool egal(double x, double y, double E) {
    double Ax = abs(x);
    double Ay = abs(y);
    double Axy = abs(x-y);
    return (Axy<E*Ax) && (Axy<E*Ay);
}
```

```{code-cell}
egal(15.999999, 16, 0.00001)
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 0f578ae8c14b5acd577ddfcd5e49e9cc
  grade: true
  grade_id: cell-da8592649f3234ef
  locked: true
  points: 1
  schema_version: 3
  solution: false
---
CHECK( egal(15.999999, 16, 0.00001) == true  );
CHECK( egal(15.99, 16, 0.00001)     == false );
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "a71e9871858917f60cd90ef6aa48781c", "grade": false, "grade_id": "cell-29e58e1837c86ada", "locked": true, "schema_version": 3, "solution": false}}

Trouvez des valeurs de `epsilon` telles que les nombres ci-dessous
soient considérés comme égaux par `egal` :

```{code-cell}
egal(15, 16, 0.0666667)
```

```{code-cell}
egal(0.0001, 0.002, 20)
```

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "813e0cb645876f6d1e2641d55ec5ca0d", "grade": true, "grade_id": "cell-fd99a546db74023d", "locked": false, "points": 1, "schema_version": 3, "solution": true}}

Que se passe-t-il lorsque $x$ ou $y$ valent $0$ ?

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

```{code-cell}
egal(0.00001, 0, 0.0000001)
```

Il n'existe pas d'espilon tel que 
$$ |x - 0| < \varepsilon|x| \qquad \text{et} \qquad |0 - y| < \varepsilon |0|$$

+++

## Bilan de la partie 3

Maintenant que la notion de précision relative est bien définie, et
que vous avez implanté la comparaison de nombres flottants avec une
précision relative fixée, vous pouvez passer à la [partie
4](02-exponentielle4.md).
