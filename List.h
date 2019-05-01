/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : List.h
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019

 Remarque(s) : Plusieurs choix d'implémentations ont été faits afin d'avoir des
               similitude avec la la STL

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <initializer_list>
#include <cstdio>
#include <iosfwd>
#include <stdexcept>
#include <iostream>

/**
 * Spécification d'une classe List personalisée
 *
 * @tparam T    Type générique de la liste
 */
template <typename T>
class List {

    /********************** Classes internes **********************/
private:

    /**
     * Noeud de la liste, contient une référence vers le noeud précédant et suivant dans la liste
     */
    class Node {
    public:
        Node *prev;
        Node *next;
        T data;

        /**
         * Constructeur
         */
        Node(const T& data, Node* prev = nullptr, Node* next = nullptr) : prev(prev), next(next), data(data) {}
    };

    // TODO
    class GenericIterator {
    protected:
        Node *current;
    public:
        GenericIterator(Node& node) : current(&node) {}

        // TODO: operator *
        T& operator * () {

        }

        // TODO: operator ->, type = Node ????
        Node* operator -> () const {

        }

        /**
         * Surcharge de l'opérateur !=
         * Les itérateurs sont égaux si ils pointent sur le même noeud
         * @param o     Deuxième iterateur à vérifier
         *
         * @return      True si les itérateurs sont égaux, false sinon
         */
        bool operator == (const GenericIterator& o) const {
            return current == o.current;
        }

        /**
         * Surcharge de l'opérateur !=
         * On retourne l'inverse du résultat de l'opérateur d'égalité (==)
         * @param o     Deuxième iterateur à vérifier
         *
         * @return      True si les itérateurs sont différents, false sinon
         */
        bool operator != (const GenericIterator& o) const {
            return !(*this == o);
        }
    };

public:

    // TODO
    class Iterator : public GenericIterator {

        /**
         * Surcharge de l'opérateur ++ en préfixe.
         * Utilisation : ++it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        // TODO: voir dans méthode
        GenericIterator& operator ++ () {
            // TODO

            return *this;
        }

        /**
         * Surcharge de l'opérateur -- en préfixe.
         * Utilisation : --it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        // TODO
        GenericIterator& operator -- () {

        }
    };

    // TODO
    class ConstIterator : public GenericIterator {

        /**
         * Surcharge de l'opérateur ++ en suffixe.
         * Utilisation : it++, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        // TODO
        GenericIterator operator ++ (int) {

        }

        /**
         * Surcharge de l'opérateur -- en suffixe.
         * Utilisation : it--, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        // TODO
        GenericIterator operator -- (int) {

        }

    };

    /********************* Contenu de List **********************/
private:
    size_t nbElements;
    Node *head;
    Node *queue;

    /**
     * Ré-initialise la liste
     */
    void clear() {
        Node* currentHead;

        while(head) {
            currentHead = head->next;
            delete head;

            head = currentHead;
        }

        nbElements = 0;
    }

    /*
    void clear() {
        Node *currentHead;

        while(head){
            currentHead = head;
            head = head->next;

            delete currentHead;
        }

        head = nullptr;
        nbElements = 0;
    }
     */


    void isIndexValid(size_t index) const {
        if (index >= nbElements) {
            throw std::out_of_range("Index out of range");
        }
    }
public:

    /**
     * Constructeur vide
     */
    List() : nbElements(0), head(nullptr), queue(nullptr) {}

    /**
     * Constructeur avec liste d'initialiseurs
     * @param values    List d'initialiseurs
     */
    List(std::initializer_list<T> values) : head(nullptr), queue(nullptr), nbElements(0) {
        for(auto it = values.begin(); it != values.end(); ++it) {
            append(*it);
        }
    }

    /**
     * Constructeur de copie
     * @param o     Liste à copier
     */
    List(const List<T>& o) : nbElements(0), head(nullptr), queue(nullptr) {
        Node *otherCurrent;

        if (!o.head) {
            return;
        }

        otherCurrent = o.head;

        while (otherCurrent) {
            append(otherCurrent->data);

            otherCurrent = otherCurrent->next;
        }
    }

    /**
     * Destructeur
     */
    ~List() {
        clear();
    }

    /**
     * Affecte une List depuis une autre List
     * @param o     Liste utilisée pour l'affection
     *
     * @return      Référence sur la liste courante
     */
    List& assign(const List<T>& o) {
        if (this != &o) {
            clear();
            List<T> tmp(o);

            head = tmp.head;
            queue = tmp.head;

            nbElements = o.nbElements;
        }

        return *this;
    }

    /**
     * Surcharge de l'opérateur d'affection
     * @param o     Liste utilisée pour l'affection
     *
     * @return      Référence sur la liste courante
     */
    List& operator = (const List<T>& o) {
        return assign(o);
    }

