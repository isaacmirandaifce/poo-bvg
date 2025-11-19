#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include "Disciplina.h"

int main() {
	// Criando disciplinas
	Disciplina d1("Programação I", 60);
	Disciplina d2("Matemática Discreta", 45);
	d1.setNota(8.0f);
	d2.setNota(5.5f);

	// Aluno
	Aluno* a = new Aluno("João Silva", "joao@example.com", "Aluno", "202312345", "ADS");
	a->adicionarDisciplina(d1);
	a->adicionarDisciplina(d2);

	// Professor
	std::vector<std::string> disciplinasProf = {"Programação I", "Estruturas de Dados"};
	Professor* p = new Professor("Dra. Marta", "marta@example.com", "Professor", "Computação", disciplinasProf);

	// Funcionário administrativo
	FuncionarioAdministrativo* f = new FuncionarioAdministrativo("Carlos RH", "carlos@example.com", "Funcionario", "Recursos Humanos", "Analista");

	// Monitor (herança múltipla)
	std::vector<std::string> disciplinasMonitoradas = {"Programação I"};
	Monitor* m = new Monitor("Lucas Monitor", "lucas@example.com", "Monitor", "202300111", "ADS",
							 "Computação", disciplinasProf, disciplinasMonitoradas);

	// Polimorfismo com ponteiros para Usuario
	std::vector<Usuario*> usuarios;
	usuarios.push_back(a);
	usuarios.push_back(p);
	usuarios.push_back(f);
	usuarios.push_back(m);

	std::cout << "---- Relatórios ----" << std::endl;
	for (const auto& u : usuarios) {
		u->gerarRelatorio();
		std::cout << std::endl;
	}

	std::cout << "---- Exibir informações do aluno (com/sem notas) ----" << std::endl;
	a->exibirInformacoes();
	std::cout << std::endl;
	a->exibirInformacoes(true); // sobrecarga: com notas

	std::cout << std::endl << "---- Monitor: disciplinas monitoradas ----" << std::endl;
	m->listarDisciplinasMonitoradas();

	// liberar memória
	for (auto u : usuarios) delete u;

	return 0;
}

