#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "../Usuarios/UsuarioAutenticavel.h"
#include "../Relatorio/Relatorio.h"
#include "../Usuarios/TipoUsuario.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    string departamento;
    string cargo;
    TipoUsuario tipoUsuario;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(string nome, string email, string tipo, string senha, string departamento, string cargo);

    void gerarRelatorio() const override;
    bool autenticar(string senhaTentativa) override;

    // Métodos para filtragem
    string getNome() const;
    string getDepartamento() const;
    string getCargo() const;
};

#endif