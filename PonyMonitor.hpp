#ifndef PONYMONITOR_HPP
#define PONYMONITOR_HPP

#include <iostream>
#include "BaseDisplay.hpp"
#include <unistd.h>
#include <limits.h>
#include "IMonitorDisplay.hpp"

class PonyMonitor : public IMonitorDisplay, public BaseDisplay  {
public:
    PonyMonitor(void);
    ~PonyMonitor(void);
    PonyMonitor(const PonyMonitor &ponymonitor);
    PonyMonitor &operator=(PonyMonitor const &);
    std::string  exec(const char* cmd);
	char** setProc(void);
	char** getProc(void) const;
	void updateData(void);
    void setWin(void);
private:
    int position;
    bool front;
    bool back;
    char** _proc;
};

#endif //PONYMONITOR_HPP