#include "Monitor.h"
#include <iostream>

Monitor::Monitor() : Aluno(), Professor(), disciplinasMonitoradas() {}

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& tipo,
				 const std::string& matricula, const std::string& curso,
				 const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinasMinistradas,
				 const std::vector<std::string>& disciplinasMonitoradas)
	: Usuario(nome, email, tipo), Aluno(nome, email, tipo, matricula, curso),
	  Professor(nome, email, tipo, areaDeAtuacao, disciplinasMinistradas), disciplinasMonitoradas(disciplinasMonitoradas) {}

void Monitor::gerarRelatorio() const {
	std::cout << "[Monitor] Nome: " << nome << " | Matrícula: " << getMatricula()
			  << " | Curso: " << getCurso() << std::endl;
	listarDisciplinasMonitoradas();
}

void Monitor::listarDisciplinasMonitoradas() const {
	if (disciplinasMonitoradas.empty()) {
		std::cout << "Nenhuma disciplina monitorada." << std::endl;
		return;
	}
	std::cout << "Disciplinas monitoradas:" << std::endl;
	for (const auto& d : disciplinasMonitoradas) {
		std::cout << "- " << d << std::endl;
	}
}
