#include <iostream>
#include <vector>
#include "Persistencia.h"
#include "SinalHandler.h"
#include "Aluno.h"
#include "ArquivoNaoEncontradoException.h"

int main() {
    SinalHandler::inicializar();
    Persistencia persistencia;
    std::vector<Aluno> alunos;

    try {
        alunos = persistencia.carregarDados("dados_alunos.txt");
        std::cout << "Dados carregados com sucesso." << std::endl;
        for (const auto& aluno : alunos) {
            aluno.exibirDados();
        }
    } catch (ArquivoNaoEncontradoException& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
    }

    return 0;
}
