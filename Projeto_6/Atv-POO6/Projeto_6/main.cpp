#include <iostream>
#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

void autenticarUsuario(UsuarioAutenticavel* usuario, const std::string& senha) {
    if (usuario->autenticar(senha)) {
        std::cout << "Autenticação bem-sucedida para " << usuario->getNome() << "!\n";
        usuario->gerarRelatorio();
    } else {
        std::cout << "Autenticação falhou para " << usuario->getNome() << ".\n";
    }
}

int main() {
    // Lista de usuários do sistema
    std::vector<std::unique_ptr<UsuarioAutenticavel>> usuarios;

    // Criação de usuários
    auto aluno = std::make_unique<Aluno>("Rikelme", "rikelme@email.com", "2025001", "ADS", "senha123");
    aluno->adicionarDisciplina("Algoritmos");
    aluno->adicionarHistorico("Algoritmos", 2023, 9.5);
    aluno->adicionarDisciplina("Banco de Dados");
    aluno->adicionarHistorico("Banco de Dados", 2024, 8.7);
    usuarios.push_back(std::move(aluno));

    auto professor = std::make_unique<Professor>("Maria", "maria@email.com", "Computação", "senhaProf");
    professor->adicionarDisciplina("Estruturas de Dados");
    professor->adicionarDisciplina("POO Avançada");
    usuarios.push_back(std::move(professor));

    auto funcionario = std::make_unique<FuncionarioAdministrativo>("Hamilton", "hamilton@email.com", "RH", "Coordenador", "senhaRH");
    usuarios.push_back(std::move(funcionario));

    // Teste de autenticação para cada usuário
    for (const auto& usuario : usuarios) {
        std::string senhaTentativa;
        std::cout << "Digite a senha para o usuário " << usuario->getNome() << ": ";
        std::cin >> senhaTentativa;

        autenticarUsuario(usuario.get(), senhaTentativa);
        std::cout << "\n";
    }

    return 0;
}
