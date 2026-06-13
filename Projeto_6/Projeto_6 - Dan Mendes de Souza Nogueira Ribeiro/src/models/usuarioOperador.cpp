#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"
#include "usuarioOperador.h"

UsuarioOperador::UsuarioOperador(int id, std::string nome, std::string senha){
    this->setID(id);
    this->setUsername(nome);
    this->setSenha(senha);
};

bool UsuarioOperador::autenticar(std::string senha){

    return getSenha() == senha;
};

TipoUsuario UsuarioOperador::getTipoUsuario() const
{

    return TipoUsuario::OPERADOR;
};

void UsuarioOperador::gerarRelatorio() const{

    for (int i = 0; i < acessos.size(); i++)
    {
        acessos[i].mostrarDados();
    }
    
};

UsuarioOperador::HistoricoAcessos::HistoricoAcessos(std::string recursoAcessado, std::string dataHora, int statuscodigo) {

    this->recursoAcessado = recursoAcessado;
    this->dataHora = dataHora;
    this->statusCodigo = statuscodigo;
};

std::string UsuarioOperador::HistoricoAcessos::getRecursoAcessado() const { return this->recursoAcessado; };
std::string UsuarioOperador::HistoricoAcessos::getDataHora() const { return this->dataHora; };
int UsuarioOperador::HistoricoAcessos::getStatusCodigo() const { return this->statusCodigo; };

void UsuarioOperador::HistoricoAcessos::mostrarDados() const {

    std::cout << std::endl << "Recurso Acessado: " << getRecursoAcessado() << std::endl << "Hora: " << getDataHora() << std::endl << "status: " << getStatusCodigo() << std::endl;
};

void UsuarioOperador::registrarAcesso(std::string recurso, std::string dataHora, int status) {
    acessos.push_back(HistoricoAcessos(recurso, dataHora, status));
}