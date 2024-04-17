#include <stdexcept>
#include "../ProjectHeaders/UserInput.h"
#include "../ProjectHeaders/InvalidInputException.h"


std::vector<std::shared_ptr<ScreenIcon>> UserInput::createIcons() {
    std::vector<std::shared_ptr<ScreenIcon>> icons;
    icons.push_back(std::make_shared<Bird>("Bird"));
    icons.push_back(std::make_shared<Snake>("Snake"));
    icons.push_back(std::make_shared<Metal>("Metal"));
    return icons;
}

void UserInput::displayIcons(const std::vector<std::shared_ptr<ScreenIcon>> &icons) {
    std::cout << "Icons:" << std::endl;
    for (size_t i = 0; i < icons.size(); ++i) {
        std::cout << i + 1 << ". " << icons[i]->getName();
        if (icons[i]->isActive()) {
            std::cout << " (Active)";
        }
        std::cout << std::endl;
    }
}

void UserInput::run() {
    std::vector<std::shared_ptr<ScreenIcon>> icons = createIcons();

    char input;
    bool running = true;

    try {
        while (running) {
            displayIcons(icons);

            std::cout << "Enter the index to activate/deactivate (0 to quit): ";
            std::cin >> input;

            if (input >= '1' && input <= '3') {
                int index = input - '0' - 1;
                icons[index]->setActive(!icons[index]->isActive());
            } else if (input == '0') {
                running = false;
            } else {
                throw InvalidInputException();
            }
        }
    } catch (const InvalidInputException &e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }
}