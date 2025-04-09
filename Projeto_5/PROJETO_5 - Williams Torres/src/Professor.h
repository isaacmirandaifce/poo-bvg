#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
#include <string>

class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtor padrão
    Professor();

    // Construtor parametrizado
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);

    // Sobrescrita do método gerarRelatorio
    void gerarRelatorio() const override;

    // Método para adicionar disciplinas ministradas
    void adicionarDisciplina(const std::string& disciplina);
};

#endif // PROFESSOR_H