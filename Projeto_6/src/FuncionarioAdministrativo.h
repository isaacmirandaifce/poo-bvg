#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;
    std::string cargo;
    double salario;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, int id,
                             const std::string& senha, const std::string& setor,
                             const std::string& cargo, double salario);

    // Getters e Setters
    std::string getSetor() const;
    std::string getCargo() const;
    double getSalario() const;
    void setSetor(const std::string& setor);
    void setCargo(const std::string& cargo);
    void setSalario(double salario);

    // Implementações dos métodos abstratos
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() const override;

    void exibirInformacoes() const override;
};

#endif
