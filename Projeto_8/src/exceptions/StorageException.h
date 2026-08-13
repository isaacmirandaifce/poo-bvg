#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>
#include <string>

/**
 * @class StorageException
 * @brief Classe base da hierarquia de erros da camada de armazenamento.
 *
 * Toda falha relacionada à persistência do Transaction Ledger (leitura ou
 * escrita de ledger.csv) deve ser sinalizada através de uma subclasse desta
 * exceção, nunca de std::exception genérica ou de códigos de erro. Isso
 * permite que o main.cpp capture StorageException de forma polimórfica
 * (um único catch cobre qualquer falha de armazenamento) e, quando
 * necessário, trate cada subtipo de forma isolada e específica.
 */
class StorageException : public std::exception {
protected:
    std::string mensagem;

public:
    explicit StorageException(const std::string& mensagem)
        : mensagem(mensagem) {}

    /**
     * @brief Retorna a mensagem descritiva do erro.
     *
     * `noexcept` é obrigatório aqui pois sobrescreve a assinatura de
     * std::exception::what(); lançar durante o tratamento de uma exceção
     * (dentro de um catch/what()) levaria a std::terminate().
     */
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

/**
 * @class FileCorruptedException
 * @brief Disparada quando ledger.csv existe, mas seu conteúdo está em
 * formato inválido ou inconsistente (ex.: linhas vazias inesperadas,
 * colunas corrompidas, falha de leitura no meio do arquivo).
 */
class FileCorruptedException : public StorageException {
public:
    explicit FileCorruptedException(const std::string& mensagem)
        : StorageException("[FileCorruptedException] " + mensagem) {}
};

/**
 * @class DiskWriteException
 * @brief Disparada quando o fluxo de escrita (std::ofstream) falha ao
 * abrir ou persistir dados em ledger.csv — por exemplo, por falta de
 * permissão ou espaço em disco.
 */
class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& mensagem)
        : StorageException("[DiskWriteException] " + mensagem) {}
};

#endif // STORAGEEXCEPTION_H
