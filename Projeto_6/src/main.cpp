#include "interfaces/Relatorio.h"
#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "#####################################################\n";
    std::cout << "#   SecureBank Pro - IAM Core (Ticket #602)          #\n";
    std::cout << "#   Simulacao de Autenticacao e Auditoria            #\n";
    std::cout << "#####################################################\n";

    // ---------------------------------------------------------------
    // 1. Criacao dos usuarios concretos (heranca de UsuarioAutenticavel
    //    e assinatura da interface Relatorio).
    // ---------------------------------------------------------------
    UsuarioAdmin admin(1, "carlos.ti", "senhaAdmin123");
    UsuarioAuditor auditor(2, "fernanda.audit", "auditPass456",
                            "PUB-KEY-4F3A9C21", "Transacoes > R$ 50.000,00");
    UsuarioOperador operador(3, "joao.caixa", "caixa789");

    admin.registrarModificacao("Atualizacao de politica de senha (min. 10 caracteres)");
    admin.registrarModificacao("Revogacao de acesso do usuario id=17 (desligamento)");

    operador.registrarAcesso("Consulta de saldo - conta 88231-4", "2026-08-10 09:12:03", 200);
    operador.registrarAcesso("Emissao de boleto - conta 88231-4", "2026-08-10 09:14:47", 200);
    operador.registrarAcesso("Tentativa de acesso a modulo administrativo", "2026-08-10 09:15:02", 403);

    // ---------------------------------------------------------------
    // 2. Simulacao de login com senha CORRETA e INCORRETA.
    // ---------------------------------------------------------------
    std::cout << "\n--- Validacao de Login ---\n";

    std::cout << "[Admin] login com senha correta: "
              << (admin.autenticar("senhaAdmin123") ? "SUCESSO" : "FALHA") << "\n";
    std::cout << "[Admin] login com senha incorreta: "
              << (admin.autenticar("senhaErrada") ? "SUCESSO" : "FALHA") << "\n";

    std::cout << "[Auditor] login com senha correta: "
              << (auditor.autenticar("auditPass456") ? "SUCESSO" : "FALHA") << "\n";
    std::cout << "[Auditor] login com senha incorreta: "
              << (auditor.autenticar("outraSenha") ? "SUCESSO" : "FALHA") << "\n";

    std::cout << "[Operador] login com senha correta: "
              << (operador.autenticar("caixa789") ? "SUCESSO" : "FALHA") << "\n";
    std::cout << "[Operador] login com senha incorreta: "
              << (operador.autenticar("123456") ? "SUCESSO" : "FALHA") << "\n";

    // ---------------------------------------------------------------
    // 3. Simulacao Polimorfica: vector<Relatorio*> percorrido em
    //    cascata, chamando .gerarRelatorio() sem saber o tipo real do
    //    objeto por tras do ponteiro de interface.
    // ---------------------------------------------------------------
    std::vector<Relatorio*> relatorios;
    relatorios.push_back(&admin);
    relatorios.push_back(&auditor);
    relatorios.push_back(&operador);

    std::cout << "\n--- Geracao de Relatorios (loop polimorfico) ---\n";
    for (Relatorio* r : relatorios) {
        r->gerarRelatorio();
    }

    // ---------------------------------------------------------------
    // 4. Demonstracao adicional: consulta rapida de TipoUsuario
    //    (enum class) para triagem no sistema de mensageria.
    // ---------------------------------------------------------------
    std::cout << "\n--- Triagem por TipoUsuario (enum class) ---\n";
    std::cout << "Admin    -> " << tipoUsuarioParaTexto(admin.getTipo()) << "\n";
    std::cout << "Auditor  -> " << tipoUsuarioParaTexto(auditor.getTipo()) << "\n";
    std::cout << "Operador -> " << tipoUsuarioParaTexto(operador.getTipo()) << "\n";

    return 0;
}
