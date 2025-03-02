#include "../include/game.hpp"
#include <ncurses.h>

Game::Game(int maxX, int maxY)
  : maxX(maxX), maxY(maxY), score(0), gameOver(false),
  snake(maxX / 2, maxY / 2), food(maxX, maxY) {}

void Game::processInput(int input) {
  if (input == KEY_F(1)) {
    gameOver = true;
  }
  snake.changeDirection(input);
}

void Game::update() {
  snake.move();

  auto head = snake.getBody()[0];
  auto foodPos = food.getPosition();
  if (head.first == foodPos.first && head.second == foodPos.second) {
    score += 10;
    snake.grow();
    food.generate(maxX, maxY);
  }

  if (snake.checkWallCollision(maxX, maxY)) {
    gameOver = true;
  }
}

void Game::render() {
  clear();
  mvprintw(maxX - 20, 5, "Score: %i", score);

  auto body = snake.getBody();
  mvprintw(body[0].first, body[0].second, "O");
  for (size_t i = 1; i < body.size(); ++i) {
    mvprintw(body[i].first, body[i].second, "o");
  }

  auto foodPos = food.getPosition();
  mvprintw(foodPos.first, foodPos.second, "F");

  refresh();
}

bool Game::isGameOver() const {
  return gameOver;
}
