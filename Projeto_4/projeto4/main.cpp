#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

using namespace std;

int main() {
    // Instanciação do aluno e das disciplinas
    Aluno aluno1("Luidy", "20241001", "Analise e Desenvolvimento de Sistemas");

    Disciplina d1("Programacao Orientada a Objetos", 80);
    Disciplina d2("Estrutura de Dados", 60);

    // Atribuição de notas
    d1.setNota(8.5);
    d2.setNota(5.5);

    // Exibição dos dados
    aluno1.exibirInformacoes();

    cout << "\n--- Boletim ---" << endl;

    // Verificação da disciplina 1
    cout << "Disciplina: " << d1.getNome() << " | Nota: " << d1.getNota() << endl;
    if (verificarAprovacao(d1)) {
        cout << "Situacao: APROVADO" << endl;
    } else {
        cout << "Situacao: REPROVADO" << endl;
    }

    cout << endl;

    // Verificação da disciplina 2
    cout << "Disciplina: " << d2.getNome() << " | Nota: " << d2.getNota() << endl;
    if (verificarAprovacao(d2)) {
        cout << "Situacao: APROVADO" << endl;
    } else {
        cout << "Situacao: REPROVADO" << endl;
    }

    return 0;
}
