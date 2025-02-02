#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::vector<std::string> disciplinas;

public:
    Professor(const std::string& nome, const std::string& email, const std::vector<std::string>& disciplinas);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) override;

    std::vector<std::string> getDisciplinas() const { return disciplinas; }
};

#endif // PROFESSOR_H