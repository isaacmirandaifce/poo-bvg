#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"

int main(){
    Filtro<Aluno> filtroAlunos;
    Aluno a1("Joao","joao@email.com");
    a1.historico.push_back(Aluno::HistoricoDisciplinar("Matematica",2025,8.5));
    filtroAlunos.adicionarElemento(a1);

    filtroAlunos.imprimirTodos([](const Aluno& a){
        std::cout << "Aluno: " << a.nome << " Email: " << a.email << std::endl;
        for(auto& h: a.historico) std::cout << h.disciplina << " Ano:" << h.ano << " Nota:" << h.nota << std::endl;
    });

    return 0;
}
