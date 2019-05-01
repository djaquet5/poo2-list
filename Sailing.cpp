//
// Created by David on 01.05.2019.
//

#include "Sailing.h"

Sailing::Sailing(const std::string &name, size_t weight) : Boat(name, weight) {}

std::string Sailing::display() const {
    return Boat::display() + " C'est un voilier !";
}
