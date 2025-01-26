#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "../usuario/usuario_autenticavel.h"  
#include "../relatorio/Relatorio.h"          

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& senha);
    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senhaTentativa) override;
    ~Aluno() {}
};

#endif
