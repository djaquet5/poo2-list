# Laboratoire 3 : Liste générique

David Jaquet & Christoph Rouff soit Rueff

## Diagramme de classes

## Choix d'implémentation

### Noeuds sentinelles

Dans l'exemple d'exécution du code fourni dans la donnée du laboratoire, nous devons pouvoir parcourir la liste dans les deux sens avec les itérateurs fournis par les méthodes `List<T>::begin()` et `List<T>::end()`. Voici l'exemple de code fourni :

```c++
List<string> l;

l.append("un");
l.append("deux");
l.append("trois");

for(List<string>::Iterator it = l.begin(); it != l.end(); ++it){
    cout << *it << " ";
}
cout << endl;
// Affichage: un deux trois

const List<int> c = { 42, 3, 14 };
for(List<int>::ConstIterator it = c.end(); it != c.begin(); --it){
    cout << *it << " ";
}
cout << endl;
// Affichage: 14 3 42
```

A titre de comparaison, la `STL` utilise les fonctions `rbegin()` et `rend` afin d'effectuer la deuxième boucle `for`. Nous ne pouvons donc pas effectuer les même opérations que la `STL`.

Après réflexion avec plusieurs membres de la classe, nous avons décidé d'implémenté deux noeuds sentinelles. Ces sentinelles se trouvent avant le début de la liste et après la fin de la liste. Elle se nomme respectivement `beforeHead` et `afterLast`.

![Schéma des sentinelles](.\SchemaSentinelle.jpg)

On peut donc voir le noeud `head` a un référence vers le noeuds `beforeHead` comme noeud précédant. Cependant pour ce dernier, la référence vers noeud suivant est la même que le noeud suivant de `head`.

Dit autrement, les instructions suivantes nous fournissent toutes une référence vers le deuxième noeud qui contient la valeur **2** (on ne compte pas les sentinelles dans la numérotation des noeuds). 

```c++
Node *n1 = head->next;
Node *n2 = beforeHead->next;
Node *n3 = head->prev->next;
```

Il est important de noter que nous donnons la même valeur aux noeuds sentinelles que les valeurs de `head`et respectivement `last`.

Les fonctions `List<T>::begin()` et `List<T>::end()` fournissent donc un itérateur pointant vers `beforeHead`et `afterLast`.

Voici donc les instructions exécutée par les boucles `for` fournie en étape par étape avec l'exemple présenté ci-dessus :

```c++
/*for(List<string>::Iterator it = l.begin(); it != l.end(); ++it){
    cout << *it << " ";
}*/
List<string>::Iterator it = l.begin();	// it pointe sur beforeHead
cout << *it << " ";						// Affiche la valeur de beforeHead, 1
++it;									// it pointe le noeud de valeur 2
cout << *it << " ";						// Affiche la valeur 2
++it;									// it pointe sur last
cout << *it << " ";						// Affiche la valeur de last, 3
++it;									// it pointe sur afterLast, l.end() retourne
										// le noeud afterLast, la boucle s'arrête.

/*for(List<int>::ConstIterator it = c.end(); it != c.begin(); --it){
    cout << *it << " ";
}*/
List<string>::ConstIterator it = l.end();	// it pointe sur afterLast
cout << *it << " ";							// Affiche la valeur de afterLast, 3
--it;										// it pointe le noeud de valeur 2
cout << *it << " ";							// Affiche la valeur 2
--it;										// it pointe sur head
cout << *it << " ";							// Affiche la valeur de head, 1
--it;										// it pointe sur beforeHead, l.begin()
											// retourne le noeud afterLast,
											// la boucle s'arrête.
```

## Avantages - Inconvénients

