#ifndef TESTARI_METAL_H
#define TESTARI_METAL_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <unordered_set>
#include <fstream>
#include <memory>
#include "SharedData.h"
#include "ScreenIcon.h"

class Metal : public ScreenIcon {
public:
    explicit Metal(const std::string &n);

    void playSound() const override;
};


#endif //TESTARI_METAL_H
