#ifndef TESTARI_INVALID_INPUT_EXCEPTION_H
#define TESTARI_INVALID_INPUT_EXCEPTION_H

#include <stdexcept>

class InvalidInputException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid input. Please enter a number between 1 and 3.";
    }
};

#endif // TESTARI_INVALID_INPUT_EXCEPTION_H
