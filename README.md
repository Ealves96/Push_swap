<h1 align="center">
🎯 Push_swap 
<h1/>

<p align="center">
 <img src="https://res.cloudinary.com/dzo1cimyr/image/upload/v1746288764/pushswap_yuaoqq.gif" width="750"/>
</p>

## 📝 Description
Push_swap est un projet algorithmique qui consiste à trier des données sur une pile en utilisant un ensemble limité d'instructions. Le but est de trier les nombres en utilisant le moins d'opérations possibles.

## 🎮 Comment jouer
1. Clonez le repository :
```bash
git clone https://github.com/votre-username/Push_swap.git
cd Push_swap
```

2. Compilez le projet :
```bash
make
```

3. Exécutez le programme :
```bash
./push_swap [nombres]
```

## 📋 Règles du jeu
- Vous disposez de deux piles : `a` et `b`
- Au début, tous les nombres sont dans la pile `a`
- La pile `b` est vide
- Le but est de trier tous les nombres dans la pile `a` en ordre croissant

## 🎯 Opérations autorisées
- `sa` : échange les 2 premiers éléments de la pile `a`
- `sb` : échange les 2 premiers éléments de la pile `b`
- `ss` : `sa` et `sb` en même temps
- `pa` : prend le premier élément de `b` et le met sur `a`
- `pb` : prend le premier élément de `a` et le met sur `b`
- `ra` : fait une rotation de la pile `a` vers le haut
- `rb` : fait une rotation de la pile `b` vers le haut
- `rr` : `ra` et `rb` en même temps
- `rra` : fait une rotation de la pile `a` vers le bas
- `rrb` : fait une rotation de la pile `b` vers le bas
- `rrr` : `rra` et `rrb` en même temps

## 🏗️ Structure du projet
```
Push_swap/
├── main.c
├── algo.c
├── algo2.c
├── parsing_mouv1.c
├── parsing_mouv2.c
├── parsing_utils.c
├── parsing_utils2.c
├── push_swap.h
├── Makefile
└── includes/
```

## 🛠️ Technologies et langages utilisés
<div align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Make-000000?style=for-the-badge&logo=make&logoColor=white" alt="Make"/>
  <img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white" alt="Git"/>
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/>
</div> 