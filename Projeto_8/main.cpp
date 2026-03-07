#include <iostream>
#include <vector>

#include "Persistencia.h"
#include "SinalHandler.h"
#include "Aluno.h"

int main() {

    SinalHandler::inicializar();

    std::vector<Aluno> alunos;

    std::cout << "Sistema Acadêmico iniciado.\n";

    try {

        alunos = Persistencia::carregarAlunos("alunos.txt");
        std::cout << "Dados carregados com sucesso.\n";

    }
    catch (const std::exception& e) {

        std::cout << "Erro ao carregar dados: " << e.what() << std::endl;
        std::cout << "Sistema iniciará sem dados.\n";

    }

    int opcao = -1;

    while (opcao != 0) {

        std::cout << "\n===== MENU =====\n";
        std::cout << "1 - Listar alunos\n";
        std::cout << "2 - Adicionar aluno\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";

        std::cin >> opcao;

        if (opcao == 1) {

            std::cout << "\nLista de alunos:\n";

            for (const auto& a : alunos) {
                std::cout << "- " << a.getNome() << std::endl;
            }

        }

        if (opcao == 2) {

            std::string nome;
            std::string senha;

            std::cout << "Nome do aluno: ";
            std::cin >> nome;

            std::cout << "Senha: ";
            std::cin >> senha;

            alunos.emplace_back(nome, senha);

            try {

                Persistencia::salvarAlunos("alunos.txt", alunos);
                std::cout << "Aluno salvo com sucesso.\n";

            }
            catch (const std::exception& e) {

                std::cout << "Erro ao salvar: " << e.what() << std::endl;

            }

        }

    }

    std::cout << "Encerrando sistema...\n";

    return 0;
}
