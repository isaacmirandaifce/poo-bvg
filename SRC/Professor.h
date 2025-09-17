#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include "Disciplina.h"
#include <vector>

class Professor : public Usuario {
private:
    std::string departamento;
    std::vector<Disciplina*> disciplinasMinistradas;

public:
    Professor(const std::string& nome, const std::string& email, 
              const std::string& departamento);

    // Sobrescrita do método virtual
    void exibirInformacoes() const override;

    void adicionarDisciplina(Disciplina* disciplina);
    void listarDisciplinas() const;

    // Getters
    std::string getDepartamento() const;
};

#endif // PROFESSOR_H