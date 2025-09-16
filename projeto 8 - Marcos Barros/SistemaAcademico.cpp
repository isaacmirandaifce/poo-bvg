#include "SistemaAcademico.h"
#include "Persistencia.h"
#include <iostream>

// --- CARREGAMENTO AUTOMÁTICO ---
void SistemaAcademico::carregarDados() {
    // Tenta carregar Alunos
    try {
        alunos = Persistencia::carregar<Aluno>(ARQUIVO_ALUNOS);
        std::cout << "Info: " << alunos.size() << " aluno(s) carregado(s)." << std::endl;
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cout << "Aviso: " << e.what() << ". Um novo arquivo será criado." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERRO CRÍTICO ao carregar alunos: " << e.what() << std::endl;
    }

    // Tenta carregar Professores
    try {
        professores = Persistencia::carregar<Professor>(ARQUIVO_PROFESSORES);
        std::cout << "Info: " << professores.size() << " professor(es) carregado(s)." << std::endl;
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cout << "Aviso: " << e.what() << ". Um novo arquivo será criado." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERRO CRÍTICO ao carregar professores: " << e.what() << std::endl;
    }

    // Tenta carregar Disciplinas
    try {
        disciplinas = Persistencia::carregar<Disciplina>(ARQUIVO_DISCIPLINAS);
        std::cout << "Info: " << disciplinas.size() << " disciplina(s) carregada(s)." << std::endl;
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cout << "Aviso: " << e.what() << ". Um novo arquivo será criado." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERRO CRÍTICO ao carregar disciplinas: " << e.what() << std::endl;
    }
}

// --- SALVAMENTO ---
// O salvamento de todos os dados pode ser chamado por qualquer função que modifique os dados.
void SistemaAcademico::salvarDados() const {
    try {
        Persistencia::salvar(alunos, ARQUIVO_ALUNOS);
        Persistencia::salvar(professores, ARQUIVO_PROFESSORES);
        Persistencia::salvar(disciplinas, ARQUIVO_DISCIPLINAS);
        std::cout << "Info: Dados salvos em disco." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERRO AO SALVAR DADOS: " << e.what() << std::endl;
    }
}

// --- MÉTODOS DE MODIFICAÇÃO (COM SALVAMENTO AUTOMÁTICO) ---
void SistemaAcademico::adicionarAluno(const Aluno& aluno) {
    alunos.push_back(aluno);
    std::cout << "Aluno " << aluno.nome << " adicionado." << std::endl;
    salvarDados(); // SALVA AUTOMATICAMENTE
}

void SistemaAcademico::adicionarProfessor(const Professor& prof) {
    professores.push_back(prof);
    std::cout << "Professor " << prof.nome << " adicionado." << std::endl;
    salvarDados(); // SALVA AUTOMATICAMENTE
}

void SistemaAcademico::adicionarDisciplina(const Disciplina& disc) {
    disciplinas.push_back(disc);
    std::cout << "Disciplina " << disc.nome << " adicionada." << std::endl;
    salvarDados(); // SALVA AUTOMATICAMENTE
}


// --- MÉTODOS DE LISTAGEM (NÃO PRECISAM SALVAR) ---
void SistemaAcademico::listarAlunos() const {
    std::cout << "\n--- Lista de Alunos ---\n";
    if (alunos.empty()) std::cout << "Nenhum aluno cadastrado.\n";
    for (const auto& aluno : alunos) {
        std::cout << "Matrícula: " << aluno.matricula << ", Nome: " << aluno.nome << std::endl;
    }
}

void SistemaAcademico::listarProfessores() const {
    std::cout << "\n--- Lista de Professores ---\n";
    if (professores.empty()) std::cout << "Nenhum professor cadastrado.\n";
    for (const auto& prof : professores) {
        std::cout << "ID: " << prof.id << ", Nome: " << prof.nome << std::endl;
    }
}

void SistemaAcademico::listarDisciplinas() const {
    std::cout << "\n--- Lista de Disciplinas ---\n";
    if (disciplinas.empty()) std::cout << "Nenhuma disciplina cadastrada.\n";
    for (const auto& disc : disciplinas) {
        std::cout << "Código: " << disc.codigo << ", Nome: " << disc.nome << std::endl;
    }
}

void SistemaAcademico::simularFalhaDeSegmentacao() {
    std::cout << "Simulando falha de segmentação..." << std::endl;
    int* ptr = nullptr;
    *ptr = 42;
}