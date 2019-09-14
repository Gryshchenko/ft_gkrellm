#include "SystemMonitor.hpp"
#include "BaseDisplay.hpp"
#include "IMonitorModule.hpp"

SystemMonitor::SystemMonitor(void): BaseDisplay(10, 30, 0, 20) {
    this->systemTitle = "Os name";
    this->kernelTitle = "Kernel version";
    this->systemName = this->getSystemName();
    this->kernelVersion = this->getKernelVersion();
}
SystemMonitor::~SystemMonitor() {
}
SystemMonitor::SystemMonitor(const SystemMonitor &systemonitor) {
    *this = systemonitor;
}
SystemMonitor &SystemMonitor::operator=(const SystemMonitor & systemMonitor) {
    this->systemTitle = systemMonitor.systemTitle;
    this->kernelTitle = systemMonitor.kernelTitle;
    this->systemName = systemMonitor.systemName;
    this->kernelVersion = systemMonitor.kernelVersion;
    return *this;
}
std::string SystemMonitor::getSystemName() const {
    return this->systemName;
}
std::string SystemMonitor::getKernelVersion() const {
    return this->kernelVersion;
}



void SystemMonitor::updateData(void) {
    this->systemName = this->setSystemName();
    this->kernelVersion = this->setKernelVersion();
}

const std::string SystemMonitor::setSystemName(void) {
    #ifdef __unix
        return "Unix";
    #elif __unix__
        return "Unix";
    #elif __APPLE__ || __MACH__
        return "Mac OSX";
    #elif __linux__
        return "Linux";
    #else
	    return "Other";
    #endif
}

const std::string SystemMonitor::setKernelVersion(void) {
    char str[256];
    size_t size = sizeof(str);
    sysctlbyname("kern.osrelease", str, &size, NULL, 0);
    return std::string(str);
}

void SystemMonitor::setWin() {
//    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string systemName = this->getSystemName();
    std::string kernelVersion = this->getKernelVersion();

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 10, "OS Name");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 3, 10, "%s", systemName.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 5, 7, "Kernel version");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 6, 10, "%s", kernelVersion.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wrefresh(this->getWin());
    refresh();
}


