#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <sys/sysctl.h>
class	IMonitorDisplay {

public:
    virtual ~IMonitorDisplay(void) {};
    virtual void setWin(void) = 0;
};


#endif