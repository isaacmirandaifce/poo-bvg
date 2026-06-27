#include <iostream>
#include <vector>
#include "interfaces/Relatorio.h"
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {
    std::cout << "=== ECOSSISTEMA DE SEGURANÇA E CONFORMIDADE IAM ===\n\n";

    UsuarioAdmin admin(101, "lucas.admin");
    UsuarioAuditor auditor(202, "clara.auditor");
    UsuarioOperador operador(303, "jose.caixa");

    operador.registrarAcesso("/api/v1/caixa/abertura", "2026-06-27 08:00:12", 200);
    operador.registrarAcesso("/api/v1/caixa/saque", "2026-06-27 09:15:45", 200);
    operador.registrarAcesso("/api/v1/admin/config", "2026-06-27 09:16:00", 403);

    std::cout << "--- Teste de Autenticação Rígida ---\n";
    std::cout << "Admin login: " << (admin.autenticar("Admin@Secure2026") ? "SUCESSO" : "FALHA") << "\n";
    std::cout << "Operador login fraudulento: " << (operador.autenticar("senhaErrada") ? "SUCESSO" : "FALHA") << "\n\n";

    std::cout << "--- Disparando Loop Polimórfico de Auditoria Normativa ---\n";
    std::vector<const Relatorio*> poolAuditoria;
    poolAuditoria.push_back(&admin);
    poolAuditoria.push_back(&auditor);
    poolAuditoria.push_back(&operador);

    for (const auto* entidade : poolAuditoria) {
        entidade->gerarRelatorio();
    }

    return 0;
}