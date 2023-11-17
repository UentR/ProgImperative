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

+++ {"slideshow": {"slide_type": "slide"}}

# TP : premiers programmes compilés en C++

## Exercice : «bonjour!»

+++

1.  Ouvrez un nouveau fichier texte `bonjour.cpp` dans votre
    répertoire `ProgImperative/Semaine5`.

	**Indication :** utilisez l'éditeur de texte intégré à JupyterLab,
    comme dans l'exercice 1 de la feuille [L'interface de
    JupyterLab](00-jupyter-interface.md). Alternativement, en salle de
    TP, vous pouvez utiliser tout éditeur de texte de votre choix :
    `geany`, `jedit`, ...

2.  Recopiez le programme suivant dans ce fichier.  
    **Attention**, le programme que vous écrivez doit respecter la
    même mise en page (retour à la ligne, espaces, majuscules).

    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        cout << "Bonjour !" << endl;
        return 0;
    }
    ```

    Ne pas oublier d'enregistrer le fichier
    (<kbd>Ctrl</kbd>-<kbd>s</kbd>).

3.  Ouvrez un terminal.

    **Indication :** utilisez le terminal intégré à JupyterLab comme
    dans l'exercice 1 de la feuille [L'interface de
    JupyterLab](00-jupyter-interface.md). Alternativement, en salle de
    TP, vous pouvez utiliser le terminal du système; dans ce cas, il
    faudra commencer par utiliser la commande `cd` pour vous déplacer
    dans le répertoire `ProgImperative/Semaine5`.

4.  Réorganisez votre espace de travail pour pouvoir voir
    simultanément l'éditeur de texte et le terminal.

    **Indication :** voir l'exercice 3 de la feuille [L'interface de
    JupyterLab](00-jupyter-interface.md).

5.  Vérifiez avec `ls` que votre répertoire contient bien le fichier
    `bonjour.cpp`. Vérifiez le contenu du fichier avec `cat
    bonjour.cpp`.

6.  **Compilez le programme `bonjour.cpp`** en tapant la commande
    suivante dans le terminal :

		g++ bonjour.cpp -o bonjour

    Si tout se passe bien, vous n'avez aucun message d'erreur.

    **Attention :** cette commande ne peut fonctionner que si vous
    êtes dans le bon répertoire!

    Si une erreur s'affiche, la lire et essayer d'identifier le
    problème en trouvant le numéro de ligne : avez-vous bien respecté
    le nom du fichier, les minuscules et majuscules, les retours à la
    ligne et espaces, les points-virgules à la fin des deux lignes
    d'instructions? Après chaque correction, **enregistrer** le
    fichier et relancer la **compilation** en retapant la commande.
    
    **Rappel :**
    on peut parcourir l'historique des commandes tapées dans le terminal
    avec les touches <kbd>↑</kbd> et <kbd>↓</kbd> du clavier.

7.  Lancez la commande `ls`; quels fichiers se trouvent maintenant
    dans votre répertoire?

8.  Votre répertoire doit contenir un fichier `bonjour` (sans
    extension). Exécutez-le en tapant

		./bonjour

    Le texte `Bonjour !` doit s'afficher. Bravo, vous avez exécuté
    votre premier programme `C++`!

9.  Modifiez le fichier `bonjour.cpp` en remplaçant «Bonjour !» par le
    message de votre choix. L'enregistrer puis lancer la commande

		./bonjour

    Que remarquez-vous?

10. Comment faire pour que l'exécution du programme reflète le
    changement effectué dans `bonjour.cpp`? Faites-le.

    Lorsque l'on modifie un programme, pour que les changements soit
    pris en compte, il faut re-compiler le programme avant de
    l'exécuter.

## Exercice : du max au min

1.  Ouvrez avec votre éditeur de texte le fichier [minmax.cpp](minmax.cpp).

2.  Compilez et exécutez ce programme comme précédemment :

        g++ minmax.cpp -o minmax

		./minmax

3.  Modifiez le programme pour qu'il affiche le *minimum* des deux
    nombres. Compilez et exécutez à nouveau pour vérifier vos
    modifications.
