#include <iostream>
#include <string>
#pragma once

/**
 * @brief Classe que representa um contato telefônico.
 */
class Contato
{
private:
    std::string nome;
    std::string telefone;

public:
    
    /**
     * @brief Define o telefone do contato.
     * @param telefone String contendo o número de telefone.
     */
    void setTelefone(std::string telefone);

    /**
     * @brief Define o nome do contato.
     * @param nome String contendo o nome do contato.
     */
    void setNome(std::string nome);

    /**
     * @brief Construtor padrão da classe Contato.
     */
    Contato();

    /**
     * @brief Destrutor da classe Contato.
     */
    ~Contato();

    /**
     * @brief Imprime o nome do contato na saída padrão.
     */
    void imprimirNome();

    /**
     * @brief Imprime o telefone do contato na saída padrão.
     */
    void imprimirTelefone();
};

/**
 * @brief Função auxiliar para criar e preencher um novo objeto Contato.
 * @param nome Nome do contato a ser criado.
 * @param telefone Telefone do contato a ser criado.
 * @return O objeto Contato instanciado e preenchido.
 */
Contato AdicionarContatos(std::string nome, std::string telefone);