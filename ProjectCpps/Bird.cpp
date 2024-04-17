#include "../ProjectHeaders/Bird.h"

Bird::Bird(const std::string &n) : ScreenIcon(n) {}

void Bird::playSound() const {
    while (isActive()) {
        outFile << "Bird tweet" << std::endl;
        dummyFunction();
    }
}
