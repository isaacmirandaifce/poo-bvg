#include "FuncionarioAdm.h"
#include <iostream>

using namespace std;

FuncionarioAdm::FuncionarioAdm(){}

FuncionarioAdm::FuncionarioAdm(
    string nome, string email, string departamento, string cargo)
    : Usuario(nome, email, "Funcionario"){
        this->departamento = departamento;
        this->cargo = cargo;
    }

    void FuncionarioAdm::gerarRelatorio() const{
        cout << "Funcionario" << nome << endl;
        cout << "Departamento " << departamento << endl;
        cout << "Cargo: " << cargo << endl;

    }