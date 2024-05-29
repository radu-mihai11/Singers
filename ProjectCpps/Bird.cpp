#include "../ProjectHeaders/Bird.h"

Bird::Bird(const std::string &n) : ScreenIcon(n) {}

void Bird::playSound() const {
    while (isActive()) {
        outFile << "Bird tweet" << std::endl;
        dummyFunction();
    }
}

std::shared_ptr<ScreenIcon<std::string>> Bird::createInstance(const std::string &name) {
    return std::make_shared<Bird>(name);
}
