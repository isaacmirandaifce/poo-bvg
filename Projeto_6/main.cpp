#include <iostream>
#include <vector>
#include "interfaces/Relatorio.h"
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {
    std::cout << "=== SECUREBANK PRO: SUBSISTEMA IAM & AUDITORIA ==-\n\n";

    // Criação de instâncias concretas
    std::vector<std::string> logsAdmin = {"Update nas regras de firewall", "Reinicio do servico de Core Bancario"};
    UsuarioAdmin admin(101, "root_admin", "Admin@2026!", logsAdmin);

    UsuarioAuditor auditor(202, "ciso_auditor", "Audit#9988", "RSA-PUB-KEY-998371", "Transacoes Acima de R$ 50k");

    UsuarioOperador operador(303, "caixa_joao", "Operador123", "Agencia Central Boa Viagem");
    operador.adicionarHistorico("/api/v1/transacoes/saque", "2026-07-29 10:15", 200);
    operador.adicionarHistorico("/api/v1/contas/extrato", "2026-07-29 10:22", 200);

    // Teste de Autenticação (Login)
    std::cout << ">>> TESTANDO FLUXO DE AUTENTICACAO <<<\n";
    std::string senhaTentativa = "Admin@2026!";
    if (admin.autenticar(senhaTentativa)) {
        std::cout << "[LOGIN SUCESS] Usuario Admin autenticado com sucesso!\n";
    } else {
        std::cout << "[LOGIN FAIL] Credenciais invalidas para Admin.\n";
    }

    if (operador.autenticar("senhaErrada")) {
        std::cout << "[LOGIN SUCESS] Operador autenticado.\n";
    } else {
        std::cout << "[LOGIN FAIL] Falha na autenticação do Operador (Senha incorreta bloqueada com segurança).\n";
    }

    std::cout << "\n>>> DISPARANDO LOOP POLIMÓRFICO DE RELATÓRIOS (INTERFACE Relatorio*) <<<\n";
    
    // Armazenando em vetor de ponteiros da interface Relatorio
    std::vector<Relatorio*> painelAuditoria;
    painelAuditoria.push_back(&admin);
    painelAuditoria.push_back(&auditor);
    painelAuditoria.push_back(&operador);

    // Execução polimórfica em cascata
    for (size_t i = 0; i < painelAuditoria.size(); ++i) {
        painelAuditoria[i]->gerarRelatorio();
    }

    return 0;
}