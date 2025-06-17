#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

// Herda virtualmente de Usuario para evitar problemas de herança múltipla na classe Monitor.
class Professor : public virtual Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(std::string nome, std::string email, std::string area);
    void adicionarDisciplina(std::string disciplina);

    // Sobrescrita do método virtual puro. 
    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H