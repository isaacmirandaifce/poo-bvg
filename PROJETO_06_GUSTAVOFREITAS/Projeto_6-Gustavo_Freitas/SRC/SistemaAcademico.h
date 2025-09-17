#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

class SistemaAcademico {
private:
    std::vector<std::shared_ptr<UsuarioAutenticavel>> usuarios;

public:
    void adicionarUsuario(std::shared_ptr<UsuarioAutenticavel> usuario);
    bool autenticarUsuario(const std::string& matricula, const std::string& senha);
    void gerarRelatorios() const;
    void listarUsuarios() const;
};

#endif // SISTEMA_ACADEMICO_H