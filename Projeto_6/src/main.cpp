#include <iostream>
#include <vector>
#include "interfaces/Relatorio.h"
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {

    // --- Instanciação dos usuários ---
    UsuarioAdmin admin(1, "joao.admin", "admin123");
    UsuarioAuditor auditor(2, "maria.auditor", "audit456", "PUB-KEY-XJ92", "Transacoes > R$10.000");
    UsuarioOperador operador(3, "carlos.operador", "oper789");

    // --- Registros prévios ---
    admin.registrarModificacao("Atualizacao de firewall em 10/06/2025");
    admin.registrarModificacao("Criacao de novo perfil de acesso");

    operador.registrarAcesso("Modulo de Caixa", "20/06/2025 08:30", 200);
    operador.registrarAcesso("Relatorio Diario", "20/06/2025 09:15", 200);
    operador.registrarAcesso("Painel Administrativo", "20/06/2025 09:20", 403);

    // --- Simulação de autenticação ---
    std::cout << "========== SIMULACAO DE LOGIN ==========" << std::endl;

    admin.autenticar("admin123");       // correto
    admin.autenticar("senhaerrada");    // incorreto

    auditor.autenticar("audit456");     // correto
    auditor.autenticar("wrongpass");    // incorreto

    operador.autenticar("oper789");     // correto
    operador.autenticar("1234");        // incorreto

    // --- Loop polimórfico via ponteiros de interface ---
    std::cout << "\n========== RELATORIOS DO SISTEMA ==========" << std::endl;

    std::vector<Relatorio*> relatorios = { &admin, &auditor, &operador };

    for (Relatorio* r : relatorios) {
        r->gerarRelatorio();
    }

    std::cout << "\n========== FIM DA SIMULACAO ==========" << std::endl;

    return 0;
}