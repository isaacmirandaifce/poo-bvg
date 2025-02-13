#include <cassert>
#include "Filtro.h"
#include "Aluno.h"

void testFiltro() {
    Filtro<Aluno> filtro;
    filtro.adicionarElemento(Aluno("João", 8.5));
    filtro.adicionarElemento(Aluno("Maria", 6.5));
    filtro.adicionarElemento(Aluno("Pedro", 7.5));

    auto alunosAprovados = filtro.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() >= 7.0;
    });

    assert(alunosAprovados.size() == 2);
    assert(alunosAprovados[0].getNome() == "João");
    assert(alunosAprovados[1].getNome() == "Pedro");
}

int main() {
    testFiltro();
    std::cout << "Todos os testes passaram!\n";
    return 0;
}