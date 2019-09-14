#include "PonyMonitor.hpp"
#include "BaseDisplay.hpp"

PonyMonitor::PonyMonitor(void): BaseDisplay() {
    this->position = 12;
    this->front = 1;
    this->back = 0;
}
PonyMonitor::~PonyMonitor() {
}
PonyMonitor::PonyMonitor(const PonyMonitor &ponymonitor) {
    *this = ponymonitor;
}
PonyMonitor &PonyMonitor::operator=(const PonyMonitor &) {
    return *this;
}

std::string  PonyMonitor::exec(const char* cmd) {
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
char** PonyMonitor::setProc(void) {
    delete [] this->_proc;
    std::string a;
    char** b = new char*[20];
    a = exec("top -o cpu -l 2 -n 20 -stats pid,command,cpu -U $(logname) | tail -n 20");
    int i = -1;
    int j = 0;
    size_t k = 0;
    b[0] = new char[256];
    while (++k < a.size())
    {
        if (a[k] == '\n')
        {
            k++;
            b[j][i] = '\0';
            j++;
            i = 0;
            b[j] = new char[256];
        }
        b[j][i++] = a[k];
    }
    return b;
}
char** PonyMonitor::getProc(void) const {
    
    return this->_proc;
}
void PonyMonitor::updateData(void)
{
    this->_proc = this->setProc();
}

void PonyMonitor::setWin() {
    wclear(this->getWin());

    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    // this->updateData();
    // char** proc = this->getProc();

    if (this->position >= 12 && this->front) {
        this->position++;
        if (this->position > 45 && this->front) {
            this->front = 0;
            this->back = 1;
        }
    }
    if (this->back) {
        this->position--;
        if (this->position < 13 && this->back) {
            this->front = 1;
            this->back = 0;
        }
    }
    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, this->position, "        _..---...,\"\"-._     ,/}/)");
    mvwprintw(this->getWin(), 3, this->position, "     .''        ,      ``..'(/-<");
    mvwprintw(this->getWin(), 4, this->position, "    /   _      {      )         \\");
    mvwprintw(this->getWin(), 5, this->position, "   ;   _ `.     `.   <         a(");
    mvwprintw(this->getWin(), 6, this->position, " ,'   ( \\  )      `.  \\ __.._ .: y");
    mvwprintw(this->getWin(), 7, this->position, "(  <\\_-) )'-.____...\\  `._   //-'");
    mvwprintw(this->getWin(), 8, this->position, " `. `-' /-._)))      `-._)))");
    mvwprintw(this->getWin(), 9, this->position, "  `...'         ");
    // for (int i = 0; i < 20; ++i)
    // {
    //     mvwprintw(this->getWin(), 10 + i + 3, 2, "%s", proc[i]);
    // }
    wattroff(this->getWin(), COLOR_PAIR(7));
    wrefresh(this->getWin());
    refresh();
}


