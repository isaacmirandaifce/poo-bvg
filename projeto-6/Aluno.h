#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

// Aluno herda de UsuarioAutenticavel e implementa a interface Relatorio
class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // 1. Definição da Classe Interna, conforme o requisito
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int anoCursado;
        double nota;

        HistoricoDisciplinar(std::string disciplina, int ano, double nota)
            : nomeDisciplina(disciplina), anoCursado(ano), nota(nota) {}
    };

private:
    std::string matricula;
    std::string curso;
    // 2. Aluno agora tem um histórico de disciplinas, usando a classe interna
    std::vector<HistoricoDisciplinar> historico;

public:
    // Construtor principal da classe Aluno
    Aluno(std::string nome, std::string email, std::string senha, std::string matricula, std::string curso);

    // Método para adicionar entradas ao histórico do aluno
    void adicionarDisciplinaAoHistorico(const std::string& disciplina, int ano, double nota);

    // 3. Implementação dos "contratos" das classes pai
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // ALUNO_H
