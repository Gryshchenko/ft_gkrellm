#include "CPUModule.hpp"

CPUModule::CPUModule(void): BaseDisplay(30, 30) {
    this->_core_count = 0;
    this->_thread_count = 0;
    this->_activecpu = 0;
    this->model = this->getModel();
    this->_cpu_usage = this->getCpuUsage();
}

CPUModule::~CPUModule() 
{

}
CPUModule::CPUModule(const CPUModule &cpumodule) {
    *this = cpumodule;
}

CPUModule &CPUModule::operator=(const CPUModule & cpumodule)
{
    this->model = cpumodule.model;
    this->_core_count = cpumodule._core_count;
    this->_thread_count = cpumodule._thread_count;
    this->_cpu_usage = cpumodule._cpu_usage;
    this->_activecpu = cpumodule._activecpu;

    return *this;
}

void CPUModule::updateData(void)
{
    this->model = this->setModel();
    this->_core_count = this->setCoreCount();
    this->_thread_count = this->setThreadCount();
    this->_cpu_usage = this->setCpuUsage();
    this->_activecpu = this->setActiveCpu();
}

std::string CPUModule::setModel(void)
{
    char str[128];
    size_t size = sizeof(str);
    sysctlbyname("machdep.cpu.brand_string", &str, &size, NULL, 0);
    return str;
}

int CPUModule::setCoreCount(void)
{
    int n = 0;

    size_t size = sizeof(int);
    sysctlbyname("machdep.cpu.core_count", &n, &size, NULL, 0);
    return n;
}
int CPUModule::setActiveCpu(void)
{
    int n = 0;

    size_t size = sizeof(int);
    sysctlbyname("hw.activecpu", &n, &size, NULL, 0);
    return n;
}

int CPUModule::setThreadCount(void)
{
    int n;

    size_t size = sizeof(int);
    sysctlbyname("machdep.cpu.thread_count", &n, &size, NULL, 0);
    return n;
}

std::string  CPUModule::exec(const char* cmd) {
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
std::string CPUModule::setCpuUsage(void) {
    std::string a;
    a = exec("top -l 1 -n 0 | grep -E \"^CPU\" | awk '{print $7}'");
    std::size_t found = a.find_last_of("%");
    std::string _cpu = a.substr(0, 2);
    this->_cpu = std::stoi(_cpu.c_str());
    a[found + 1]  = '\0';
    return a;
}

std::string CPUModule::getModel(void) const
{
    return this->model;
}

int CPUModule::getCoreCount(void) const {
    return this->_core_count;
}

int CPUModule::getThreadCount(void) const {
    return this->_thread_count;
}

int CPUModule::getActiveCpu(void) const {
    return this->_activecpu;
}

std::string CPUModule::getCpuUsage(void) const {
    return this->_cpu_usage;
}

void CPUModule::setWin()
{
    wclear(this->getWin());
    wattron(this->getWin(), COLOR_PAIR(12));
    box(this->getWin(), 0, 0);
    wattroff(this->getWin(), COLOR_PAIR(12));
    this->updateData();
    std::string model = this->getModel();
    std::string cpu_usage = this->getCpuUsage();
    int c_count = this->getCoreCount();
    int p_count = this->getThreadCount();
    int a_count = this->getActiveCpu();

    std::string cpu_graf = "";
    for (int i = 0; i < this->_cpu; ++i) {
        cpu_graf += "|";
    }

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 2, 12, "Model:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 2, 35, "%s", model.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 4, 12, "Number of cores:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 4, 35, "%d", c_count);
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 6, 12, "Number of threads:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 6, 35, "%d", p_count);
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 8, 12, "Number of active cpu:");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 8, 35, "%d", a_count);
    wattroff(this->getWin(), COLOR_PAIR(5));

    wattron(this->getWin(), COLOR_PAIR(7));
    mvwprintw(this->getWin(), 10, 12, "CPU usage: ");
    wattroff(this->getWin(), COLOR_PAIR(7));

    wattron(this->getWin(), COLOR_PAIR(5));
    mvwprintw(this->getWin(), 10, 35, "%s", cpu_usage.c_str());
    wattroff(this->getWin(), COLOR_PAIR(5));

    if (this->_cpu > 60)
        wattron(this->getWin(), COLOR_PAIR(11));
    else if (this->_cpu > 40)
        wattron(this->getWin(), COLOR_PAIR(13));
    else
        wattron(this->getWin(), COLOR_PAIR(16));
    mvwprintw(this->getWin(), 15, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 16, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 17, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 18, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 19, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 20, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 21, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 22, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 23, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 24, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 25, 12, cpu_graf.c_str());
    mvwprintw(this->getWin(), 26, 12, cpu_graf.c_str());
    wattroff(this->getWin(), COLOR_PAIR(11));
    wattroff(this->getWin(), COLOR_PAIR(13));
    wattroff(this->getWin(), COLOR_PAIR(16));
    wrefresh(this->getWin());
    refresh();
}
