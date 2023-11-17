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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "d7152fc1ff1988cc180a0a234bd70a2e", "grade": false, "grade_id": "cell-ff26d1e4ab285cb4", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : retour sur l'exercice 3 du TD

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "23e6b697bab1e68fe14f70fb2b382003", "grade": false, "grade_id": "cell-1b21180343eef5af", "locked": true, "schema_version": 3, "solution": false}}

Consultez l'énoncé de TD et et implantez en `C++` les algorithmes de
l'exercice 3, autant que possible sans consulter vos notes de TD.
Pensez à faire des tests pour vérifier vos réponses. Vous aurez besoin
d'ajouter de nouvelles cellules (bouton <kbd>+</kbd> dans la barre
d'outil de la feuille).

```{code-cell}
int max2(double a, double b)  {
    if (a<b) { return b; }
    else { return a; }
}
```

```{code-cell}
max2(2, 3.5)
```

```{code-cell}
max2(-3.1, 6)
```

```{code-cell}
int max3( double a, double b, double c) {
    return max2(max2(a,b), c);
}
```

```{code-cell}
max3(2, -0, 6)
```

```{code-cell}
max3(-1.1, 5, 0)
```

```{code-cell}
max3(8, 9, .1)
```

```{code-cell}
int max3alt(double a, double b, double c) {
    if (a>b && a>c) { return a; }
    else if (b>a && b>c) { return b; }
    else if (c>a && c>b) { return c; }
    return 0;
}
```

```{code-cell}
max3alt(2, -0, 6)
```

```{code-cell}
max3alt(-1.1, 5, 0)
```

```{code-cell}
max3alt(8, 9, .1)
```

### Specification :

```{code-cell}
// Programme moyenne
// Entrée : 3 réels pour les notes de maths et 2 réels pour les notes de physique
// Sortir : La moyenne des notes de maths et de physique en sachant qu'on garde la meilleure note de math et la meilleure note de physique qu'on va respectivement multipliée par 5 et 3
```

```{code-cell}
double mean(double M1, double M2, double M3, double P1, double P2) {
    double Math = max3(M1, M2, M3)*3;
    double PC = max2(P1, P2)*2;
    return (Math+PC)/5.;
}
```

```{code-cell}
mean(5, 8, 7, 2, 0)
```
