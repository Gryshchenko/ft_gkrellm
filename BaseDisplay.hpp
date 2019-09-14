#ifndef BASEDISPLAY_HPP
#define BASEDISPLAY_HPP

#include <ncurses.h>
#include <curses.h>
#include <string>
#include <iostream>

class BaseDisplay {
public:
    BaseDisplay(int h, int w, int x, int y);
    BaseDisplay(int h, int w, int y);
    BaseDisplay(int h, int w);
    BaseDisplay(void);
    ~BaseDisplay(void);
    BaseDisplay(const BaseDisplay &basedisplay);
    BaseDisplay &operator=(BaseDisplay const &);

    int		getHeight(void) const;
    int		getWidth(void) const;
    int		getXPos(void) const;
    int		getYPos(void) const;
    WINDOW	*getWin(void) const;
    int		getColor(int i) const;

private:
    int				height;
    int				width;
    int				xpos;
    int				ypos;
    WINDOW			*win;
};

#endif //BASEDISPLAY_HPP