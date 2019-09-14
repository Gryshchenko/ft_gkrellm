#include "Engine.hpp"
#include "AsciiPictures.hpp"
#include "Terminal.hpp"
#include "TimeMonitor.hpp"
#include "UserMonitor.hpp"
#include "CPUModule.hpp"
#include "SystemMonitor.hpp"
#include "MemoryMonitor.hpp"
#include "NetworkMonitor.hpp"
#include "PonyMonitor.hpp"

Engine::Engine(void) {
    //Initialization
    initscr();
    //disabled show character from keyboard press
    noecho();
    curs_set(false);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(10, COLOR_BLUE, COLOR_BLUE);
    init_pair(11, COLOR_RED, COLOR_RED);
    init_pair(12, COLOR_CYAN, COLOR_CYAN);
    init_pair(13, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(14, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(15, COLOR_WHITE, COLOR_WHITE);
    init_pair(16, COLOR_GREEN, COLOR_GREEN);
    nodelay(stdscr, true);
    this->width = this->term->getWidth();
    this->height = this->term->getHeight();
}
Engine::~Engine() {
}
Engine::Engine(const Engine &engine) {
    *this = engine;
}
Engine &Engine::operator=(const Engine &engine) {
    this->height = engine.height;
    this->width = engine.width;
    return *this;
}
void Engine::Base() {

    TimeMonitor time;
    UserMonitor user;
    SystemMonitor system;
    MemoryMonitor memory;
    NetworkMonitor network;
    CPUModule   cpu;
    PonyMonitor pony;

    int screenHeight, screenWidth;
    while (1) {
        getmaxyx(stdscr, screenHeight, screenWidth);
        if (screenWidth < 200) {
            wclear(stdscr);
            printw("Screen resolution too small!\n");
        } else {
            time.setWin();
            user.setWin();
            cpu.setWin();
            system.setWin();
            memory.setWin();
            pony.setWin();
            network.setWin();
        }
        if (getch() == 27) {
            endwin();
            break;
        }
        usleep(100000);
    }
    endwin();
}

void Engine::update() {

}