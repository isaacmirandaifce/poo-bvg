/**
 * @file Contato.h
 * @brief Interface (declaração) da classe Contato do módulo CRM B2B.
 *
 * Este arquivo apenas DECLARA o que a classe tem (atributos e métodos).
 * A lógica (implementação) fica em Contato.cpp.
 */

// Guardas de inclusão: impedem que este header seja incluído duas vezes
// na mesma unidade de compilação (o que geraria erro de "redefinição").
#ifndef CONTATO_H
#define CONTATO_H

#include <string>

class Contato {
private:
    std::string nome;      // Nome do contato corporativo
    std::string telefone;  // Telefone do contato

public:
    // Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    // Destrutor: chamado automaticamente quando o objeto sai da memória
    ~Contato();

    // Métodos de exibição (const: não alteram o objeto)
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // CONTATO_H
