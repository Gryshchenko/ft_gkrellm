#include "BaseDisplay.hpp"

BaseDisplay::BaseDisplay( int h, int w, int x, int y)
        : height(h), width(w), xpos(x),ypos(y) {
    this->win = newwin(this->height, this->width, this->ypos, this->xpos);
    nodelay(this->win, true);
    scrollok(this->win,false);
}

BaseDisplay::BaseDisplay(int h, int w, int y) : height(h), width(w),ypos(y){
    int maxHeight, maxWidth;
    getmaxyx(stdscr, maxHeight, maxWidth);
    this->win = newwin(this->height, this->width, this->ypos, maxWidth - w);
    nodelay(this->win, true);

}

BaseDisplay::BaseDisplay(int h, int x) : height(h), xpos(x){
    int maxHeight, maxWidth;
    getmaxyx(stdscr, maxHeight, maxWidth);
    this->win = newwin(this->height, maxWidth - 60, this->ypos, this->xpos);
    nodelay(this->win, true);
}

BaseDisplay::BaseDisplay() {
    int maxHeight, maxWidth;
    getmaxyx(stdscr, maxHeight, maxWidth);
    this->win = newwin(maxHeight - 30, maxWidth, 30, 0);
    nodelay(this->win, true);
}

int		BaseDisplay::getHeight( void ) const {
    return this->height;
}
int		BaseDisplay::getWidth( void ) const {
    return this->width;
}

int		BaseDisplay::getXPos( void ) const {
    return this->xpos;
}
int		BaseDisplay::getYPos( void ) const {
    return this->ypos;
}

WINDOW	*BaseDisplay::getWin( void ) const {
    return this->win;
}


BaseDisplay::~BaseDisplay() {
}

BaseDisplay::BaseDisplay(const BaseDisplay &basedisplay) {
    *this = basedisplay;
}

BaseDisplay &BaseDisplay::operator=(const BaseDisplay &) {
    return *this;
}