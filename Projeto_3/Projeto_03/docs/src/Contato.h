#ifndef CONTATO_H
#define CONTATO_H

#include <string>

/* Classe Contato
-> Representa um contato de cliente corporativo (B2B) do módulo CRM. */
class Contato {

private:
    std::string nome;      // Nome do contato / empresa
    std::string telefone;  // Telefone de contato

public:
    // Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    // Destrutor (emite log de desalocação)
    ~Contato();

    // Métodos de impressão
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // CONTATO_H