---
jupytext:
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

# TP : l'interface de JupyterLab

:::{admonition} Objectif pédagogique

Se familiariser avec l'interface de JupyterLab : gestion de fichiers,
manipulation d'onglets, ...

:::

JupyterLab fournit un environnement modulaire et flexible pour le calcul
interactif et exploratoire. On y retrouve des fonctionnalités typiques
d'environnements de développement intégrés (IDE), voire de navigation
de document.

+++

L'interface de JupyterLab consiste en une zone de travail principale
contenant des onglets de documents et d'activités, une barre de menu,
et deux barres latérales repliables, l'une à gauche et l'autre à
droite.

+++

La barre latérale gauche contient notamment :

- ![icône navigateur de fichiers](media/file-manager-icon.png) un
  navigateur de fichiers
- ![icône gestionnaire d'activités](media/resource-manager-icon.png) un
  gestionnaire de ressources (activités, noyaux, ...)
- ![icône table des matières](media/table-of-contents-icon.png) la table
  des matières du document courant

+++

Vous y trouverez aussi le gestionnaire d'extensions. Selon les
extensions qui sont installées, d'autres onglets peuvent apparaître.

+++

## Exercice 1 : le navigateur de fichiers

- Cliquez plusieurs fois sur l'icône du navigateur de fichier
  ![icône navigateur de fichiers](media/file-manager-icon.png)
  pour tour à tour afficher ce dernier ou replier la barre latérale de
  gauche.
- Affichez le navigateur de fichier, et retrouvez-y les documents de
  ce cours :
  - le tableau de bord;
  - les devoirs pour chaque semaine;
  - la page d'accueil de la semaine 5;
  - ce document que vous lisez maintenant.
    
  **Indication :** chercher `ProgImperative`, `Semaine5`, `index.md`,
  `00-jupyter-interface.md`

- Faites un clic droit sur le nom d'un fichier (appui long sur
  tablette ou téléphone). Vous obtenez un menu avec les opérations
  usuelles d'un navigateur de fichiers : renommer, copier, coller, ...
  et quelques autres.

- Ouvrez le répertoire `Semaine5` dans le navigateur de fichier.

- Cliquez sur l'icône ![icône lanceur](media/launcher-icon.png) dans
  le navigateur de fichier pour ouvrir un nouveau *lanceur*
  d'activité.
- Utilisez le lanceur pour ouvrir un nouveau fichier texte; celui-ci
  s'appelle par défaut `untitled.txt`. Renommez le en `essai.txt`.
  Tapez un peu de texte à l'intérieur du fichier puis enregistrez le
  avec le raccourci clavier <kbd>Ctrl</kbd>-<kbd>s</kbd>.
- Utilisez à nouveau un lanceur pour ouvrir une nouvelle feuille
  (notebook) Python. Renommez la en `essai.ipynb`.

+++

## Exercice 2 : le terminal

Le ***terminal*** est une alternative au navigateur de
fichiers; pour interagir avec le système d'exploitation (lancer un
programme, naviguer dans les fichiers, ...) on y tape des commandes
dans une interface textuelle plutôt que de cliquer dans une interface
graphique. Avec un peu d'apprentissage, ce mode d'interaction est très
efficace et se prête à l'automatisation. 

Nous nous contentons dans cet exercice de montrer comment ouvrir un
terminal et y taper des commandes.

- Utilisez à nouveau un lanceur du navigateur de fichiers pour ouvrir
  un terminal. 
  
  **Note :** selon votre environnement, le terminal peut ne pas être
  disponible. Dans ce cas, passez directement à l'exercice suivant.
- Dans le terminal, tapez la commande `ls`, suivie de
  <kbd>Entrée</kbd>. Vous devriez retrouver la même liste de fichiers
  que dans le navigateur, dont `essai.txt` et `essai.ipynb`.

  **Indication :** en salle TP du 336, il se peut que le terminal soit
  ouvert à la racine de votre répertoire personnel. Dans ce cas, tapez
  la commande suivante pour aller dans le répertoire `Semaine5` :

        cd ~/ProgImperative/Semaine5

+++

## Exercice 3 : la table des matières

- Ouvrez la table des matières de ce document en cliquant sur ![icône
  table des matières](media/table-of-contents-icon.png) dans la barre
  latérale de gauche. Cliquez sur les titres de sections pour naviguer
  rapidement dans le document.

+++

## Exercice 4 : organiser l'espace de travail

+++

Par défaut, la zone de travail consiste en un unique
***panneau*** contenant toutes les activités (lanceur,
document, feuille, éditeur de texte, terminal, ...) rangées chacune
dans un onglet. Il est possible de restucturer l'espace de travail en
disposant ces activités sur plusieurs panneaux, afin notamment de
pouvoir voir plusieurs activités simultanément. Pour cela, il suffit
de déplacer les activités par glisser-déposer du titre de leurs
onglets. Les panneaux eux-même peuvent être redimensionnés par
glisser-déposer des bordures les séparant.

- Réorganisez vos activités pour voir simultanément le fichier
  `essai.txt` et le terminal, l'un dans un paneau à gauche, l'autre
  dans un panneau à droite.
- Déplacez la feuille `essai.ipynb` dans un nouveau panneau en dessous
  des deux précédents.
- Redimensionez les panneaux à votre guise.
- Repliez la barre de gauche; mettez votre navigateur web en plein
  écran; zoomez et dézoomez avec <kbd>Ctrl</kbd>-<kbd>+</kbd> et
  <kbd>Ctrl</kbd>-<kbd>-</kbd>, pour obtenir le compromis entre
  lisibilité et visibilité qui vous est le plus confortable.
- Remettez toutes les activités dans un seul panneau.

+++

## Exercice 5 : le gestionnaire d'activités

- Ouvrez le gestionnaire d'activités en cliquant sur l'icône ![icône
  gestionnaire d'activités](media/resource-manager-icon.png) de la
  barre latérale de gauche. Vous y trouverez la liste des onglets
  ouverts, des noyaux en cours d'exécution des terminaux ouverts.
  Utilisez le gestionnaire d'activités pour faire du ménage, en
  fermant tout ce que vous n'utilisez pas.

+++

## Conclusion

Dans cette feuille, vous avez exploré les fonctionalités de base de
l'interface de JupyterLab, notamment pour organiser votre espace de
travail et faire du ménage dans les activités en cours.

:::{tip} Bonnes pratiques

Ajustez régulièrement votre espace de travail en fonction de votre
travail en cours : taille de fenêtre, niveau de zoom, disposition des
panneaux, sélection des activités ouvertes, ... Vous gagnerez ainsi en
confort visuel et en efficacité. Le ménage réduira en outre la
consommation de ressources (mémoire utilisée, ...), contribuant à la
robustesse et la fluidité d'exécution, tout particulièrement sur un
service partagé aux ressources limitées (par ex. JupyterHub).

:::

## Pour aller plus loin

- Consultez la [documentation de l'interface JupyterLab](https://jupyterlab.readthedocs.io/en/stable/user/interface.html).
