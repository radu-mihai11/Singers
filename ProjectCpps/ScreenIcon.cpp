#include "../ProjectHeaders/ScreenIcon.h"

std::ofstream outFile("output.txt");

template<typename T>
ScreenIcon<T>::ScreenIcon(const T &n) : name(n), currentState(false) {}

template<typename T>
T ScreenIcon<T>::getName() const {
    return name;
}

template<typename T>
bool ScreenIcon<T>::isActive() const {
    return currentState;
}

template<typename T>
void ScreenIcon<T>::setActive(bool value) {
    currentState = value;
    if (currentState) {
        activeSounds.insert(name);
        std::thread soundThread(&ScreenIcon<T>::playSound, this);
        soundThread.detach();
    } else {
        activeSounds.erase(name);
    }
}

template<typename T>
void ScreenIcon<T>::playSound() const {

}

template class ScreenIcon<std::string>;
