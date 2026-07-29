#include "UsuarioOperador.h"
#include <iostream>

// Implementação dos métodos da Classe Interna usando resolução de escopo dupla
UsuarioOperador::HistoricoAcessos::HistoricoAcessos(std::string recurso, std::string dataHora, int status)
    : recursoAcessado(recurso), dataHora(dataHora), statusCodigo(status) {}

void UsuarioOperador::HistoricoAcessos::exibirDetalhes() const {
    std::cout << "    [Sessão] Recurso: " << recursoAcessado 
              << " | Data/Hora: " << dataHora 
              << " | Status HTTP: " << statusCodigo << "\n";
}

UsuarioOperador::UsuarioOperador(int id, std::string username, std::string senha, std::string depto)
    : UsuarioAutenticavel(id, username, senha, TipoUsuario::OPERADOR), departamentoRetaguarda(depto) {}

void UsuarioOperador::adicionarHistorico(std::string recurso, std::string dataHora, int status) {
    historicoSessoes.emplace_back(recurso, dataHora, status);
}

bool UsuarioOperador::autenticar(std::string senha) {
    return (this->senhaHash == senha);
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "[RELATÓRIO OPERADOR - CAIXA] ID: " << id << " | User: " << username << " | Departamento: " << departamentoRetaguarda << "\n";
    std::cout << "--> Histórico de Sessões Ocultas (Protegido por Classe Interna):\n";
    if (historicoSessoes.empty()) {
        std::cout << "    Nenhum registro de acesso recente.\n";
    } else {
        for (const auto& hist : historicoSessoes) {
            hist.exibirDetalhes();
        }
    }
    std::cout << "----------------------------------------------------\n";
}