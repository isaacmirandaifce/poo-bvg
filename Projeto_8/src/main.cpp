#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    // Inicializa tratador de sinais
    SinalHandler::inicializar();

    // Caminhos de exemplo para arquivos de dados
    const std::string alunosPath = "dados_alunos.txt";
    const std::string profsPath = "dados_professores.txt";
    const std::string discPath = "dados_disciplinas.txt";

    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    // Define rotina de salvamento que será chamada no tratador de sinais
    SinalHandler::setShutdownHandler([&]() {
        try {
            Persistencia::salvarAlunos(alunosPath, alunos);
            Persistencia::salvarProfessores(profsPath, professores);
            Persistencia::salvarDisciplinas(discPath, disciplinas);
            std::cerr << "Dados salvos com sucesso pelo tratador de sinais.\n";
        } catch (const std::exception& e) {
            std::cerr << "Falha ao salvar dados no tratador de sinais: " << e.what() << "\n";
        }
    });

    try {
        alunos = Persistencia::carregarAlunos(alunosPath);
        std::cout << "Carregou " << alunos.size() << " aluno(s).\n";
    } catch (const std::exception& e) {
        std::cerr << "Aviso: não foi possível carregar alunos: " << e.what() << "\n";
    }

    try {
        professores = Persistencia::carregarProfessores(profsPath);
        std::cout << "Carregou " << professores.size() << " professor(es).\n";
    } catch (const std::exception& e) {
        std::cerr << "Aviso: não foi possível carregar professores: " << e.what() << "\n";
    }

    try {
        disciplinas = Persistencia::carregarDisciplinas(discPath);
        std::cout << "Carregou " << disciplinas.size() << " disciplina(s).\n";
    } catch (const std::exception& e) {
        std::cerr << "Aviso: não foi possível carregar disciplinas: " << e.what() << "\n";
    }

    // Exemplo simples de uso: adicionar um aluno e salvar imediatamente
    Aluno novo("João da Silva", "joao@example.com", "2025001", "Engenharia");
    alunos.push_back(novo);
    try {
        Persistencia::salvarAlunos(alunosPath, alunos);
        std::cout << "Aluno salvo com sucesso.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar alunos: " << e.what() << "\n";
    }

    std::cout << "Programa em execução. Use Ctrl+C para enviar SIGINT e acionar salvamento.\n";
    // Mantém processo vivo para possibilitar teste com sinais
    while (true) {
        // Loop simples; em um app real aqui ficaria a lógica do sistema
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}
