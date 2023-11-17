---
exports:
- format: pdf
  output: TD.pdf
  template: ../../template/TD
- format: tex
  output: TDmd.tex
  template: ../../template/TD
jupytext:
  notebook_metadata_filter: exports, myst, math
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.15.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
math:
  \SI: '#1\ #2'
  \kilogram: \text{kg}
  \meter: \text{m}
  \mref: \mathbf{m}_\text{ref}
  \per: /
  \second: \text{s}
  \squared: ^2
---

# TD 4 : Des fonctions, des tests et de la documentation

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7deabe4711ae540e85a5822a3f3a077c", "grade": true, "grade_id": "10", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 1 : Premières fonctions

Voici une fonction qui calcule la surface d'un rectangle :

:::{literalinclude} surface-rectangle-correction.cpp
:start-after: BEGIN surfaceRectangle
:end-before: END surfaceRectangle
:::

1.  Implantez une **fonction** `surfaceDisque` qui calcule la surface
    d'un disque de rayon donné. On prendra $\pi=3,1415926$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Implantez une **fonction** `surfaceTriangle` qui calcule la
    surface d'un triangle de base et de hauteur données.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "97199d0d9867c06ed0163aae82552050", "grade": true, "grade_id": "20", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 2 : En route vers l'exponentielle
<i></i>
1.  Nous avons vu en cours et en TP une fonction `factorielle(n)` qui
    calcule la factorielle d'un entier positif $n$. Pour un exercice
    du TP à venir, et pour éviter les problèmes de dépassement de
    capacité, il est souhaitable que les calculs intermédiaires et le
    résultat soient des `double`. Adaptez en conséquence la fonction
    `factorielle`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  On considère la fonction dont la documentation et l'entête sont
    donnés ci-dessous :

    :::{literalinclude} puissance-correction.cpp
    :start-after: BEGIN puissanceEntete
    :end-before: END puissanceEntete
    :::

    Quels sont les types de ses paramètres formels et de sa valeur de
    retour?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Écrivez quelques exemples d'utilisation de la fonction
    `puissance`. Éditez-les sous forme de tests, en vous inspirant du
    test suivant pour la fonction `surfaceRectangle`:

    :::{literalinclude} surface-rectangle-correction.cpp
    :start-after: BEGIN surfaceRectangleTest
    :end-before: END surfaceRectangleTest
    :::

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  Implantez la fonction `puissance`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

5.  Cherchez dans les notes de cours la sémantique **simplifiée** de
    l'appel d'une fonction.

6.  Exécutez pas à pas le programme suivant :

    :::{literalinclude} appel-fonction-simplifiee-correction.cpp
    :start-after: BEGIN code_a_comprendre
    :end-before: END code_a_comprendre
    :::

    Quelle est la valeur de la variable `resultat` à la fin?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

7.  $\clubsuit$ Implantez les fonctions `factorielle` et `puissance`
    en récursif cette fois, puis refaites l'exécution pas à
    pas. Qu'est-ce qui change?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7fd0a539d0dad5297d5fd6c0daa370b6", "grade": true, "grade_id": "30", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 3 : Variables locales/globales, pile et exécution pas à pas

On considère les deux programmes suivants :

:::{literalinclude} variable_globale-correction.cpp
:start-after: BEGIN variableGlobale
:end-before: END variableGlobale
:::

:::{literalinclude} variable_locale-correction.cpp
:start-after: BEGIN variableLocale
:end-before: END variableLocale
:::

1.  Mettez en évidence les différences entre les deux programmes (par
    exemple au surligneur).

