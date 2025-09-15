#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

/**
 * Classe base abstrata Usuario
 * Define a estrutura básica para todos os tipos de usuários do sistema
 */
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

    // Destrutor virtual para polimorfismo
    virtual ~Usuario();

    // Métodos getters
    std::string getNome() const;
    std::string getEmail() const;
    std::string getTipo() const;

    // Métodos setters
    void setNome(const std::string& nome);
    void setEmail(const std::string& email);
    void setTipo(const std::string& tipo);

    // Método virtual puro - deve ser implementado nas classes derivadas
    virtual void gerarRelatorio() const = 0;

    // Método virtual para exibir informações básicas
    virtual void exibirInformacoes() const;
};

#endif // USUARIO_H
