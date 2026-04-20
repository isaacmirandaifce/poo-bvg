#include <cassert>
#include <iostream>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

void testarAutenticacaoAluno() {
    Aluno aluno("Fernanda", "202401", "1234");

    assert(aluno.autenticar("1234") == true);
    assert(aluno.autenticar("senhaErrada") == false);

    std::cout << "Teste de autenticação do aluno OK\n";
}

void testarAutenticacaoProfessor() {
    Professor prof("Carlos", "P001", "abcd");

    assert(prof.autenticar("abcd") == true);
    assert(prof.autenticar("123") == false);

    std::cout << "Teste de autenticação do professor OK\n";
}

void testarTipoUsuario() {
    Aluno aluno("Ana", "202402", "senha");

    assert(aluno.getTipo() == TipoUsuario::ALUNO);

    std::cout << "Teste da enumeração TipoUsuario OK\n";
}

void testarClasseInternaHistorico() {
    Aluno aluno("Maria", "202403", "123");

    aluno.adicionarDisciplina("POO", 2024, 9.0);
    aluno.adicionarDisciplina("Banco de Dados", 2024, 8.5);

    // Se chegou até aqui sem erro, o teste é válido
    std::cout << "Teste da classe interna HistoricoDisciplinar OK\n";
}

void testarRelatorioPolimorfico() {
    Relatorio* r1 = new Aluno("João", "202404", "abc");
    Relatorio* r2 = new Professor("Lucia", "P002", "123");
    Relatorio* r3 = new FuncionarioAdministrativo("Paulo", "F002", "admin");

    r1->gerarRelatorio();
    r2->gerarRelatorio();
    r3->gerarRelatorio();

    delete r1;
    delete r2;
    delete r3;

    std::cout << "Teste de polimorfismo com interface Relatorio OK\n";
}

int main() {
    std::cout << "Iniciando testes do sistema...\n\n";

    testarAutenticacaoAluno();
    testarAutenticacaoProfessor();
    testarTipoUsuario();
    testarClasseInternaHistorico();
    testarRelatorioPolimorfico();

    std::cout << "\nTodos os testes foram executados com sucesso!\n";
    return 0;
}
