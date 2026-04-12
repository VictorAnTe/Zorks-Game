#include <iostream>
#include <string>
#include <vector>
#include "World.h"

const bool game_over = false;

int main() {
    // Initialization of the world, we create one World that would contain a vector with each entity
    World myWorld;

    std::string userInput;
    bool isRunning = true;

    // Game Loop
    while (myWorld.close_game == false) {
        std::cout << "\n> ";
        std::getline(std::cin, userInput);

        if (userInput == "quit") break;

        myWorld.Update(userInput);
    }

    std::cout << "\nThanks for playing!" << std::endl;
    return 0;
}