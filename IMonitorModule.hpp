#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <string>

class	IMonitorModule {

public:
    virtual ~IMonitorModule(void) {};
    virtual void updateData(void) = 0;

};


#endif