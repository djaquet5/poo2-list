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

#include <cstdio>
#include <stdexcept>
#include <ostream>

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
        explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr) : prev(prev), next(next), data(data) {}
    };

    /**
     * Iterateur generique pour la List
     */
    class GenericIterator {
    protected:
        Node *current;
    public:
        /**
         * Constructeur
         */
        explicit GenericIterator(Node* node) : current(node) {}

        /**
         * Surcharge de l'opérateur ==
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

    private:
        /**
         * Methode privée qui renvoie une exception si le Node est null
         *
         * @throw out_of_range si le Node est null
         */
        void checkBound(Node* node) {
            if(!node) {
                throw std::out_of_range("Iterator out of range");
            }
        }

    protected:
        /**
         * Incrémente l'itérateur (fait pointer l'itérateur sur le prochain
         * élément de la liste
         *
         * @throw out_of_range si le prochain Node est null
         */
        void inc() {
            checkBound(current->next);
            current = current->next;
        }

        /**
         * Décrémente l'itérateur (fait pointer l'itérateur sur l'élément
         * précédent de la liste
         *
         * @throw out_of_range si le Node précédent est null
         */
        void dec() {
            checkBound(current->prev);
            current = current->prev;
        }
    };

public:

    /**
     * Itérateur (mutable) pour la liste
     */
    class Iterator : public GenericIterator {

    public:
        /**
         * Constructeur
         */
        explicit Iterator(Node* node) : GenericIterator(node) {};

        /**
         * Surcharge de l'opérateur de déréférencement
         */
        T& operator * () const {
            return GenericIterator::current->data;
        }

        /**
         * Surcharge de l'opérateur de déréférencement + adressage
         */
        T* operator -> () const {
            return &(GenericIterator::current->data);
        }

        /**
         * Surcharge de l'opérateur ++ en préfixe.
         * Utilisation : ++it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        Iterator& operator ++ () {
            GenericIterator::inc();
            return *this;
        }

        /**
         * Surcharge de l'opérateur -- en préfixe.
         * Utilisation : --it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        Iterator& operator -- () {
            GenericIterator::dec();
            return *this;
        }

        /**
         * Surcharge de l'opérateur ++ en suffixe.
         * Utilisation : it++, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        Iterator operator ++ (int) {
            Iterator currentIterator(*this);
            GenericIterator::inc();
            return currentIterator;
        }

        /**
         * Surcharge de l'opérateur -- en suffixe.
         * Utilisation : it--, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        Iterator operator -- (int) {
            Iterator currentIterator(*this);
            GenericIterator::dec();
            return currentIterator;
        }
    };

    /**
     * Itérateur (immutable) pour la liste
     */
    class ConstIterator : public GenericIterator {

    public:

        /**
         * Constructeur
         */
        explicit ConstIterator(Node* node) : GenericIterator(node) {};

        /**
         * Surcharge de l'opérateur de déréférencement
         */
        T operator * () const {
            return GenericIterator::current->data;
        }

        /**
         * Surcharge de l'opérateur de déréférencement + adressage
         */
        T const * operator -> () const {
            return &(GenericIterator::current->data);
        }

        /**
         * Surcharge de l'opérateur ++ en préfixe.
         * Utilisation : ++it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        ConstIterator& operator ++ () {
            GenericIterator::inc();
            return *this;
        }

        /**
         * Surcharge de l'opérateur -- en préfixe.
         * Utilisation : --it, où it est l'itérateur
         *
         * @return      Nouvel élément pointé par l'itérateur
         */
        ConstIterator& operator -- () {
            GenericIterator::dec();
            return *this;
        }

        /**
         * Surcharge de l'opérateur ++ en suffixe.
         * Utilisation : it++, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        ConstIterator operator ++ (int) {
            ConstIterator currentIterator(*this);
            GenericIterator::inc();
            return currentIterator;
        }

        /**
         * Surcharge de l'opérateur -- en suffixe.
         * Utilisation : it--, où it est l'itérateur
         *
         * @return      Elément anciennement pointé
         */
        ConstIterator operator -- (int) {
            ConstIterator currentIterator(*this);
            GenericIterator::dec();
            return currentIterator;
        }
    };

    /********************* Contenu de List **********************/
private:
    size_t length;
    Node *head;
    Node *last;
    Node *beforeHead;
    Node *afterLast;

    /**
     * Ré-initialise la liste
     */
    void clear() {
        Node* currentHead;

        while(head) {
            currentHead = head->next;
            if(head != afterLast) {
                delete head;
            }

            head = currentHead;
        }
        last = nullptr;
        length = 0;

        if (beforeHead) {
            delete beforeHead;
        }

        if (afterLast) {
            delete afterLast;
        }
        afterLast = nullptr;
        beforeHead = nullptr;
    }

    /**
     * Vérifie si l'index est valide. Autrement, il faut que l'index soit compris
     * dans l'intervalle [0, nbElements[
     * Si l'index est >=, on générune une std:out_of_range exception
     * @param index     Index à vérifier
     */
    void isIndexValid(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
    }

    /**
     * Initialise la sentinelle se trouvant avant le head
     */
    void initBeforeHead(){
        if (!head) {
            return;
        }

        if (beforeHead) {
            beforeHead->data = head->data;

            beforeHead->next = head->next;
            beforeHead->prev = nullptr;
        } else {
            beforeHead = new Node(head->data, nullptr, head->next);
        }

        head->prev = beforeHead;
    }

    /**
     * Initialise la sentinelle se trouvant après le dernir élément
     */
    void initAfterLast(){
        if (!last) {
            return;
        }

        if (afterLast) {
            afterLast->data = last->data;

            afterLast->prev = last->prev;
            afterLast->next = nullptr;
        } else {
            afterLast = new Node(last->data, last->prev);
        }

        last->next = afterLast;
    }

    /**
     * Initialise les deux sentinelles
     */
    void initSentinels() {
        initBeforeHead();
        initAfterLast();
    }

public:

    /**
     * Constructeur vide
     */
    List() : length(0), head(nullptr), last(nullptr), beforeHead(nullptr), afterLast(nullptr) {}

    /**
     * Constructeur avec liste d'initialiseurs
     * @param values    List d'initialiseurs
     */
    List(std::initializer_list<T> values) : List() {
        for(auto it = values.begin(); it != values.end(); ++it) {
            append(*it);
        }

        initSentinels();
    }

    /**
     * Constructeur de copie
     * @param o     Liste à copier
     */
    List(const List<T>& o) : List() {
        Node *otherCurrent;

        if (!o.head) {
            return;
        }

        otherCurrent = o.head;

        while (otherCurrent && otherCurrent != o.afterLast) {
            append(otherCurrent->data);

            otherCurrent = otherCurrent->next;
        }

        initSentinels();
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
            tmp.head = nullptr;

            last = tmp.last;

            length = o.length;
            initSentinels();
        }

        return *this;
    }

    /**
     * Surcharge de l'opérateur d'affectation
     * @param o     Liste utilisée pour l'affectation
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
    T& get(size_t index) {
        isIndexValid(index);

        Iterator it = begin();

        for(size_t i = 0; i < index; ++i) {
            ++it;
        }

        return *it;
    }

    /**
     * Rend l'élément présent à un indice donné
     * @param index     Indice de l'élément à récupérer
     *
     * @return          Elément voulu
     */
    T get(size_t index) const {
        isIndexValid(index);

        ConstIterator it = begin();

        for(size_t i = 0; i < index; ++i) {
            ++it;
        }

        return *it;
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
        return length;
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
            last = newHead;
        }

        head = newHead;
        initSentinels();

        ++length;
    }

    /**
     * Ajoute un élément à la fin de la liste
     *
     * @param o     L'élément à ajouter
     */
    void append(const T& o) {
        Node *newQueue = new Node(o, last, nullptr);

        // On vérifie si il y a déjà des éléments dans la liste
        if (last) {
            last->next = newQueue;
        } else {
            head = newQueue;
        }

        last = newQueue;
        initSentinels();

        ++length;
    }

    /**
     * Supprime l'élément de la liste à un index donné
     *
     * @param index     Index de l'élément à supprimer
     */
    void removeAt(size_t index) {
        Node *current;

        isIndexValid(index);

        // On crée un noeud qui est avant le début de la liste
        current = head;

        // On veut supprimer la tête
        if (index == 0) {
            if(length == 1) {
                clear();
            } else {
                head = head->next;

                delete current;
                --length;
                initSentinels();
            }
            return;
        }

        for(size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;

        if(current == last) {
            last = current->prev;
        } else {
            current->next->prev = current->prev;
        }

        delete current;
        --length;
        initSentinels();
    }

    /**
     * Supprime les élément identique à la valeur donné en paramètre
     *
     * @param o     Elément à vérifier
     */
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
    Iterator begin() {
        return Iterator(beforeHead);
    }

    /**
     * Crée un itérateur pointant sur le dernier élément de la liste
     *
     * @return      Itérateur pointant sur le dernier élément de la liste
     */
    Iterator end() {
        return Iterator(afterLast);
    }

    /**
     * Crée un itérateur constant pointant sur le premier élément de la liste
     *
     * @return      Iterateur constant pointant sur le premier élément de la liste
     */
    ConstIterator begin() const {
        return ConstIterator(beforeHead);
    }

    /**
     * Crée un itérateur constant pointant sur le dernier élément de la liste
     *
     * @return      Itérateur constant pointant sur le dernier élément de la liste
     */
    ConstIterator end() const {
        return ConstIterator(afterLast);
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
        int index = 0;
        ConstIterator it = begin();

        while(it != end()) {
            if(*it == o) {
                return index;
            }
            ++it;
            ++index;
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
    friend std::ostream& operator << (std::ostream& os, const List& list) {
        ConstIterator it = list.begin();

        os << "(";
        while(it != list.end()) {
            if(it != list.begin()) {
                os << ", ";
            }

            os << *it;
            ++it;
        }
        os <<")";

        return os;
    }
};
