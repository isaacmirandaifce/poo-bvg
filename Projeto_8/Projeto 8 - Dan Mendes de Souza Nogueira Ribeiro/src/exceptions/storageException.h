#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H
#include <iostream>
#include <string>
#include <exception>

class StorageException : public std::exception {
    protected:
        std::string message;

    public:
        explicit StorageException(const std::string &msg = "Erro storage") : message(msg) {}

        virtual ~StorageException() = default;

        virtual const char *what() const noexcept override { return message.c_str(); };
};

class FileCorruptedException : public StorageException{

    public:
        explicit FileCorruptedException(const std::string &msg = "Os dados estao corrompidos ou em formato invalido") : StorageException(msg) {};
};

class DiskWriteException : public StorageException{

    public:
        explicit DiskWriteException(const std::string &msg = "Falta de permissao ou espaco no disco") : StorageException(msg) {};
};

#endif