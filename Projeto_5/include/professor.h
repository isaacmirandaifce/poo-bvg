#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"
#include <vector>
#include <string>

// Classe derivada Professor
class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtores
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& areaDeAtuacao);

    // Método para adicionar uma disciplina ministrada
    void adicionarDisciplina(const std::string& disciplina);

    // Sobrescrita de gerarRelatorio
    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
