#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;
    std::size_t senhaHash;
public:
    Professor();
    Professor(const std::string& nome, const std::string& email,
              const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas = {});

    void setSenha(const std::string& senha);
    bool autenticar(const std::string& senha) const override;

    void gerarRelatorio() const override;
    void adicionarDisciplinaMinistrada(const std::string& d);
    const std::vector<std::string>& getDisciplinasMinistradas() const { return disciplinasMinistradas; }
    const std::string& getAreaDeAtuacao() const { return areaDeAtuacao; }
};

#endif // PROFESSOR_H
