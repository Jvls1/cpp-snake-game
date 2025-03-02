#include <vector>
#include <ncurses.h>
#include "../include/snake.hpp"

Snake::Snake(int initialX, int initialY) {
  body = {{initialX, initialY}};
}

std::vector<std::pair<int, int>> Snake::getBody() {
  return body; 
}

void Snake::changeDirection(int newDirection) {
  if ((direction == KEY_UP && newDirection != KEY_DOWN) ||
    (direction == KEY_DOWN && newDirection != KEY_UP) ||
    (direction == KEY_LEFT && newDirection != KEY_RIGHT) ||
    (direction == KEY_RIGHT && newDirection != KEY_LEFT)) {
    direction = newDirection;
  }   
}

void Snake::move() {
  for (size_t i = body.size() - 1; i > 0; --i) {
    body[i] = body[i - 1];
  }

  switch (direction) {
    case KEY_UP: body[0].first--; break;
    case KEY_DOWN: body[0].first++; break;
    case KEY_LEFT: body[0].second--; break;
    case KEY_RIGHT: body[0].second++; break;
  }
}

void Snake::grow() {
  body.push_back(body.back());
}

bool Snake::checkWallCollision(int maxX, int maxY) {
  return (body[0].first < 0 || body[0].first >= maxX ||
  body[0].second < 0 || body[0].second >= maxY);
}

bool Snake::checkSelfCollision() {
  for (size_t i = 1; i < body.size(); ++i) {
    if (body[i].first == body[0].first && body[i].second == body[0].second) {
      return true;
    }
  }
  return false;
}

