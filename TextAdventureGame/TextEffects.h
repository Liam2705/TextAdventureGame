#ifndef TEXTEFFECTS_H
#define TEXTEFFECTS_H

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

enum class TextSpeed {
    INSTANT = 0,      //No delay - instant display
    FAST = 15,        //Quick typing (menus, combat)
    NORMAL = 30,      //Standard dialogue speed
    SLOW = 50,        //Story moments
    VERY_SLOW = 80    //Important story moments
};

class TextEffects {
private:
    static bool skipEnabled;
    static TextSpeed currentSpeed;

public:
    //Typewriter effect - prints text character by character
    static void typewriter(const std::string& text,
        TextSpeed speed = TextSpeed::NORMAL,
        bool newline = true);

    //Print instantly (no animation)
    static void printInstant(const std::string& text, bool newline = true);

    //Display act transition screen
    static void displayActTransition(int actNumber,
        const std::string& actTitle,
        const std::string& subtitle = "");

    //Wait for player to press Enter
    static void waitForEnter(const std::string& prompt = "\nPress Enter to continue...");

    //Clear screen
    static void clearScreen();

    //Settings
    static void setSpeed(TextSpeed speed);
    static void enableSkip(bool enable);
    static TextSpeed getSpeed();
};


#endif

