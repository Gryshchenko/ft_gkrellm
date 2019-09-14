#include "Terminal.hpp"

Terminal::Terminal(void) {
    getmaxyx(stdscr, this->height, this->width);
}

Terminal::Terminal(Terminal const &terminal) {
    *this = terminal;
}

Terminal &	Terminal::operator=(Terminal const & terminal) {
    this->height = terminal.getHeight();
    this->width = terminal.getWidth();
    return *this;
}

int		Terminal::getHeight(void) const {
    return this->height;
}
int		Terminal::getWidth(void) const {
    return this->width;
}

void	Terminal::update(void) {
    getmaxyx(stdscr, this->height, this->width);
}

