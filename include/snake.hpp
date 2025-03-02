#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <ncurses.h>

class Snake {
private:
    int direction;
    std::vector<std::pair<int, int>> body;

public:
    Snake(int initialX, int initialY);
    
    std::vector<std::pair<int, int>> getBody();
    void changeDirection(int newDirection);
    void move();
    void grow();
    bool checkWallCollision(int maxX, int maxY);
    bool checkSelfCollision();
};

#endif //SNAKE_HPP
