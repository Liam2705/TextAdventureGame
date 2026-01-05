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

//Finale Sequence
void Act3Manager::startFinaleSequence(Player* player) {
    if (finaleStarted) {
        return;
    }

    finaleStarted = true;

    if (!chaseComplete) {
        runChaseSequence(player);
    }

    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         YOUR APARTMENT\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You lock the door behind you.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The familiar hum of your terminal. Rain on the windows.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The data chip feels heavy in your pocket.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();


    runDecryptionSequence();
    revealConspiracy();
    fixerConfrontation();

    displayChoiceMenu();
}

//Decryption Sequence
void Act3Manager::runDecryptionSequence() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         DECRYPTION SEQUENCE\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You approach your terminal.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Slot the data chip into the reader.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "[INITIALIZING...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "[MILITARY-GRADE ENCRYPTION DETECTED]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "[ANALYZING SECURITY LAYERS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\n";

    waitForEnter();

    decryptionStage1();
    decryptionStage2();
    decryptionStage3();

    std::cout << "\n";
    std::cout << "[DECRYPTION COMPLETE]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\n";
    TextEffects::typewriter("The screen flickers.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Data floods across your display.", TextSpeed::FAST);
    std::cout << "\n\n";

    waitForEnter();
}

/*
* MANAGES THE THREE STAGES OF DECRYPTION PROCESS
*/

void Act3Manager::decryptionStage1() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         LAYER 1: INITIAL BREACH\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The system pushes back immediately.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Corporate countermeasures. Adaptive firewalls.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("This data is HEAVILY protected.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::cout << "How do you respond?\n\n";
    std::cout << "1. Deploy aggressive counter-ICE protocols\n";
    std::cout << "2. Reroute through distributed proxy networks\n";
    std::cout << "3. Let your ICE Breaker auto-handle the intrusion\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You unleash a barrage of counter-protocols.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Digital warfare. Attack and counter-attack.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The firewall buckles under the assault.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You route your intrusion through a dozen proxies.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The firewall loses track of the source.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Confusion creates openings. You slip through.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You let the ICE Breaker do its work.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Military-grade algorithms engage automatically.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The tool earned its reputation. The wall cracks.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n\n";
    std::cout << "[LAYER 1 BYPASSED]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "\n";
    TextEffects::typewriter("First barrier down. But there are more.", TextSpeed::NORMAL);
    std::cout << "\n";

    waitForEnter();
}

