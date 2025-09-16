#include <iostream>
#include <limits>
#include "SinalHandler.h"
#include "SistemaAcademico.h"
#include "Excecoes.h"

void exibirMenu() {
    std::cout << "\n--- Menu Principal ---" << std::endl;
    std::cout << "1. Adicionar Aluno" << std::endl;
    std::cout << "2. Listar Alunos" << std::endl;
    std::cout << "3. Adicionar Professor" << std::endl;
    std::cout << "4. Listar Professores" << std::endl;
    std::cout << "5. Adicionar Disciplina" << std::endl;
    std::cout << "6. Listar Disciplinas" << std::endl;
    std::cout << "7. Simular Falha de Segmentação (SIGSEGV)" << std::endl;
    std::cout << "8. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main() {
    SistemaAcademico sistema;

    // O registro da função de salvar continua o mesmo, pois salvarDados() agora salva tudo.
    SinalHandler::registrarFuncaoSalvar([&sistema]() {
        sistema.salvarDados();
    });
    SinalHandler::inicializar();

    // Carrega todos os dados (alunos, profs, disc) de uma vez.
    sistema.carregarDados();

    int escolha = 0;
    while (escolha != 8) {
        exibirMenu();
        std::cin >> escolha;

        if (std::cin.fail()) {
            std::cout << "Entrada inválida. Por favor, insira um número." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (escolha) {
            case 1: { // Adicionar Aluno
                int matricula;
                std::string nome;
                std::cout << "Digite a matrícula do aluno: "; std::cin >> matricula;
                std::cout << "Digite o nome do aluno: "; std::cin.ignore(); std::getline(std::cin, nome);
                sistema.adicionarAluno(Aluno(matricula, nome));
                break;
            }
            case 2: sistema.listarAlunos(); break;
            case 3: { // Adicionar Professor
                int id;
                std::string nome;
                std::cout << "Digite o ID do professor: "; std::cin >> id;
                std::cout << "Digite o nome do professor: "; std::cin.ignore(); std::getline(std::cin, nome);
                sistema.adicionarProfessor(Professor(id, nome));
                break;
            }
            case 4: sistema.listarProfessores(); break;
            case 5: { // Adicionar Disciplina
                std::string codigo, nome;
                std::cout << "Digite o código da disciplina: "; std::cin >> codigo;
                std::cout << "Digite o nome da disciplina: "; std::cin.ignore(); std::getline(std::cin, nome);
                sistema.adicionarDisciplina(Disciplina(codigo, nome));
                break;
            }
            case 6: sistema.listarDisciplinas(); break;
            case 7: sistema.simularFalhaDeSegmentacao(); break;
            case 8: std::cout << "Saindo..." << std::endl; break;
            default: std::cout << "Opção inválida." << std::endl; break;
        }
    }

    return 0;
}