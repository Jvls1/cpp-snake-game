#ifndef GAME_HPP
#define GAME_HPP

#include "snake.hpp"
#include "food.hpp"
#include <ncurses.h>

class Game {
private:
    int maxX, maxY;
    int score;
    bool gameOver;
    Snake snake;
    Food food;

public:
    Game(int maxX, int maxY);

    void processInput(int input);
    void update();
    void render();
    bool isGameOver() const;
};

#endif //GAME_HPP
