#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(std::string nome, std::string email, std::string senha, std::string departamento);

    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;

    // Projeto 7:
    void adicionarDisciplinaMinistrada(const std::string& disciplina);
    bool ministra(const std::string& disciplina) const;
    std::string getDepartamento() const { return departamento; }
    const std::vector<std::string>& getDisciplinasMinistradas() const { return disciplinasMinistradas; }
};

#endif
