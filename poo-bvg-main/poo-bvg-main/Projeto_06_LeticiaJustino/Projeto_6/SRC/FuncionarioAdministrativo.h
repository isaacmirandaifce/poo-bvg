#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string cargo;
    std::string setor;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                             const std::string& matricula, const std::string& senha,
                             const std::string& cargo, const std::string& setor);

    void gerarRelatorio() const override;

    std::string getCargo() const;
    std::string getSetor() const;
    void setCargo(const std::string& cargo);
    void setSetor(const std::string& setor);
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H