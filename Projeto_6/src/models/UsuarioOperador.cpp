#include "UsuarioOperador.h"
#include <iostream>

UsuarioOperador::HistoricoAcessos::HistoricoAcessos(std::string recurso, std::string dh, int status) : recursoAcessado(recurso), dataHora(dh), statusCodigo(status) {}

void UsuarioOperador::HistoricoAcessos::exibir() const {
    std::cout << "\t<Recurso> " << recursoAcessado << " ; Data e Hora: " << dataHora << " ; HTTP Status: " << statusCodigo << "\n";
};

UsuarioOperador::UsuarioOperador(int id, std::string username, std::string senha) : UsuarioAutenticavel(id, username, TipoUsuario::OPERADOR), senhaOperador(senha) {}

bool UsuarioOperador::autenticar(std::string senha) {
    return this->senhaOperador == senha;
};

void UsuarioOperador::acessarRecurso(std::string recurso, std::string dh, int status) {
    historicoLogs.push_back(HistoricoAcessos(recurso, dh, status));
};

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "(OPERADOR LOG) ID: " << id << " ; User: " << username << "\n";
    std::cout << "\tHistoricode Sessão Oculto:\n";

    for(const auto& log : historicoLogs) {
        log.exibir();
    }
}