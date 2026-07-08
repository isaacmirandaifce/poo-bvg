#include <iostream>
#include <vector>
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {
    std::vector<Relatorio*> auditoria;

    // Instanciando via polimorfismo
    auditoria.push_back(new UsuarioAdmin(1, "admin_ti"));
    auditoria.push_back(new UsuarioAuditor(2, "auditor_sec"));
    auditoria.push_back(new UsuarioOperador(3, "op_caixa"));

    std::cout << "--- Sistema de Auditoria SecureBank ---\n";
    for (Relatorio* r : auditoria) {
        r->gerarRelatorio();
        std::cout << "---------------------------------------\n";
    }

    // Limpeza de memória
    for (Relatorio* r : auditoria) {
        delete r;
    }

    return 0;
}
