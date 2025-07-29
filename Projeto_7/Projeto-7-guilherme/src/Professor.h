#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include "Relatorio.h"
#include <vector>
#include <string>
#include <iostream>

class Professor : virtual public Usuario, public Relatorio {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(std::string nome, std::string email, std::string area);

    void adicionarDisciplina(std::string disciplina);
    bool ministraDisciplina(const std::string& disciplina) const;
    void imprimirInformacoes() const;
    void gerarRelatorio() const override;
};

#endif
