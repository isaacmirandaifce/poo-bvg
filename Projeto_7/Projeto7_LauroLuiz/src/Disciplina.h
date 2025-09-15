#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

/**
 * Classe que representa uma disciplina no sistema acadêmico
 */
class Disciplina {
private:
    std::string codigo;
    std::string nome;
    std::string professor;
    int cargaHoraria;
    int creditos;
    int ano;

public:
    /**
     * Construtor padrão
     */
    Disciplina() : codigo(""), nome(""), professor(""), cargaHoraria(0), creditos(0), ano(0) {}

    /**
     * Construtor parametrizado
     * @param codigo - código da disciplina
     * @param nome - nome da disciplina
     * @param professor - nome do professor responsável
     * @param cargaHoraria - carga horária da disciplina
     * @param creditos - número de créditos
     * @param ano - ano em que foi cursada
     */
    Disciplina(const std::string& codigo, const std::string& nome,
               const std::string& professor, int cargaHoraria, int creditos, int ano)
        : codigo(codigo), nome(nome), professor(professor),
          cargaHoraria(cargaHoraria), creditos(creditos), ano(ano) {}

    // Getters
    std::string getCodigo() const { return codigo; }
    std::string getNome() const { return nome; }
    std::string getProfessor() const { return professor; }
    int getCargaHoraria() const { return cargaHoraria; }
    int getCreditos() const { return creditos; }
    int getAno() const { return ano; }

    // Setters
    void setCodigo(const std::string& codigo) { this->codigo = codigo; }
    void setNome(const std::string& nome) { this->nome = nome; }
    void setProfessor(const std::string& professor) { this->professor = professor; }
    void setCargaHoraria(int carga) { this->cargaHoraria = carga; }
    void setCreditos(int creditos) { this->creditos = creditos; }
    void setAno(int ano) { this->ano = ano; }

    /**
     * Operador de saída para impressão
     */
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina) {
        os << "Disciplina: " << disciplina.nome << " (" << disciplina.codigo << ")"
           << " | Professor: " << disciplina.professor
           << " | Carga: " << disciplina.cargaHoraria << "h"
           << " | Créditos: " << disciplina.creditos
           << " | Ano: " << disciplina.ano;
        return os;
    }

    /**
     * Operador de comparação para ordenação
     */
    bool operator<(const Disciplina& outra) const {
        return nome < outra.nome;
    }

    /**
     * Operador de igualdade
     */
    bool operator==(const Disciplina& outra) const {
        return codigo == outra.codigo;
    }
};

#endif // DISCIPLINA_H
