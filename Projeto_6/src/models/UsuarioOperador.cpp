#include "UsuarioOperador.h"
#include <iostream>

const TipoUsuario UsuarioOperador::tipo = TipoUsuario::OPERADOR;

// ---------------------------------------------------------------------
// Implementacao da classe interna HistoricoAcessos.
// Como ela esta aninhada em UsuarioOperador, todo metodo definido fora
// da declaracao da classe precisa da resolucao de escopo DUPLA:
// UsuarioOperador::HistoricoAcessos::Metodo(...)
// ---------------------------------------------------------------------

UsuarioOperador::HistoricoAcessos::HistoricoAcessos(const std::string& recursoAcessado,
                                                      const std::string& dataHora,
                                                      int statusCodigo)
    : recursoAcessado(recursoAcessado), dataHora(dataHora), statusCodigo(statusCodigo) {
}

const std::string& UsuarioOperador::HistoricoAcessos::getRecursoAcessado() const {
    return recursoAcessado;
}

const std::string& UsuarioOperador::HistoricoAcessos::getDataHora() const {
    return dataHora;
}

int UsuarioOperador::HistoricoAcessos::getStatusCodigo() const {
    return statusCodigo;
}

// ---------------------------------------------------------------------
// Implementacao da classe externa UsuarioOperador.
// ---------------------------------------------------------------------

UsuarioOperador::UsuarioOperador(int id, const std::string& username, const std::string& senha)
    : UsuarioAutenticavel(id, username, senha) {
}

bool UsuarioOperador::autenticar(std::string senha) {
    return gerarHash(senha) == senhaHash;
}

void UsuarioOperador::registrarAcesso(const std::string& recursoAcessado, const std::string& dataHora, int statusCodigo) {
    // Construcao de um objeto da classe interna privada; so a classe
    // externa consegue fazer isso.
    historico.emplace_back(recursoAcessado, dataHora, statusCodigo);
}

TipoUsuario UsuarioOperador::getTipo() const {
    return tipo;
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "\n===== Relatorio [" << tipoUsuarioParaTexto(tipo) << "] =====\n";
    std::cout << "Usuario: " << username << " (ID: " << id << ")\n";
    std::cout << "Historico de acessos (" << historico.size() << " registros):\n";

    if (historico.empty()) {
        std::cout << "  - Nenhum acesso registrado nesta sessao.\n";
    } else {
        // Somente aqui, dentro do proprio metodo polimorfico da classe
        // externa, os dados ocultos sao expostos de forma controlada.
        for (const auto& registro : historico) {
            std::cout << "  - [" << registro.getDataHora() << "] "
                      << registro.getRecursoAcessado()
                      << " (status: " << registro.getStatusCodigo() << ")\n";
        }
    }
    std::cout << "=====================================\n";
}
