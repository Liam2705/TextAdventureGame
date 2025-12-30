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

    //Shows current dialogue line with animation
    if (currentDialogueLine < dialogue.size()) {
        TextEffects::typewriter(dialogue[currentDialogueLine], TextSpeed::NORMAL);
        currentDialogueLine++;

        //Checks if more dialogue is available
        if (currentDialogueLine >= dialogue.size()) {
            hasMoreDialogue = false;
            std::cout << "\n";
            TextEffects::typewriter("(" + name + " has nothing more to say.)", TextSpeed::FAST);
        }
    }
    else {
        TextEffects::typewriter("(" + name + " has nothing more to say.)", TextSpeed::FAST);
    }

    std::cout << "\n";
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