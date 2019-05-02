# Laboratoire 3 : Liste générique

David Jaquet & Christoph Rouff soit Rueff

## Diagramme de classes

## Choix d'implémentation

### Itérateurs

Pour ce qui est de l'implémentation des itérateurs, nous avons une classe générique ```GenericIterator``` qui prend en charge l'implémentation des opérateurs ```==``` et ```!=``` ainsi que des méthodes ```inc()``` et ```dec()``` qui permettent de déplacer le pointeur sur le ```Node``` visité.

Les classes ```Iterator``` et ```ConstIterator``` héritent de ```GenericIterator``` et implémentent les surcharges d'opérateurs ```*, ->, ++it, it++, --it et it--``` de manière à ce que ```Iterator``` permette de modifier la liste parourue sans que ce soit le cas pour ```ConstIterator```.

Bien que les opérateurs ```++, --``` soient les mêmes dans les deux enfants de l'itérateur générique, celui-ci ne les implémente pas car il ne définit pas l'opérateur ```*``` qui permet, selon si on est dans ```Iterator``` ou ```ConstIterator```, de déréférencer l'itérateur de manière à permettre une modification où non.

## Avantages - Inconvénients