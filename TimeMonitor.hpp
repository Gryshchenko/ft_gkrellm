#ifndef TIMEMONITOR_HPP
#define TIMEMONITOR_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include "BaseDisplay.hpp"
#include "IMonitorDisplay.hpp"

class TimeMonitor : public IMonitorDisplay, public BaseDisplay, public IMonitorModule {
public:
    TimeMonitor(void);
    ~TimeMonitor(void);
    TimeMonitor(const TimeMonitor &timemonitor);
    TimeMonitor &operator=(TimeMonitor const &timeMonitor);
    std::string getTimeName() const;
    std::string getDataName() const;
    std::string getTime() const;
    std::string getDate() const;
    void updateData(void);
    void setWin(void);
    const std::string getLocalTime(void);
    const std::string getLocalDate(void);

private:
    std::string dateName;
    std::string timeName;
    std::string time;
    std::string date;

};

#endif //TIMEMONITOR_HPP