    /**
     * Rend l'élément présent à un indice donné
     * @param index     Indice de l'élément à récupérer
     *
     * @return          Elément voulu
     */
    // TODO: Tester avec les itérateurs
    T& get(size_t index) {
        isIndexValid(index);

        Iterator it = begin();

//        for(size_t i = 0; i < index; ++i) {
//            ++it;
//        }

        // On peut remplacer la boucle par cette ligne si on surcharge l'opérateur +=
//         it += index;
//
//        return (*it)->data;
    }

    /**
     * Rend l'élément présent à un indice donné
     * @param index     Indice de l'élément à récupérer
     *
     * @return          Elément voulu
     */
    // TODO: Tester avec les itérateurs
    T get(size_t index) const {
        isIndexValid(index);

        ConstIterator it = begin();

//        for(size_t i = 0; i < index; ++i) {
//            ++it;
//        }
//
//        return (*it)->data;
    }

    /**
     * Rend l'élément présent à un indice donné
     * @param index     Indice de l'élément à récupérer
     *
     * @return          Elément voulu
     */
    T& operator [] (size_t index) {
        return get(index);
    }

    /**
     * Rend l'élément présent à un indice donné
     * @param index     Indice de l'élément à récupérer
     *
     * @return          Elément voulu
     */
    T operator [] (size_t index) const {
        return get(index);
    }

    /**
     * Retourne le nombre d'éléments présent dans la liste
     *
     * @return  Taille de la liste en int
     */
    size_t size() const {
        return nbElements;
    }

    /**
     * Ajoute un élément au début de la liste
     *
     * @param o     L'élément à ajouter
     */
    void insert(const T& o) {
        Node *newHead = new Node(o, nullptr, head);

        // On vérifie si il y a déjà des éléments dans la liste
        if (head) {
            head->prev = newHead;
        } else {
            queue = newHead;
        }

        head = newHead;
        ++nbElements;
    }

    /**
     * Ajoute un élément à la fin de la liste
     *
     * @param o     L'élément à ajouter
     */
    void append(const T& o) {
        Node *newQueue = new Node(o, queue, nullptr);

        // On vérifie si il y a déjà des éléments dans la liste
        if (queue) {
            queue->next = newQueue;
        } else {
            head = newQueue;
        }

        queue = newQueue;
        ++nbElements;
    }

    /**
     * Supprime l'élément de la liste à un index donné
     *
     * @param index     Index de l'élément à supprimer
     */
    // TODO: Pas sur que ça marche ? => A TESTER
    void removeAt(size_t index) {
        Node *current;

        if (nbElements == 0) {
            throw std::runtime_error("The list is empty.");
        }

        if(index >= nbElements){
            throw std::invalid_argument("Index is out of bounds.");
        }

        // On veut supprimer la tête
        if (index == 0) {
            current = head;
            head = head->next;

            delete current;
            --nbElements;
            return;
        }

        // On crée un noeud qui est avant le début de la liste
        *current = Node(nullptr, nullptr, head);// TODO: => Memory Leak ???

        for(size_t i = 0; i <= index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;

        if(current == queue) {
            queue = current->next;
        } else {
            current->next->prev = current->prev;
        }

        delete current;
        --nbElements;
    }

    /**
     * Supprime les élément identique à la valeur donné en paramètre
     *
     * @param o     Elément à vérifier
     */
    // TODO: Pas sur que ça marche ? => A TESTER
    void remove(const T& o) {
        int index;

        while ((index = find(o)) != -1) {
            removeAt((size_t) index);
        }
    }

    /**
     * Crée un itérateur pointant sur le premier élément de la liste
     *
     * @return      Iterateur pointant sur le premier élément de la liste
     */
    // TODO
    Iterator begin() {

    }

    /**
     * Crée un itérateur pointant sur le dernier élément de la liste
     *
     * @return      Itérateur pointant sur le dernier élément de la liste
     */
    // TODO
    Iterator end() {

    }

    /**
     * Crée un itérateur constant pointant sur le premier élément de la liste
     *
     * @return      Iterateur constant pointant sur le premier élément de la liste
     */
    // TODO
    ConstIterator begin() const {

    }

    /**
     * Crée un itérateur constant pointant sur le dernier élément de la liste
     *
     * @return      Itérateur constant pointant sur le dernier élément de la liste
     */
    // TODO
    ConstIterator end() const {

    }

    /**
     * Recherche dans la liste l'élément reçu en paramètre et retourne l'indice du premier
     * élément trouvé.
     *
     * @param o     Elément cherché
     *
     * @return      Indice du premier élément trouvé au format size_t, retourne -1 si
     *              l'élément n'est pas dans la liste
     */
    int find(const T& o) const {
        Node *current = head;
        int index = 0;

        while (current) {
            if (current->data = o) { // TODO == ???
                return index;
            }

            ++index;
            current = current->next;
        }

        return -1;
    }

    /**
     * Surcharge de l'opérateur de flux de sortie
     * @param os    Flux de sortie
     * @param list  Liste à afficher
     *
     * @return      Référence sur le flux de sortie
     */
    // TODO
    friend std::ostream& operator << (std::ostream& os, const List& list) {

    }
};
