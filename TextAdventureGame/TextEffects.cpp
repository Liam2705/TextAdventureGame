#include "TextEffects.h"
#include <iostream>
#include <thread>
#include <chrono>

//Initialize static members
bool TextEffects::skipEnabled = true;
TextSpeed TextEffects::currentSpeed = TextSpeed::NORMAL;

/**
 * TYPEWRITER EFFECT
 * Prints text one character at a time with configurable speed
 */
void TextEffects::typewriter(const std::string& text, TextSpeed speed, bool newline) {
    //If speed is INSTANT, just print normally
    if (speed == TextSpeed::INSTANT) {
        std::cout << text;
        if (newline) std::cout << "\n";
        std::cout.flush();
        return;
    }

    int delayMs = static_cast<int>(speed);

    for (char c : text) {
        std::cout << c << std::flush;

        //Sleep for the delay
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }

    if (newline) {
        std::cout << "\n";
    }
    std::cout.flush();
}

/**
 * PRINT INSTANT
 * No animation
 */
void TextEffects::printInstant(const std::string& text, bool newline) {
    std::cout << text;
    if (newline) {
        std::cout << "\n";
    }
    std::cout.flush();
}

/**
 * DISPLAY ACT TRANSITION
 * Slow act display when a new act is triggered
 */
void TextEffects::displayActTransition(int actNumber,
    const std::string& actTitle,
    const std::string& subtitle) {
    clearScreen();

    //Top spacing
    printInstant("\n\n\n\n");

    //Top border
    printInstant("============================================================");
    printInstant("");

    //Act number
    std::string actText = "ACT " + std::to_string(actNumber);
    printInstant("                        ", false);
    typewriter(actText, TextSpeed::SLOW, true);

    printInstant("");

    //Act title
    size_t titlePadding = (60 - actTitle.length()) / 2;
    for (size_t i = 0; i < titlePadding; i++) {
        printInstant(" ", false);
    }
    typewriter(actTitle, TextSpeed::VERY_SLOW, true);

    //Subtitle if provided
    if (!subtitle.empty()) {
        printInstant("");
        size_t subtitlePadding = (60 - subtitle.length()) / 2;
        for (size_t i = 0; i < subtitlePadding; i++) {
            printInstant(" ", false);
        }
        typewriter(subtitle, TextSpeed::NORMAL, true);
    }

    printInstant("");

    //Bottom border
    printInstant("============================================================");

    //Bottom spacing
    printInstant("\n\n");

    //Wait for player
    waitForEnter();
    clearScreen();
}

/**
 * WAIT FOR ENTER
 * Pauses and waits for player to input
 */
void TextEffects::waitForEnter(const std::string& prompt) {
    printInstant(prompt, false);
    std::cin.get();
}

/**
 * CLEAR SCREEN
 * Clears all text from the screen
 */
void TextEffects::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * SETTINGS
 * Settings to modify various aspects of the text effects
 */
void TextEffects::setSpeed(TextSpeed speed) {
    currentSpeed = speed;
}

void TextEffects::enableSkip(bool enable) {
    skipEnabled = enable;
}

TextSpeed TextEffects::getSpeed() {
    return currentSpeed;
}