#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "disciplina.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Aluno : public UsuarioAutenticavel {
protected:
    std::string curso;
    std::vector<std::shared_ptr<Disciplina>> disciplinas;

public:
    // Classe interna HistoricoDisciplinar
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int anoCursado;
        float nota;

    public:
        // Construtor da classe interna
        HistoricoDisciplinar(const std::string& nome, int ano, float nota)
            : nomeDisciplina(nome), anoCursado(ano), nota(nota) {}

        // Métodos Getter
        std::string getNomeDisciplina() const { return nomeDisciplina; }
        int getAnoCursado() const { return anoCursado; }
        float getNota() const { return nota; }

        // Métodos Setter
        void setNota(float novaNota) { nota = novaNota; }

        // Exibir informações do histórico
        void exibirInformacoes() const {
            std::cout << "Disciplina: " << nomeDisciplina 
                      << ", Ano: " << anoCursado 
                      << ", Nota: " << nota << std::endl;
        }
    };

    // Vetor de histórico de disciplinas cursadas
    std::vector<HistoricoDisciplinar> historicoDisciplinar;

    // Construtores
    Aluno(const std::string& nome, const std::string& email, TipoUsuario tipo, const std::string& senha, const std::string& curso);


    // Método para adicionar disciplina
    void adicionarDisciplina(const std::shared_ptr<Disciplina>& disciplina);

    // Sobrescrita do método para gerar o relatório
    void gerarRelatorio() const override;
     

    // Getter para disciplinas
    const std::vector<std::shared_ptr<Disciplina>>& getDisciplinas() const;

    // Método para adicionar ao histórico
    void adicionarAoHistorico(const std::string& nomeDisciplina, int ano, float nota);
    bool autenticar(const std::string& senha) const override;
    ~Aluno() {}
};

#endif // ALUNO_H
