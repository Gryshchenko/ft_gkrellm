#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "BaseDisplay.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

class CPUModule : public BaseDisplay, public IMonitorModule, public  IMonitorDisplay
{
public:
	CPUModule( void );
	~CPUModule( void );
	CPUModule(const CPUModule &cpumodule);
	CPUModule &operator=(CPUModule const &cpumodule);

    void updateData(void);
    std::string getModel(void) const;
    std::string getCpuUsage(void) const;
    int getCoreCount(void) const;
    int getThreadCount(void) const;
    int getActiveCpu(void) const;
    void setWin(void);
    std::string setModel(void);
    int         setCoreCount(void);
    int         setThreadCount(void);
    int         setActiveCpu(void);
    std::string setCpuUsage(void);

    std::string exec(const char* cmd);

private:
    std::string model;
    std::string _cpu_usage;
    int _cpu;
    int _core_count;
    int _thread_count;
    int _activecpu;
};
#endif