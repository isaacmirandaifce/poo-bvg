#include <iostream>
#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

void exibirTipoUsuario(TipoUsuario tipo) {
    switch (tipo) {
        case TipoUsuario::ALUNO:
            std::cout << "Tipo de Usuario: Aluno" << std::endl;
            break;
        case TipoUsuario::PROFESSOR:
            std::cout << "Tipo de Usuario: Professor" << std::endl;
            break;
        case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO:
            std::cout << "Tipo de Usuario: Funcionario Administrativo" << std::endl;
            break;
    }
}

int main() {
    auto aluno = std::make_unique<Aluno>("Samela Farias", "111.222.333-44", "senha123", "20241ADS001");
    aluno->getHistorico().adicionarDisciplina("Programacao Orientada a Objetos", 2024, 9.5f);
    aluno->getHistorico().adicionarDisciplina("Estrutura de Dados", 2024, 8.0f);

    auto professor = std::make_unique<Professor>("Joao", "444.555.666-77", "prof#abc", "Ciencia da Computacao");
    professor->adicionarDisciplinaLecionada("Inteligencia Artificial");
    professor->adicionarDisciplinaLecionada("Teoria da Computacao");

    auto funcionario = std::make_unique<FuncionarioAdministrativo>("Ana Sousa", "777.888.999-00", "admin@secret", "Coordenadora de Curso");

    std::vector<UsuarioAutenticavel*> usuarios;
    usuarios.push_back(aluno.get());
    usuarios.push_back(professor.get());
    usuarios.push_back(funcionario.get());

    std::cout << "--- Sistema de Gestão Academica ---\n\n";

    for (const auto* user : usuarios) {
        std::cout << "-----------------------------------------\n";
        std::cout << "Tentando autenticar o usuario: " << user->getNome() << std::endl;
        exibirTipoUsuario(user->getTipo());

        // Teste de autenticação
        if (user->autenticar("senha_errada")) {
            std::cout << "Autenticacao (com senha errada) bem-sucedida!\n";
        } else {
            std::cout << "Autenticacao (com senha errada) falhou.\n";
        }

        std::string senhaCorreta;
        if (dynamic_cast<const Aluno*>(user)) senhaCorreta = "senha123";
        if (dynamic_cast<const Professor*>(user)) senhaCorreta = "prof#abc";
        if (dynamic_cast<const FuncionarioAdministrativo*>(user)) senhaCorreta = "admin@secret";

        if (user->autenticar(senhaCorreta)) {
            std::cout << "Autenticacao (com senha correta) bem-sucedida!\n\n";

            // Geração de Relatório (usando a interface Relatorio)
            // É necessário fazer um cast para acessar o método da interface
            const Relatorio* relatorio = dynamic_cast<const Relatorio*>(user);
            if (relatorio) {
                std::cout << relatorio->gerarRelatorio();
            }
        } else {
             std::cout << "Autenticacao (com senha correta) falhou.\n";
        }
    }
    std::cout << "-----------------------------------------\n";

    return 0;
}