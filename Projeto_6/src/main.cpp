#include <iostream>
#include <vector>

#include "interfaces/Relatorio.h"
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {
    std::cout << "\tINIT\n\n";

    UsuarioAdmin admin(101, "sysadmin_01", "root@123");
    UsuarioAuditor auditor(202, "auditor_master", "compliance2026");
    UsuarioOperador operador(303, "op_caixa_05", "senha_caixa");

    operador.acessarRecurso("/api/transferencia_ted", "2026-06-11 14:32:01", 200);
    operador.acessarRecurso("/api/saque_alto_valor", "2026-06-11 15:10:45", 401);

    std::vector<Relatorio*> relatoriosAuditados;

    std::cout << "\tLog de Autenticação\n";

    if (admin.autenticar("root@123")) {
        std::cout << "(+) Admin logado com sucesso.\n";
        relatoriosAuditados.push_back(&admin);
    }

    if (auditor.autenticar("senha_errada")) {
        relatoriosAuditados.push_back(&auditor);
    } else {
        std::cout << "(-) Auditor: Falha de Autenticação. Acesso a geração de logs negado\n";
    }

    if (operador.autenticar("senha_caixa")) {
        std::cout << "(+) Operador logado com sucesso.\n";
        relatoriosAuditados.push_back(&operador);
    }

    std::cout << "\n\tProcessamento em Cascata de Relatorios (Polimorfismo)\n";

    for (const Relatorio* relatorio : relatoriosAuditados) {
        relatorio->gerarRelatorio();
        std::cout << "-------------------------------------";
    }

    return 0;
}