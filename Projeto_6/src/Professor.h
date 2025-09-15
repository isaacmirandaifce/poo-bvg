#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::vector<std::string> disciplinasMinistradas;
    std::string titulacao;

public:
    Professor(const std::string& nome, const std::string& email, int id,
              const std::string& senha, const std::string& departamento,
              const std::string& titulacao);

    // Getters e Setters
    std::string getDepartamento() const;
    std::string getTitulacao() const;
    void setDepartamento(const std::string& departamento);
    void setTitulacao(const std::string& titulacao);

    // Gerenciamento de disciplinas
    void adicionarDisciplina(const std::string& disciplina);
    void removerDisciplina(const std::string& disciplina);

    // Implementações dos métodos abstratos
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() const override;

    void exibirInformacoes() const override;
};
