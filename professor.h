#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo;
    std::string nome;
    std::vector<std::string> disciplinas;
public:
    Professor(const std::string& nome, const std::string& senha);

    bool autenticar(const std::string& senhaTentativa) const override;
    void gerarRelatorio() const override;

    void adicionarDisciplina(const std::string& d) { disciplinas.push_back(d); }
    std::string getNome() const { return nome; }
    const std::vector<std::string>& getDisciplinas() const { return disciplinas; }
};

#endif // PROFESSOR_H
