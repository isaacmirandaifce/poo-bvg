#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Persistencia.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

void callback(int sinal) {
    // ...implementação...
}

int main() {
    Persistencia persist;
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    // Carregar dados no início
    try {
        persist.carregarTudo(alunos, professores, disciplinas);
    } catch (const std::exception &e) {
        std::cerr << "Erro ao carregar dados: " << e.what() << std::endl;
    }

    bool rodando = true;
    while (rodando) {

        std::cout << "\n--- Menu (demo) ---\n";
        std::cout << "1 - Listar alunos\n2 - Adicionar aluno\n3 - Salvar manualmente\n0 - Sair\nEscolha: ";
        int opc;
        if (!(std::cin >> opc)) {
            std::cin.clear();
            std::string dump;
            std::getline(std::cin, dump);
            continue;
        }
        if (opc == 0) {
            try {
                persist.salvarTudo(alunos, professores, disciplinas);
            } catch (const std::exception &e) {
                std::cerr << "Erro ao salvar: " << e.what() << std::endl;
            }
            rodando = false;
        } else if (opc == 1) {
            std::cout << "Alunos registrados:\n";
            for (const auto &a : alunos)
                std::cout << a.id << " - " << a.nome << " (" << a.matricula << ")\n";
        } else if (opc == 2) {
            int id;
            std::string nome, matricula;
            std::cout << "id: "; std::cin >> id; std::cin.ignore();
            std::cout << "nome: "; std::getline(std::cin, nome);
            std::cout << "matricula: "; std::getline(std::cin, matricula);
            alunos.emplace_back(id, nome, matricula);
            try {
                persist.salvarAlunos(alunos);
                std::cout << "Aluno salvo automaticamente.\n";
            } catch (const std::exception &e) {
                std::cerr << "Erro ao salvar alunos: " << e.what() << std::endl;
            }
        } else if (opc == 3) {
            try {
                persist.salvarTudo(alunos, professores, disciplinas);
                std::cout << "Salvo.\n";
            } catch (const std::exception &e) {
                std::cerr << "Erro ao salvar: " << e.what() << std::endl;
            }
        } else {
            std::cout << "Opcao invalida." << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Encerrando normalmente. Ate mais." << std::endl;
    return 0;
}