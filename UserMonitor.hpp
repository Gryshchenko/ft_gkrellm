#ifndef USERMONITOR_HPP
#define USERMONITOR_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include "BaseDisplay.hpp"
#include <unistd.h>
#include <limits.h>
#include "IMonitorDisplay.hpp"

class UserMonitor : public IMonitorDisplay, public BaseDisplay, public IMonitorModule{
public:
    UserMonitor(void);
    ~UserMonitor(void);
    UserMonitor(const UserMonitor &usermonitor);
    UserMonitor &operator=(UserMonitor const &userMonitor);
    void updateData(void);
    std::string getUserName() const;
    std::string getHostName() const;
    std::string getHost() const;
    std::string getUser() const;
    void setWin(void);
    const std::string setUser(void);
    const std::string setHost(void);

private:
    std::string userName;
    std::string hostName;
    std::string user;
    std::string host;

};

#endif //USERMONITOR_HPP