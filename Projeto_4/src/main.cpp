#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    
    // Cria aluno
    
    Aluno aluno1("Germano de Oliveira Moraes", "2023001", "ADS");

    // Cria disciplina
    
    Disciplina d1("Programacao I", 60);
    Disciplina d2("Estruturas de Dados", 80);

    // Atribui notas
    
    d1.setNota(7.5f);
    d2.setNota(5.5f);

    // Exibi informações do aluno
    
    cout << "=== Informacoes do Aluno ===" << endl;
    aluno1.exibirInformacoes();
    cout << endl;

    // Verifica a aprovacao por disciplina usando a funcao amiga
    
    cout << "Disciplina: " << d1.getNome() << " - Nota: " << d1.getNota()
         << " - Status: " << (verificarAprovacao(aluno1, d1) ? "APROVADO" : "REPROVADO") << endl;

    cout << "Disciplina: " << d2.getNome() << " - Nota: " << d2.getNota()
         << " - Status: " << (verificarAprovacao(aluno1, d2) ? "APROVADO" : "REPROVADO") << endl;

    return 0;
}

