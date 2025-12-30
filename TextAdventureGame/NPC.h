#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>

class Player;

/**
 * NPC Base Class
 * Represents characters the player can interact with
 */
class NPC {
protected:
    std::string name;
    std::string description;
    std::vector<std::string> dialogue;  
    int currentDialogueLine;
    bool hasMoreDialogue;               

public:
    //Constructor
    NPC(const std::string& npcName,
        const std::string& npcDesc);

    //Virtual destructor
    virtual ~NPC();

    //Adds dialogue lines (single or multiple)
    void addDialogue(const std::string& line);
    void addDialogue(const std::vector<std::string>& lines);

    //Getters
    std::string getName() const;
    std::string getDescription() const;
    bool canTalk() const;

    //Main interaction 
    virtual void talk(Player* player);

    //Displays NPC info
    void display() const;

    //Reset dialogue to beginning
    void resetDialogue();
};

#endif