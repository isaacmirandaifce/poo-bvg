#include <iostream>
#include <string>
#include <vector>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "SistemaRelatorios.h"

/**
 * Função para popular dados de teste do sistema acadêmico
 */
void popularDadosTeste(Filtro<Aluno>& filtroAlunos,
                      Filtro<Professor>& filtroProfessores,
                      Filtro<Disciplina>& filtroDisciplinas) {

    // Adicionando alunos de teste
    std::cout << "Populando dados de teste..." << std::endl;

    // Alunos
    filtroAlunos.adicionarElemento(Aluno("Ana Silva", "2021001", 2021, 8.5));
    filtroAlunos.adicionarElemento(Aluno("Carlos Santos", "2021002", 2021, 6.8));
    filtroAlunos.adicionarElemento(Aluno("Maria Oliveira", "2022001", 2022, 9.2));
    filtroAlunos.adicionarElemento(Aluno("João Pereira", "2022002", 2022, 7.3));
    filtroAlunos.adicionarElemento(Aluno("Pedro Lima", "2023001", 2023, 5.9));
    filtroAlunos.adicionarElemento(Aluno("Julia Costa", "2023002", 2023, 8.8));
    filtroAlunos.adicionarElemento(Aluno("Lucas Ferreira", "2021003", 2021, 7.1));

    // Adicionando disciplinas para alguns alunos
    filtroAlunos[0].adicionarDisciplina("Cálculo I");
    filtroAlunos[0].adicionarDisciplina("Programação I");
    filtroAlunos[1].adicionarDisciplina("Cálculo I");
    filtroAlunos[2].adicionarDisciplina("Estrutura de Dados");
    filtroAlunos[3].adicionarDisciplina("Programação I");
    filtroAlunos[4].adicionarDisciplina("Cálculo I");

    // Professores
    filtroProfessores.adicionarElemento(Professor("Dr. Roberto Nascimento", "Matemática", "Cálculo", 15));
    filtroProfessores.adicionarElemento(Professor("Dra. Fernanda Alves", "Computação", "Programação", 12));
    filtroProfessores.adicionarElemento(Professor("Dr. Marcus Rocha", "Computação", "Algoritmos", 8));
    filtroProfessores.adicionarElemento(Professor("Dra. Carolina Souza", "Matemática", "Álgebra", 20));
    filtroProfessores.adicionarElemento(Professor("Dr. Antonio Silva", "Física", "Mecânica", 18));

    // Adicionando disciplinas para os professores
    filtroProfessores[0].adicionarDisciplina("Cálculo I");
    filtroProfessores[0].adicionarDisciplina("Cálculo II");
    filtroProfessores[1].adicionarDisciplina("Programação I");
    filtroProfessores[1].adicionarDisciplina("Programação II");
    filtroProfessores[2].adicionarDisciplina("Estrutura de Dados");
    filtroProfessores[2].adicionarDisciplina("Algoritmos");
    filtroProfessores[3].adicionarDisciplina("Álgebra Linear");
    filtroProfessores[4].adicionarDisciplina("Física I");

    // Disciplinas
    filtroDisciplinas.adicionarElemento(Disciplina("MAT101", "Cálculo I", "Dr. Roberto Nascimento", 60, 4, 2023));
    filtroDisciplinas.adicionarElemento(Disciplina("CCP101", "Programação I", "Dra. Fernanda Alves", 80, 4, 2023));
    filtroDisciplinas.adicionarElemento(Disciplina("CCP201", "Estrutura de Dados", "Dr. Marcus Rocha", 80, 4, 2022));
    filtroDisciplinas.adicionarElemento(Disciplina("MAT201", "Cálculo II", "Dr. Roberto Nascimento", 60, 4, 2022));
    filtroDisciplinas.adicionarElemento(Disciplina("FIS101", "Física I", "Dr. Antonio Silva", 80, 5, 2023));
    filtroDisciplinas.adicionarElemento(Disciplina("MAT301", "Álgebra Linear", "Dra. Carolina Souza", 60, 3, 2021));
    filtroDisciplinas.adicionarElemento(Disciplina("CCP301", "Algoritmos", "Dr. Marcus Rocha", 60, 3, 2021));

    std::cout << "Dados populados com sucesso!" << std::endl;
}

/**
 * Demonstra funcionalidades básicas da classe Filtro
 */
