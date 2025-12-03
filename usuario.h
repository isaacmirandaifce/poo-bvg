#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
// Declaração da classe base Usuario
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;
// Outros atributos comuns a todos os usuários podem ser adicionados aqui
public:
    Usuario();
    Usuario(std::string nome, std::string email, std::string tipo);

    virtual ~Usuario() {}

    // MÉTODO VIRTUAL PURO → obriga sobrescrita
    virtual void gerarRelatorio() const = 0;
};

#endif
