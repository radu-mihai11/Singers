//
// Created by Spiffy on 16.04.2024.
//

#include "../ProjectHeaders/Snake.h"

Snake::Snake(const std::string &n) : ScreenIcon(n) {}

void Snake::playSound() const {
    while (isActive()) {
        outFile << "Snake hiss" << std::endl;
        dummyFunction();
    }
}
