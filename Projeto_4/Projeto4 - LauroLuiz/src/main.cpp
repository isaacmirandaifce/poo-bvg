#include <iostream>
#include <vector>
#include <iomanip>
#include "Aluno.h"
#include "Disciplina.h"

void exibirMenuPrincipal() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "    SISTEMA DE GERENCIAMENTO DE NOTAS   " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Cadastrar Aluno" << std::endl;
    std::cout << "2. Adicionar Disciplina" << std::endl;
    std::cout << "3. Exibir Relatório Completo" << std::endl;
    std::cout << "4. Verificar Aprovações" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Escolha uma opção: ";
}

void exibirRelatorioAprovacoes(const std::vector<Disciplina>& disciplinas) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         RELATÓRIO DE APROVAÇÕES        " << std::endl;
    std::cout << "========================================" << std::endl;
    
    int aprovadas = 0, reprovadas = 0;
    float somaNotas = 0.0f;
    
    for (const auto& disciplina : disciplinas) {
        std::cout << "Disciplina: " << disciplina.getNome() << std::endl;
        std::cout << "Nota: " << std::fixed << std::setprecision(1) << disciplina.getNota() << std::endl;
        
        // Usando a função amiga para verificar aprovação
        if (verificarAprovacao(disciplina)) {
            std::cout << "Status: APROVADO ✓" << std::endl;
            aprovadas++;
        } else {
            std::cout << "Status: REPROVADO ✗" << std::endl;
            reprovadas++;
        }
        
        somaNotas += disciplina.getNota();
        std::cout << "----------------------------------------" << std::endl;
    }
    
    if (!disciplinas.empty()) {
        float media = somaNotas / disciplinas.size();
        std::cout << "RESUMO GERAL:" << std::endl;
        std::cout << "Disciplinas aprovadas: " << aprovadas << std::endl;
        std::cout << "Disciplinas reprovadas: " << reprovadas << std::endl;
        std::cout << "Média geral: " << std::fixed << std::setprecision(2) << media << std::endl;
        std::cout << "Status geral: " << (media >= 6.0f ? "APROVADO" : "REPROVADO") << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

int main() {
    Aluno aluno;
    std::vector<Disciplina> disciplinas;
    int opcao;
    
    // Dados de exemplo para demonstração
    bool exemploCarregado = false;
    
    do {
        exibirMenuPrincipal();
        std::cin >> opcao;
        std::cin.ignore(); // Limpar buffer
        
        switch (opcao) {
            case 1: {
                std::string nome, matricula, curso;
                std::cout << "\n--- CADASTRO DE ALUNO ---" << std::endl;
                std::cout << "Nome: ";
                std::getline(std::cin, nome);
                std::cout << "Matrícula: ";
                std::getline(std::cin, matricula);
                std::cout << "Curso: ";
                std::getline(std::cin, curso);
                
                aluno = Aluno(nome, matricula, curso);
                std::cout << "Aluno cadastrado com sucesso!" << std::endl;
                break;
            }
            
            case 2: {
                if (aluno.getNome().empty()) {
                    std::cout << "Erro: Cadastre um aluno primeiro!" << std::endl;
                    break;
                }
                
                std::string nomeDisciplina;
                int cargaHoraria;
                float nota;
                
                std::cout << "\n--- ADICIONAR DISCIPLINA ---" << std::endl;
                std::cout << "Nome da disciplina: ";
                std::getline(std::cin, nomeDisciplina);
                std::cout << "Carga horária: ";
                std::cin >> cargaHoraria;
                std::cout << "Nota (0-10): ";
                std::cin >> nota;
                std::cin.ignore();
                
                disciplinas.push_back(Disciplina(nomeDisciplina, cargaHoraria, nota));
                std::cout << "Disciplina adicionada com sucesso!" << std::endl;
                break;
            }
            
            case 3: {
                if (aluno.getNome().empty()) {
                    std::cout << "Erro: Cadastre um aluno primeiro!" << std::endl;
                    break;
                }
                
                std::cout << "\n========================================" << std::endl;
                std::cout << "         RELATÓRIO COMPLETO            " << std::endl;
                std::cout << "========================================" << std::endl;
                
                aluno.exibirInformacoes();
                
                std::cout << "\nDISCIPLINAS CURSADAS:" << std::endl;
                if (disciplinas.empty()) {
                    std::cout << "Nenhuma disciplina cadastrada." << std::endl;
                } else {
                    for (const auto& disciplina : disciplinas) {
                        disciplina.exibirInformacoes();
                    }
                }
                break;
            }
            
            case 4: {
                if (disciplinas.empty()) {
                    std::cout << "Erro: Adicione disciplinas primeiro!" << std::endl;
                    break;
                }
                
                exibirRelatorioAprovacoes(disciplinas);
                break;
            }
            
            case 0:
                std::cout << "Encerrando o sistema..." << std::endl;
                break;
                
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
                break;
        }
        
        // Carregar exemplo na primeira execução se não houver dados
        if (!exemploCarregado && aluno.getNome().empty()) {
            char resposta;
            std::cout << "\nDeseja carregar dados de exemplo? (s/n): ";
            std::cin >> resposta;
            std::cin.ignore();
            
            if (resposta == 's' || resposta == 'S') {
                aluno = Aluno("João Silva Santos", "2024001", "Análise e Desenvolvimento de Sistemas");
                disciplinas.push_back(Disciplina("Programação Orientada a Objetos", 80, 8.5f));
                disciplinas.push_back(Disciplina("Banco de Dados", 60, 7.2f));
                disciplinas.push_back(Disciplina("Engenharia de Software", 60, 5.8f));
                disciplinas.push_back(Disciplina("Estruturas de Dados", 80, 9.1f));
                
                std::cout << "Dados de exemplo carregados com sucesso!" << std::endl;
            }
            exemploCarregado = true;
        }
        
    } while (opcao != 0);
    
    return 0;
}