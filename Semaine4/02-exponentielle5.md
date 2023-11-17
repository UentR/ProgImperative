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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "fc78fbcc6c6f5f0b33ef0083fdca373a", "grade": false, "grade_id": "cell-a5a96caf0e3314b2", "locked": true, "schema_version": 3, "solution": false}}

# TP : implanter la fonction exponentielle (5/5)

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "101eb700825630e3e93bcf4e54b9af68", "grade": false, "grade_id": "cell-bc097d26c9102dde", "locked": true, "schema_version": 3, "solution": false}}

## Partie 5 : optimisation ♣

Dans ce cas précis, il n'est pas très efficace de réutiliser les
fonctions `puissance` et `factorielle` : on effectue les calculs
plusieurs fois! En effet, tel que nous avons écrit notre fonction
exponentielle, pour calculer $x^{r+1}$ on reprend le calcul du début
(nouvel appel à la fonction puissance) sans utiliser le fait qu'on a
déjà calculé $x^r$ et que $x^{r+1} = x^r \times x$ (et de même pour le
calcul de la factorielle qui est repris du début à chaque appel à la
fonction factorielle alors que $(r+1)! = r! \times (r+1)$).  On va
écrire une nouvelle version plus efficace de la fonction
exponentielle, qui ne fait pas appel aux fonctions puissance ou
factorielle pour éviter ce problème de calculs faits plusieurs fois.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "0f390345d50eff58e9cffef24b527b3d", "grade": false, "grade_id": "cell-6d56e4530ad5eb9d", "locked": true, "schema_version": 3, "solution": false}}

Copiez-collez ici les fonctions `abs` et `egal` de la
[partie 3](02-exponentielle3.md) :

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: feed7b0ea60242c06966eb17f9ecb49d
  grade: false
  grade_id: cell-11c71a2c606e0da6
  locked: false
  schema_version: 3
  solution: true
---
double abs(double x) {
    if (x<0) { return -x; }
    return x;
}
```

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 660ed4e300bd81daa16372bfbf9b1181
  grade: false
  grade_id: cell-f8b3f1f99b27afb6
  locked: false
  schema_version: 3
  solution: true
---
bool egal(double x, double y, double E) {
    double Ax = abs(x);
    double Ay = abs(y);
    double Axy = abs(x-y);
    return (Axy<E*Ax) && (Axy<E*Ay);
}
```

Complétez la fonction ci-dessous qui calcule l'exponentielle à
précision donnée **sans** utiliser de fonction annexe (sauf `egal`),
et en procédant de façon plus efficace. Pour cela, vous aurez besoin
de trois variables d'accumulation : celle de la puissance, celle de
la factorielle et celle de l'exponentielle.

```{code-cell}
---
deletable: false
nbgrader:
  cell_type: code
  checksum: 6c45e940b8d3752d393114435eb7af2d
  grade: false
  grade_id: cell-303a8716a80dcc32
  locked: false
  schema_version: 3
  solution: true
---
/** Calcul rapide de la fonction exponentielle à précision donnée
 * @param x un nombre de type double
 * @param epsilon un nombre de type double
 * @return e^x avec précision epsilon
**/
double expRapide(double x, double epsilon) {
    double currentSomme, lastSomme, puissance, fact;
    currentSomme = 1;
    puissance = x;
    fact = 1;
    int n = 1;
    do {
        lastSomme = currentSomme;
        currentSomme += (puissance / fact);
        n++;
        puissance *= x;
        fact *= n;
    } while (!egal(lastSomme, currentSomme, epsilon));
    return currentSomme;
}
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: 8d0201184bba0f21e1cc937519951ef5
  grade: false
  grade_id: cell-c96d4c17c02ce941
  locked: true
  schema_version: 3
  solution: false
---
expRapide(5, 0.000000001) // 148.413159
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: e544e90d711df8993da0ea869a5fbdbb
  grade: false
  grade_id: cell-733b09f1d02a12cf
  locked: true
  schema_version: 3
  solution: false
---
expRapide(3, 0.000000001) // 20.085537
```

```{code-cell}
---
deletable: false
editable: false
nbgrader:
  cell_type: code
  checksum: ee6fce39ac451bf744049ea8b586429b
  grade: false
  grade_id: cell-54872c873b619fe1
  locked: true
  schema_version: 3
  solution: false
---
expRapide(1, 0.000000001) // 2.718282
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bed3d1cdb8a8d299ad757ac0ccd54840", "grade": false, "grade_id": "cell-765bea92acc94ff3", "locked": true, "schema_version": 3, "solution": false}}

Évaluez la performance de la fonction `expRapide` en utilisant à
nouveau `timeit`. Est-ce vraiment plus rapide?

```{code-cell}
%timeit expRapide(10, 0.00000001);
```

Amélioration d'environ 94%

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "1a57be5a1f128cccfa27b6c566981aa1", "grade": false, "grade_id": "cell-54073acf05987882", "locked": true, "schema_version": 3, "solution": false}}

## Bilan

Vous avez maintenant une implantation nettement plus rapide de la
fonction exponentielle. Faut-il pour autant toujours tout réimplanter
plutôt que de réutiliser ? Non, surtout pas :

> «Early optimisation is the root of all evil»
>
> -- Donald Knuth

Ici, on pourrait par exemple obtenir les mêmes performances sans
duplication de code par *mémoïsation* (conserver les valeurs déjà
calculées de $n!$ et $x^n$ pour éviter de les recalculer). En général,
c'est à traiter au cas par cas, en tenant compte du compromis entre
temps de dévelopement et performances requises, des questions de
complexité (cf cours à venir), etc.

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "f3313388c3a778384dc9d70cd75033d4", "grade": false, "grade_id": "cell-c367cfa1df22e874", "locked": true, "schema_version": 3, "solution": false}}

Vous pouvez maintenant passer à la [suite du TP](index.md).
