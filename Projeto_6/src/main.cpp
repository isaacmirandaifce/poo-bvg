#include <iostream>
#include <vector>

#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"
#include "interfaces/Relatorio.h"

int main() {
    UsuarioAdmin admin(1, "admin_master", "1234");
    UsuarioAuditor auditor(2, "auditor_logs", "abcd");
    UsuarioOperador operador(3, "operador_caixa", "senha");

    std::cout << "=== TESTE DE AUTENTICACAO ===" << std::endl;

    if (admin.autenticar("1234")) {
        std::cout << "Administrador autenticado com sucesso." << std::endl;
    } else {
        std::cout << "Falha na autenticacao do administrador." << std::endl;
    }

    if (auditor.autenticar("abcd")) {
        std::cout << "Auditor autenticado com sucesso." << std::endl;
    } else {
        std::cout << "Falha na autenticacao do auditor." << std::endl;
    }

    if (operador.autenticar("senha")) {
        std::cout << "Operador autenticado com sucesso." << std::endl;
    } else {
        std::cout << "Falha na autenticacao do operador." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== ACOES ESPECIFICAS DOS USUARIOS ===" << std::endl;

    admin.gerenciarUsuarios();
    auditor.consultarLogs();

    operador.executarOperacao("Consulta de conta");
    operador.executarOperacao("Atualizacao de cadastro");

    std::cout << std::endl;
    std::cout << "=== RELATORIOS GERADOS COM POLIMORFISMO ===" << std::endl;

    std::vector<Relatorio*> relatorios;

    relatorios.push_back(&admin);
    relatorios.push_back(&auditor);
    relatorios.push_back(&operador);

    for (const Relatorio* relatorio : relatorios) {
        std::cout << "-----------------------------" << std::endl;
        relatorio->gerarRelatorio();
    }

    return 0;
}