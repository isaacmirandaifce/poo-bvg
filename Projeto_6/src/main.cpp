#include <iostream>
#include <memory>
#include "SistemaGestaoAcademica.h"

void demonstrarSistema() {
    SistemaGestaoAcademica sistema;

    // Criando alunos
    auto aluno1 = std::make_unique<Aluno>("João Silva", "joao@email.com", 1001,
                                         "senha123", "Análise e Desenvolvimento de Sistemas", 3);
    aluno1->adicionarDisciplina("Programação Orientada a Objetos", 2023, 8.5);
    aluno1->adicionarDisciplina("Banco de Dados", 2023, 9.0);
    aluno1->adicionarDisciplina("Estruturas de Dados", 2024, 7.8);

    auto aluno2 = std::make_unique<Aluno>("Maria Santos", "maria@email.com", 1002,
                                         "maria456", "Engenharia de Software", 2);
    aluno2->adicionarDisciplina("Algoritmos", 2023, 9.2);
    aluno2->adicionarDisciplina("Matemática Discreta", 2024, 8.0);

    // Criando professores
    auto professor1 = std::make_unique<Professor>("Dr. Carlos Oliveira", "carlos@universidade.edu", 2001,
                                                 "prof123", "Computação", "Doutor");
    professor1->adicionarDisciplina("Programação Orientada a Objetos");
    professor1->adicionarDisciplina("Estruturas de Dados");

    auto professor2 = std::make_unique<Professor>("Profa. Ana Costa", "ana@universidade.edu", 2002,
                                                 "ana789", "Matemática", "Mestra");
    professor2->adicionarDisciplina("Cálculo I");
    professor2->adicionarDisciplina("Álgebra Linear");

    // Criando funcionários administrativos
    auto funcionario1 = std::make_unique<FuncionarioAdministrativo>("Roberto Admin", "roberto@universidade.edu", 3001,
                                                                   "admin123", "Secretaria Acadêmica",
                                                                   "Coordenador", 5500.00);

    auto funcionario2 = std::make_unique<FuncionarioAdministrativo>("Lucia Financeiro", "lucia@universidade.edu", 3002,
                                                                   "lucia456", "Financeiro",
                                                                   "Analista", 4200.00);

    // Adicionando usuários ao sistema
    sistema.adicionarAluno(std::move(aluno1));
    sistema.adicionarAluno(std::move(aluno2));
    sistema.adicionarProfessor(std::move(professor1));
    sistema.adicionarProfessor(std::move(professor2));
    sistema.adicionarFuncionario(std::move(funcionario1));
    sistema.adicionarFuncionario(std::move(funcionario2));

    std::cout << "=== SISTEMA AVANÇADO DE GESTÃO ACADÊMICA ===" << std::endl;
    std::cout << "Sistema inicializado com sucesso!" << std::endl;

    // Exibir estatísticas
    sistema.exibirEstatisticasTipoUsuario();

    // Demonstração de autenticação
    std::cout << "\n=== DEMONSTRAÇÃO DE AUTENTICAÇÃO ===" << std::endl;

    // Tentativa de login válida
    UsuarioAutenticavel* usuarioLogado = sistema.autenticarUsuario(1001, "senha123");
    if (usuarioLogado) {
        std::cout << "Login realizado com sucesso para: " << usuarioLogado->getNome() << std::endl;
        usuarioLogado->exibirInformacoes();
    }

    // Tentativa de login inválida
    UsuarioAutenticavel* loginInvalido = sistema.autenticarUsuario(1001, "senhaerrada");
    if (!loginInvalido) {
        std::cout << "\nLogin falhou - senha incorreta" << std::endl;
    }

    // Gerar relatórios de todos os usuários
    sistema.gerarRelatoriosGerais();

    // Buscar usuários por tipo
    std::cout << "\n=== BUSCA POR TIPO DE USUÁRIO ===" << std::endl;
    auto alunos = sistema.buscarUsuariosPorTipo(TipoUsuario::ALUNO);
    std::cout << "Alunos encontrados: " << alunos.size() << std::endl;
    for (auto* aluno : alunos) {
        std::cout << "- " << aluno->getNome() << " (ID: " << aluno->getId() << ")" << std::endl;
    }

    // Demonstração da classe interna HistoricoDisciplinar
    std::cout << "\n=== DEMONSTRAÇÃO DA CLASSE INTERNA ===" << std::endl;
    UsuarioAutenticavel* alunoEncontrado = sistema.buscarUsuarioPorId(1001);
    if (alunoEncontrado && alunoEncontrado->getTipo() == TipoUsuario::ALUNO) {
        Aluno* aluno = dynamic_cast<Aluno*>(alunoEncontrado);
        if (aluno) {
            std::cout << "Histórico do aluno " << aluno->getNome() << ":" << std::endl;
            aluno->exibirHistoricoCompleto();
        }
    }

    // Exibir todos os usuários
    sistema.exibirTodosUsuarios();

    std::cout << "\n=== DEMONSTRAÇÃO CONCLUÍDA ===" << std::endl;
}

int main() {
    try {
        demonstrarSistema();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
