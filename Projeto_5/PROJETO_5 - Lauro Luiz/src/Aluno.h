#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include <map>

/**
 * Classe derivada Aluno
 * Representa um aluno do sistema acadêmico
 */
class Aluno : public virtual Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;
    std::map<std::string, double> notas; // disciplina -> nota

public:
    // Construtor padrão
    Aluno();

    // Construtor parametrizado
    Aluno(const std::string& nome, const std::string& email,
          const std::string& matricula, const std::string& curso);

    // Destrutor virtual
    virtual ~Aluno();

    // Métodos getters
    std::string getMatricula() const;
    std::string getCurso() const;
    std::vector<std::string> getDisciplinasCursadas() const;

    // Métodos setters
    void setMatricula(const std::string& matricula);
    void setCurso(const std::string& curso);

    // Métodos para gerenciar disciplinas e notas
    void adicionarDisciplina(const std::string& disciplina);
    void adicionarNota(const std::string& disciplina, double nota);
    double obterNota(const std::string& disciplina) const;

    // Sobrescrita do método virtual puro da classe base
    virtual void gerarRelatorio() const override;

    // Sobrecarga: método para exibir informações com ou sem notas
    void exibirInformacoes() const; // Sem notas
    void exibirInformacoes(bool mostrarNotas) const; // Com ou sem notas

    // Método para calcular média geral
    double calcularMediaGeral() const;
};

#endif // ALUNO_H
