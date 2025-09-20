#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(std::string nome, std::string email, std::string senha, std::string areaDeAtuacao);
    void adicionarDisciplina(const std::string& disciplina);

    // Overrides
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // PROFESSOR_H
