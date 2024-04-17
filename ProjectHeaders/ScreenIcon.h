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

class ScreenIcon : public SharedData {
protected:
    std::string name;
    bool currentState;

public:
    explicit ScreenIcon(std::string n);

    [[nodiscard]] virtual std::string getName() const;

    [[nodiscard]] bool isActive() const;

    virtual void setActive(bool value);

    virtual void playSound() const;
};


#endif //TESTARI_SCREENICON_H
