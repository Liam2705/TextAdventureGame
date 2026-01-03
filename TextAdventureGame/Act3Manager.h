#ifndef ACT3MANAGER_H
#define ACT3MANAGER_H

#include <string>
#include <vector>

//Forward declarations
class Player;
class GameEngine;

/**
 * Handles all the Act 3 specific sequences
 * Manages: Chase sequences, decryption, confrontation, choice menu, endings
 * Provides custom scenes and player interaction for Act 3 specifically
 */
class Act3Manager {
private:
    bool act3Active;
    bool chaseComplete;
    bool decryptionComplete;
    bool finaleStarted;

    GameEngine* gameEngine;

    //Chase sequence
    void runChaseSequence(Player* player);
    void chaseStage1_ServerRoom();
    void chaseStage2_Lobby();
    void chaseStage3_PlazaEntrance();
    void chaseStage4_Streets();
    void chaseStage5_Transit();
    void chaseStage6_Downtown();
    void chaseFinal_Escape();

    //Decryption sequence
    void runDecryptionSequence();
    void decryptionStage1();
    void decryptionStage2();
    void decryptionStage3();
    void revealConspiracy();

    //Confrontation
    void fixerConfrontation();

    //Choice and endings
    void displayChoiceMenu();
    void playEnding(int choice);
    void ending1_ExposeTheTruth();
    void ending2_SellTheData();
    void ending3_TrustTheFixer();
    void ending4_DestroyEverything();

    //Helper functions
    int getChoice(int min, int max);
    void waitForEnter(const std::string& prompt = "\n[Press Enter to continue...]");
    void clearScreen();

public:
    //Constructor
    Act3Manager(GameEngine* engine);

    //Controls for Act 3
    void startAct3();
    bool isAct3Active() const;
    bool isChaseComplete() const;

    //Called when player enters apartment during Act 3
    void startFinaleSequence(Player* player);
};

#endif
