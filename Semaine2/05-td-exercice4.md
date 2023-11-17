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

# TP : retour sur l'exercice 4 du TD

```{code-cell}
int prix;
int somme;

// En centimes
prix = 110;
somme = 200;

int diff = (somme - prix);

int npieces50, npieces20, npieces10, npieces5;
npieces50 = 0;
npieces20 = 0;
npieces10 = 0;
npieces5 = 0;

while (diff >= 50) {
    diff -= 50;
    npieces50++;
}

while (diff >= 20) {
    diff -= 20;
    npieces20++;
}

while (diff >= 10) {
    diff -= 10;
    npieces10++;
}

while (diff >= 05) {
    diff -= 05;
    npieces5++;
}
```

```{code-cell}
npieces50
```

```{code-cell}
npieces20
```

```{code-cell}
npieces10
```

```{code-cell}
npieces5
```
