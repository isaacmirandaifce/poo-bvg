#include <iostream>
#include "../src/Aluno.h"

int main() {
    // criando um aluno
    Aluno aluno("Leticia", "leticia123", "123456", "ADS", 2025);

    // testando a autenticação
    std::string senhaCorreta = "123456";
    std::string senhaErrada = "senhaerrada";

    std::cout << "[TESTE AUTENTICAÇÃO - Correta] ";
    if (aluno.autenticar(senhaCorreta)) {
        std::cout << "Sucesso" << std::endl;
    } else {
        std::cout << "Falha" << std::endl;
    }

    std::cout << "[TESTE AUTENTICAÇÃO - Errada] ";
    if (!aluno.autenticar(senhaErrada)) {
        std::cout << "Sucesso (bloqueado corretamente)" << std::endl;
    } else {
        std::cout << "Falha (senha incorreta permitida)" << std::endl;
    }

    // teste de geração de relatório (polimorfismo)
    std::cout << "\n[TESTE RELATÓRIO]\n";
    aluno.gerarRelatorio();

    return 0;
}
