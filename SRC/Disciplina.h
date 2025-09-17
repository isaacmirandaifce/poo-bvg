#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <vector>

class Disciplina {
private:
    std::string codigo;
    std::string nome;
    std::string professor;
    int creditos;
    std::vector<std::string> alunosMatriculados;

public:
    Disciplina(const std::string& codigo, const std::string& nome, 
               const std::string& professor, int creditos);

    void matricularAluno(const std::string& aluno);
    void listarAlunos() const;

    // Getters
    std::string getCodigo() const;
    std::string getNome() const;
    std::string getProfessor() const;
    int getCreditos() const;
};

#endif // DISCIPLINA_H