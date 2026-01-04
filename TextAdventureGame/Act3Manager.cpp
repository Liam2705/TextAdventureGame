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

//STAGE 1: Server Room
void Act3Manager::chaseStage1_ServerRoom() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 1: SERVER ROOM EXIT\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The server room door is cycling shut.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Security lockdown in progress.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("You have seconds to act.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::cout << "What do you do?\n\n";
    std::cout << "1. Hack the door controls\n";
    std::cout << "2. Shoot the control panel\n";
    std::cout << "3. Find the emergency exit\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You jack into the door's control system.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Code flows. Protocols bend. The lock disengages.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The door slides open. Clean exit.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You draw your weapon and fire.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("CRACK! The control panel explodes in sparks.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The door jerks open. Alarms intensify.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("They definitely heard that.", TextSpeed::SLOW);
        break;

    case 3:
        TextEffects::typewriter("You spot the emergency exit marker.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You shoulder through the door. It gives way.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You're in a maintenance corridor. Darker, but safer.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    waitForEnter();
}

//STAGE 2: Corporate Lobby
void Act3Manager::chaseStage2_Lobby() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 2: CORPORATE LOBBY\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You burst into the main lobby.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Security drones activate overhead. Red targeting lasers sweep the floor.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Corporate guards pour in from side entrances.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::cout << "Your move:\n\n";
    std::cout << "1. Sprint straight for the exit\n";
    std::cout << "2. Duck behind server terminals\n";
    std::cout << "3. Trigger the fire alarm\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You break into a full sprint.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Boots pound marble. Lasers track you.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Gunfire erupts behind you--but you're already through the exit.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You drop low and weave between server terminals.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The drones lose line of sight. Guards search frantically.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You slip past them, a ghost in the machine.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You smash the fire alarm with your elbow.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Sirens wail. Sprinklers engage. Water cascades.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Guards shout in confusion. In the chaos, you vanish.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    waitForEnter();
}

//STAGE 3: Plaza Entrance
void Act3Manager::chaseStage3_PlazaEntrance() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 3: PLAZA ENTRANCE\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The checkpoint ahead. Your only exit.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Security barriers are lowering. They're trying to trap you.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Guards closing in from behind.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::cout << "Quick decision:\n\n";
    std::cout << "1. Slide under the closing barrier\n";
    std::cout << "2. Override the security console\n";
    std::cout << "3. Shoot your way through\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You dive. The world tilts sideways.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You slide under the barrier as it slams shut behind you.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The guards pound on the barrier. Too late.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You jack into the security console.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Admin override... accepted. Barriers retract.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You walk through calmly as the system resets.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You open fire on the barrier controls.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Sparks fly. Metal groans. The barrier jerks upward.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You charge through the gap, weapon still smoking.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    TextEffects::typewriter("You're outside. Rain hits your face.", TextSpeed::SLOW);
    std::cout << "\n";

    waitForEnter();
}

//STAGE 4: Streets
void Act3Manager::chaseStage4_Streets() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 4: THE STREETS\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("Neon and rain. The city pulses around you.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Behind: corporate security in pursuit.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Ahead: the transit station. Your escape route.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::cout << "Choose your path:\n\n";
    std::cout << "1. Take the main street\n";
    std::cout << "2. Cut through back alleys\n";
    std::cout << "3. Blend into the night market crowd\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You run down the main thoroughfare.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Pedestrians scatter. Vehicles swerve.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You're exposed, but fast. The transit station looms ahead.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You dive into the alleyways.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Darkness. Puddles. Graffiti-covered walls.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You lose the pursuit in the maze of side streets.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You slip into the crowded night market.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Vendors hawk synthetic food. Music blares.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You're just another face in the crowd. Invisible.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    waitForEnter();
}

//STAGE 5: Transit Station
void Act3Manager::chaseStage5_Transit() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 5: TRANSIT STATION\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The transit station. Grimy. Flickering lights.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Corporate security has called ahead.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Transit cops are moving to intercept.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::cout << "Final push:\n\n";
    std::cout << "1. Board the train normally (blend in)\n";
    std::cout << "2. Jump onto the moving train\n";
    std::cout << "3. Use the maintenance tunnels\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You walk calmly to the platform.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Hood up. Head down. Just another commuter.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The transit cops scan the crowd... and miss you.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You board the train. Doors close. It pulls away.", TextSpeed::SLOW);
        break;

    case 2:
        TextEffects::typewriter("The train is already moving. No time.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You run alongside it, grab the rail, and swing aboard.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Passengers stare. You don't care. You're on.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You spot the maintenance access. Locked.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Three seconds of work. The lock gives.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You descend into the tunnels. Dark, but safe.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You follow the tracks back to Downtown.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    waitForEnter();
}

//STAGE 6: Downtown
void Act3Manager::chaseStage6_Downtown() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         STAGE 6: DOWNTOWN DISTRICT\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You're back in Downtown.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Familiar neon signs. Rain-slicked streets.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("But the corps know you're here somewhere.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Time to reach your apartment.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::cout << "Last leg:\n\n";
    std::cout << "1. Take the direct route through Neon Street\n";
    std::cout << "2. Navigate rooftops and back passages\n";
    std::cout << "3. Steal a hover-bike\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You walk through Neon Street boldly.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Confidence is camouflage. Act like you belong.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("No one stops you. Your apartment building ahead.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You scale a fire escape. Take to the rooftops.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The city sprawls below. You move like a shadow.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Drop down behind your building. Home.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You hot-wire a parked hover-bike.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The engine roars. You tear through the streets.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Reckless. Fast. You ditch it near your apartment.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n";
    waitForEnter();
}

//FINAL STAGE: The Escape
void Act3Manager::chaseFinal_Escape() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ESCAPE COMPLETE\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You duck into a dark alley near your building.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Press against the cold wall. Hold your breath.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("Corporate security vehicles pass by...", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    TextEffects::typewriter("They don't see you.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You're clear.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("But they'll keep searching. Time is limited.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("You slip into your apartment building.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Forty floors up. Your sanctuary.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("For now.", TextSpeed::SLOW);
    std::cout << "\n";

    waitForEnter();
}