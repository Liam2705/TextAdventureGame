#include "NPC.h"
#include "Player.h"
#include "TextEffects.h"
#include <iostream>

NPC::NPC(const std::string& npcName, const std::string& npcDesc)
    : name(npcName),
    description(npcDesc),
    currentDialogueLine(0),
    hasMoreDialogue(true) {

    std::cout << "NPC CREATED: " << name << "\n";
}

NPC::~NPC() {
    std::cout << "NPC DESTROYED: " << name << "\n";
}

//Adds a single dialogue line
void NPC::addDialogue(const std::string& line) {
    dialogue.push_back(line);
}

//Adds multiple dialogue lines
void NPC::addDialogue(const std::vector<std::string>& lines) {
    for (const std::string& line : lines) {
        dialogue.push_back(line);
    }
}

//Helper function to get player input during dialogue with NPC
char NPC::getDialogueInput() {
    std::string input;
    std::getline(std::cin, input);

    //If player presses enter
    if (input.empty()) {
        return '\n';
    }

    //Otherwise return the first character input by player ('Q' or 'q')
    return input[0];
}

//Getters
std::string NPC::getName() const {
    return name;
}

std::string NPC::getDescription() const {
    return description;
}

bool NPC::canTalk() const {
    return !dialogue.empty() && hasMoreDialogue;
}

//Main talk interaction
void NPC::talk(Player* player) {
    if (dialogue.empty()) {
        std::cout << "\n" << name << " has nothing to say.\n";
        return;
    }

    //Shows NPC header
    std::cout << "\n=======================================\n";
    std::cout << "  " << name << "\n";
    std::cout << "=======================================\n\n";

    //Tracks if this is a new conversation or continuing
    bool isNewConversation = (currentDialogueLine == 0);

    if (!isNewConversation && currentDialogueLine < dialogue.size()) {
        std::cout << "(Continuing conversation...)\n\n";
    }

    //Loop through remaining dialogue lines
    for (int i = currentDialogueLine; i < dialogue.size(); i++) {
        //Displays current line
        TextEffects::typewriter(dialogue[i], TextSpeed::NORMAL);
        std::cout << "\n";

        //Update progress
        currentDialogueLine = i + 1;

        //Check if there's more dialogue
        if (currentDialogueLine < dialogue.size()) {
            //Show prompt
            std::cout << "\n> Continue (ENTER) | Exit (Q): ";

            //Get player input
            char input = getDialogueInput();

            //Check if player wants to exit
            if (input == 'q' || input == 'Q') {
                std::cout << "\n(Conversation paused)\n";
                return;  //Exit function, saves progress
            }

            std::cout << "\n";
        }
    }

    //All dialogue has been shown
    hasMoreDialogue = false;
    std::cout << "\n========================================\n";
    std::cout << "(" << name << " has nothing more to say.)\n";
    std::cout << "========================================\n";
}

//Displays NPC info (when looking around at a location)
void NPC::display() const {
    std::cout << name << " - " << description;
    if (!hasMoreDialogue) {
        std::cout << " (already talked)";
    }
    std::cout << "\n";
}

//Reset dialogue
void NPC::resetDialogue() {
    currentDialogueLine = 0;
    hasMoreDialogue = true;
}