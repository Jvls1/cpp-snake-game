#include <ncurses.h>
#include <unistd.h>
#include "../include/game.hpp"

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  timeout(100);
  curs_set(0);

  int maxX, maxY;
  getmaxyx(stdscr, maxX, maxY);

  Game game(maxX, maxY);

  while (!game.isGameOver()) {
    game.processInput(getch());
    game.update();
    game.render();
    usleep(100000);
  }

  endwin();
  return 0;
}
