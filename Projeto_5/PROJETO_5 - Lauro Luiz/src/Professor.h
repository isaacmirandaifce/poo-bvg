#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

/**
 * Classe derivada Professor
 * Representa um professor do sistema acadêmico
 */
class Professor : public virtual Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtor padrão
    Professor();

    // Construtor parametrizado
    Professor(const std::string& nome, const std::string& email,
              const std::string& areaDeAtuacao);

    // Destrutor virtual
    virtual ~Professor();

    // Métodos getters
    std::string getAreaDeAtuacao() const;
    std::vector<std::string> getDisciplinasMinistradas() const;

    // Métodos setters
    void setAreaDeAtuacao(const std::string& areaDeAtuacao);

    // Métodos para gerenciar disciplinas
    void adicionarDisciplinaMinistrada(const std::string& disciplina);
    void removerDisciplinaMinistrada(const std::string& disciplina);
    bool ministraDisciplina(const std::string& disciplina) const;

    // Sobrescrita do método virtual puro da classe base
    virtual void gerarRelatorio() const override;

    // Sobrescrita do método exibirInformacoes
    virtual void exibirInformacoes() const override;

    // Método específico para contar disciplinas
    int contarDisciplinasMinistradas() const;
};

#endif // PROFESSOR_H
