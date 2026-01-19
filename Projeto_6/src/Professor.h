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
    Professor(std::string n,std::string s,std::string area,std::vector<std::string> d)
        : UsuarioAutenticavel(n,s,TipoUsuario::PROFESSOR), areaDeAtuacao(area), disciplinasMinistradas(d) {}
    bool autenticar(const std::string& s) override { return s==senha; }
    void gerarRelatorio() const override {
        printf("Professor: %s\\nArea: %s\\n", nome.c_str(), areaDeAtuacao.c_str());
        for(auto& d : disciplinasMinistradas) printf("Disciplina: %s\\n", d.c_str());
    }
};
#endif
