---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

+++ {"deletable": false, "editable": false}

# Jupyter : l'indentation

:::{admonition} Objectifs pédagogiques

- apprendre à indenter efficacement le code
- renforcer l'utilisation du clavier vue dans le tutoriel [se
  débarrasser de sa souris](../Semaine6/00-jupyter-jeter-sa-souris.md).

:::

:::{prf:definition}

L'***indentation*** consiste à mettre en valeur la structure
du code en commençant chaque ligne par un nombre d'espaces
proportionnel à la profondeur d'imbrication dans les blocs de
code. Cela permet d'en améliorer la lisibilité. Dans certains langages
comme Python, cette indentation dénote à elle seule la structure en
blocs et est donc requise.

:::

+++ {"deletable": false, "editable": false}

## Observation

Voici deux cellules. Placez votre curseur à la fin de la ligne de
chacune et tapez <kbd>Entrée</kbd> :

```{code-cell}
for ligne in Monfichier
```

```{code-cell}
for ligne in Monfichier:
```

Eh oui! Comme la plupart des éditeurs de code, l'éditeur de Jupyter a
automatiquement proposé une indentation adaptée au contexte au moment
du retour à la ligne. En Python, cette indentation est plus
qu'esthétique, elle est nécessaire. Voyez plutôt ci-après.

**Exemple :**

Exécutez les deux cellules suivantes :

```{code-cell}
Maliste=["I","love","Python"]
for ligne in Maliste :
    print(ligne)
```

```{code-cell}
Maliste=["I","love","Python"]
for ligne in Maliste :
print(ligne)
```

Ouf! Une erreur signale ici l'indentation incorrecte. Mais ce ne sera
pas toujours le cas :

```{code-cell}
Maliste = ["I", "love", "Python"]
for ligne in range (0, len(Maliste)):
    a = ligne  # instruction diverses
    print("Maliste contient ", a, " : ", Maliste[a])
```

ne produit pas le même résultat que :

```{code-cell}
Maliste=["I", "love", "Python"]
for ligne in range (0, len(Maliste)):
    a = ligne  # instruction diverses
print("Maliste contient ", a, " : ", Maliste[a])
```

+++ {"deletable": false, "editable": false, "tags": []}

## Exercice

Indentez correctement la table des matières ci-dessous en utilisant
seulement le clavier (pour réviser, voir le tutoriel [se débarrasser
de sa souris](../Semaine6/00-jupyter-jeter-sa-souris.md)).

:::{admonition} Raccourcis clavier

* Utilisez <kbd>Tab</kbd> pour indenter .
* Pour désindenter utilisez <kbd>Maj</kbd>+<kbd>Tab</kbd>.
* Pour indenter ou désindenter plusieurs lignes d'un coup,
  sélectionnez les avec <kbd>Maj</kbd>+<kbd>↑</kbd> ou <kbd>↓</kbd>
  puis utilisez <kbd>Tab</kbd> ou <kbd>Maj</kbd>+<kbd>Tab</kbd>.

:::

Voici le résultat attendu : 
* TITRE
    * Titre 1
        * Titre 1.1
    * Titre 2
        * Titre 2.1
            * Titre 2.1.1
            * Titre 2.1.2
        * Titre 2.2
        * Titre 2.3
        * Titre 2.4
            * Titre 2.4.1
    * Titre 3
        * Titre 3.1
        * Titre 3.2

+++ {"deletable": false, "editable": true}

* TITRE
* Titre 1
* Titre 1.1
* Titre 2
* Titre 2.1
* Titre 2.1.1
* Titre 2.1.2
* Titre 2.2
* Titre 2.3
* Titre 2.4
* Titre 2.4.1
* Titre 3
* Titre 3.1
* Titre 3.2

+++ {"deletable": false, "editable": false}

## Conclusion

Une bonne indentation est essentielle à la lisibilité du code, voire
même à sa correction. Aussi les éditeurs de texte offrent-t-ils des
outils pour la vérifier et l'ajuster efficacement. Il convient de les
maîtriser. Au delà de la programmation, cela s'applique à l'édition de
tout **texte structuré** : Markdown, HTML, etc.

+++ {"deletable": false, "editable": true}

## Acquis

Pour valider les acquis ci-dessous, entrez en mode édition, puis
placez un "x" à la place de l'espace entre les crochets.

- [ ] Une indentation est nécessaire pour faire fonctionner les boucles en Python
- [ ] Indenter différemment un script va produire des résultats différents
- [ ] Je dois toujours relire mon script et vérifier mes sorties
- [ ] Je maîtrise la sélection et indentation multiple
- [ ] J'ai réussi à utiliser uniquement le clavier

