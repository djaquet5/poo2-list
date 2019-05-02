/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Yacht.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/

#include "Yacht.h"

Yacht::Yacht(const std::string &name, size_t weight) : Boat(name, weight) {}

std::string Yacht::display() const {
    return Boat::display() + ", un magnifique Yacht !";
}
