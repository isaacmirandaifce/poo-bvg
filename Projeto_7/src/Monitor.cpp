#include "Monitor.h"

void Monitor::gerarRelatorio() const {
    Aluno::gerarRelatorio();
    cout << " - Monitor de: ";
    for (const auto& d : disciplinasMinistradas) cout << d << " ";
    cout << endl;
}