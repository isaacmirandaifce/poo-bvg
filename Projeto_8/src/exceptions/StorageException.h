#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>

// Classe base para erros de armazenamento
class StorageException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Erro de armazenamento.";
    }
};

// Erro para arquivos corrompidos
class FileCorruptedException : public StorageException {
public:
    const char* what() const noexcept override {
        return "Arquivo corrompido ou com formato invalido.";
    }
};

// Erro para falhas de escrita em disco
class DiskWriteException : public StorageException {
public:
    const char* what() const noexcept override {
        return "Falha ao gravar dados no disco.";
    }
};

#endif