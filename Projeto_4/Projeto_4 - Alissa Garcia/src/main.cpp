//Código de Alissa Garcia ADS S3

#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"
using namespace std;

bool verificarAprovacao(const Disciplina& n){
        return n.nota >= 6;
    }

int main() {
        
    //Criei um aluno qualquer
    Aluno aluno1("Mariana Maria", "111111111", "ADS");

    // Criei duas disciplinas
    Disciplina POO("Programação Orientada a Objetos", 80, 10);
    Disciplina BD("Banco de Dados", 90, 5);

    // Configurando notas
    POO.setNota(10);
    BD.setNota(5);

    // Exibindo informações
    aluno1.exibirInformacoes();

    cout << "Programação Orientada a Objetos: ";
    cout << (verificarAprovacao(POO) ? "Aprovado" : "Reprovado") << endl;

    cout << "Banco de Dados: ";
    cout << (verificarAprovacao(BD) ? "Aprovado" : "Reprovado") << endl;

    return 0;
}
