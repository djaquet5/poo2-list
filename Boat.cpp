/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Boat.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 01.05.2019
 -----------------------------------------------------------------------------------
*/

#include "Boat.h"

Boat::Boat(std::string name, std::size_t weight) : name(name), weight(weight) {}

std::string Boat::display() const {
    return "Nom: " + name + ", " + std::to_string(weight) + "kg";
}

std::ostream &operator<<(std::ostream &os, const Boat &b) {
    return os << b.display();
}
