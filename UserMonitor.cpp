#include "UserMonitor.hpp"
#include "BaseDisplay.hpp"

UserMonitor::UserMonitor(void): BaseDisplay(10, 30, 0, 10) {
    this->userName = "User name";
    this->hostName = "Hostname";
    this->host = this->getHost();
    this->user = this->getUser();
}
UserMonitor::~UserMonitor() {
}
UserMonitor::UserMonitor(const UserMonitor &usermonitor) {
    *this = usermonitor;
}
UserMonitor &UserMonitor::operator=(const UserMonitor & userMonitor) {
    this->userName = userMonitor.userName;
    this->hostName = userMonitor.hostName;
    this->host = userMonitor.host;
    this->user = userMonitor.user;
    return *this;
}
std::string UserMonitor::getUserName() const {
    return this->userName;
}
std::string UserMonitor::getHostName() const {
    return this->hostName;
}
std::string UserMonitor::getUser() const {
    return this->user;
}
std::string UserMonitor::getHost() const {
    return this->host;
}
void UserMonitor::updateData(void) {
    this->user = this->setUser();
    this->host = this->setHost();
}

const std::string UserMonitor::setUser(void) {
    return std::string(getlogin());
}

const std::string UserMonitor::setHost(void) {
    char hostname[_POSIX_HOST_NAME_MAX];
    gethostname(hostname, _POSIX_HOST_NAME_MAX);
    return std::string(hostname);
}

void UserMonitor::setWin() {
//    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string host = this->getHost();
    std::string user = this->getUser();

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 12, "Host");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 3, 7, "%s", host.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 5, 12, "Name:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 6, 12, "%s", user.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wrefresh(this->getWin());
    refresh();
}


