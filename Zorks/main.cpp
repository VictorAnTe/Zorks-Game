#include <iostream>
#include <string>
#include <vector>
#include "World.h"

int main() {
    // Initialization of the world, we create one World that would contain a vector with each entity
    World myWorld;

    std::cout << "Welcome to Zork!" << std::endl;
    std::cout << "----------------" << std::endl;

    std::string userInput;
    bool isRunning = true;

    // Game Loop
    while (isRunning) {
        std::cout << "\n> ";
        std::getline(std::cin, userInput);

        if (userInput == "quit") {
            isRunning = false;
        }
        else {
            // World is the responsable of processing all the game logic and update entities
            myWorld.Update(userInput);
        }
    }

    std::cout << "\nThanks for playing!" << std::endl;
    return 0;
}