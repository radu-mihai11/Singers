#ifndef TESTARI_ICONFACTORY_H
#define TESTARI_ICONFACTORY_H

#include <memory>
#include "ScreenIcon.h"

class IconFactory {
public:
    virtual std::shared_ptr<ScreenIcon<std::string>> createBird() const = 0;
    virtual std::shared_ptr<ScreenIcon<std::string>> createSnake() const = 0;
    virtual std::shared_ptr<ScreenIcon<std::string>> createMetal() const = 0;
    virtual ~IconFactory() = default;
};

#endif //TESTARI_ICONFACTORY_H
