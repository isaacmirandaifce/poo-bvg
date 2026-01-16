#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include <string>

class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;

public:
    // Construtor padrão
    Aluno();

    // Construtor parametrizado
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso);

    // Sobrescrita do método gerarRelatorio
    void gerarRelatorio() const override;

    // Método sobrecarregado para exibir informações detalhadas
    void exibirInformacoes(bool comNotas) const;

    // Métodos para adicionar disciplinas
    void adicionarDisciplina(const std::string& disciplina);
};

#endif // ALUNO_H