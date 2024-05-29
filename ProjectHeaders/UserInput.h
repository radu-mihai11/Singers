#ifndef TESTARI_USERINPUT_H
#define TESTARI_USERINPUT_H

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
#include "Bird.h"
#include "Snake.h"
#include "Metal.h"


template<typename T2>
class UserInput : public SharedData {
private:
    static std::vector<std::shared_ptr<ScreenIcon<std::string>>> createIcons();

public:
    static void displayIcons(const std::vector<std::shared_ptr<ScreenIcon<std::string>>> &icons);
    static void run();
};

#include "../ProjectCpps/UserInput.tpp"

#endif // TESTARI_USERINPUT_H