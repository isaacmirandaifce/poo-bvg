#include <iostream>
#include <string>
#include "Filtro.h"
#include "Aluno.h"

int main() {
    /* Criando um filtro para Alunos */
    Filtro<Aluno> filtroAlunos;

    /* Adicionando alunos */
    filtroAlunos.adicionarElemento(Aluno("Larissa", 10.0));
    filtroAlunos.adicionarElemento(Aluno("Samara", 5.7));
    filtroAlunos.adicionarElemento(Aluno("Nicole", 9.2));
    filtroAlunos.adicionarElemento(Aluno("Kauan", 7.5));
    filtroAlunos.adicionarElemento(Aluno("Sandra", 8.2));

    /* Filtrando alunos com média acima de 7.0 */
    auto alunosComMediaAlta = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() > 7.0;
    });

    /* Imprimindo alunos com média acima de 7.0 */
    std::cout << "Alunos com média acima de 7.0:" << std::endl;
    for (const auto& aluno : alunosComMediaAlta) {
        aluno.exibirInformacoes();
    }

    return 0;
}
