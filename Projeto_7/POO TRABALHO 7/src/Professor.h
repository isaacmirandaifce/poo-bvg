#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string areaAtuacao;
    std::vector<std::string> disciplinasMinistradas;
    std::size_t senhaHash;

public:
    Professor();
    Professor(const std::string& nome,
              const std::string& email,
              const std::string& areaAtuacao,
              const std::vector<std::string>& disciplinas = {});

    void definirSenha(const std::string& senha);
    bool autenticar(const std::string& senha) const override;

    void adicionarDisciplina(const std::string& disciplina);
    const std::vector<std::string>& getDisciplinasMinistradas() const;

    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
