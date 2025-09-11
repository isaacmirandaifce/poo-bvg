#include <iostream>
#include <vector>
#include <memory>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"
#include "Persistencia.h"
#include "SinalHandler.h"

void testarAutenticacaoEImprimir(std::shared_ptr<UsuarioAutenticavel> usuario, const std::string& senhaTentativa) {
    if (usuario->autenticar(senhaTentativa)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticacao.\n";
    }
}

int main() {
    std::vector<std::shared_ptr<Aluno>> alunos;
    std::vector<std::shared_ptr<Professor>> professores;

    SinalHandler::registrarDados(&alunos, &professores);
    SinalHandler::inicializar();

    try {
        alunos = Persistencia::carregarAlunos("dados/alunos.csv");
        professores = Persistencia::carregarProfessores("dados/professores.csv");
        std::cout << "[INFO] Dados carregados com sucesso.\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERRO] Problema ao carregar dados: " << e.what() << std::endl;
    }

    // criando os usuarios
    auto aluno = std::make_shared<Aluno>("Leticia Carvalho", "leticiacarvalhoads@email.com", "1234");
    auto professor = std::make_shared<Professor>("Dr. Roberto Feitosa", "roberto@ufx.br", "abcd", "Matematica");
    auto funcionario = std::make_shared<FuncionarioAdministrativo>("Felipe Alves", "felipe@adm.br", "admin", "Secretaria");

    // adicionando disciplinas no historico do aluno
    aluno->adicionarDisciplina("Algoritmos", 2023, 8.5);
    aluno->adicionarDisciplina("Estrutura de Dados", 2024, 9.0);

    // armazenando como ponteiros para interface de relatorio
    std::vector<std::shared_ptr<Relatorio>> relatorios = { aluno, professor, funcionario };

    // autenticando os usuarios
    std::cout << "Tentando autenticar aluno com senha correta:\n";
    testarAutenticacaoEImprimir(aluno, "1234");

    std::cout << "\nTentando autenticar professor com senha incorreta:\n";
    testarAutenticacaoEImprimir(professor, "errado");

    // gerando os relatorios
    std::cout << "\n--- Relatorios dos Usuarios ---\n";
    for (const auto& r : relatorios) {
        r->gerarRelatorio();
        std::cout << "------------------------------\n";
    }

    // filtro genérico
    Filtro<std::shared_ptr<Aluno>> filtroAlunos;
    Filtro<std::shared_ptr<Professor>> filtroProfessores;

    filtroAlunos.adicionarElemento(aluno);
    filtroProfessores.adicionarElemento(professor);

    std::cout << "\nAlunos com media geral acima de 7.0:\n";
    auto alunosAprovados = filtroAlunos.filtrarPorCondicao([](const std::shared_ptr<Aluno>& a) {
        return a->calcularMediaGeral() > 7.0;
    });

    for (const auto& a : alunosAprovados) {
        std::cout << a->getNome() << " - Media Geral: " << a->calcularMediaGeral() << std::endl;
    }

    std::cout << "\nProfessores de Matematica:\n";
    auto profMatematica = filtroProfessores.filtrarPorCondicao([](const std::shared_ptr<Professor>& p) {
        return p->getDisciplina() == "Matematica";
    });

    for (const auto& p : profMatematica) {
        std::cout << p->getNome() << " - Disciplina: " << p->getDisciplina() << std::endl;
    }

    // adiciona os usuarios criados nas listas principais
    alunos.push_back(aluno);
    professores.push_back(professor);

    // salva os dados automaticamente após alterações
    try {
        Persistencia::salvarAlunos(alunos, "dados/alunos.csv");
        Persistencia::salvarProfessores(professores, "dados/professores.csv");
        std::cout << "[INFO] Dados salvos com sucesso.\n";
    } catch (const std::exception& e) {
        std::cerr << "[ERRO] Falha ao salvar dados: " << e.what() << std::endl;
    }

    std::cout << "\n[INFO] Sistema em execucao. Pressione Ctrl+C para testar o tratamento de sinal.\n";

    // loop infinito simulando o sistema ativo
    while (true) {
        // sistema rodando...
    }

    return 0;
}