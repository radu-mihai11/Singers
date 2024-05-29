#include "../ProjectHeaders/Metal.h"

Metal::Metal(const std::string &n) : ScreenIcon(n) {}

void Metal::playSound() const {
    while (isActive()) {
        outFile << "Metal cling" << std::endl;
        dummyFunction();
    }
}

std::shared_ptr<ScreenIcon<std::string>> Metal::createInstance(const std::string &name) {
    return std::make_shared<Metal>(name);
}
