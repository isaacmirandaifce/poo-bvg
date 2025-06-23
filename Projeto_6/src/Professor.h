#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>
#include <sstream>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::vector<std::string> disciplinasLecionadas;

public:
    Professor(std::string nome, std::string cpf, std::string senha, std::string departamento);

    void adicionarDisciplinaLecionada(const std::string& disciplina);
    bool autenticar(const std::string& senhaFornecida) const override;
    std::string gerarRelatorio() const override;
};

#endif 