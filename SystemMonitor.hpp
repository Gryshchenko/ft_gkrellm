#ifndef SYSTEMMONITOR_HPP
#define SYSTEMMONITOR_HPP

#include <iostream>
#include "BaseDisplay.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class SystemMonitor : public IMonitorDisplay, public BaseDisplay, public IMonitorModule {
public:
    SystemMonitor(void);
    ~SystemMonitor(void);
    SystemMonitor(const SystemMonitor &systemonitor);
    SystemMonitor &operator=(SystemMonitor const &systemMonitor);
    void updateData(void);
    std::string getSystemName() const;
    std::string getKernelVersion() const;
    void setWin(void);
    const std::string setSystemName(void);
    const std::string setKernelVersion(void);

private:
    std::string systemName;
    std::string kernelVersion;
    std::string systemTitle;
    std::string kernelTitle;

};

#endif //SYSTEMMONITOR_HPP