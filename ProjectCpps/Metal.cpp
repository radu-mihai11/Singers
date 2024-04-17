#include "../ProjectHeaders/Metal.h"

Metal::Metal(const std::string &n) : ScreenIcon(n) {}

void Metal::playSound() const {
    while (isActive()) {
        outFile << "Metal cling" << std::endl;
        dummyFunction();
    }
}
