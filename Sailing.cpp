/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Sailing.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/

#include "Sailing.h"

Sailing::Sailing(const std::string &name, size_t weight) : Boat(name, weight) {}

std::string Sailing::display() const {
    return Boat::display() + ", un beau voilier !";
}
