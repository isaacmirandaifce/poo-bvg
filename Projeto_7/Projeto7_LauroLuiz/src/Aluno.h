#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include <iostream>

/**
 * Classe que representa um aluno no sistema acadêmico
 */
class Aluno {
private:
    std::string nome;
    std::string matricula;
    int ano;
    double media;
    std::vector<std::string> disciplinasCursadas;

public:
    /**
     * Construtor padrão
     */
    Aluno() : nome(""), matricula(""), ano(0), media(0.0) {}

    /**
     * Construtor parametrizado
     * @param nome - nome do aluno
     * @param matricula - matrícula do aluno
     * @param ano - ano de ingresso
     * @param media - média geral do aluno
     */
    Aluno(const std::string& nome, const std::string& matricula,
          int ano, double media)
        : nome(nome), matricula(matricula), ano(ano), media(media) {}

    // Getters
    std::string getNome() const { return nome; }
    std::string getMatricula() const { return matricula; }
    int getAno() const { return ano; }
    double getMedia() const { return media; }
    const std::vector<std::string>& getDisciplinasCursadas() const { return disciplinasCursadas; }

    // Setters
    void setNome(const std::string& nome) { this->nome = nome; }
    void setMatricula(const std::string& matricula) { this->matricula = matricula; }
    void setAno(int ano) { this->ano = ano; }
    void setMedia(double media) { this->media = media; }

    /**
     * Adiciona uma disciplina à lista de disciplinas cursadas
     * @param disciplina - nome da disciplina
     */
    void adicionarDisciplina(const std::string& disciplina) {
        disciplinasCursadas.push_back(disciplina);
    }

    /**
     * Verifica se o aluno cursou uma disciplina específica
     * @param disciplina - nome da disciplina
     * @return true se o aluno cursou a disciplina
     */
    bool cursouDisciplina(const std::string& disciplina) const {
        for (const auto& disc : disciplinasCursadas) {
            if (disc == disciplina) return true;
        }
        return false;
    }

    /**
     * Operador de saída para impressão
     */
    friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno) {
        os << "Aluno: " << aluno.nome << " | Matrícula: " << aluno.matricula
           << " | Ano: " << aluno.ano << " | Média: " << aluno.media;
        return os;
    }

    /**
     * Operador de comparação para ordenação
     */
    bool operator<(const Aluno& outro) const {
        return nome < outro.nome;
    }

    /**
     * Operador de igualdade
     */
    bool operator==(const Aluno& outro) const {
        return matricula == outro.matricula;
    }
};

#endif // ALUNO_H
