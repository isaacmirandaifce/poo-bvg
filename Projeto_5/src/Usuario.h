#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    Usuario();
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);
    virtual ~Usuario() = default;

    std::string getNome() const;
    std::string getEmail() const;
    std::string getTipo() const;

    void setNome(const std::string& nome);
    void setEmail(const std::string& email);
    void setTipo(const std::string& tipo);

    // "virtual puro" (classe abstrata)
    virtual void gerarRelatorio() const = 0;  //obriga todas as subclasses a implementarem seu próprio relatório
};

#endif
