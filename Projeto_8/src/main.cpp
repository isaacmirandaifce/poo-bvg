#include <iostream>
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    try {
        // Carregar dados
        std::vector<Aluno> alunos = Persistencia::carregarAlunos("data/alunos.txt");
        std::vector<Professor> professores = Persistencia::carregarProfessores("data/professores.txt");
        std::vector<Disciplina> disciplinas = Persistencia::carregarDisciplinas("data/disciplinas.txt");

        // Configurar tratador de sinais
        SinalHandler::setDados(alunos, professores, disciplinas);
        SinalHandler::inicializar();

        // Exibir dados
        std::cout << "Alunos:\n";
        for (const auto& aluno : alunos) {
            std::cout << "ID: " << aluno.getId() << ", Nome: " << aluno.getNome() << "\n";
        }

        std::cout << "\nProfessores:\n";
        for (const auto& professor : professores) {
            std::cout << "ID: " << professor.getId() << ", Nome: " << professor.getNome() << "\n";
        }

        std::cout << "\nDisciplinas:\n";
        for (const auto& disciplina : disciplinas) {
            std::cout << "ID: " << disciplina.getId() << ", Nome: " << disciplina.getNome()
                      << ", Professor ID: " << disciplina.getProfessorId() << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }

    return 0;
}