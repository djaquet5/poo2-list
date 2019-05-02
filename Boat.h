/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Boat.h
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>

/**
 * Class Boat
 *
 * Représentation d'un bateau
 */
class Boat {
private:
    std::string name;
    std::size_t weight;
public:
    /**
     * Constructeur
     */
    Boat(std::string name, std::size_t weight);

    virtual std::string display() const;

    friend std::ostream& operator << (std::ostream& os, const Boat& b);
};
