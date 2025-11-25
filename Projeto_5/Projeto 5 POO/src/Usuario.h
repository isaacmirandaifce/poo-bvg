#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo; // aluno, professor, funcionario, monitor

public:
    Usuario();
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);
    virtual ~Usuario();

    // método virtual puro -> classe abstrata
    virtual void gerarRelatorio() const = 0;

    const std::string& getNome() const;
    const std::string& getEmail() const;
    const std::string& getTipo() const;
};

#endif // USUARIO_H
