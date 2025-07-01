#ifndef SISTEMAACADEMICO_H
#define SISTEMAACADEMICO_H

#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Persistencia.h"
#include <vector>
#include <string>
#include <sstream>

class SistemaAcademico {
private:
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    void salvarAutomaticamente();

public:
    SistemaAcademico();
    ~SistemaAcademico();

    void adicionarAluno(const std::string& nome, int matricula);
    void adicionarProfessor(const std::string& nome, int id);
    void adicionarDisciplina(const std::string& nome, const std::string& codigo);

    void listarTodos() const;
    
    const std::vector<Aluno>& getAlunos() const { return alunos; }
    const std::vector<Professor>& getProfessores() const { return professores; }
    const std::vector<Disciplina>& getDisciplinas() const { return disciplinas; }

    void setAlunos(const std::vector<Aluno>& novosAlunos) { alunos = novosAlunos; }
    void setProfessores(const std::vector<Professor>& novosProfessores) { professores = novosProfessores; }
    void setDisciplinas(const std::vector<Disciplina>& novasDisciplinas) { disciplinas = novasDisciplinas; }
};

#endif