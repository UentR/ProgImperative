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

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "e8bd9ddb6ea4e3b5a2d4cf211c19664f", "grade": false, "grade_id": "cell-dec956729eec3931", "locked": true, "schema_version": 3, "solution": false, "task": false}}

# TP : Point de Chute ♣

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "93a3d104168f88e91920f76020743f2c", "grade": false, "grade_id": "cell-bd398009573de426", "locked": true, "schema_version": 3, "solution": false, "task": false}}

1.  Implantez la fonction `point_de_chute` de l'exercice 6 du
    <a href="TD.pdf">TD</a>.

```{code-cell}
#include <cmath>
```

```{code-cell}
double point_de_chute(double V, double A) {
    A = A*0.01745329251;
    return cos(A)*sin(A)*V*V*2/9.8;
}
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "ec4efee8725cef6ad08873359a0b4ffc", "grade": false, "grade_id": "cell-bd398009573de427", "locked": true, "schema_version": 3, "solution": false, "task": false}}

2.  Vérifiez que l'on obtient les valeurs attendues pour les tests.

```{code-cell}
point_de_chute(8,81)
```

```{code-cell}
sin(45)
```

```{code-cell}
CHECK( std::abs(point_de_chute(35, 45) - 125) <= 0.01);
CHECK( std::abs(point_de_chute(8, 81) - 2.02) <= 0.01);
CHECK( std::abs(point_de_chute(51, 13) - 116.35) <= 0.01);
CHECK( std::abs(point_de_chute(37, 35) - 131.27) <= 0.01);
CHECK( std::abs(point_de_chute(31, 83) - 23.73) <= 0.01);
```

+++ {"deletable": false, "editable": false, "nbgrader": {"cell_type": "markdown", "checksum": "dbae6ce8a9ac041a9cec177eb3dd91e8", "grade": false, "grade_id": "cell-bd398009573de428s", "locked": true, "schema_version": 3, "solution": false, "task": false}}

3.  Le résultat est-il correct pour un angle de $-5$ degrés?

```{code-cell}
CHECK(point_de_chute(100, -5) == -point_de_chute(100,5))
```
