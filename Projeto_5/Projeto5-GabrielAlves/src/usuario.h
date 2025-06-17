#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

// Classe base abstrata para todos os usuários do sistema.
// Utiliza o conceito de herança para compartilhar atributos comuns.
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    // Construtor parametrizado
    Usuario(std::string nome, std::string email, std::string tipo)
        : nome(nome), email(email), tipo(tipo) {}

    // Destrutor virtual para garantir a destruição correta em classes derivadas
    virtual ~Usuario() {}

    // Método virtual puro (função abstrata).
    // Obriga as classes derivadas a implementarem sua própria versão de gerarRelatorio.
    // Demonstra o polimorfismo. 
    virtual void gerarRelatorio() const = 0;
};

#endif // USUARIO_H