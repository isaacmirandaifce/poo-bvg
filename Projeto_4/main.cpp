#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {

    //criando um objeto aluno e definindo informações
    Aluno aluno("João Silva", "12345", "Ciência da Computação");

    //criando dois objetos diciplina e definindo informações
    Disciplina disciplina1("Matemática", 60, 7.5);
    Disciplina disciplina2("Física", 45, 5.0);

    //exibindo informações
    aluno.exibirInformacoes();

    //verificando status dos aluno
    std::cout << "Status de Aprovação em " << disciplina1.getNota() << ": "
              << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << std::endl;
    std::cout << "Status de Aprovação em " << disciplina2.getNota() << ": "
              << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << std::endl;

    return 0;
}
