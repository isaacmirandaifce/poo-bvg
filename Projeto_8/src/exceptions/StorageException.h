#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>
#include <string>

class StorageException : public std::exception {
protected:
    std::string mensagem;
public:
    explicit StorageException(const std::string& msg) : mensagem(msg) {}
    virtual const char* what() const noexcept override { return mensagem.c_str(); }
};

class FileCorruptedException : public StorageException {
public:
    FileCorruptedException() : StorageException("Erro: Arquivo corrompido ou formato invalido.") {}
};

class DiskWriteException : public StorageException {
public:
    DiskWriteException() : StorageException("Erro: Falha na escrita em disco (sem espaco ou permissao).") {}
};

#endif
