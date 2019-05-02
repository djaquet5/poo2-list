//
// Created by David on 01.05.2019.
//

#pragma once

#include <string>

class Boat {
private:
    std::string name;
    std::size_t weight;
public:
    Boat(std::string name, std::size_t weight);

    virtual std::string display() const;

    friend std::ostream& operator << (std::ostream& os, const Boat& b);
};
