#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>
#include "Usuario.h"

class FuncionarioAdministrativo : virtual public Usuario {
private:
	std::string departamento;
	std::string cargo;
public:
	FuncionarioAdministrativo();
	FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& tipo,
							 const std::string& departamento, const std::string& cargo);

	void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
