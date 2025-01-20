#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

// Classe base Usuario
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    // Construtores
    Usuario();
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);

    // Método virtual puro para geração de relatórios
    virtual void gerarRelatorio() const = 0;

    // Destrutor virtual
    virtual ~Usuario() {}
};

#endif // USUARIO_H
