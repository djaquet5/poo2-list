/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Yacht.h
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Boat.h"

/**
 * Class Yacht
 *
 * Représentation d'un Yacht
 */
class Yacht : public Boat {
public:
    Yacht(const std::string &name, size_t weight);
    std::string display() const;
};
