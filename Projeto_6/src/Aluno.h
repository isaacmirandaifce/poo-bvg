#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int ano;
        float nota;
        HistoricoDisciplinar(std::string n, int a, float nt)
            : nomeDisciplina(n), ano(a), nota(nt) {}
    };
private:
    std::string matricula;
    std::string curso;
    std::vector<HistoricoDisciplinar> historico;
public:
    Aluno(std::string n, std::string s, std::string m, std::string c)
        : UsuarioAutenticavel(n,s,TipoUsuario::ALUNO), matricula(m), curso(c) {}
    void adicionarHistorico(std::string nome, int ano, float nota) {
        historico.emplace_back(nome, ano, nota);
    }
    bool autenticar(const std::string& s) override { return s==senha; }
    void gerarRelatorio() const override {
        printf("Aluno: %s\\nMatricula: %s\\nCurso: %s\\n", nome.c_str(), matricula.c_str(), curso.c_str());
        for(auto& h : historico) {
            printf("Disciplina: %s, Ano: %d, Nota: %.2f\\n", h.nomeDisciplina.c_str(), h.ano, h.nota);
        }
    }
};
#endif
