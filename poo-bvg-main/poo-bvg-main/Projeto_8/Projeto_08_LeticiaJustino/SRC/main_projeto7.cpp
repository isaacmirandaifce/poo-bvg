#include <iostream>
#include <memory>
#include "headers/SistemaAcademico.h"
#include "headers/Aluno.h"
#include "headers/Professor.h"
#include "headers/FuncionarioAdministrativo.h"
#include "headers/Filtro.h"
#include "headers/FiltroAcademico.h"

void demonstrarFiltros() {
    std::cout << "=== DEMONSTRAÇÃO DE FILTROS GENÉRICOS ===" << std::endl << std::endl;

    // Criando alguns alunos para teste
    Aluno aluno1("João Silva", "joao@email.com", "2023001", "senha123", "ADS");
    aluno1.adicionarDisciplina("Programação OO", 2023, 8.5);
    aluno1.adicionarDisciplina("Banco de Dados", 2023, 9.0);

    Aluno aluno2("Maria Santos", "maria@email.com", "2023002", "senha456", "SI");
    aluno2.adicionarDisciplina("Programação OO", 2023, 7.0);
    aluno2.adicionarDisciplina("Matemática", 2023, 6.5);

    Aluno aluno3("Pedro Costa", "pedro@email.com", "2023003", "senha789", "ADS");
    aluno3.adicionarDisciplina("Programação OO", 2023, 9.5);
    aluno3.adicionarDisciplina("Banco de Dados", 2023, 8.0);

    // Criando filtro genérico de alunos
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(aluno1);
    filtroAlunos.adicionarElemento(aluno2);
    filtroAlunos.adicionarElemento(aluno3);

    std::cout << "1. TODOS OS ALUNOS:" << std::endl;
    filtroAlunos.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });
    std::cout << std::endl;

    // Filtro por média >= 7.0
    auto alunosAprovados = FiltroAcademico::filtrarAlunosPorMedia(filtroAlunos, 7.0);
    std::cout << "2. ALUNOS COM MÉDIA >= 7.0:" << std::endl;
    alunosAprovados.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });
    std::cout << std::endl;

    // Ordenação por nome
    auto alunosOrdenadosNome = FiltroAcademico::ordenarAlunosPorNome(filtroAlunos);
    std::cout << "3. ALUNOS ORDENADOS POR NOME:" << std::endl;
    alunosOrdenadosNome.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });
    std::cout << std::endl;

    // Ordenação por média (decrescente)
    auto alunosOrdenadosMedia = FiltroAcademico::ordenarAlunosPorMedia(filtroAlunos);
    std::cout << "4. ALUNOS ORDENADOS POR MÉDIA (DECRESCENTE):" << std::endl;
    alunosOrdenadosMedia.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });
    std::cout << std::endl;

    // Filtro personalizado por curso
    auto alunosADS = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getCurso() == "ADS";
    });
    std::cout << "5. ALUNOS DO CURSO ADS:" << std::endl;
    alunosADS.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });
    std::cout << std::endl;

    // Demonstração com professores
    Professor prof1("Ana Lima", "ana@email.com", "PROF001", "senha123", "Tecnologia");
    prof1.adicionarDisciplina("Programação OO");
    prof1.adicionarDisciplina("Estrutura de Dados");

    Professor prof2("Carlos Souza", "carlos@email.com", "PROF002", "senha456", "Matemática");
    prof2.adicionarDisciplina("Cálculo");
    prof2.adicionarDisciplina("Álgebra");

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(prof1);
    filtroProfessores.adicionarElemento(prof2);

    std::cout << "6. TODOS OS PROFESSORES:" << std::endl;
    filtroProfessores.aplicarAcao([](const Professor& professor) {
        std::cout << "   " << professor << std::endl;
    });
    std::cout << std::endl;

    // Filtro de professores por departamento
    auto professoresTech = FiltroAcademico::filtrarProfessoresPorDepartamento(filtroProfessores, "Tecnologia");
    std::cout << "7. PROFESSORES DE TECNOLOGIA:" << std::endl;
    professoresTech.aplicarAcao([](const Professor& professor) {
        std::cout << "   " << professor << std::endl;
    });
}

int main() {
    // Demonstrar funcionalidades dos filtros
    demonstrarFiltros();

    std::cout << std::endl << "=== INTEGRAÇÃO COM SISTEMA EXISTENTE ===" << std::endl;
    
    // Usando o sistema acadêmico existente do Projeto 6
    SistemaAcademico sistema;
    
    auto aluno1 = std::make_shared<Aluno>("Ana Costa", "ana@email.com", "2024001", "senha123", "ADS");
    aluno1->adicionarDisciplina("Programação OO", 2024, 9.0);
    aluno1->adicionarDisciplina("Banco de Dados", 2024, 8.5);
    
    auto aluno2 = std::make_shared<Aluno>("Bruno Oliveira", "bruno@email.com", "2024002", "senha456", "SI");
    aluno2->adicionarDisciplina("Programação OO", 2024, 6.5);
    aluno2->adicionarDisciplina("Matemática", 2024, 7.0);
    
    sistema.adicionarUsuario(aluno1);
    sistema.adicionarUsuario(aluno2);

    // Usando os novos métodos de filtro do sistema
    auto todosAlunos = sistema.obterTodosAlunos();
    auto alunosDestaque = FiltroAcademico::filtrarAlunosPorMedia(todosAlunos, 8.0);
    
    std::cout << "Alunos com média >= 8.0 no sistema:" << std::endl;
    alunosDestaque.aplicarAcao([](const Aluno& aluno) {
        std::cout << "   " << aluno << std::endl;
    });

    return 0;
}