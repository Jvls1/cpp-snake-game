#ifndef FOOD_HPP
#define FOOD_HPP

#include <utility>

class Food {
private:
    int x, y;

public:
    Food(int maxX, int maxY);
    
    void generate(int maxX, int maxY);
    std::pair<int, int> getPosition() const;
};

#endif //FOOD_HPP
