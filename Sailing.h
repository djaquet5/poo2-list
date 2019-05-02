/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Sailing.h
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/
#pragma once


#include "Boat.h"

/**
 * Class Sailing
 *
 * Représentation d'un Voilier
 */
class Sailing : public Boat {
public:
    Sailing(const std::string &name, size_t weight);
    std::string display() const;
};