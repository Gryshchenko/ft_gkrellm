#ifndef MEMORYMONITOR_HPP
#define MEMORYMONITOR_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <iostream>
#include "BaseDisplay.hpp"

class MemoryMonitor : public IMonitorDisplay, public BaseDisplay, public IMonitorModule {
public:
    MemoryMonitor(void);
    ~MemoryMonitor(void);
    MemoryMonitor(const MemoryMonitor &memorymonitor);
    MemoryMonitor &operator=(MemoryMonitor const &memoryMonitor);
    void updateData(void);
    std::string getTotalMemory() const;
    std::string getUsedMemory() const;
    std::string getFreeMemory() const;
    std::string getHost() const;
    std::string getUser() const;
    void setWin(void);
    std::string setTotalMemory(void);
    std::string setUsedMemory(void);
    std::string setFreeMemory(void);

private:
    std::string totalMemory;
    std::string usedMemory;
    std::string freeMemory;
    int _totalMemory;
    int _usedMemory;
    int _freeMemory;

};

#endif //MEMORYMONITOR_HPP