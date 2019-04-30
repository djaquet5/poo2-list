//
// Created by David on 30.04.2019.
//

#pragma once

#include <initializer_list>
#include <cstdio>
#include <iosfwd>
#include <stdexcept>

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

    };

public:

    // TODO
    class Iterator : public GenericIterator {

    };

    // TODO
    class ConstIterator : public GenericIterator {

    };

    /********************* Contenu de List **********************/
private:
    size_t nbElements;
    Node* head;
    Node *queue;

    /**
     * Ré-initialise la liste
     */
    void clear() {
        Node *currentHead;

        while(head){
            currentHead = head;
            delete currentHead;

            head = head->next;
        }

        head = nullptr;
        nbElements = 0;
    }

public:

    /**
     * Constructeur vide
     */
    List() : nbElements(0), head(nullptr) {}

    /**
     * Constructeur avec liste d'initialiseurs
     * @param values    List d'initialiseurs
     */
    // TODO
    List(std::initializer_list<T> values) : nbElements(values.size()) {

    }

    /**
     * Constructeur de copie
     * @param o     Liste à copier
     */
    // TODO
    List(const List<T>& o) {

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
    // TODO: Copier chacun des noeuds
    List& assign(const List<T>& o) {
        if (this != &o) {
            clear();

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
    // TODO
    T& get(size_t index) {

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
    ConstIterator end() const;

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
            if (current->data = o) {
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
