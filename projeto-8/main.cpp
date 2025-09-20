#include <iostream>
#include <vector>
#include <string>
#include "Persistencia.h"
#include "SinalHandler.h"
#include "Excecoes.h"
#include "Aluno.h"
#include "Professor.h"

void limparMemoria(std::vector<Aluno*>& alunos, std::vector<Professor*>& professores) {
    for (Aluno* a : alunos) {
        delete a;
    }
    alunos.clear();
    for (Professor* p : professores) {
        delete p;
    }
    professores.clear();
}

int main() {
    std::vector<Aluno*> alunos;
    std::vector<Professor*> professores;

    SinalHandler::inicializar(alunos, professores);

    std::cout << "Iniciando Sistema de Gestao Academica..." << std::endl;
    try {
        alunos = Persistencia::carregarAlunos("alunos.csv");
        std::cout << "Dados de " << alunos.size() << " alunos carregados." << std::endl;
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cout << "Aviso: " << e.what() << " Um novo arquivo sera criado ao salvar." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERRO CRITICO AO CARREGAR DADOS: " << e.what() << std::endl;
        return 1;
    }

    int opcao = 0;
    while (opcao != 9) {
        std::cout << "\n--- MENU PRINCIPAL ---\n"
                  << "1. Adicionar Novo Aluno\n"
                  << "2. Listar Alunos\n"
                  << "3. Forcar Falha de Segmentacao (Teste SIGSEGV)\n"
                  << "9. Sair e Salvar\n"
                  << "Pressione Ctrl+C a qualquer momento para testar o SIGINT.\n"
                  << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Opcao invalida." << std::endl;
            continue;
        }
        std::cin.ignore(10000, '\n'); // Limpa o buffer do teclado

        switch (opcao) {
            case 1: {
                std::string nome, email, senha, matricula, curso;
                std::cout << "Digite o nome: "; std::getline(std::cin, nome);
                std::cout << "Digite o email: "; std::getline(std::cin, email);
                std::cout << "Digite a senha: "; std::getline(std::cin, senha);
                std::cout << "Digite a matricula: "; std::getline(std::cin, matricula);
                std::cout << "Digite o curso: "; std::getline(std::cin, curso);

                alunos.push_back(new Aluno(nome, email, senha, matricula, curso));

                try {
                    Persistencia::salvarAlunos("alunos.csv", alunos);
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao salvar o novo aluno: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "\n--- Lista de Alunos ---\n";
                for (const auto& aluno : alunos) {
                    std::cout << "Nome: " << aluno->getNome() << ", Matricula: " << aluno->getMatricula() << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Forcando uma falha de segmentacao..." << std::endl;
                int* p = nullptr;
                *p = 10;
                break;
            }
            case 9:
                break;
            default:
                std::cout << "Opcao invalida." << std::endl;
                break;
        }
    }

    std::cout << "Salvando dados finais antes de encerrar..." << std::endl;
    try {
        Persistencia::salvarAlunos("alunos.csv", alunos);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar dados na saida: " << e.what() << std::endl;
    }

    limparMemoria(alunos, professores);

    std::cout << "Programa encerrado." << std::endl;
    return 0;
}
