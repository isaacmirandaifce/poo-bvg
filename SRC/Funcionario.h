#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include Usuario.h
#include string

class Funcionario  public Usuario {
private
    stdstring cargo;
    stdstring setor;

public
    Funcionario(const stdstring& nome, const stdstring& email,
                const stdstring& cargo, const stdstring& setor);

     Sobrescrita do método virtual
    void exibirInformacoes() const override;

     Getters
    stdstring getCargo() const;
    stdstring getSetor() const;
};

#endif  FUNCIONARIO_H