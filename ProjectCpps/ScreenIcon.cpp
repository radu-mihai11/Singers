#include "../ProjectHeaders/ScreenIcon.h"

std::ofstream outFile("output.txt");

ScreenIcon::ScreenIcon(std::string n) : name(std::move(n)), currentState(false) {}

std::string ScreenIcon::getName() const {
    return name;
}

bool ScreenIcon::isActive() const {
    return currentState;
}

void ScreenIcon::setActive(bool value) {
    currentState = value;
    if (currentState) {
        activeSounds.insert(name);
        std::thread soundThread(&ScreenIcon::playSound, this);
        soundThread.detach();
    } else {
        activeSounds.erase(name);
    }
}

void ScreenIcon::playSound() const {
    while (isActive()) {
        outFile << "Playing sound " << name << std::endl;
        dummyFunction();
    }
}
