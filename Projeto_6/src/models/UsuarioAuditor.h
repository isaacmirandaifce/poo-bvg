#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string senhaCorreta;
    std::string chavePublica;
    std::string escopoVarredura;

public:
    // Construtor exige os dados específicos do auditor para o relatório
    UsuarioAuditor(int id, std::string username, std::string senha, std::string chave, std::string escopo);
    
    // Contratos de herança
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif