#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(const std::string& nome, const std::string& email,
              const std::string& matricula, const std::string& senha,
              const std::string& departamento);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;

    std::string getDepartamento() const;
    void setDepartamento(const std::string& departamento);
};

#endif // PROFESSOR_H