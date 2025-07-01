#include <iostream>
#include <limits>
#include "SistemaAcademico.h"
#include "SinalHandler.h"
#include "Excecoes.h"

void menu() {
    std::cout << "\n===== Sistema de Gerenciamento Academico =====" << std::endl;
    std::cout << "1. Adicionar Aluno" << std::endl;
    std::cout << "2. Adicionar Professor" << std::endl;
    std::cout << "3. Adicionar Disciplina" << std::endl;
    std::cout << "4. Listar Tudo" << std::endl;
    std::cout << "5. Forcar Falha de Segmentacao (Teste SIGSEGV)" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    SistemaAcademico sistema;

    
    SinalHandler::inicializar(&sistema);

    int opcao;
    do {
        menu();
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cout << "Entrada invalida. Por favor, insira um numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                std::string nome;
                int matricula;
                std::cout << "Nome do aluno: ";
                std::getline(std::cin, nome);
                std::cout << "Matricula do aluno: ";
                std::cin >> matricula;
                sistema.adicionarAluno(nome, matricula);
                break;
            }
            case 2: {
                std::string nome;
                int id;
                std::cout << "Nome do professor: ";
                std::getline(std::cin, nome);
                std::cout << "ID do professor: ";
                std::cin >> id;
                sistema.adicionarProfessor(nome, id);
                break;
            }
            case 3: {
                std::string nome, codigo;
                std::cout << "Nome da disciplina: ";
                std::getline(std::cin, nome);
                std::cout << "Codigo da disciplina: ";
                std::getline(std::cin, codigo);
                sistema.adicionarDisciplina(nome, codigo);
                break;
            }
            case 4:
                sistema.listarTodos();
                break;
            case 5:
                std::cout << "Forcando falha de segmentacao..." << std::endl;
                {
                    int *ptr = nullptr;
                    *ptr = 42; // Causa SIGSEGV
                }
                break;
            case 0:
                std::cout << "Encerrando o sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }

    } while (opcao != 0);

    return 0;
}