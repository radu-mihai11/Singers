#include "../ProjectHeaders/SharedData.h"

void SharedData::dummyFunction() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

std::mutex SharedData::soundMutex;
std::unordered_set<std::string> SharedData::activeSounds;