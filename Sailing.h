//
// Created by David on 01.05.2019.
//

#pragma once


#include "Boat.h"

class Sailing : public Boat {
public:
    Sailing(const std::string &name, size_t weight);
    std::string display() const;
};