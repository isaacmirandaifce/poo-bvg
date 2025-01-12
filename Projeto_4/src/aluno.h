#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <vector>
#include "disciplina.h"

class Aluno {
    private:
            std::string nome;
            std::string matricula;
            std::string curso;

    public:
            // constructor
            Aluno();
            Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

            void exibirInformacoes() const;

            std::string getNome() const;
};

#endif