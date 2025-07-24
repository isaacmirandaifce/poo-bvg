#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include "Relatorio.h" // ADICIONADO
#include <vector>

class Professor : virtual public Usuario, public Relatorio { // HERANÇA DE RELATORIO ADICIONADA
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(std::string nome, std::string email, std::string area);

    void adicionarDisciplina(std::string disciplina);
    void gerarRelatorio() const override;
};

#endif
