#include "Monitor.h"
#include <iostream>
void Monitor::listarDisciplinasMonitoradas() {
    std::cout << "Disciplinas monitoradas:\n";
    for(auto &d : disciplinasMonitoradas) std::cout << d << std::endl;
}
