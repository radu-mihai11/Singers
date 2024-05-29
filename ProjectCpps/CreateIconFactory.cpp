#include "../ProjectHeaders/CreateIconFactory.h"

std::shared_ptr<ScreenIcon<std::string>> CreateIconFactory::createBird() const {
    return std::make_shared<Bird>("Bird");
}

std::shared_ptr<ScreenIcon<std::string>> CreateIconFactory::createSnake() const {
    return std::make_shared<Snake>("Snake");
}

std::shared_ptr<ScreenIcon<std::string>> CreateIconFactory::createMetal() const {
    return std::make_shared<Metal>("Metal");
}
