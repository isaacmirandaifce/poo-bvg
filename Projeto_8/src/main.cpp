#include <iostream>
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    SinalHandler::inicializar();

    try {
        auto alunos = Persistencia::carregarAlunos("dados/alunos.txt");

        std::cout << "Alunos carregados com sucesso!" << std::endl;

        Persistencia::salvarAlunos("dados/alunos.txt", alunos);

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}