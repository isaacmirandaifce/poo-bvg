#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;

public:
    Aluno();
    Aluno(std::string n, std::string e, std::string t, std::string mat, std::string cur);
    virtual ~Aluno() {}

    void adicionarDisciplina(std::string disc);
    void gerarRelatorio() override;

    // Sobrecarga exigida pelo enunciado
    void exibirInformacoesDetalhadas();
    void exibirInformacoesDetalhadas(const std::vector<double>& notas);
};

#endif