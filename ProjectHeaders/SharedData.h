#ifndef TESTARI_SHAREDDATA_H
#define TESTARI_SHAREDDATA_H

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <unordered_set>
#include <fstream>
#include <memory>

class SharedData {
protected:
    static std::mutex soundMutex;
    static std::unordered_set<std::string> activeSounds;

    static void dummyFunction();
};


#endif //TESTARI_SHAREDDATA_H
