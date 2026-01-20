#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<std::unique_ptr<Usuario>> usuarios; //Cria um vetor que guarda ponteiros para Usuario

    usuarios.push_back(std::make_unique<Aluno>(
        "Joao Paulo", "joaopauloalbuquerque@email.com", "2025001", "ADS",
        std::vector<std::string>{"POO", "Banco de Dados", "Redes"}
    ));
     //cria um Professor, mas guarda no mesmo vetor de Usuario
    usuarios.push_back(std::make_unique<Professor>(
        "Jéssica", "jessica@email.com", "Tecnologia da Informação",
        std::vector<std::string>{"Engenharia de Software", "PEED"}
    ));

    usuarios.push_back(std::make_unique<FuncionarioAdministrativo>(
        "Rogilson", "rogilson@email.com", "Secretario", "Assistente"
    ));

    usuarios.push_back(std::make_unique<Monitor>(
        "Luidy Costa", "luidycosta@email.com", "2025010", "ADS",
        std::vector<std::string>{"POO", "Banco de Dados"},
        "Programacao",
        std::vector<std::string>{"Logica de Programação"}, // ministradas (exemplo)
        std::vector<std::string>{"POO"}         // monitoradas
    ));

    std::cout << "=== RELATORIOS  ===\n\n";
    for (const auto& u : usuarios) {    //Percorre o vetor de Usuario
        u->gerarRelatorio(); // chama o override certo
    }

    std::cout << "=== SOBRECARGA (ALUNO) ===\n\n";
    Aluno a("Bruno", "bruno@email.com", "2025999", "ADS",
            std::vector<std::string>{"POO", "Matematica Discreta"});

    a.exibirDetalhes();   //Chama a versão sem notas → sobrecarga.
    a.exibirDetalhes(std::vector<float>{9.5f, 8.0f});   //Chama a versão com notas. Possui o mesmo nome mas parâmetros diferentes.

    std::cout << "=== MONITOR (METODO EXTRA) ===\n\n";
    Monitor m("Larissa", "larissa@email.com", "2025777", "ADS",
              std::vector<std::string>{"POO"},
              "Computacao",
              std::vector<std::string>{"Introducao a Programacao"},
              std::vector<std::string>{"POO", "ED"}
    );
    m.listarDisciplinasMonitoradas();

    return 0;
}
