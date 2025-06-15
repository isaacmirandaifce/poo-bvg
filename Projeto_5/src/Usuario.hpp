#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

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

    virtual void gerarRelatorio() const = 0;  // método virtual puro
};

#endif
