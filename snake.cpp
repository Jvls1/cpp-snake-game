#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <vector>

const int INITIAL_DIRECTION = KEY_UP;

int maxX, maxY;
int currentX, currentY;
int foodX, foodY;
int currentDirection = INITIAL_DIRECTION;
int score = 0;
bool gameOver = false;
std::vector<std::pair<int, int>> snake;

void processInput(int ch);
void updateGame(); 
void render();
int generateRandomInt(int max);

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  timeout(100); 
  curs_set(0);

  getmaxyx(stdscr, maxY, maxX);
  const int START_Y = maxY / 2;
  const int START_X = maxX / 2;
  
  snake = {{START_Y, START_X}};

  foodY = generateRandomInt(maxY);
  foodX = generateRandomInt(maxX);
   
  while (!gameOver) {
    processInput(getch());
    updateGame();
    render();
    usleep(100000);
  }
  endwin();

  return 0;
}

void processInput(int input) {
  if (input == KEY_F(1))
    gameOver = true;
  switch (input) {
    case KEY_UP:
      if (currentDirection != KEY_DOWN)
        currentDirection = KEY_UP;
      break;
    case KEY_DOWN:
      if (currentDirection != KEY_UP)
        currentDirection = KEY_DOWN;
      break;
    case KEY_LEFT:
      if (currentDirection != KEY_RIGHT)
        currentDirection = KEY_LEFT;
      break;
    case KEY_RIGHT:
      if (currentDirection != KEY_LEFT)
        currentDirection = KEY_RIGHT;
      break;
  }
}

void updateGame() {
  for (size_t i = snake.size() - 1; i > 0; --i) {
    snake[i] = snake[i - 1];
  }

  switch (currentDirection) {
    case KEY_UP:
      snake[0].first--;
      break;
    case KEY_DOWN:
      snake[0].first++;
      break;
    case KEY_LEFT:
      snake[0].second--;
      break;
    case KEY_RIGHT:
      snake[0].second++;
      break;
  }

  if (snake[0].first == foodY and snake[0].second == foodX) {
    score += 10;
    snake.push_back(snake.back());
    foodX = generateRandomInt(maxX);
    foodY = generateRandomInt(maxY);
  }
  if (snake[0].first < 0 || snake[0].first >= maxY || snake[0].second < 0 || snake[0].second > maxX) {
    gameOver = true;
  }
  
}

void renderScore() {
  mvprintw(0, 2, "Score: %i", score);
}

void renderSnake() {
  mvprintw(snake[0].first, snake[0].second, "%c", 'O');
  for (size_t i = 1; i < snake.size(); ++i) {
    mvprintw(snake[i].first, snake[i].second, "o");
  }
}

void renderFood() {
  mvprintw(foodX, foodY, "%c", 'F');
}

void render() {
  clear();
  renderScore();
  renderSnake();
  renderFood();
  refresh(); 
}

int generateRandomInt(int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  int min = 1; 
  std::uniform_int_distribution<> distrib(min, max -2);
  return distrib(gen);
}
