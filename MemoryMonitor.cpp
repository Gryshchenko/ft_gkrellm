#include "MemoryMonitor.hpp"
#include "BaseDisplay.hpp"

MemoryMonitor::MemoryMonitor(void): BaseDisplay(15, 30, 0) {
    this->totalMemory = this->setTotalMemory();
    this->freeMemory = this->setFreeMemory();
    this->usedMemory = setUsedMemory();
}
MemoryMonitor::~MemoryMonitor() {
}
MemoryMonitor::MemoryMonitor(const MemoryMonitor &usermonitor) {
    *this = usermonitor;
}
MemoryMonitor &MemoryMonitor::operator=(const MemoryMonitor & userMonitor) {
    this->totalMemory = userMonitor.totalMemory;
    this->freeMemory = userMonitor.freeMemory;
    this->usedMemory = userMonitor.usedMemory;
    return *this;
}
std::string MemoryMonitor::setUsedMemory() {
    return std::to_string(this->_totalMemory - this->_freeMemory);
}
std::string MemoryMonitor::setFreeMemory() {
    int _tmpfreeMemory;
    size_t _sizeOfFreeMemory = sizeof(_tmpfreeMemory);
    sysctlbyname("vm.page_free_count", &_tmpfreeMemory, &_sizeOfFreeMemory, NULL, 0);
    this->_freeMemory = _tmpfreeMemory * 4096 / 1024 / 1024;
    return std::to_string(this->_freeMemory);
}
std::string MemoryMonitor::setTotalMemory() {
    unsigned long long totalMemory;
    size_t size = sizeof(totalMemory);
    sysctlbyname("hw.memsize", &totalMemory, &size, NULL, 0);
    this->_totalMemory = totalMemory / 1024 / 1024;
    return std::to_string(this->_totalMemory);
}

std::string MemoryMonitor::getFreeMemory() const {

    return this->freeMemory;
}

std::string MemoryMonitor::getTotalMemory() const {
    return this->totalMemory;
}
std::string MemoryMonitor::getUsedMemory() const {
    return this->usedMemory;
}

void MemoryMonitor::updateData(void) {
    this->totalMemory = this->setTotalMemory();
    this->freeMemory = this->setFreeMemory();
    this->usedMemory = setUsedMemory();
}

void MemoryMonitor::setWin() {
    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string totalMemory = this->getTotalMemory();
    std::string freeMemory = this->getFreeMemory();
    std::string usedMemory = this->getUsedMemory();

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 10, "Total memory");

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 3, 13, "%s", totalMemory.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 5, 10, "Used memory");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 6, 13, "%s", usedMemory.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 8, 10, "Free memory");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 9, 13, "%s", freeMemory.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wrefresh(this->getWin());
    refresh();
}


