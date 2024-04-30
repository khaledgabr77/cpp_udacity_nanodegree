#include <iostream>
#include <thread>
#include <condition_variable>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "metagame.h"

int main()
{
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    // Metagame stats
    MetaGame stats;
    stats.printPlatform();

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.UpdateStartSpeed();

    // Synchronization primitives
    std::mutex mutex;
    std::condition_variable cv;
    bool gameFinished = false;

    // Function to run game loop
    auto gameLoop = [&]() {
        while (!gameFinished) {
            std::unique_lock<std::mutex> lock(mutex);
            game.Run(controller, renderer, kMsPerFrame);
            cv.wait(lock, [&]() { return game.IsGameOver(); });
            gameFinished = true;
        }
    };

    // Create and run the game loop thread
    std::thread gameThread(gameLoop);

    // Main thread
    controller.HandleInput(game);
    {
        std::lock_guard<std::mutex> lock(mutex);
        cv.notify_one(); // Notify game loop to terminate
    }
    gameThread.join(); // Wait for the game loop thread to finish

    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";

    return 0;
}

