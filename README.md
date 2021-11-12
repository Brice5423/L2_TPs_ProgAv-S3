# TP Prog Avance S3
_________________________

## Mes taches à faire au TP5

### Taches à faire

### Taches terminer

_________________________

## Mes taches à faire au TP4

**Le faire à la maison

_________________________

## Make

### Lancement

- Terminal : **Ubuntu**
- Commande : **make**

### Modification 

- **_PROG** : Permet de donner le nom qu'on veut pour l'exécutable
- **_DEP** : Il faut donnée le nom de tous les fichiers **`.h`** qui faut compiler
- **_OBJ** : Il faut donnée le nom de tous les fichiers **`.c`** qui faut compiler *(mettre un **`.o`** à la place
  d'un **`.c`**)*

_Exemple, avec le TP2 :_

![img.png](img.png)

## Dossier à créer

- **bin** : dossier pour l'executable
- **include** : dossier pour tout les `.h`
- **obj** : dossier pour les `.o`
- **src** : dossier pour les `.c`

## Pour exécuter manuellement

- Méthode 1 :
    - gcc nom_fichier.c -0 nom_executable
    - ./nom_executable
- Méthode 2 :
    - gcc -Wall -std=c11 -o nom_executable nom_fichier.c
    - ./nom_executable

## Autre commende

- cd
- ls
