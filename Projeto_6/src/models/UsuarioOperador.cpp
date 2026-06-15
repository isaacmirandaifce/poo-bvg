#include "UsuarioOperador.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string obterDataHoraAtual() {
    std::time_t agora = std::time(nullptr);
    std::tm* tempoLocal = std::localtime(&agora);

    std::ostringstream dataFormatada;
    dataFormatada << std::put_time(tempoLocal, "%d/%m/%Y %H:%M:%S");

    return dataFormatada.str();
}
void UsuarioOperador::HistoricoAcessos::adicionarAcesso(
    const std::string& recursoAcessado,
    const std::string& dataHora,
    int statusCodigo
) {
    registros.push_back({recursoAcessado, dataHora, statusCodigo});
}

void UsuarioOperador::HistoricoAcessos::exibirHistorico() const {
    std::cout << "Historico de acessos:" << std::endl;

    if (registros.empty()) {
        std::cout << "Nenhum acesso registrado." << std::endl;
        return;
    }

    for (const RegistroAcesso& registro : registros) {
        std::cout << "- Recurso acessado: " << registro.recursoAcessado << std::endl;
        std::cout << "  Data/Hora: " << registro.dataHora << std::endl;
        std::cout << "  Status: " << registro.statusCodigo << std::endl;
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
    historico.exibirHistorico();
}

void UsuarioOperador::executarOperacao(const std::string& recursoAcessado) {
    int statusCodigo = 200;

    std::cout << username << " acessou o recurso: " << recursoAcessado << std::endl;

    historico.adicionarAcesso(
        recursoAcessado,
        obterDataHoraAtual(),
        statusCodigo
    );
}
