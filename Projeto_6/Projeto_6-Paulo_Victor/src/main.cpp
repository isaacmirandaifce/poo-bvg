#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno("Joao Silva", "12345", "Engenharia de Software", "senha123");
    aluno.adicionarDisciplinaAoHistorico("C++", 2023, 8.5f);
    aluno.adicionarDisciplinaAoHistorico("Banco de Dados", 2023, 7.0f);
    aluno.gerarRelatorio();
    aluno.exibirHistoricoCompleto();

    Professor professor("Maria Oliveira", "Ciencia da Computaçao", "senha456");
    professor.adicionarDisciplinaMinistrada("Algoritmos");
    professor.gerarRelatorio();

    FuncionarioAdministrativo funcionario("Carlos Souza", "RH", "Analista", "senha789");
    funcionario.gerarRelatorio();

    return 0;
}