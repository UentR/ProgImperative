---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
rise:
  auto_select: first
  autolaunch: true
  centered: false
  controls: false
  enable_chalkboard: true
  height: 100%
  margin: 0
  maxScale: 1
  minScale: 1
  scroll: true
  slideNumber: true
  start_slideshow_at: selected
  transition: none
  width: 90%
---

+++ {"slideshow": {"slide_type": "slide"}}

# Tableaux à deux dimensions, exceptions

+++ {"slideshow": {"slide_type": "fragment"}}

## Prélude

+++ {"slideshow": {"slide_type": "slide"}}

### Annonces

+++ {"slideshow": {"slide_type": "fragment"}}

#### Examen mi semestre

- [Sujet et correction disponibles en ligne](https://nicolas.thiery.name/Enseignement/Info111/index.html#documents)

+++ {"slideshow": {"slide_type": "fragment"}}

#### Projet

- [Informations et sujets disponibles en ligne](https://nicolas.thiery.name/Enseignement/Info111/projet.html)

+++ {"slideshow": {"slide_type": "fragment"}}

#### Bureau d'Intervention Pédagogique

- de l'aide individuelle en libre service
- tous les jours, 12h30-14h30, salle 160 du 333
- Nouveau : **aussi en informatique** le lundi 16h30-18h, même lieu  
  (retard possible du tuteur en fonction des bus)

% +++ {"slideshow": {"slide_type": "fragment"}}
%
% - Contrôle PLaTon :
%   - sur eCampus, à l'heure qui vous convient entre jeudi 9h et vendredi minuit
%   - durée: 1h
%   - programme : tous les exercices PLaTon, hors tableaux à deux dimensions
%
% +++ {"slideshow": {"slide_type": "fragment"}}
%
% - Examen mi-semestre
%   - Vendredi 28, 13h45-15h45, salle 337-3
%   - programme : tout ce que l'on a vu en Semaine 1-6
%
% +++
%
% - Prologin
%
% +++ {"slideshow": {"slide_type": "fragment"}}
%
% - Recherche volontaires pour des tests utilisateur de JupyterLab
%   - Gabriela a besoin de vous!
%   - Contribuez au logiciel libre
%   - Découvrez une des facettes du dévelopement logiciel
%   - Pas de prérequis
%   - Voir l'[annonce](https://ecampus.paris-saclay.fr/mod/forum/discuss.php?d=86631)

+++ {"slideshow": {"slide_type": "fragment"}}

#### Bêta test du [Brevet IA](https://cirrus.universite-paris-saclay.fr/s/ZmfZtkkyPgby5NF)

- Recherche volontaires!
- Voir l'[annonce](https://ecampus.paris-saclay.fr/mod/forum/discuss.php?d=122144)

+++ {"slideshow": {"slide_type": "slide"}}

### Résumé des épisodes précédents

#### Motivation

**Manipulation de collections de données**

**Fil conducteur :** Implantation d'un annuaire

+++ {"slideshow": {"slide_type": "fragment"}}

-   Tableaux : valeurs composites homogènes: `vector<...>`
    -   Construction :
        1.  Déclaration
        2.  Allocation
        3.  Initialisation
-   Sémantique des tableaux, modèle mémoire avec pile et tas
-   Généralisation des tableaux : les collections
-   La boucle «pour tout» : `for ( auto valeur: collection ) { ... }`

+++ {"slideshow": {"slide_type": "fragment"}}

**<div style="color: red; text-align: center; font-weight:bold;">Aller plus loin?</div>**

+++ {"slideshow": {"slide_type": "slide"}}

### Au programme

1. [Tableaux à deux dimensions](cours-tableaux2D.md)
2. [Exceptions](cours-exceptions.md)

+++ {"slideshow": {"slide_type": "slide"}}

## Résumé du cours

+++ {"slideshow": {"slide_type": "fragment"}, "tags": []}

### Projet

- Sujets sur la page web (ou presque)
- Première séance de TP dédiée en Semaine 9
- Commencez dès maintenant: lire les consignes et les sujets; choisir; premières étapes

+++ {"slideshow": {"slide_type": "fragment"}}

### Tableaux 2D

- Modélisation par des tableaux de tableaux : rien de nouveau!
- Construction en quatre étapes :
     - Déclaration
     - Allocation
     - Allocation des sous-tableaux
     - Initialisation
- Retour sur le modèle mémoire pile et tas

+++ {"slideshow": {"slide_type": "fragment"}}

### Exceptions

-   Signaler les situations exceptionnelles : `throw ...`
-   Gérer les situations exceptionnelles: `try ... catch ...`

