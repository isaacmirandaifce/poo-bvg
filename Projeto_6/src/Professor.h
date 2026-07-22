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

public:
    Professor();
    Professor(std::string nome, std::string email, const std::string& senha, std::string areaDeAtuacao);

    void adicionarDisciplinaMinistrada(const std::string& disciplina);

    // Sobrescrita: implementacao do metodo abstrato herdado de UsuarioAutenticavel
    bool autenticar(std::string senha) override;

    // Sobrescrita: implementacao do metodo virtual puro da interface Relatorio
    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
