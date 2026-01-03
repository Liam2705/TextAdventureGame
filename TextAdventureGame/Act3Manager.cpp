#include "Act3Manager.h"
#include "GameEngine.h"
#include "Player.h"
#include "TextEffects.h"
#include <iostream>

//Constructor
Act3Manager::Act3Manager(GameEngine* engine)
    : act3Active(false),
    chaseComplete(false),
    decryptionComplete(false),
    finaleStarted(false),
    gameEngine(engine) {
}

//Activate Act 3
void Act3Manager::startAct3() {
    act3Active = true;
    std::cout << "\n[Act 3 activated - Chase sequence ready]\n";
}

//Getters
bool Act3Manager::isAct3Active() const { return act3Active; }
bool Act3Manager::isChaseComplete() const { return chaseComplete; }

//Helper functions
int Act3Manager::getChoice(int min, int max) {
    int choice;
    while (true) {
        std::cout << "\n> Enter choice [" << min << "-" << max << "]: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice >= min && choice <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }

        std::cout << "Invalid choice! Choose between " << min << " and " << max << ".\n";
    }
}

void Act3Manager::waitForEnter(const std::string& prompt) {
    std::cout << prompt;
    std::cin.get();
}

void Act3Manager::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
* CHASE SEQUENCE HANDLERS
* Handles the multiple parts of the chase sequence after Act 3 is triggered
*/

void Act3Manager::runChaseSequence(Player* player) {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ESCAPE SEQUENCE INITIATED\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The alarm blares. Red lights flood the corridors.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("You clutch the data chip. Time to move.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    chaseStage1_ServerRoom();
    chaseStage2_Lobby();
    chaseStage3_PlazaEntrance();
    chaseStage4_Streets();
    chaseStage5_Transit();
    chaseStage6_Downtown();
    chaseFinal_Escape();

    chaseComplete = true;

    std::cout << "\n================================================\n";
    std::cout << "You've made it to your apartment building.\n";
    std::cout << "Time to see what's on that chip.\n";
    std::cout << "================================================\n";

    waitForEnter();
}