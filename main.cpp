#include <iostream>
#include <vector>
#include "Persistencia.h"
#include "SinalHandler.h"

void salvarDados() {
    try {
        std::vector<std::string> dados = {"Aluno1,Matematica", "Aluno2,Fisica"};
        Persistencia::salvar("dados.txt", dados);
        std::cout << "Dados salvos com sucesso!\n";
    } catch (const Persistencia::ErroArquivo& e) {
        std::cerr << "ERRO: " << e.what() << "\n";
    }
}

int main() {
    SinalHandler::configurar();
    SinalHandler::setFuncaoSaida(salvarDados);
    
    try {
        auto dados = Persistencia::carregar("dados.txt");
        std::cout << "Dados carregados:\n";
        for (const auto& linha : dados) {
            std::cout << linha << "\n";
        }
    } catch (const Persistencia::ErroArquivo& e) {
        std::cerr << "AVISO: " << e.what() << " - Iniciando com dados vazios\n";
    }
    
    std::cout << "Pressione Ctrl+C para testar o tratamento de sinal\n";
    while (true) {
        // Simula o programa em execução
    }
    
    return 0;
}