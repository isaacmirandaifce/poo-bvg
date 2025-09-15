#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include <iostream>

/**
 * Classe que representa um professor no sistema acadêmico
 */
class Professor {
private:
    std::string nome;
    std::string departamento;
    std::string especialidade;
    std::vector<std::string> disciplinasMinistradas;
    int anosExperiencia;

public:
    /**
     * Construtor padrão
     */
    Professor() : nome(""), departamento(""), especialidade(""), anosExperiencia(0) {}

    /**
     * Construtor parametrizado
     * @param nome - nome do professor
     * @param departamento - departamento do professor
     * @param especialidade - especialidade do professor
     * @param anosExperiencia - anos de experiência
     */
    Professor(const std::string& nome, const std::string& departamento,
              const std::string& especialidade, int anosExperiencia)
        : nome(nome), departamento(departamento), especialidade(especialidade),
          anosExperiencia(anosExperiencia) {}

    // Getters
    std::string getNome() const { return nome; }
    std::string getDepartamento() const { return departamento; }
    std::string getEspecialidade() const { return especialidade; }
    int getAnosExperiencia() const { return anosExperiencia; }
    const std::vector<std::string>& getDisciplinasMinistradas() const { return disciplinasMinistradas; }

    // Setters
    void setNome(const std::string& nome) { this->nome = nome; }
    void setDepartamento(const std::string& departamento) { this->departamento = departamento; }
    void setEspecialidade(const std::string& especialidade) { this->especialidade = especialidade; }
    void setAnosExperiencia(int anos) { this->anosExperiencia = anos; }

    /**
     * Adiciona uma disciplina à lista de disciplinas ministradas
     * @param disciplina - nome da disciplina
     */
    void adicionarDisciplina(const std::string& disciplina) {
        disciplinasMinistradas.push_back(disciplina);
    }

    /**
     * Verifica se o professor ministra uma disciplina específica
     * @param disciplina - nome da disciplina
     * @return true se o professor ministra a disciplina
     */
    bool ministraDisciplina(const std::string& disciplina) const {
        for (const auto& disc : disciplinasMinistradas) {
            if (disc == disciplina) return true;
        }
        return false;
    }

    /**
     * Operador de saída para impressão
     */
    friend std::ostream& operator<<(std::ostream& os, const Professor& professor) {
        os << "Professor: " << professor.nome << " | Departamento: " << professor.departamento
           << " | Especialidade: " << professor.especialidade
           << " | Experiência: " << professor.anosExperiencia << " anos";
        return os;
    }

    /**
     * Operador de comparação para ordenação
     */
    bool operator<(const Professor& outro) const {
        return nome < outro.nome;
    }

    /**
     * Operador de igualdade
     */
    bool operator==(const Professor& outro) const {
        return nome == outro.nome && departamento == outro.departamento;
    }
};

#endif // PROFESSOR_H
