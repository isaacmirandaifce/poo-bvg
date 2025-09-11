#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;

public:
    // Construtor padrão
    Usuario();

    // Construtor parametrizado
    Usuario(const std::string& nome, const std::string& email, const std::string& tipo);

    // Destrutor virtual
    virtual ~Usuario();

    // Método virtual puro para gerar relatório
    virtual void gerarRelatorio() const = 0;

    // Métodos acessores
    std::string getNome() const;
    std::string getEmail() const;
    std::string getTipo() const;
};

#endif // USUARIO_H
