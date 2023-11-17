
jupytext:
  notebook_metadata_filter: exports, myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---
% Fin entête jupytext
# Résumé de la syntaxe de base Python

```
if x == 1 :                  # Instruction conditionnelle (if)
      ...
```
```
if x == 1 :                  # Instruction conditionnelle (if/else)
      ...
  elif x < 2 and not y >= 3:
      ...
  else:
      ...
```
```
for i in range(10):           # Instruction itérative: boucle for
```
```
while i <= 10:                # Instruction itérative: boucle while
      ...
```
```
def factorielle(n):           # Exemple de déclaration de fonction
      """La fonction factorielle (documentation au format PEP 484)

          Args:
              n (int): un  entier positif

          Returns:
              int: n!
      """
      resultat = 1
      for k in range(n):
          resultat = resultat * k
      return resultat
```
```
def factorielleTest():        # Les tests de la fonction factorielle
      assert factorielle(0) ==  1
      assert factorielle(1) ==  1
      assert factorielle(2) ==  2
      assert factorielle(4) == 24
```
```
import numpy          # Import d'une librairie. Utilisation: numpy.pi
import numpy as np    # Import d'une librairie avec alias. Utilisation: np.pi
from numpy import pi  # Import d'une seule fonction. Utilisation: pi
```
```
n = input()           # Lit la variable n au clavier
print(3*x + 1)        # Affiche la valeur d'une expression et saute une ligne
```

