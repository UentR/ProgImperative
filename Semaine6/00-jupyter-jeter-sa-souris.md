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

# TP : Jupyter : se débarrasser de sa souris

<!-- modifier le texte ne pas mettre d'instructions -->

<div class="alert alert-info">

Objectif pédagogique : S'exercer à utiliser le clavier et les
raccourcis afin de s'affranchir progressivement de l'utilisation de la
souris

</div>

## Exercice 1 : jetez votre souris à la poubelle

Dans cet exercice, vous devrez couper-coller des mots pour les
déplacer le plus vite possible.

<div class="alert alert-warning">

Il est interdit d'utiliser une souris ou un pad!

Et, pour pimenter le tout, c'est chronométré!

</div>

<div class="alert alert-info">

**Pour gagner du temps :** 

* <kbd>Ctrl</kbd>+<kbd>→</kbd> permet de se déplacer de mot en mot;
* <kbd>Maj</kbd>+<kbd>→</kbd> permet de se déplacer en sélectionnant
  le chemin parcouru par le curseur;
* Enfin, <kbd>Maj</kbd>+<kbd>Ctrl</kbd>+<kbd>→</kbd> permet de
  sélectionner un mot complet.

Ces raccourcis se généralisent aux autres touches de déplacement,
comme <kbd>↑</kbd>, <kbd>↓</kbd> pour agir sur des lignes entières.

</div>

Faites apparaître le chronomètre en évaluant la cellule ci-dessous :

<!--
```{code-cell} ipython3
---
deletable: false
editable: false
---
%%javascript
Jupyter.notebook.execute_cells([2,3,7,13])
```
-->

```{code-cell} ipython3
:deletable: false
:editable: false

from chronometre import Chronometre
chrono = Chronometre()
chrono
```

Puis lancez-le dès que vous êtes prêt.e :

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.start()
```

Et arrêtez-le quand vous avez fini :

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.stop()
```

+++ {"deletable": true, "editable": true}

*Dans les trois phrases suivantes, déplacez le texte en gras pour
l'insérer à la place des crochets :*

Le Python est un [...] bleu et **serpent** jaune.

**chronomètre** Pour arrêter le [...] il vous suffira de cliquer sur le carré.

Pour supprimer une cellule avec les [...] clavier je peux faire
<kbd>Échap</kbd>, <kbd>D</kbd>, <kbd>D</kbd>. **raccourcis**

+++ {"deletable": true, "editable": true}

## Exercice 2 : et ne revenez pas la chercher!

Même exercice, mais cela se complique : le texte est réparti sur
plusieurs cellules. Il va maintenant falloir changer de cellule
également grâce au clavier. Pour cela utilisez <kbd>Échap</kbd> pour
sortir du mode édition. Vous pouvez alors changer de cellule avec les
flèches. Utilisez <kbd>Entrée</kbd> pour éditer de nouveau une cellule.

```{code-cell} ipython3
:deletable: false
:editable: false

from chronometre import Chronometre
chrono = Chronometre()
chrono
```

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.start()
```

```{code-cell} ipython3

```

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.stop()
```

+++ {"deletable": false, "editable": true}

Pour insérer une cellule au-dessus de la cellule courante avec les
[...] claviers je peux faire <kbd>Échap</kbd>, <kbd>a</kbd> **raccourcis**.

+++ {"deletable": false, "editable": true}

Pour [...] une cellule au-dessous de la cellule courante avec les
raccourcis clavier je peux faire <kbd>Échap</kbd>, <kbd>b</kbd> **ajouter**.

+++ {"deletable": false, "editable": true}

**utiliser** Pour sauvegarder à tout moment, je peux [...]
<kbd>Ctrl</kbd>+<kbd>S</kbd>.

+++ {"deletable": false, "editable": false}

## Exercice 3 : jamais 203

Un dernier pour la route avec des extraits du [*Zen de
Python*](https://fr.wikipedia.org/wiki/Zen_de_Python) et deux nouveaux
raccourcis clavier :
- <kbd>↖</kbd> pour aller en début de ligne
- <kbd>Fin</kbd> pour aller à la fin de la ligne

Sur de petits claviers d'ordinateurs portables, ces touches peuvent
être remplacées respectivement par <kbd>fn</kbd>+<kbd>←</kbd> et
<kbd>fn</kbd>+<kbd>→</kbd>.

```{code-cell} ipython3
:deletable: false
:editable: false

from chronometre import Chronometre
chrono = Chronometre()
chrono
```

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.start()
```

```{code-cell} ipython3
:deletable: false
:editable: false

chrono.stop()
```

+++ {"deletable": true, "editable": true}

Beautiful **ugly** is better than [...].<br>
**implicit** Explicit is better than [...] .<br>
Simple is better than complex.<br>

+++ {"deletable": true, "editable": true}

Complex is better than complicated.<br>
**Supprimez-moi je n'ai rien à faire ici**<br> 
Flat is better than nested.<br>
[...] is better than dense. **Sparse**<br>

+++ {"deletable": true, "editable": true}

Readability counts.<br>

+++ {"deletable": true, "editable": true}

Special cases aren't special enough to break the rules.<br>
Although practicality beats purity.<br>
[...] should never pass silently **Errors**.<br>
Unless explicitly silenced.<br>

+++ {"deletable": true, "editable": true}

**guess** In the face of ambiguity, refuse the temptation to [...]. <br>
There should be one – and preferably only one – obvious way to do it.<br>
Although that way may not be obvious at first unless you're Dutch.<br>

+++ {"deletable": true, "editable": true}

[...] is better than never. **Now**<br>
Although never is often better than right now.<br>
If the [...] is hard to explain, it's a bad idea. **implementation**<br>
If the implementation is easy to explain, it may be a good idea.<br>
Namespaces are one honking great idea – let's do more of those!<br>
<!--
+++ {"deletable": false, "editable": false}

## Je veux battre mon score

Pour réinitialiser le carnet et tenter de battre votre record : 
[Cliquez ici](https://jupyterhub.ijclab.in2p3.fr/jupyter/user-redirect/git-pull?repo=https%3A%2F%2Fgitlab.dsi.universite-paris-saclay.fr%2Fjupyter%2Ftutoriel-jupyter&urlpath=tree%2Ftutoriel-jupyter%2Ftuto-jeter-sa-souris.md&branch=main)
<br>
-->

+++ {"deletable": false, "editable": false}

## Conclusion

Vous vous en rendrez bientôt compte, délaisser votre souris au profit
du clavier vous permettra de beaucoup gagner en efficacité. En bonus,
vous retrouverez une grande part des raccourcis que vous avez
rencontré ici dans d'autres logiciels comme les traitements de
textes. Vous gagnerez donc aussi du temps en dehors de Jupyter.
