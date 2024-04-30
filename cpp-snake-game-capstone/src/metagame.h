#ifndef METAGAME_H
#define METAGAME_H

#include "SDL.h"
#include <string>
#include <iostream>
#include <memory> // Include for smart pointers

class MetaGame
{
public:
    MetaGame() : platformUsed(getPlatform()), dynamicData(nullptr)
    {
    }

    // Copy constructor
    MetaGame(const MetaGame& other)
        : platformUsed(other.platformUsed), dynamicData(nullptr)
    {
        if (other.dynamicData) {
            dynamicData = new int[5]; // Just an example allocation for demonstration
            std::copy(other.dynamicData, other.dynamicData + 5, dynamicData);
        }
    }

    // Copy assignment operator
    MetaGame& operator=(const MetaGame& other)
    {
        if (this != &other) {
            platformUsed = other.platformUsed;
            delete[] dynamicData;
            dynamicData = nullptr;
            if (other.dynamicData) {
                dynamicData = new int[5]; // Just an example allocation for demonstration
                std::copy(other.dynamicData, other.dynamicData + 5, dynamicData);
            }
        }
        return *this;
    }

    // Move constructor
    MetaGame(MetaGame&& other) noexcept
        : platformUsed(std::move(other.platformUsed)), dynamicData(other.dynamicData)
    {
        other.dynamicData = nullptr;
    }

    // Move assignment operator
    MetaGame& operator=(MetaGame&& other) noexcept
    {
        if (this != &other) {
            platformUsed = std::move(other.platformUsed);
            delete[] dynamicData;
            dynamicData = other.dynamicData;
            other.dynamicData = nullptr;
        }
        return *this;
    }

    /**
     * Sets the user's system platform to the private variable platformUsed.
     * Returns the platform as a std::string.
     */
    std::string getPlatform(); // No need to return by reference

    void printPlatform();

    // Destructor to clean up resources
    ~MetaGame();

    // Function to demonstrate dynamically allocated memory
    void allocateDynamicData(int size);

private:
    std::string platformUsed;
    int* dynamicData; // Example of dynamically allocated memory
};

// Using move semantics to return platform
std::string MetaGame::getPlatform()
{
    const char *platform = SDL_GetPlatform();
    return std::string(platform); // Use move semantics
}

void MetaGame::printPlatform()
{
    if (!platformUsed.empty())
        std::cout << "Platform Detected: " << platformUsed << std::endl;
    else
        std::cout << "No System Platform Detected." << std::endl;
}

// Destructor definition
MetaGame::~MetaGame()
{
    delete[] dynamicData; // Clean up dynamically allocated memory
    dynamicData = nullptr; // Optional: Set pointer to null after deletion
}

void MetaGame::allocateDynamicData(int size)
{
    dynamicData = new int[size]; // Allocate dynamic memory
    std::cout << "Allocated " << size << " integers dynamically." << std::endl;
}

#endif
