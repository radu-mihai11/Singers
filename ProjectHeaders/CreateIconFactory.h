#ifndef TESTARI_CREATEICONFACTORY_H
#define TESTARI_CREATEICONFACTORY_H

#include "IconFactory.h"
#include "Bird.h"
#include "Snake.h"
#include "Metal.h"

class CreateIconFactory : public IconFactory {
public:
    std::shared_ptr<ScreenIcon<std::string>> createBird() const override;
    std::shared_ptr<ScreenIcon<std::string>> createSnake() const override;
    std::shared_ptr<ScreenIcon<std::string>> createMetal() const override;
};

#endif // TESTARI_CONCRETEICONFACTORY_H
