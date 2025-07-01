#include "SistemaAcademico.h"
#include <iostream>

SistemaAcademico::SistemaAcademico() {
    
    Persistencia::carregarDados(*this);
}

SistemaAcademico::~SistemaAcademico() {
    
    salvarAutomaticamente();
}

void SistemaAcademico::salvarAutomaticamente() {
    Persistencia::salvarDados(*this);
}

void SistemaAcademico::adicionarAluno(const std::string& nome, int matricula) {
    alunos.push_back({nome, matricula});
    std::cout << "Aluno adicionado. Salvando automaticamente..." << std::endl;
    salvarAutomaticamente();
}

void SistemaAcademico::adicionarProfessor(const std::string& nome, int id) {
    professores.push_back({nome, id});
    std::cout << "Professor adicionado. Salvando automaticamente..." << std::endl;
    salvarAutomaticamente();
}

void SistemaAcademico::adicionarDisciplina(const std::string& nome, const std::string& codigo) {
    disciplinas.push_back({nome, codigo});
    std::cout << "Disciplina adicionada. Salvando automaticamente..." << std::endl;
    salvarAutomaticamente();
}

void SistemaAcademico::listarTodos() const {
    std::cout << "\n--- Alunos ---" << std::endl;
    if (alunos.empty()) {
        std::cout << "Nenhum aluno cadastrado." << std::endl;
    } else {
        for(const auto& aluno : alunos) {
            std::cout << "Matricula: " << aluno.matricula << ", Nome: " << aluno.nome << std::endl;
        }
    }

    std::cout << "\n--- Professores ---" << std::endl;
    if (professores.empty()) {
        std::cout << "Nenhum professor cadastrado." << std::endl;
    } else {
        for(const auto& prof : professores) {
            std::cout << "ID: " << prof.id << ", Nome: " << prof.nome << std::endl;
        }
    }

    std::cout << "\n--- Disciplinas ---" << std::endl;
    if (disciplinas.empty()) {
        std::cout << "Nenhuma disciplina cadastrada." << std::endl;
    } else {
        for(const auto& disc : disciplinas) {
            std::cout << "Codigo: " << disc.codigo << ", Nome: " << disc.nome << std::endl;
        }
    }
}