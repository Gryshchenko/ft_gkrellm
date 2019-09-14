#ifndef ASCIIPICTURES_HPP
#define ASCIIPICTURES_HPP

#include "Engine.hpp"

#include <ncurses.h>
#include <curses.h>

class AsciiPictures {
public:
    AsciiPictures(void);
    ~AsciiPictures(void);
    AsciiPictures(const AsciiPictures &asciipictures);
    AsciiPictures &operator=(AsciiPictures const &asciipictures);

    void startGame(void) const;
private:
    std::string name;
};

#endif //ASCIIPICTURES_HPP