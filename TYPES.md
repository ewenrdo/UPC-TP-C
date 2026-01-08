
# Types en C

_On a noté en gras avec un astérisque (\*) les types qui seront utilisés dans le cours._

## Types basiques entiers

------------------------------------------------------------------------------
| Classe             | Nom systématique   | Autres noms | Lecture dans printf |
| ------------------ | ------------------ | ----------- |---------------------|
| Entiers non signés | **_Bool**\*        | bool        | %u                  |
| Entiers non signés | unsigned char      |             | %u                  |
| Entiers non signés | unsigned short     |             | %u                  |
| Entiers non signés | **unsigned int**\* | unsigned    | %u                  |
| Entiers non signés | unsigned long      |             | %lu                 |
| Entiers non signés | unsigned long long |             | %llu                |
| Entiers non signés | **size_t**\*       |             | %zu                 |
| Entiers signés     | **char**\*         |             | %c / %d             |
| Entiers signés     | signed char        |             | %d                  |
| Entiers signés     | signed short       | short       | %d                  |
| Entiers signés     | **signed int**\*   | int         | %d                  |
| Entiers signés     | signed long        | long        | %ld                 |
| Entiers signés     | signed long long   | long long   | %lld                |
-------------------------------------------------------------------------------

Il n'y a pas de garantie sur le nombre d'octets occupé par une valeur d'un certain type. Autrement dit, la taille d'un `int` peut varier d'une machine à une autre. Cependant, les règles suivantes sont garanties par la norme C :
- La taille d'un `char` est toujours de 1 octet.
Il n'y a pas de garantie sur les valeurs possibles pour les types et sur comment elles se comparent entre elles _(même si on a toujours "l'inclusion" de types, comme en Java)_.

**Librairie :** Pour utiliser le type `bool`, il faut inclure la librairie `<stdbool.h>`. Pour utiliser le type `size_t`, il faut inclure la librairie `<stddef.h>`.

## Types basiques flottants (réels)

-----------------------------------------------
| Classe          | Nom systématique |
| --------------- | ---------------- |
| Flottant signés | float            |
| Flottant signés | **double**\*     |
| Flottant signés | long double      |
-----------------------------------------------

# Constantes

En C, on a des constantes (car sinon, il faudrait tout représenter en nombres...). Voici les principales constantes :
- Constantes booléennes : `true`, `false` (nécessite l'inclusion de `<stdbool.h>`)
- Constantes entières en base 10 : `123`, `0`, `15`, ...
- Constances entières en base 16 :
    - Préfixe `0x` suivi de chiffres hexadécimaux (0-9, A-F,a-f) : `0x1A3F`, `0x0`, ...
    - _Par exemple, en non signé, `0X1A` représente l'entier 26._
- Constantes flottantes en base 10 : `3.14`, `0.0`, `2.5e3`, `1.0E-4`, ... _(le `e` ou `E` indique la puissance de 10)_
- Constantes entières de caractères : `'a'`, `'Z'`, `'0'`, `'\n'`, `'\t'`, `'\x1A'`, ... _(utilisent des apostrophes)_
- Constantes de chaînes de caractères : `"Bonjour"`, `"C'est super !"`, `"\n\t"`, ... _(utilisent des guillemets)_

# Limites

Les valeurs entières et flottantes ont des limites qui dépendent de la machine. 
Pour obtenir celles des entiers, on peut inclure la librairie `<limits.h>` et utiliser par exemples : `INT_MAX`, `CHAR_MIN`, `UINT_MAX`, ...

Pour les flottants, on peut inclure la librairie `<float.h>` et utiliser par exemples : `FLT_MAX`, `DBL_MIN`, ...
_Remarque :_ les doubles négatifs sont compris entre `-DBL_MAX` et `-DBL_MIN`.

# Remaruqes
- Les constantes entiers décimales sont signées par défaut MAIS :
  - On peut forcer à ce quʼelles soient non signés en mettant U à la fin, par exemple `10U`
  - Quand on les affecte, lʼaffectation convertit dans le type du terme de gauche, par exemple dans `unsigned x=10` 10 est converti en `unsigned`
  - Il faut faire attention quand on diminue la taille du type -> en fait il faut éviter de faire cela
- Il faut éviter dʼutiliser la représentation hexadécimal pour exprimer des valeurs négatives
- On peut faire des choses comme `unsigned a=-2`, dans ce cas lʼopérateur unaire `-` est réalisé pour le type unsigned et cela revient à faire `UINT_MAX+1-2` -> il faut là aussi éviter cela
*- Ce qui se passe dans le cas de conversion avec diminution de taille de type dépend de lʼenvironnement dʼexécution.**