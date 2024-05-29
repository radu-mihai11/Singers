#include "../ProjectHeaders/Snake.h"

Snake::Snake(const std::string &n) : ScreenIcon(n) {}

void Snake::playSound() const {
    while (isActive()) {
        outFile << "Snake hiss" << std::endl;
        dummyFunction();
    }
}

std::shared_ptr<ScreenIcon<std::string>> Snake::createInstance(const std::string &name) {
    return std::make_shared<Snake>(name);
}
