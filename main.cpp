#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"
using namespace std;

int main() {
    // criação do aluno
    Aluno a1("Lucas Souza", "202511223", "ADS");

    // criação das disciplinas
    Disciplina d1("Logica de Programacao", 60);
    Disciplina d2("Banco de Dados", 80);

    // colocando notas
    d1.setNota(7.0);
    d2.setNota(5.5);

    // exibindo informações do aluno
    a1.exibirInformacoes();

    // verificando status nas disciplinas
    cout << endl;
    cout << "Disciplina: " << d1.getNome() << " - Nota: " << d1.getNota();
    cout << " - " << (verificarAprovacao(d1) ? "Aprovado" : "Reprovado") << endl;

    cout << "Disciplina: " << d2.getNome() << " - Nota: " << d2.getNota();
    cout << " - " << (verificarAprovacao(d2) ? "Aprovado" : "Reprovado") << endl;

    return 0;
}
