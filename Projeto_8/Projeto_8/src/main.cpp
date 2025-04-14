// main.cpp
#include <iostream>
#include <vector>
#include "Persistencia.h"
#include "SinalHandler.h"
#include "ExcecoesPersonalizadas.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int main() {
    SinalHandler::inicializar();

    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    try {
        alunos = Persistencia::carregarAlunos("dados/alunos.csv");
        professores = Persistencia::carregarProfessores("dados/professores.csv");
        disciplinas = Persistencia::carregarDisciplinas("dados/disciplinas.csv");
        std::cout << "Dados carregados com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar dados: " << e.what() << std::endl;
    }

    Aluno novoAluno("123", "Joãozinho Pereira", "ADS");
    alunos.push_back(novoAluno);

    try {
        Persistencia::salvarAlunos("dados/alunos.csv", alunos);
        Persistencia::salvarProfessores("dados/professores.csv", professores);
        Persistencia::salvarDisciplinas("dados/disciplinas.csv", disciplinas);
        std::cout << "Dados salvos com sucesso!\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar dados: " << e.what() << std::endl;
    }

    std::cout << "Sistema encerrado normalmente.\n";
    return 0;
}
