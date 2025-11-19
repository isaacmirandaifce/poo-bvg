#ifndef MONITOR_H
#define MONITOR_H

#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
private:
	std::vector<std::string> disciplinasMonitoradas;
public:
	Monitor();
	Monitor(const std::string& nome, const std::string& email, const std::string& tipo,
			const std::string& matricula, const std::string& curso,
			const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinasMinistradas,
			const std::vector<std::string>& disciplinasMonitoradas);

	void gerarRelatorio() const override;
	void listarDisciplinasMonitoradas() const;
};

#endif // MONITOR_H

