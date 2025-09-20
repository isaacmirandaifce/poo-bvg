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
    // Construtor
    Professor(std::string nome, std::string email, std::string senha, std::string areaDeAtuacao);

    // Método para adicionar disciplinas
    void adicionarDisciplina(const std::string& disciplina);

    // Implementação dos "contratos" das classes pai
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // PROFESSOR_H
