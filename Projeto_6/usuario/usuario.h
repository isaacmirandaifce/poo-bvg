#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// Classe base Usuario
class Usuario {
protected:
    std::string nome;      
    std::string email;     
    std::string tipo;      

public:

    // Construtor padrão
    Usuario() : nome(""), email(""), tipo("") {}

    // Construtor para inicializar os atributos da classe
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
        : nome(nome), email(email), tipo(tipo) {}

    // Método virtual implementar pelas classes derivadas
    virtual void gerarRelatorio() const = 0;

    // Destruidor para garantir a destruição das classes derivadas
    virtual ~Usuario() {}
};

#endif
