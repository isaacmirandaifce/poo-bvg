#include "../headers/Aluno.h"
#include <iostream>
#include <iomanip>

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, double nota)
    : nomeDisciplina(nomeDisciplina), ano(ano), nota(nota) {}

std::string Aluno::HistoricoDisciplinar::getNomeDisciplina() const { return nomeDisciplina; }
int Aluno::HistoricoDisciplinar::getAno() const { return ano; }
double Aluno::HistoricoDisciplinar::getNota() const { return nota; }
void Aluno::HistoricoDisciplinar::setNota(double novaNota) { nota = novaNota; }

Aluno::Aluno(const std::string& nome, const std::string& email,
             const std::string& matricula, const std::string& senha,
             const std::string& curso)
    : UsuarioAutenticavel(nome, email, matricula, TipoUsuario::ALUNO, senha),
      curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& nomeDisciplina, int ano, double nota) {
    historico.emplace_back(nomeDisciplina, ano, nota);
}

double Aluno::calcularMedia() const {
    if (historico.empty()) return 0.0;
    
    double soma = 0.0;
    for (const auto& disciplina : historico) {
        soma += disciplina.getNota();
    }
    return soma / historico.size();
}

void Aluno::gerarRelatorio() const {
    std::cout << "=== RELATÓRIO DO ALUNO ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Média Geral: " << std::fixed << std::setprecision(2) << calcularMedia() << std::endl;
    std::cout << "\nHistórico Disciplinar:" << std::endl;
    
    for (const auto& disciplina : historico) {
        std::cout << "- " << disciplina.getNomeDisciplina() 
                  << " (" << disciplina.getAno() << "): "
                  << disciplina.getNota() << std::endl;
    }
    std::cout << "==========================" << std::endl;
}

std::string Aluno::getCurso() const { return curso; }
void Aluno::setCurso(const std::string& curso) { this->curso = curso; }