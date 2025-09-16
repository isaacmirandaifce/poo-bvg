#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <string>
#include "Aluno.h" // Incluir outros modelos aqui (Professor, Disciplina, etc)
#include "Excecoes.h"

class Persistencia {
public:
    // Salva um vetor de objetos em um arquivo
    template <typename T>
    static void salvar(const std::vector<T>& dados, const std::string& nomeArquivo);

    // Carrega um vetor de objetos de um arquivo
    template <typename T>
    static std::vector<T> carregar(const std::string& nomeArquivo);
};

// Implementação dos templates precisa estar no header ou ser incluída explicitamente
#include "Persistencia.tpp"

#endif // PERSISTENCIA_H