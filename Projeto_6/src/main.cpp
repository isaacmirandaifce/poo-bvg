#include <iostream>
#include <vector>

// Inclusão dos headers das classes concretas
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

int main() {
    std::cout << "--- [ SecureBank Pro - IAM Module Inicializado ] ---\n\n";

    // 1. Instanciação dos Perfis de Acesso
    UsuarioAdmin admin(1, "admin_root", "senhaSegura123");
    
    UsuarioAuditor auditor(2, "auditor_chefe", "senhaAud2026", 
                           "RSA-2048: 0x9A4F...B3E1", 
                           "Transacoes PIX Acima de R$50k");
                           
    UsuarioOperador operador(3, "joao_caixa", "senhaOp321");

    // 2. Simulando operações e uso da Classe Interna (HistoricoAcessos)
    std::cout << ">> Registrando operacoes no sistema de caixa...\n";
    operador.registrarAcesso("/api/transacao/saque", "2026-08-30 14:05:00", 200);
    operador.registrarAcesso("/api/cliente/dados", "2026-08-30 14:15:30", 403); // Tentativa falha (Acesso negado)
    operador.registrarAcesso("/api/transacao/deposito", "2026-08-30 14:20:10", 200);

    // 3. Simulação de Autenticação (Polimorfismo de método da classe base abstrata)
    std::cout << "\n>> Tentativa de Login Operador (Senha Incorreta): " 
              << (operador.autenticar("senhaErrada") ? "SUCESSO" : "FALHA") << "\n";
    
    std::cout << ">> Tentativa de Login Operador (Senha Correta): " 
              << (operador.autenticar("senhaOp321") ? "SUCESSO" : "FALHA") << "\n\n";

    // 4. LOOP POLIMÓRFICO: Exigência do Ticket (Uso de Interface)
    std::cout << "--- PROCESSANDO RELATORIOS DE AUDITORIA EM CASCATA ---\n";
    
    // Vetor de ponteiros para a INTERFACE Relatorio
    std::vector<Relatorio*> relatorios;
    
    relatorios.push_back(&admin);
    relatorios.push_back(&auditor); 
    relatorios.push_back(&operador);

    // Iterando sobre o vetor e acionando o método gerador por polimorfismo dinâmico
    for (Relatorio* rel : relatorios) {
        rel->gerarRelatorio();
        std::cout << "--------------------------------------------------\n";
    }

    std::cout << "--- [ Encerramento do Modulo de Auditoria ] ---\n";

    return 0;
}