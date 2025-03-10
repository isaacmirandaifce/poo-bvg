#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
#include <string>
#include <algorithm> // Necessário para implementação do método em Professor.cpp

class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;

    // Método para verificar se o professor ministra uma disciplina específica
    bool lecionaDisciplina(const std::string& disciplina) const;
};

#endif // PROFESSOR_H
