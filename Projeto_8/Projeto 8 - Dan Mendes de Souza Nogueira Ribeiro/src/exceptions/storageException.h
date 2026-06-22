#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H
#include <iostream>
#include <string>
#include <exception>

/**
 * @class StorageException
 * @brief Exceção base para erros de armazenamento no sistema.
 * * Herda de std::exception e serve como classe base para todas as exceções
 * específicas relacionadas a falhas de persistência de dados.
 */
class StorageException : public std::exception {
    protected:
        std::string message;

    public:
        /**
         * @brief Construtor da exceção de armazenamento.
         * @param msg Mensagem de erro descritiva.
         */
        explicit StorageException(const std::string &msg = "Erro storage") : message(msg) {}

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~StorageException() = default;

        /**
         * @brief Retorna a mensagem de erro da exceção.
         * @return const char* Ponteiro para a string C contendo a mensagem de erro.
         */
        virtual const char *what() const noexcept override { return message.c_str(); };
};

/**
 * @class FileCorruptedException
 * @brief Exceção lançada quando os dados do arquivo de armazenamento estão corrompidos ou ilegíveis.
 */
class FileCorruptedException : public StorageException{

    public:
        /**
         * @brief Construtor da exceção de arquivo corrompido.
         * @param msg Mensagem de erro descritiva detalhando a corrupção.
         */
        explicit FileCorruptedException(const std::string &msg = "Os dados estao corrompidos ou em formato invalido") : StorageException(msg) {};
};

/**
 * @class DiskWriteException
 * @brief Exceção lançada quando ocorre uma falha ao tentar escrever dados no disco.
 */
class DiskWriteException : public StorageException{

    public:
        /**
         * @brief Construtor da exceção de falha de escrita em disco.
         * @param msg Mensagem de erro descritiva sobre a falha (ex: falta de espaço).
         */
        explicit DiskWriteException(const std::string &msg = "Falta de permissao ou espaco no disco") : StorageException(msg) {};
};

#endif