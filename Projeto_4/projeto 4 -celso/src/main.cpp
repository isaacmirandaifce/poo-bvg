#include "Disciplina.h"
#include "Aluno.h"
#include <iostream>

int main() {
    Aluno aluno("Maria Silva", "20231234", "ADS");
    Disciplina d1("Matemática", 60, 0.0f);
    Disciplina d2("Programação", 80, 0.0f);

    d1.setNota(7.5f);
    d2.setNota(5.8f);

    aluno.exibirInformacoes();

    Disciplina disciplinas[] = {d1, d2};
    for (const auto& d : disciplinas) {
        std::cout << "Disciplina: " << d.getNome()
                  << " | Nota: " << d.getNota()
                  << " | Status: " << (verificarAprovacao(d) ? "Aprovado" : "Reprovado")
                  << std::endl;
    }

    return 0;
}