void Act3Manager::decryptionStage2() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         LAYER 2: DEEPER DEFENSES\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("The encryption fights harder now.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Multi-factor authentication. Neural locks. Quantum keys.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Whatever's in here, they REALLY don't want it found.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::cout << "Next approach:\n\n";
    std::cout << "1. Brute force through remaining layers\n";
    std::cout << "2. Exploit known backdoor vulnerabilities\n";
    std::cout << "3. Use social engineering attack vectors\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("Raw computational power. No finesse.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("You throw every processor cycle at the problem.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Heat. Fan noise. But it's working.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("Every system has flaws. You find them.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("Unpatched vulnerabilities. Legacy code.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("You exploit the gaps in their armor.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You craft false authentication credentials.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The system thinks you're authorized personnel.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("It opens the doors for you willingly.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n\n";
    std::cout << "[LAYER 2 BYPASSED]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    std::cout << "[LAYER 3 BYPASSED]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "\n";
    TextEffects::typewriter("Firewalls crumble. Protocols break.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("You're close now. One more barrier.", TextSpeed::NORMAL);
    std::cout << "\n";

    waitForEnter();
}

void Act3Manager::decryptionStage3() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         LAYER 3: FINAL BARRIER\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("One last firewall.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("This one is different. Adaptive. Learning. Intelligent.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("It's fighting back in real-time.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::cout << "Final push:\n\n";
    std::cout << "1. Overload the system with simultaneous requests\n";
    std::cout << "2. Inject polymorphic code that adapts as it spreads\n";
    std::cout << "3. Direct neural handshake (risky but fast)\n";

    int choice = getChoice(1, 3);

    std::cout << "\n";

    switch (choice) {
    case 1:
        TextEffects::typewriter("You flood the system. Thousands of requests.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The AI tries to adapt, but can't handle the volume.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("It collapses under its own weight.", TextSpeed::NORMAL);
        break;

    case 2:
        TextEffects::typewriter("You release code that changes as it moves.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("The firewall can't predict the next mutation.", TextSpeed::NORMAL);
        std::cout << "\n";
        TextEffects::typewriter("It's fighting a ghost. You win.", TextSpeed::NORMAL);
        break;

    case 3:
        TextEffects::typewriter("You jack directly into the neural interface.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("Your mind against the AI. Pure thought-speed combat.", TextSpeed::FAST);
        std::cout << "\n";
        TextEffects::typewriter("The human element. Unpredictable. You overwhelm it.", TextSpeed::NORMAL);
        break;
    }

    std::cout << "\n\n";
    TextEffects::typewriter("The barrier SHATTERS.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Data floods your screen.", TextSpeed::FAST);
    std::cout << "\n";
}

//Conspiracy Reveal
void Act3Manager::revealConspiracy() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "     PROJECT GHOSTLIGHT - ULTRA CLASSIFIED\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("SUBJECT: Memory Modification Initiative", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("STATUS: Operational - Global Scale", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("FACILITIES: 47 Active Sites Worldwide", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         OPERATION SUMMARY\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("\"Unwilling subjects identified and extracted...\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Neural patterns rewritten using proprietary technology...\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Memories replaced with corporate-approved narratives...\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Subjects returned to society as compliant assets...\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         APPLICATIONS\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("- Witness memory erasure (corporate crime cover-ups)", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("- Activist neutralization (rewrite to loyal citizens)", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("- Whistleblower prevention (pre-emptive modification)", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("- Sleeper agent creation (hidden programming)", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You feel sick.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("This isn't just surveillance.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("This is identity murder.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("They're erasing people's MINDS.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "    MODIFICATION QUEUE - PRIORITY TARGETS\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "TANAKA, YUKI - JOURNALIST - SCHEDULED\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "RODRIGUEZ, MARIA - ACTIVIST - SCHEDULED\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "CHEN, DAVID - WHISTLEBLOWER - IN PROGRESS\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    std::cout << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "\n";
    std::cout << "RUNNER - UNAUTHORIZED DATA ACCESS - HIGH PRIORITY\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "\n";
    TextEffects::typewriter("Your name.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("They're coming for you.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         PERSONNEL FILE\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("You keep scrolling. Another name catches your eye.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "YAMAMOTO, JIN\n";
    std::cout << "DESIGNATION: Memory Technician #156\n";
    std::cout << "STATUS: Fractured Conditioning - Partial Recall\n";
    std::cout << "THREAT LEVEL: Critical\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "NOTE: Subject exhibits signs of recovered memories.\n";
    std::cout << "      Original personality emerging through conditioning.\n";
    std::cout << "      Recommend immediate termination.\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("Jin.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("They did it to him.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("That's why he defected... isn't it?", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("Or is his rebellion just more programming?", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();
}

//Confrontation with Jin
void Act3Manager::fixerConfrontation() {
    clearScreen();

    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "[KNOCK KNOCK KNOCK]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Three sharp raps on your door.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("You know that rhythm.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    TextEffects::typewriter("Your hand moves toward your weapon--", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Runner, it's me. Open up. Now.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("Jin's voice.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You open the door.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Jin pushes inside quickly. Locks the door behind him.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Checks the window. Scans the street below.", TextSpeed::FAST);
    std::cout << "\n\n";

    TextEffects::typewriter("He looks exhausted. Older than you remember.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    TextEffects::typewriter("\"I see you decrypted it,\" he says,", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("eyeing your terminal.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("The files are still on screen.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Your name. His name.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("He sits down heavily in your only chair.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Yeah. I saw my file years ago.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"That's when I knew.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Memory Technician #156.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("He laughs bitterly.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I don't even know if 'Jin Yamamoto' is my real name.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"Five years I've been running this operation.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"Building a network. Stealing data. Fighting back.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"But every day I wonder...\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("He looks at you directly.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"Am I choosing this? Or did they program me", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("to THINK I'm rebelling?\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Maybe I'm still working for them.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"Maybe this whole resistance is part of their plan.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Maybe I led you here to get caught.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("He shakes his head.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I don't know what's real anymore.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Silence.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("Rain patters on the window.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1200));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"But here's what I DO know,\" he says.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Corps are outside. Searching the district.\"", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("\"They'll find this place in minutes.\"", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"You've got the evidence. The files.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"Proof of what they're doing.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("He stands. Looks at you.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"So we decide. Right now. What do we do with it?\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();
}

void Act3Manager::displayChoiceMenu() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "              THE CHOICE\n";
    std::cout << "================================================\n\n";

    TextEffects::typewriter("Jin waits for your answer.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("Outside: sirens in the distance.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("The corps are closing in.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You have the data. The truth about", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("memory modification. The evidence.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("What do you do?", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "================================================\n\n";

    std::cout << "[1] EXPOSE THE TRUTH\n";
    std::cout << "    Upload everything to the global net.\n";
    std::cout << "    The world will know what they've done.\n";
    std::cout << "    No going back.\n\n";

    std::cout << "[2] SELL THE DATA\n";
    std::cout << "    Find a buyer. Get paid. Disappear.\n";
    std::cout << "    The truth stays hidden, but you survive rich.\n\n";

    std::cout << "[3] TRUST THE FIXER\n";
    std::cout << "    \"What's YOUR plan, Jin?\"\n";
    std::cout << "    Let him handle it. Unknown outcome.\n\n";

    std::cout << "[4] DESTROY EVERYTHING\n";
    std::cout << "    Burn the data. Erase your trail. Vanish.\n";
    std::cout << "    The truth dies, but so does your past.\n\n";

    std::cout << "================================================\n\n";

    TextEffects::typewriter("This choice cannot be undone.", TextSpeed::SLOW);
    std::cout << "\n\n";

    int choice = getChoice(1, 4);

    playEnding(choice);
}

//Controls which ending is played
void Act3Manager::playEnding(int choice) {
    switch (choice) {
    case 1:
        ending1_ExposeTheTruth();
        break;
    case 2:
        ending2_SellTheData();
        break;
    case 3:
        ending3_TrustTheFixer();
        break;
    case 4:
        ending4_DestroyEverything();
        break;
    }
}

//Endings

void Act3Manager::ending1_ExposeTheTruth() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ENDING 1: EXPOSE THE TRUTH\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You turn to your terminal.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"You're sure?\" Jin asks.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You nod.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("\"The world deserves to know.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Your fingers fly across the keyboard.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("Upload protocols engage.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The data fragments. Replicates. Spreads.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Across a thousand networks simultaneously.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "[UPLOADING TO DARKNET NODES...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[DISTRIBUTING TO NEWS NETWORKS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[POSTING TO ACTIVIST FORUMS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[SEEDING TORRENT TRACKERS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "\n";
    std::cout << "[UPLOAD COMPLETE]\n";
    std::cout << "[PROPAGATION: UNSTOPPABLE]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("Everywhere. All at once.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Jin's face pales.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"It's done. No stopping it now.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Your terminal erupts with alerts.", TextSpeed::FAST);
    std::cout << "\n";
    TextEffects::typewriter("The story is spreading like wildfire.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "BREAKING: MEGACORP CONSPIRACY EXPOSED\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "MEMORY MODIFICATION FACILITIES REVEALED\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "LEAKED DOCUMENTS CONFIRM PROJECT GHOSTLIGHT\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "GLOBAL OUTRAGE AS EVIDENCE SURFACES\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"They're going to come for us,\" Jin says quietly.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"With everything they have.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You stand up. Check your gear.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"Then we'd better not be here.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("He nods. Pulls out a burner phone.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I know people. Resistance cells. Safe houses.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"We can disappear. Go underground.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("He looks at you seriously.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"You'll never have a normal life again, Runner.\"", TextSpeed::SLOW);
    std::cout << "\n";
    TextEffects::typewriter("\"You know that?\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You look at the screen one last time.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("The truth is out there now.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("People are already organizing. Protesting.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The corps are scrambling to respond.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("\"Some things are worth more than comfort,\" you say.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Jin allows himself a small smile.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"Let's go.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();
 
    //AFTERMATH
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "              THREE MONTHS LATER\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("The data leak ignited a global movement.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Within weeks, protests filled the streets", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("of every major city.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The corporations scrambled to contain the damage,", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("but it was too late.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Project Ghostlight was shut down.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Arrests were made.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("International laws were passed.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("But the corps are patient. Powerful.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("They'll rebuild. Rebrand. Try again.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Different name. Same game.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("And you?", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You disappeared into the underground resistance.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("A ghost yourself.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    //EPILOGUE
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "                 EPILOGUE\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Hunted. Wanted. Never safe.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You move from safe house to safe house.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("New identity every few months.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Always looking over your shoulder.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("But you're free.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("And every morning, you wake up knowing:", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You told the truth when it mattered.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You saved lives.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You made the world a little less dark.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    waitForEnter();


    clearScreen();

    std::cout << "\n\n\n";
    std::cout << "================================================\n";
    std::cout << "           THANK YOU FOR PLAYING\n";
    std::cout << "================================================\n\n";
    std::cout << "              CYBERPUNK RUNNER\n";
    std::cout << "         A Text Adventure by Liam Bennett\n\n";
    std::cout << "================================================\n\n";
    std::cout << "            ENDING 1 of 4 ACHIEVED:\n";
    std::cout << "              EXPOSE THE TRUTH\n\n";
    std::cout << "================================================\n\n\n";


    std::cout << "What would you like to do?\n\n";
    std::cout << "1. Play Again\n";
    std::cout << "2. Quit\n";

    int choice = getChoice(1, 2);

    if (choice == 1) {
        
        waitForEnter();
    }

    exit(0);
}

void Act3Manager::ending2_SellTheData() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ENDING 2: SELL THE DATA\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You look at Jin.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I know someone. A buyer.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Jin's jaw tightens.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"You're making a mistake.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You turn to your terminal.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"Maybe. But I'm making it rich.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You place the call through encrypted channels.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The negotiation is swift.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Professional. Cold.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "[BUYER IDENTIFIED: UNDERGROUND BROKER NETWORK]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[OFFER: 5,000,000 CREDITS]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[UNTRACEABLE ACCOUNT]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[IMMEDIATE TRANSFER]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You accept.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("The data changes hands in encrypted packets.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "[TRANSFER COMPLETE]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    std::cout << "[5,000,000 CREDITS DEPOSITED]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    std::cout << "[TRANSACTION FINALIZED]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You stare at the number on your screen.", TextSpeed::SLOW);
    std::cout << "\n\n";

    TextEffects::typewriter("Five million credits.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("More than you'd earn in ten lifetimes.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Jin stands.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Enjoy it while it lasts.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"That data will be used to blackmail rivals.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"To consolidate power.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"The modification won't stop.\"", TextSpeed::SLOW);
    std::cout << "\n";
    TextEffects::typewriter("\"It'll just change ownership.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("He walks to the door. Pauses.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"I thought you were different.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("Then he's gone.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("The door closes.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You're alone with your fortune.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    //AFTERMATH
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "              ONE YEAR LATER\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You retired to a private island.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("No extradition treaty. No questions asked.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The money bought you everything you ever wanted.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Luxury. Security. Peace.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("But the news feeds tell a different story.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("The brokers used your data for leverage.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Hostile takeovers. Blackmail. Assassinations.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Within a year, a single syndicate controlled", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("60% of the underground economy.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Project Ghostlight continued.", TextSpeed::SLOW);
    std::cout << "\n";
    TextEffects::typewriter("Under new management.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("The harvesting never stopped.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("If anything, it got worse.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    //EPILOGUE
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "                 EPILOGUE\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You live in paradise.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("But every night, you see their faces.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("The people on the list.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The ones you could have saved.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("TANAKA, YUKI - Status: Modified", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("RODRIGUEZ, MARIA - Status: Modified", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("CHEN, DAVID - Status: Terminated", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You sold the truth for gold.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("And gold doesn't wash away blood.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    waitForEnter();


    clearScreen();

    std::cout << "\n\n\n";
    std::cout << "================================================\n";
    std::cout << "           THANK YOU FOR PLAYING\n";
    std::cout << "================================================\n\n";
    std::cout << "              CYBERPUNK RUNNER\n";
    std::cout << "         A Text Adventure by [Your Name]\n\n";
    std::cout << "================================================\n\n";
    std::cout << "            ENDING 2 of 4 ACHIEVED:\n";
    std::cout << "              SELL THE DATA\n\n";
    std::cout << "================================================\n\n\n";

    std::cout << "What would you like to do?\n\n";
    std::cout << "1. Play Again\n";
    std::cout << "2. Quit\n";

    int choice = getChoice(1, 2);

    if (choice == 1) {
        waitForEnter();
    }

    exit(0);
}

void Act3Manager::ending3_TrustTheFixer() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ENDING 3: TRUST THE FIXER\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"What's YOUR plan, Jin?\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("He looks surprised. Then a slight smile.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"You're asking me?\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You nod.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"You've kept me alive this far.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"You know this world better than I do.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Jin nods slowly.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Alright. Here's what we do.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("He pulls out a burner phone.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I've got contacts. Underground network.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"People who've been fighting the corps for decades.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"We use this data as leverage,\" he explains.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Blackmail the execs. Force a treaty.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"They agree to shut down Ghostlight,\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"leave the resistance alone, or we leak everything.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"It's not perfect,\" he admits.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"The corps stay in power. They keep their wealth.\"", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("\"But we save lives. Buy time.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"Sometimes survival is the best you can hope for.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You consider it.", TextSpeed::NORMAL);
    std::cout << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    TextEffects::typewriter("\"And us?\" you ask.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"We join the resistance. Keep watching. Keep fighting.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"One shadow war at a time.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You extend your hand.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"Let's do it.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Jin shakes it firmly.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Over the next few hours, Jin coordinates with his network.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Encrypted calls. Dead drops. Old codes.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "[CONTACTING RESISTANCE CELLS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[ESTABLISHING SECURE CHANNELS...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[INITIATING NEGOTIATIONS...]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Three days of tense negotiation.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The corps send representatives. So does the resistance.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Threats. Counter-threats. Ultimatums.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Finally, a deal is reached.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    //AFTERMATH
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "              THE TREATY\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Project Ghostlight is suspended.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The modification list is purged.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Existing facilities enter \"standby mode.\"", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("In exchange, the data stays buried.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("The resistance gets breathing room.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("It's not victory.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("But it's not defeat.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    //EPILOGUE
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "                 EPILOGUE\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You became a shadowrunner for the resistance.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The corps still rule the world.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("But there are limits now.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Boundaries they won't cross,", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("as long as the blackmail data exists.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("An uneasy peace.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You and Jin run operations together.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Stealing data. Exposing crimes. Saving who you can.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("It's not the glorious revolution.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("It's not the happy ending.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("But it's honest work.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("And in a world of neon and lies,", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("that's worth something.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    waitForEnter();

    clearScreen();

    std::cout << "\n\n\n";
    std::cout << "================================================\n";
    std::cout << "           THANK YOU FOR PLAYING\n";
    std::cout << "================================================\n\n";
    std::cout << "              CYBERPUNK RUNNER\n";
    std::cout << "         A Text Adventure by [Your Name]\n\n";
    std::cout << "================================================\n\n";
    std::cout << "            ENDING 3 of 4 ACHIEVED:\n";
    std::cout << "              TRUST THE FIXER\n\n";
    std::cout << "================================================\n\n\n";

    std::cout << "What would you like to do?\n\n";
    std::cout << "1. Play Again\n";
    std::cout << "2. Quit\n";

    int choice = getChoice(1, 2);

    if (choice == 1) {
        waitForEnter();
    }

    exit(0);
}

void Act3Manager::ending4_DestroyEverything() {
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "         ENDING 4: DESTROY EVERYTHING\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"Neither.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Jin looks at you.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"What?\"", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You pull the data chip from the terminal.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    TextEffects::typewriter("\"I burn it. I wipe my identity. I leave.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"Runner, that's--\"", TextSpeed::FAST);
    std::cout << "\n\n";

    TextEffects::typewriter("\"My choice.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You snap the chip in half.", TextSpeed::FAST);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "[CRACK]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Then you turn to your terminal.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    std::cout << "[INITIATING SECURE WIPE...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[SEVEN-PASS MILITARY OVERWRITE...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[DESTROYING ALL DATA...]\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[WIPING SYSTEM LOGS...]\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Nothing recoverable.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Jin watches in silence.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"The corps will keep harvesting people,\" he says quietly.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"I know.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"More will die.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"I know.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You open a hidden safe in your wall.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Fake IDs. Passports. Clean identities.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("Untraceable credits.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You've been preparing for this.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("\"Then why?\" Jin asks.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You look at him.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"Because I'm not a hero.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"I'm a survivor.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"And I'm done with this city.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("You head for the door.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Jin doesn't try to stop you.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("\"Good luck, Runner.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("\"You're going to need it.\"", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("You don't look back.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    //AFTERMATH
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "              SIX MONTHS LATER\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You disappeared.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("New name. New city. New life.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("The corps never found you.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("No trail. No evidence. No target.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You became a ghost.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Project Ghostlight continued.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("The harvesting never stopped.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Jin and his resistance fought on without you.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Smaller victories. Harder battles.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("But you were gone.", TextSpeed::SLOW);
    std::cout << "\n\n";

    waitForEnter();

    //EPILOGUE
    clearScreen();

    std::cout << "\n================================================\n";
    std::cout << "                 EPILOGUE\n";
    std::cout << "================================================\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("You live in a small apartment in a quiet district.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Far from Neo-Tokyo. Far from the corps.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("You work a normal job. 9 to 5. Paycheck to paycheck.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("No running. No corps. No danger.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("Sometimes you see the news.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    TextEffects::typewriter("Protests. Arrests. The resistance still fighting.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Sometimes you wonder if you should have stayed.", TextSpeed::SLOW);
    std::cout << "\n";
    TextEffects::typewriter("Made the hard choice.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    waitForEnter();

    clearScreen();

    std::cout << "\n";
    TextEffects::typewriter("But you're alive.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("And you're free.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    TextEffects::typewriter("No one hunting you. No one modifying your memories.", TextSpeed::NORMAL);
    std::cout << "\n";
    TextEffects::typewriter("No corp pulling your strings.", TextSpeed::NORMAL);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    TextEffects::typewriter("Maybe, in a world like this,", TextSpeed::SLOW);
    std::cout << "\n";
    TextEffects::typewriter("that's all anyone can really ask for.", TextSpeed::SLOW);
    std::cout << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    waitForEnter();

    clearScreen();

    std::cout << "\n\n\n";
    std::cout << "================================================\n";
    std::cout << "           THANK YOU FOR PLAYING\n";
    std::cout << "================================================\n\n";
    std::cout << "              CYBERPUNK RUNNER\n";
    std::cout << "         A Text Adventure by [Your Name]\n\n";
    std::cout << "================================================\n\n";
    std::cout << "            ENDING 4 of 4 ACHIEVED:\n";
    std::cout << "              DESTROY EVERYTHING\n\n";
    std::cout << "================================================\n\n\n";

    std::cout << "What would you like to do?\n\n";
    std::cout << "1. Play Again\n";
    std::cout << "2. Quit\n";

    int choice = getChoice(1, 2);

    if (choice == 1) {
        waitForEnter();
    }

    exit(0);
}