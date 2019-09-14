#include "Engine.hpp"

#define WAIT 50000

AsciiPictures::AsciiPictures(void) {
}

AsciiPictures::~AsciiPictures() {
}

AsciiPictures::AsciiPictures(const AsciiPictures &asciipictures) {
    *this = asciipictures;
}

AsciiPictures &AsciiPictures::operator=(const AsciiPictures &asciipictures) {
    this->name = asciipictures.name;
    return *this;
}

void AsciiPictures::startGame() const {
    int y;
    int x;
    int z;
    getmaxyx(stdscr, y, x);
    y = y / 3;
    z = y;
    x = x / 3;
    wattron(stdscr, COLOR_PAIR(2));
    mvwaddstr(stdscr, y, x,     " _____ _____         _ _ _____ ");
    mvwaddstr(stdscr, y + 1, x, "|   __|  |  |___ ___| | |     |");
    mvwaddstr(stdscr, y + 2, x, "|  |  |    -|  _| -_| | | | | |");
    mvwaddstr(stdscr, y + 3, x, "|_____|__|__|_| |___|_|_|_|_|_|");
    mvwaddstr(stdscr, y + 4, x, "                               ");
    refresh();
    usleep(WAIT);
    clear();
}

