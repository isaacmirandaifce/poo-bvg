#include <iostream>
#include <string>
#include "Filtro.h"
#include "Aluno.h"

int main() {
    /* Criando um filtro para Alunos */
    Filtro<Aluno> filtroAlunos;

    /* Adicionando alunos */
    filtroAlunos.adicionarElemento(Aluno("Jhonata", 10.0));
    filtroAlunos.adicionarElemento(Aluno("José", 6.7));
    filtroAlunos.adicionarElemento(Aluno("Vieira", 8.2));
    filtroAlunos.adicionarElemento(Aluno("Carla", 9.5));
    filtroAlunos.adicionarElemento(Aluno("Sofia", 7.2));

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