2.  Cherchez dans les notes de cours la sémantique **détaillée** de
    l'appel d'une fonction (formalisation suivant le modèle
    d'exécution).

3.  Exécutez pas à pas les deux programmes en décrivant au fur et à
    mesure l'état de la mémoire (pile). Quelle est la valeur des
    variables `i` et `resultat` à la fin de l'exécution?

4.  Décrivez la différence de comportement entre ces programmes, et
    retrouvez dans les notes de cours le commentaire à ce propos.

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "77c71d2386188d17aaae848cbfe0b66e", "grade": true, "grade_id": "40", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 4 : La trilogie code, documentation, tests

Analysez la fonction `volumePiscine` suivante :
:::{literalinclude} piscine-correction.cpp
:start-after: BEGIN volumePiscine
:end-before: END volumePiscine
:::
Munie des tests :
:::{literalinclude} piscine-correction.cpp
:start-after: BEGIN volumePiscineTests
:end-before: END volumePiscineTests
:::

1.  Est-ce que les tests passent?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  La documentation, le code et les tests sont-ils cohérents?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Corrigez les anomalies éventuelles.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "42314bca9063204b0b1052eaf7416642", "grade": true, "grade_id": "50", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 5 : $\clubsuit$

Analysez la fonction `mystere` suivante :

:::{literalinclude} mystere-correction.cpp
:start-after: BEGIN mystereTout
:end-before: END mystereTout
:::

Munie des tests :

:::{literalinclude} mystere-correction.cpp
:start-after: BEGIN mystereTests
:end-before: END mystereTests
:::

1.  Comment fait-on appel à cette fonction (quelle est sa **syntaxe**)?

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Que fait cette fonction (quelle est sa **sémantique**)?  
    **Indications :** pour les chaînes de caractères, l'opérateur `+`
    représente la concaténation (par exemple `"Cou" + "cou"` a pour
    valeur `"Coucou"`); comme pour les entiers, `x += expression` est
    un raccourci pour `x = x + expression`; enfin, dans une chaîne de
    caractères, «`\n`» représente un saut de ligne.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Ré-écrivez la fonction en choisissant des noms pertinents pour la
    fonction et ses variables et en la faisant précéder de sa
    documentation.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "7a2d9a97dd7dc58978c7a30a3b85d029", "grade": true, "grade_id": "60", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 6 : $\clubsuit$

Le but de cet exercice est de coder une fonction `point_de_chute` qui
calcule l'abscisse $x_c$ à laquelle tombe un projectile lancé en $x =
0$ avec une vitesse $v$ suivant un angle $\alpha$ (exprimé en degrés
par rapport à l'horizontale). Implantez la fonction
`point_de_chute`. On commencera par écrire sa documentation ainsi que
des tests (voir TD 1).  

**Rappels :**

-   l'abscisse est donnée par la formule : $x_c=(2v_xv_y)/g$ où $v_x =
    v\cos(\alpha)$, $v_y = v\sin(\alpha)$ et $g$ est l'accélération
    gravitationnelle (environ $\SI{9,8}{\meter\per\second\squared}$ sur la planète
    Terre).

-   en C`++`, les fonctions mathématiques sinus et cosinus sont
    implantées par les fonctions prédéfinies `sin(arg)` et `cos(arg)`
    dans `<cmath>`, où l'angle `arg` est exprimé en radians.

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

<s></s>

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "bcc71c5cd0a5d9ecce77050a07c562a0", "grade": true, "grade_id": "70", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 7 : $\clubsuit$

Le but de cet exercice est de calculer la hauteur en fonction du temps
$z(t)$ à laquelle se trouve un pot de fleur ($m=\SI{3}{\kilogram}$)
lâché à $t=0$ depuis le 10{sup}`ème` étage ($h_0=\SI{27}{\meter}$), en
chute libre avec résistance de l'air; puis de calculer le temps de
chute.

1.  Implantez une fonction `chute_libre(t)` calculant $z(t)$ pour un
    $V_0$ donné ($V_0=\SI{80}{\meter\per\second}$).  
    **Indications :**
    -   La hauteur s'exprime en fonction du temps par
	    :::{math}
		z(t)=h_0-(V_0t+\frac{V_0^2}{g} \ln\left(\frac{1}{2}\left(1+e^{-2tg/V_0}\right)\right)\,,
	    :::
        où $V_0$ est la vitesse limite
        de chute de l'objet et $g=\SI{9.81}{\meter\per\second\squared}$.
    -   La fonction logarithme népérien est prédéfinie sous la forme
        `log(arg)` dans `<cmath>`.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

2.  Que se passe-t-il si on varie $h_0$ et $V_0$? Généralisez votre
    fonction pour prendre en paramètres additionnels la hauteur
    initiale $h_0$ et la vitesse limite de chute $V_0$. Pour la
    gravité, définir une variable globale $g$.  
	**Bonus :** définir cette variable globale comme une constante
    (nous irons sur Mars une autre fois).

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

    Écrivez les appels à la fonction précédente pour calculer $z(t)$
	pour $t=\SI{2}{s}$ et pour différentes valeurs de $V_0$: $10$, $40$,
	$60$, $120$, $\SI{180}{\meter\per\second}$.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

3.  Écrivez une fonction `temps_de_chute` qui prend les même
    paramètres que précédemment et utilise `chute_libre` de façon
    répétée pour déterminer une approximation de la durée $t_c$ de la
    chute du pot de fleur jusqu'au sol.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

4.  La vitesse limite peut être obtenue en fonction de la masse
    volumique de l'air $\rho$, du coefficient de résistance
    aérodynamique $C_x$ et de la section de l'objet $S$ à l'aide de la
    formule $V_0=\sqrt{\frac{2mg}{C_x \rho S}}$. Implantez une
    fonction `vitesse_limite` pour calculer cette formule.  Puis
    implantez de nouvelles fonctions utilisant les précédentes pour
    calculer $z(t)$ et le temps de chute $t_c$ en fonction des
    paramètres $C_x$, $S$, et $m$. On suppose que $\rho$ est une
    variable globale déjà définie.

    % REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::

+++ {"deletable": false, "nbgrader": {"cell_type": "markdown", "checksum": "c3a55afe1b95ec9cc57111a5949fcb76", "grade": true, "grade_id": "80", "locked": false, "points": 0, "schema_version": 3, "solution": true}}

::::{admonition} Exercice 8 : $\clubsuit$ Triangles rectangles à côtés entiers

**Inspiré du problème 39 du Projet Euler, Integer right triangles**

Pour un périmètre $p=120$ donné, il n'existe que trois configurations
pour un triangle rectangle dont les côté sont de longueurs entières :
$\{20, 48, 52\}, \{24, 45, 51\}, \{30, 40, 50\}$.

Documentez et écrivez une fonction `nombreTrianglesRectanglesEntiers`
qui prend en entrée un entier, le périmètre fixé, et renvoie le nombre
de configurations possibles de triangles rectangles à côtés de
longueurs entières.

**Indications :** On pensera à écrire des fonctions intermédiaires
utiles, par exemple une fonction qui vérifie que la longueur de
l'hypothénuse d'un triangle rectangle est entière et renvoie sa valeur
à partir des longueurs de ses deux autres côtés, ou une fonction qui
vérifie si la somme des longueurs des trois côtés vaut bien le
périmètre fixé. Ne pas oublier de prévoir des tests automatiques pour
chaque fonction qui le permet.

% REMPLACER CETTE LIGNE PAR VOTRE RÉPONSE

::::
