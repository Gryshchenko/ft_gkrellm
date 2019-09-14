#include "NetworkMonitor.hpp"
#include "BaseDisplay.hpp"

NetworkMonitor::NetworkMonitor(void): BaseDisplay(15, 30, 15) {
    this->pocketsIn  = this->setPocketsIn();
    this->pocketsOut = this->setPocketsOut();
}
NetworkMonitor::~NetworkMonitor() {
}
NetworkMonitor::NetworkMonitor(const NetworkMonitor &networkmonitor) {
    *this = networkmonitor;
}
NetworkMonitor &NetworkMonitor::operator=(const NetworkMonitor & netwrokMonitor) {
    this->pocketsIn = netwrokMonitor.pocketsIn;
    this->pocketsOut = netwrokMonitor.pocketsOut;
    return *this;
}
std::string NetworkMonitor::setPocketsIn() {
    std::string	top_data = this->exec("top -l 1 | grep -E \"^Networks\" | awk '{print $3}'");
    std::size_t found = top_data.find_last_of("M");
    top_data[found + 1]  = '\0';
    return top_data;
}
std::string NetworkMonitor::setPocketsOut() {
    std::string	top_data = this->exec("top -l 1 | grep -E \"^Networks\" | awk '{print $5}'");
    std::size_t found = top_data.find_last_of("M");
    top_data[found + 1]  = '\0';
    return top_data;
}
std::string NetworkMonitor::getPocketsIn() const {
    return this->pocketsIn;
}
std::string NetworkMonitor::getPocketsOut() const {
    return this->pocketsOut;
}
void NetworkMonitor::updateData(void) {
    this->pocketsIn = this->setPocketsIn();
    this->pocketsOut = this->setPocketsOut();
}
std::string  NetworkMonitor::exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}
void NetworkMonitor::setWin() {
//    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string pocketsIn = this->getPocketsIn();
    std::string pocketsOut = this->getPocketsOut();

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 10, "Networks");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 4, 10, "Pockets In");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 5, 8, "%s", pocketsIn.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 7, 10, "Pockets Out");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 8, 8, "%s", pocketsOut.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wrefresh(this->getWin());
    refresh();
}


