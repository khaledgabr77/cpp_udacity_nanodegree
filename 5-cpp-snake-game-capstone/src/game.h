#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void UpdateStartSpeed();
	// Set game over status
	void SetGameOver(bool gameOver);
  void SetSnakeDirection(Snake::Direction direction);

	// Check if the game is over
	bool IsGameOver() const;
private:
  Snake snake;
  SDL_Point food;
  bool gameOver;
  Snake::Direction snakeDirection;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};



#endif