void demonstrarFuncionalidadesBasicas() {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "DEMONSTRAÇÃO DAS FUNCIONALIDADES BÁSICAS DA CLASSE FILTRO" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    // Criando um filtro simples com números
    Filtro<int> numeros;
    numeros.adicionarElemento(10);
    numeros.adicionarElemento(25);
    numeros.adicionarElemento(5);
    numeros.adicionarElemento(30);
    numeros.adicionarElemento(15);

    std::cout << "\n--- Números originais ---" << std::endl;
    numeros.imprimirTodos([](const int& num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    // Filtrar números maiores que 15
    auto numerosMaiores = numeros.filtrarPorCondicao([](const int& num) {
        return num > 15;
    });

    std::cout << "\n--- Números > 15 ---" << std::endl;
    numerosMaiores.imprimirTodos([](const int& num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    // Ordenar números
    auto numerosOrdenados = numeros.obterOrdenadoPorCriterio([](const int& a, const int& b) {
        return a < b;
    });

    std::cout << "\n--- Números ordenados (crescente) ---" << std::endl;
    numerosOrdenados.imprimirTodos([](const int& num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    // Contar elementos que satisfazem condição
    size_t count = numeros.contarPorCondicao([](const int& num) {
        return num % 5 == 0;
    });
    std::cout << "\n--- Números divisíveis por 5: " << count << " ---" << std::endl;
}

/**
 * Demonstra todas as funcionalidades do sistema acadêmico
 */
void demonstrarSistemaAcademico() {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "SISTEMA GENÉRICO DE FILTRAGEM E RELATÓRIOS ACADÊMICOS" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    // Criando filtros para cada tipo de objeto
    Filtro<Aluno> filtroAlunos;
    Filtro<Professor> filtroProfessores;
    Filtro<Disciplina> filtroDisciplinas;

    // Populando dados de teste
    popularDadosTeste(filtroAlunos, filtroProfessores, filtroDisciplinas);

    // 1. Relatório de alunos com média acima de 7.0
    SistemaRelatorios::relatorioAlunosMediaAlta(filtroAlunos, 7.0);

    // 2. Relatório de professores que ministram "Cálculo I"
    SistemaRelatorios::relatorioProfessoresDisciplina(filtroProfessores, "Cálculo I");

    // 3. Relatório de disciplinas cursadas em 2023
    SistemaRelatorios::relatorioDisciplinasPorAno(filtroDisciplinas, 2023);

    // 4. Relatório de médias por ano
    SistemaRelatorios::relatorioMediasPorAno(filtroAlunos);

    // 5. Estatísticas gerais
    SistemaRelatorios::relatorioEstatisticas(filtroAlunos, "ALUNOS");
    SistemaRelatorios::relatorioEstatisticas(filtroProfessores, "PROFESSORES");
    SistemaRelatorios::relatorioEstatisticas(filtroDisciplinas, "DISCIPLINAS");
}

/**
 * Demonstra funcionalidades avançadas de filtragem
 */
void demonstrarFuncionalidadesAvancadas() {
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "FUNCIONALIDADES AVANÇADAS DE FILTRAGEM" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    Filtro<Aluno> filtroAlunos;

    // Adicionando alguns alunos
    filtroAlunos.adicionarElemento(Aluno("Alice", "A001", 2023, 8.5));
    filtroAlunos.adicionarElemento(Aluno("Bruno", "B002", 2022, 6.5));
    filtroAlunos.adicionarElemento(Aluno("Carlos", "C003", 2023, 9.0));
    filtroAlunos.adicionarElemento(Aluno("Diana", "D004", 2021, 7.8));

    std::cout << "\n--- Demonstração: algumSatisfaz() ---" << std::endl;
    bool temMediaAlta = filtroAlunos.algumSatisfaz([](const Aluno& aluno) {
        return aluno.getMedia() >= 9.0;
    });
    std::cout << "Existe algum aluno com média >= 9.0? " << (temMediaAlta ? "Sim" : "Não") << std::endl;

    std::cout << "\n--- Demonstração: todosSatisfazem() ---" << std::endl;
    bool todosAprovados = filtroAlunos.todosSatisfazem([](const Aluno& aluno) {
        return aluno.getMedia() >= 6.0;
    });
    std::cout << "Todos os alunos estão aprovados (média >= 6.0)? " << (todosAprovados ? "Sim" : "Não") << std::endl;

    std::cout << "\n--- Demonstração: buscarPrimeiro() ---" << std::endl;
    bool encontrado;
    Aluno alunoEncontrado = filtroAlunos.buscarPrimeiro([](const Aluno& aluno) {
        return aluno.getAno() == 2021;
    }, encontrado);

    if (encontrado) {
        std::cout << "Primeiro aluno de 2021 encontrado: " << alunoEncontrado.getNome() << std::endl;
    } else {
        std::cout << "Nenhum aluno de 2021 encontrado." << std::endl;
    }

    std::cout << "\n--- Demonstração: removerPorCondicao() ---" << std::endl;
    std::cout << "Alunos antes da remoção: " << filtroAlunos.tamanho() << std::endl;
    filtroAlunos.removerPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() < 7.0;
    });
    std::cout << "Alunos após remover os com média < 7.0: " << filtroAlunos.tamanho() << std::endl;

    std::cout << "\n--- Alunos restantes ---" << std::endl;
    filtroAlunos.imprimirTodos([](const Aluno& aluno) {
        std::cout << aluno << std::endl;
    });
}

/**
 * Menu interativo para demonstrar as funcionalidades
 */
void menuInterativo() {
    int opcao;
    do {
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "MENU PRINCIPAL - SISTEMA DE FILTRAGEM GENÉRICA" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        std::cout << "1. Demonstrar funcionalidades básicas" << std::endl;
        std::cout << "2. Demonstrar sistema acadêmico completo" << std::endl;
        std::cout << "3. Demonstrar funcionalidades avançadas" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "Escolha uma opção: ";

        std::cin >> opcao;

        switch (opcao) {
            case 1:
                demonstrarFuncionalidadesBasicas();
                break;
            case 2:
                demonstrarSistemaAcademico();
                break;
            case 3:
                demonstrarFuncionalidadesAvancadas();
                break;
            case 0:
                std::cout << "\nEncerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "\nOpção inválida! Tente novamente." << std::endl;
        }

        if (opcao != 0) {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (opcao != 0);
}

/**
 * Função principal
 */
int main() {
    std::cout << "Bem-vindo ao Sistema Genérico de Filtragem e Relatórios Acadêmicos!" << std::endl;
    std::cout << "Este sistema demonstra o uso de templates e métodos genéricos em C++." << std::endl;

    menuInterativo();

    return 0;
}
