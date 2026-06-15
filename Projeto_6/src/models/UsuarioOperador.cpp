#include "UsuarioOperador.h"
#include <iostream>

void UsuarioOperador::HistoricoAcessos::adicionarAcesso(const std::string& acesso) {
    acessos.push_back(acesso);
}

void UsuarioOperador::HistoricoAcessos::exibirHistorico() const {
    std::cout << "Historico de acessos:" << std::endl;

    if (acessos.empty()) {
        std::cout << "Nenhum acesso registrado." << std::endl;
        return;
    }

    for (const std::string& acesso : acessos) {
        std::cout << "- " << acesso << std::endl;
    }
}

UsuarioOperador::UsuarioOperador(
    int id,
    const std::string& username,
    const std::string& senha
) : UsuarioAutenticavel(id, username, senha) {}

bool UsuarioOperador::autenticar(const std::string& senhaInformada) const {
    return senhaInformada == senha;
}

std::string UsuarioOperador::getNivelAcesso() const {
    return "Acesso operacional limitado";
}

TipoUsuario UsuarioOperador::getTipo() const {
    return TipoUsuario::OPERADOR;
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "Relatorio do Operador" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Usuario: " << username << std::endl;
    std::cout << "Nivel de acesso: " << getNivelAcesso() << std::endl;
}

void UsuarioOperador::executarOperacao(const std::string& operacao) {
    std::cout << username << " executou a operacao: " << operacao << std::endl;
    historico.adicionarAcesso(operacao);
}

void UsuarioOperador::mostrarHistorico() const {
    historico.exibirHistorico();
}