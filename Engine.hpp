#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <unistd.h>
#include <iostream>
#include <string>

#include "Terminal.hpp"
#include "AsciiPictures.hpp"
#include "BaseDisplay.hpp"

#define WIN_HEIGHT 40
#define WIN_WIDTH 100

class Engine {
public:
    Engine(void);
    ~Engine(void);
    Engine(const Engine &engine);
    Engine &operator=(Engine const &engine);
    void Base(void);
    void update(void);
protected:
    int width;
    int height;
    int maxHeight;
    int maxWidth;
    WINDOW* mainWindow;
    Terminal * term;

};

#endif //ENGINE_HPP