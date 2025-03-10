#include <iostream>
#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include "Filtro.h" // Inclui a classe genérica Filtro
#include "Persistencia.h" // Inclui a classe Persistencia
#include "SinalHandler.h" // Inclui a classe SinalHandler

// Função de autenticação já existente
void autenticarUsuario(UsuarioAutenticavel* usuario, const std::string& senha) {
    if (usuario->autenticar(senha)) {
        std::cout << "Autenticação bem-sucedida para " << usuario->getNome() << "!\n";
        usuario->gerarRelatorio();
    } else {
        std::cout << "Autenticação falhou para " << usuario->getNome() << ".\n";
    }
}

int main() {
    // Listas de dados
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    // Carregar dados persistentes, caso existam
    Persistencia::carregarDados(alunos, professores, disciplinas);

    // Configura o tratamento de sinais para salvar os dados ao encerrar o programa
    SinalHandler::configurarHandler(alunos, professores, disciplinas);

    // Lista de usuários do sistema (agora com Aluno, Professor e Funcionario)
    std::vector<std::unique_ptr<UsuarioAutenticavel>> usuarios;

    // Criação de usuários
    auto aluno = std::make_unique<Aluno>("Rikelme", "rikelme@email.com",
                        "2025001", "ADS", "senha123");
    aluno->adicionarDisciplina("Algoritmos");
    aluno->adicionarHistorico("Algoritmos", 2023, 9.5);
    aluno->adicionarDisciplina("Banco de Dados");
    aluno->adicionarHistorico("Banco de Dados", 2024, 8.7);
    usuarios.push_back(std::move(aluno));

    auto professor = std::make_unique<Professor>("Maria", "maria@email.com",
                                                   "Computação", "senhaProf");
    professor->adicionarDisciplina("Estruturas de Dados");
    professor->adicionarDisciplina("POO Avançada");
    usuarios.push_back(std::move(professor));

    auto funcionario = std::make_unique<FuncionarioAdministrativo>("Hamilton",
                                  "hamilton@email.com",
                                  "RH", "Coordenador", "senhaRH");
    usuarios.push_back(std::move(funcionario));

    // Teste de autenticação para cada usuário
    for (const auto& usuario : usuarios) {
        std::string senhaTentativa;
        std::cout << "Digite a senha para o usuário " << usuario->getNome() << ": ";
        std::cin >> senhaTentativa;
        autenticarUsuario(usuario.get(), senhaTentativa);
        std::cout << "\n";
    }

    // ---------- Utilizando Filtro para Alunos ----------
    // Cria um filtro para objetos do tipo Aluno*
    Filtro<Aluno*> filtroAlunos;
    for (const auto& usuario : usuarios) {
        // Tenta converter para Aluno (para filtrar apenas os alunos)
        if (Aluno* alunoPtr = dynamic_cast<Aluno*>(usuario.get())) {
            filtroAlunos.adicionarElemento(alunoPtr);
        }
    }

    // Filtra os alunos com média acima de 7.0
    auto alunosComMediaAlta = filtroAlunos.filtrarPorCondicao([](const Aluno* aluno) -> bool {
        return aluno->calcularMedia() > 7.0;
    });

    std::cout << "\nAlunos com média acima de 7.0:\n";
    // Utiliza o método imprimirTodos para exibir os alunos filtrados
    for (const auto* aluno : alunosComMediaAlta) {
        std::cout << aluno->getNome() << " - Média: " << aluno->calcularMedia() << "\n";
    }

    // ---------- Utilizando Filtro para Professores ----------
    // Cria um filtro para objetos do tipo Professor*
    Filtro<Professor*> filtroProfessores;
    for (const auto& usuario : usuarios) {
        if (Professor* profPtr = dynamic_cast<Professor*>(usuario.get())) {
            filtroProfessores.adicionarElemento(profPtr);
        }
    }

    std::string disciplinaBuscada = "POO Avançada";
    auto professoresDaDisciplina = filtroProfessores.filtrarPorCondicao(
        [&](const Professor* prof) -> bool {
            return prof->lecionaDisciplina(disciplinaBuscada);
        }
    );

    std::cout << "\nProfessores que ministram " << disciplinaBuscada << ":\n";
    for (const auto* prof : professoresDaDisciplina) {
        std::cout << prof->getNome() << "\n";
    }

    // ---------- Exemplo de Ordenação ----------
    // Ordena os alunos por média de forma decrescente
    filtroAlunos.ordenar([](const Aluno* a, const Aluno* b) -> bool {
        return a->calcularMedia() > b->calcularMedia();
    });

    std::cout << "\nAlunos ordenados por média (decrescente):\n";
    filtroAlunos.imprimirTodos([](const Aluno* aluno) {
        std::cout << aluno->getNome() << " - Média: " << aluno->calcularMedia() << "\n";
    });

    // ---------- Listar Disciplinas de um Aluno em um Determinado Ano ----------
    int anoDesejado = 2024;
    if (!alunosComMediaAlta.empty()) {
        // Utiliza o primeiro aluno da lista como exemplo
        Aluno* alunoExemplo = alunosComMediaAlta.front();
        auto disciplinasAno = alunoExemplo->getDisciplinasPorAno(anoDesejado);
        std::cout << "\nDisciplinas cursadas por " << alunoExemplo->getNome()
                  << " no ano " << anoDesejado << ":\n";
        for (const auto& disc : disciplinasAno) {
            std::cout << "- " << disc << "\n";
        }
    }

    // Salvar dados no final do programa
    Persistencia::salvarDados(alunos, professores, disciplinas);

    return 0;
}
