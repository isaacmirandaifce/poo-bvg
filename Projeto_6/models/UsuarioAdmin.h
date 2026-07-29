#ifndef USUARIO_ADMIN_H
#define USUARIO_ADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <vector>

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
private:
    std::vector<std::string> logsModificacoes;

public:
    UsuarioAdmin(int id, std::string username, std::string senha, std::vector<std::string> logs);

    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif // USUARIO_ADMIN_H