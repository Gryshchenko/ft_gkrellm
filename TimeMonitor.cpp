#include "TimeMonitor.hpp"
#include "BaseDisplay.hpp"

TimeMonitor::TimeMonitor(void): BaseDisplay(10, 30, 0, 0) {
    this->dateName = "Date";
    this->timeName = "Time";
    this->time = this->getLocalTime();
    this->date = this->getLocalDate();
}
TimeMonitor::~TimeMonitor() {
}
TimeMonitor::TimeMonitor(const TimeMonitor &timemonitor) {
    *this = timemonitor;
}
TimeMonitor &TimeMonitor::operator=(const TimeMonitor & timeMonitor) {
    this->dateName = timeMonitor.dateName;
    this->timeName = timeMonitor.timeName;
    this->time = timeMonitor.time;
    this->date = timeMonitor.date;
    return *this;
}
std::string TimeMonitor::getDataName() const {
    return this->dateName;
}
std::string TimeMonitor::getTimeName() const {
    return this->timeName;
}
std::string TimeMonitor::getDate() const {
    return this->date;
}
std::string TimeMonitor::getTime() const {
    return this->time;
}
void TimeMonitor::updateData(void) {
    this->date = this->getLocalDate();
    this->time = this->getLocalTime();
}


const std::string TimeMonitor::getLocalDate(void) {
    time_t now = std::time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return std::string(buf);
}

const std::string TimeMonitor::getLocalTime(void) {
    time_t now = std::time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return std::string(buf);
}

void TimeMonitor::setWin() {
//    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string time = this->getTime();
    std::string date = this->getDate();

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 12, "Time");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 3, 10, "%s", time.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 5, 12, "Date:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 6, 10, "%s", date.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wrefresh(this->getWin());
    refresh();
}


