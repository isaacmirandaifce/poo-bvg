#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "../usuario/usuario_autenticavel.h"  // Corrigido caminho relativo
#include "../relatorio/Relatorio.h"          // Corrigido caminho relativo
#include <vector>
#include <string>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::string& senha);
    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senhaTentativa) override;
    ~Professor() {}
};

#endif 