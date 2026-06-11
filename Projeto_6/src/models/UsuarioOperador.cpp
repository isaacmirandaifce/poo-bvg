#include "UsuarioOperador.h"
#include <iostream>

using namespace std;

UsuarioOperador::HistoricoAcessos::HistoricoAcessos(
    string recurso,
    string dataHora,
    int status)
{
    this->recursoAcessado = recurso;
    this->dataHora = dataHora;
    this->statusCodigo = status;
}

void UsuarioOperador::HistoricoAcessos::exibir() const
{
    cout
        << recursoAcessado
        << " | "
        << dataHora
        << " | "
        << statusCodigo
        << endl;
}

UsuarioOperador::UsuarioOperador(
    int id,
    string username,
    string senha)
    : UsuarioAutenticavel(id, username, senha)
{
}

void UsuarioOperador::adicionarAcesso(
    string recurso,
    string dataHora,
    int status)
{
    historico.push_back(
        HistoricoAcessos(
            recurso,
            dataHora,
            status));
}

bool UsuarioOperador::autenticar(string senha)
{
    return this->senha == senha;
}

void UsuarioOperador::gerarRelatorio() const
{
    cout << "\n===== RELATORIO OPERADOR =====\n";

    for(const auto& item : historico)
    {
        item.exibir();
    }
}

TipoUsuario UsuarioOperador::getTipo() const
{
    return TipoUsuario::OPERADOR;
}