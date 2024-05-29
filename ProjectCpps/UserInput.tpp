#ifndef TESTARI_USERINPUT_TPP
#define TESTARI_USERINPUT_TPP

#include <stdexcept>
#include "../ProjectHeaders/UserInput.h"
#include "../ProjectHeaders/InvalidInputException.h"
#include "../ProjectHeaders/CreateIconFactory.h"

template<typename T2>
std::vector<std::shared_ptr<ScreenIcon<std::string>>> UserInput<T2>::createIcons() {
    std::vector<std::shared_ptr<ScreenIcon<std::string>>> icons;
    CreateIconFactory factory;

    icons.push_back(factory.createBird());
    icons.push_back(factory.createSnake());
    icons.push_back(factory.createMetal());

    return icons;
}

template<typename T2>
void UserInput<T2>::displayIcons(const std::vector<std::shared_ptr<ScreenIcon<std::string>>> &icons) {
    std::cout << "Icons:" << std::endl;
    for (size_t i = 0; i < icons.size(); ++i) {
        std::cout << i + 1 << ". " << icons[i]->getName();
        if (icons[i]->isActive()) {
            std::cout << " (Active)";
        }
        std::cout << std::endl;
    }
}

template<typename T2>
void UserInput<T2>::run() {
    std::vector<std::shared_ptr<ScreenIcon<std::string>>> icons = createIcons();

    T2 input;
    bool running = true;
    bool displayErrorMessage = false;

    while (running) {

        if (displayErrorMessage) {
            std::cerr << "\n Invalid input. Please enter a number between 1 and 3. \n" << std::endl;
            displayErrorMessage = false;
        }

        displayIcons(icons);

        std::cout << "Enter the index to activate/deactivate (0 to quit): ";
        std::cin >> input;

        try {
            if (input >= static_cast<T2>('1') && input <= static_cast<T2>('3')) {
                int index = static_cast<int>(input - '0' - 1);
                icons[index]->setActive(!icons[index]->isActive());

                if (auto bird = std::dynamic_pointer_cast<Bird>(icons[index])) {
                    if (icons[index]->isActive()) {
                        std::cout << "\nBird activated!\n" << std::endl;
                    } else {
                        std::cout << "\nBird deactivated!\n" << std::endl;
                    }
                }
                else
                    if (auto snake = std::dynamic_pointer_cast<Snake>(icons[index])) {
                        if (icons[index]->isActive()) {
                            std::cout << "\nSnake activated!\n" << std::endl;
                        } else {
                            std::cout << "\nSnake deactivated!\n" << std::endl;
                        }
                    }
                    else
                        if (auto metal = std::dynamic_pointer_cast<Metal>(icons[index])) {
                            if (icons[index]->isActive()) {
                                std::cout << "\nMetal activated!\n" << std::endl;
                            } else {
                                std::cout << "\nMetal deactivated!\n" << std::endl;
                            }
                        }

            } else if (input == static_cast<T2>('0')) {
                running = false;
            } else {
                throw InvalidInputException();
            }
        } catch (const InvalidInputException &e) {
            displayErrorMessage = true;
        } catch (...) {
            std::cout << "An unexpected error occurred." << std::endl; //asta nu apare niciodata
        }
    }
}

#endif // TESTARI_USERINPUT_TPP
