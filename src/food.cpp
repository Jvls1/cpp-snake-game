#include <random>
#include "../include/food.hpp"

Food::Food(int maxX, int maxY) {
  generate(maxX, maxY);
}

void Food::generate(int maxX, int maxY) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribX(1, maxX - 2);
  std::uniform_int_distribution<> distribY(1, maxY - 2);
  x = distribX(gen);
  y = distribY(gen);
}

std::pair<int, int> Food::getPosition() const {
  return {x, y};
}
