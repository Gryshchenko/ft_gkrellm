#ifndef NETWORKMONITOR_HPP
#define NETWORKMONITOR_HPP

#include <iostream>
#include "BaseDisplay.hpp"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <stdexcept>
#include <stdio.h>
#include <string>

class NetworkMonitor : public IMonitorDisplay, public BaseDisplay, public IMonitorModule {
public:
    NetworkMonitor(void);
    ~NetworkMonitor(void);
    NetworkMonitor(const NetworkMonitor &networkmonitor);
    NetworkMonitor &operator=(NetworkMonitor const &networkMonitor);
    void updateData(void);
    std::string getPocketsIn() const;
    std::string getPocketsOut() const;
    void setWin(void);
    std::string setPocketsIn(void);
    std::string setPocketsOut(void);
    std::string exec(const char* cmd);
private:
    std::string pocketsIn;
    std::string pocketsOut;

};

#endif //MEMORYMONITOR_HPP