#ifndef TESTARI_SNAKE_H
#define TESTARI_SNAKE_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <unordered_set>
#include <fstream>
#include <memory>
#include "ScreenIcon.h"


class Snake : public ScreenIcon<std::string> {
public:
    explicit Snake(const std::string &n);

    void playSound() const override;

    std::shared_ptr<ScreenIcon<std::string>> createInstance(const std::string &name) override;
};


#endif //TESTARI_SNAKE_H