//
// Created by Spiffy on 16.04.2024.
//

#ifndef TESTARI_SCREENICON_H
#define TESTARI_SCREENICON_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <unordered_set>
#include <fstream>
#include <memory>
#include <utility>
#include "SharedData.h"

extern std::ofstream outFile;

template<typename T>
class ScreenIcon : public SharedData {
protected:
    T name;
    bool currentState;

public:
    explicit ScreenIcon(const T &n);

    [[nodiscard]] T getName() const;

    [[nodiscard]] bool isActive() const;

    void setActive(bool value);

    virtual void playSound() const;

    virtual std::shared_ptr<ScreenIcon<T>> createInstance(const T &name) = 0;
};


#endif //TESTARI_SCREENICON_H