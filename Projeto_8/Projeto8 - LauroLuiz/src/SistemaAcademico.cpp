#include "SistemaAcademico.h"
#include "SinalHandler.h"
#include <limits>

SistemaAcademico::SistemaAcademico() {
    carregarDados();
    // Definir ponteiros para o tratador de sinais
    SinalHandler::definirDados(&alunos, &professores, &disciplinas);
}

SistemaAcademico::~SistemaAcademico() {
    try {
        salvarDados();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar dados no destrutor: " << e.what() << std::endl;
    }
}

void SistemaAcademico::adicionarAluno(const Aluno& aluno) {
    alunos.push_back(aluno);
    std::cout << "Aluno adicionado com sucesso!" << std::endl;

    try {
        salvarDados(); // Auto-save
    } catch (const std::exception& e) {
        std::cerr << "Aviso: Falha ao salvar dados automaticamente: " << e.what() << std::endl;
    }
}

void SistemaAcademico::listarAlunos() const {
    if (alunos.empty()) {
        std::cout << "Nenhum aluno cadastrado." << std::endl;
        return;
    }

    std::cout << "\n=== LISTA DE ALUNOS ===" << std::endl;
    for (const auto& aluno : alunos) {
        aluno.exibir();
    }
}

void SistemaAcademico::adicionarProfessor(const Professor& professor) {
    professores.push_back(professor);
    std::cout << "Professor adicionado com sucesso!" << std::endl;

    try {
        salvarDados(); // Auto-save
    } catch (const std::exception& e) {
        std::cerr << "Aviso: Falha ao salvar dados automaticamente: " << e.what() << std::endl;
    }
}

void SistemaAcademico::listarProfessores() const {
    if (professores.empty()) {
        std::cout << "Nenhum professor cadastrado." << std::endl;
        return;
    }

    std::cout << "\n=== LISTA DE PROFESSORES ===" << std::endl;
    for (const auto& professor : professores) {
        professor.exibir();
    }
}

void SistemaAcademico::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
    std::cout << "Disciplina adicionada com sucesso!" << std::endl;

    try {
        salvarDados(); // Auto-save
    } catch (const std::exception& e) {
        std::cerr << "Aviso: Falha ao salvar dados automaticamente: " << e.what() << std::endl;
    }
}

void SistemaAcademico::listarDisciplinas() const {
    if (disciplinas.empty()) {
        std::cout << "Nenhuma disciplina cadastrada." << std::endl;
        return;
    }

    std::cout << "\n=== LISTA DE DISCIPLINAS ===" << std::endl;
    for (const auto& disciplina : disciplinas) {
        disciplina.exibir();
    }
}

void SistemaAcademico::carregarDados() {
    try {
        alunos = Persistencia::carregarAlunos();
        professores = Persistencia::carregarProfessores();
        disciplinas = Persistencia::carregarDisciplinas();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar dados: " << e.what() << std::endl;
    }
}

void SistemaAcademico::salvarDados() {
    try {
        Persistencia::salvarAlunos(alunos);
        Persistencia::salvarProfessores(professores);
        Persistencia::salvarDisciplinas(disciplinas);
    } catch (const std::exception& e) {
        throw;
    }
}

void SistemaAcademico::executarMenu() {
    int opcao = 0;

    do {
        std::cout << "\n========== SISTEMA ACADÊMICO RESILIENTE ==========" << std::endl;
        std::cout << "1. Adicionar Aluno" << std::endl;
        std::cout << "2. Listar Alunos" << std::endl;
        std::cout << "3. Adicionar Professor" << std::endl;
        std::cout << "4. Listar Professores" << std::endl;
        std::cout << "5. Adicionar Disciplina" << std::endl;
        std::cout << "6. Listar Disciplinas" << std::endl;
        std::cout << "7. Salvar Dados Manualmente" << std::endl;
        std::cout << "8. Carregar Dados" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "Escolha uma opção: ";

        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida! Digite um número." << std::endl;
            continue;
        }

        std::cin.ignore(); // Limpar buffer

        try {
            switch (opcao) {
                case 1: {
                    int id;
                    std::string nome, curso;
                    double nota;

                    std::cout << "ID do aluno: ";
                    std::cin >> id;
                    std::cin.ignore();

                    std::cout << "Nome: ";
                    std::getline(std::cin, nome);

                    std::cout << "Curso: ";
                    std::getline(std::cin, curso);

                    std::cout << "Nota: ";
                    std::cin >> nota;

                    adicionarAluno(Aluno(id, nome, curso, nota));
                    break;
                }

                case 2:
                    listarAlunos();
                    break;

                case 3: {
                    int id;
                    std::string nome, disciplina, departamento;

                    std::cout << "ID do professor: ";
                    std::cin >> id;
                    std::cin.ignore();

                    std::cout << "Nome: ";
                    std::getline(std::cin, nome);

                    std::cout << "Disciplina: ";
                    std::getline(std::cin, disciplina);

                    std::cout << "Departamento: ";
                    std::getline(std::cin, departamento);

                    adicionarProfessor(Professor(id, nome, disciplina, departamento));
                    break;
                }

                case 4:
                    listarProfessores();
                    break;

                case 5: {
                    int codigo, cargaHoraria, creditos;
                    std::string nome;

                    std::cout << "Código da disciplina: ";
                    std::cin >> codigo;
                    std::cin.ignore();

                    std::cout << "Nome: ";
                    std::getline(std::cin, nome);

                    std::cout << "Carga horária: ";
                    std::cin >> cargaHoraria;

                    std::cout << "Créditos: ";
                    std::cin >> creditos;

                    adicionarDisciplina(Disciplina(codigo, nome, cargaHoraria, creditos));
                    break;
                }

                case 6:
                    listarDisciplinas();
                    break;

                case 7:
                    salvarDados();
                    std::cout << "Dados salvos manualmente!" << std::endl;
                    break;

                case 8:
                    carregarDados();
                    std::cout << "Dados recarregados!" << std::endl;
                    break;

                case 0:
                    std::cout << "Encerrando sistema..." << std::endl;
                    salvarDados();
                    std::cout << "Dados salvos. Até logo!" << std::endl;
                    break;

                default:
                    std::cout << "Opção inválida! Tente novamente." << std::endl;
                    break;
            }
        } catch (const ArquivoNaoEncontradoException& e) {
            std::cout << "Erro: " << e.what() << std::endl;
            std::cout << "Deseja continuar mesmo assim? (s/n): ";
            char resposta;
            std::cin >> resposta;
            if (resposta != 's' && resposta != 'S') {
                opcao = 0;
            }
        } catch (const PermissaoNegadaException& e) {
            std::cout << "Erro: " << e.what() << std::endl;
            std::cout << "Verifique as permissões do arquivo." << std::endl;
        } catch (const FalhaConversaoException& e) {
            std::cout << "Erro: " << e.what() << std::endl;
            std::cout << "Dados corrompidos no arquivo." << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Erro inesperado: " << e.what() << std::endl;
        }

    } while (opcao != 0);
}
