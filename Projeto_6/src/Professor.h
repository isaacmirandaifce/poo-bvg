#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& senha,
              const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas);

    bool autenticar(const std::string& senha) const override;
    void exibirInformacoes() const override;
    void gerarRelatorio() const override;
};

#endif