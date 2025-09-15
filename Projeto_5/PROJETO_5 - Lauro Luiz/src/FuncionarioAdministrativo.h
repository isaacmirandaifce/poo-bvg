#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

/**
 * Classe derivada FuncionarioAdministrativo
 * Representa um funcionário administrativo do sistema acadêmico
 */
class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtor padrão
    FuncionarioAdministrativo();

    // Construtor parametrizado
    FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                              const std::string& departamento, const std::string& cargo);

    // Destrutor virtual
    virtual ~FuncionarioAdministrativo();

    // Métodos getters
    std::string getDepartamento() const;
    std::string getCargo() const;

    // Métodos setters
    void setDepartamento(const std::string& departamento);
    void setCargo(const std::string& cargo);

    // Sobrescrita do método virtual puro da classe base
    virtual void gerarRelatorio() const override;

    // Sobrescrita do método exibirInformacoes
    virtual void exibirInformacoes() const override;

    // Método específico para exibir hierarquia organizacional
    void exibirHierarquia() const;

    // Método para verificar se pode acessar determinado sistema
    bool podeAcessarSistema(const std::string& sistema) const;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
