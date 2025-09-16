#include <iostream>
#include <stdexcept>
#include "include/Persistencia.h"
#include "include/SinalHandler.h"
#include "include/SistemaAcademico.h"

// Pequeno menu para demonstração
void menu() {
    std::cout << "\n--- Sistema Acadêmico Resiliente ---\n"
              << "1) Listar resumo\n"
              << "2) Adicionar aluno\n"
              << "3) Adicionar professor\n"
              << "4) Adicionar disciplina\n"
              << "0) Sair\n"
              << "Escolha: ";
}

int main() {
    Persistencia persist("data");
    SistemaAcademico sistema;
    sistema.setPersistencia(&persist);

    // Inicializar tratador de sinais *antes* de operações longas
    SinalHandler::inicializar();
    SinalHandler::registrarCallbackSeguro([&](int sinal){
        std::cerr << "[Auto-Save] Salvando dados antes de encerrar...\n";
        try {
            persist.saveAll(sistema);
            std::cerr << "[OK] Dados salvos em ./data\n";
        } catch (const std::exception& e) {
            std::cerr << "[FALHA] Não foi possível salvar: " << e.what() << "\n";
        }
    });

    try {
        persist.loadAll(sistema);
        std::cout << "Dados carregados com sucesso.\n";
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cerr << e.what() << " -> Iniciando com base vazia.\n";
    } catch (const PermissaoNegadaException& e) {
        std::cerr << e.what() << " -> Verifique permissões.\n";
    } catch (const ConversaoDadosException& e) {
        std::cerr << "Erro de conversão: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado ao carregar: " << e.what() << "\n";
    }

    int opcao = -1;
    while (true) {
        menu();
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Entrada inválida.\n";
            continue;
        }
        if (opcao == 0) {
            std::cout << "Saindo...\n";
            break;
        }
        if (opcao == 1) {
            sistema.listarResumo();
        } else if (opcao == 2) {
            int id; std::string nome, curso;
            std::cout << "ID: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "Nome: "; std::getline(std::cin, nome);
            std::cout << "Curso: "; std::getline(std::cin, curso);
            sistema.addAluno(Aluno{id, nome, curso});
        } else if (opcao == 3) {
            int id; std::string nome, area;
            std::cout << "ID: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "Nome: "; std::getline(std::cin, nome);
            std::cout << "Área: "; std::getline(std::cin, area);
            sistema.addProfessor(Professor{id, nome, area});
        } else if (opcao == 4) {
            int codigo, carga; std::string nome;
            std::cout << "Código: "; std::cin >> codigo;
            std::cin.ignore();
            std::cout << "Nome: "; std::getline(std::cin, nome);
            std::cout << "Carga Horária: "; std::cin >> carga;
            sistema.addDisciplina(Disciplina{codigo, nome, carga});
        } else {
            std::cout << "Opção inválida.\n";
        }
    }

    try {
        persist.saveAll(sistema);
        std::cout << "Dados salvos com sucesso.\n";
    } catch (const std::exception& e) {
        std::cerr << "Falha ao salvar no encerramento: " << e.what() << "\n";
    }
    return 0;
}
