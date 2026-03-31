#include <iostream>
#include "Aluno.h"
#include "Professor.h"

int main() {
    Aluno aluno("Germano", "germano@email.com", "123");
    aluno.adicionarHistorico("POO", 2024, 8.5);

    if (aluno.autenticar("123")) {
        aluno.gerarRelatorio();
    }

    return 0;
}