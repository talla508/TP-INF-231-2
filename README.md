TP : Listes chaînées en C

Ceci est mon tout premier TP sur les listes chaînées en langage C 🎉
Le projet contient plusieurs programmes indépendants, chacun montre une opération sur une variante de liste chaînée.

1️⃣ Liste simplement chaînée : suppression de toutes les occurrences

  Fichier : simple_suppression_occurrence.c

  Ce programme :

Lit une valeur donnée par l’utilisateur.

Parcourt toute la liste.

Supprime tous les nœuds qui contiennent cette valeur.

Exemple :
Liste avant : 1 -> 5 -> 3 -> 5 -> 7 -> NULL
Valeur à supprimer : 5
Liste après  : 1 -> 3 -> 7 -> NULL

2️⃣ Liste simplement chaînée : insertion dans une liste triée

  Fichier : simple_insertion_triee.c

  Ce programme :

Insère un nouvel élément dans une liste déjà triée par ordre croissant.

Place automatiquement l’élément à la bonne position.

Exemple :
Liste avant : 2 -> 5 -> 8 -> NULL
Élément inséré : 7
Liste après  : 2 -> 5 -> 7 -> 8 -> NULL

3️⃣ Liste doublement chaînée : insertion dans une liste triée

 Fichier : double_insertion_triee.c

  Ce programme :

Fonctionne comme le précédent, mais avec une liste doublement chaînée.

Chaque nœud a un pointeur precedent et un pointeur suivant.

L’insertion met à jour les deux liens.

Exemple :
Liste avant : 2 <-> 5 <-> 8 <-> NULL
Élément inséré : 1
Liste après  : 1 <-> 2 <-> 5 <-> 8 <-> NULL

4️⃣ Liste simplement chaînée circulaire : insertion en tête et en queue

  Fichier : simple_circulaire.c

  Ce programme :

Utilise une liste circulaire (le dernier nœud pointe sur le premier).

Permet deux opérations :

Insertion en tête.

Insertion en queue.

Exemple (après quelques insertions) :
Liste circulaire : 10 -> 20 -> 30 -> ... -> (retour à 10)
5️⃣ Liste doublement chaînée circulaire : insertion en tête et en queue

  Fichier : double_circulaire.c

  Ce programme :

Utilise une liste doublement circulaire (le dernier nœud pointe vers le premier ET inversement).

Permet deux opérations :

Insertion en tête.

Insertion en queue.

Exemple :
Liste circulaire double : 10 <-> 20 <-> 30 <-> ... <-> (retour à 10)


Compilation et exécution

Chaque fichier .c peut être compilé séparément avec gcc.
Exemple pour la liste simplement triée :

gcc simple_insertion_triee.c -o simple_triee
./simple_triee
