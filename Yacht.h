//
// Created by David on 02.05.2019.
//

#pragma once

#include "Boat.h"

class Yacht : public Boat {
public:
    Yacht(const std::string &name, size_t weight);
    std::string display() const;
};
