#ifndef SISTEMA_RELATORIOS_H
#define SISTEMA_RELATORIOS_H

#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include <iostream>
#include <iomanip>
#include <string>

/**
 * Classe que implementa um sistema genérico de relatórios acadêmicos
 * Utiliza a classe Filtro para operações genéricas sobre diferentes tipos de dados
 */
class SistemaRelatorios {
public:
    /**
     * Gera relatório de alunos com média acima de um valor especificado
     * @param filtroAlunos - filtro contendo os alunos
     * @param mediaMinima - média mínima para filtrar
     */
    static void relatorioAlunosMediaAlta(const Filtro<Aluno>& filtroAlunos, double mediaMinima = 7.0) {
        std::cout << "\n=== RELATÓRIO: ALUNOS COM MÉDIA ACIMA DE " << mediaMinima << " ===" << std::endl;
        std::cout << std::string(60, '-') << std::endl;

        auto alunosMediaAlta = filtroAlunos.filtrarPorCondicao([mediaMinima](const Aluno& aluno) {
            return aluno.getMedia() >= mediaMinima;
        });

        if (alunosMediaAlta.estaVazia()) {
            std::cout << "Nenhum aluno encontrado com média >= " << mediaMinima << std::endl;
        } else {
            std::cout << "Total de alunos encontrados: " << alunosMediaAlta.tamanho() << std::endl;
            std::cout << std::string(60, '-') << std::endl;

            // Ordena por média (decrescente)
            auto alunosOrdenados = alunosMediaAlta.obterOrdenadoPorCriterio([](const Aluno& a, const Aluno& b) {
                return a.getMedia() > b.getMedia();
            });

            alunosOrdenados.imprimirTodos([](const Aluno& aluno) {
                std::cout << std::fixed << std::setprecision(2) << aluno << std::endl;
            });
        }
        std::cout << std::string(60, '=') << std::endl;
    }

    /**
     * Gera relatório de professores que ministram uma disciplina específica
     * @param filtroProfessores - filtro contendo os professores
     * @param disciplina - nome da disciplina
     */
    static void relatorioProfessoresDisciplina(const Filtro<Professor>& filtroProfessores,
                                               const std::string& disciplina) {
        std::cout << "\n=== RELATÓRIO: PROFESSORES QUE MINISTRAM '" << disciplina << "' ===" << std::endl;
        std::cout << std::string(70, '-') << std::endl;

        auto professoresDisciplina = filtroProfessores.filtrarPorCondicao([disciplina](const Professor& professor) {
            return professor.ministraDisciplina(disciplina);
        });

        if (professoresDisciplina.estaVazia()) {
            std::cout << "Nenhum professor encontrado ministrando a disciplina '" << disciplina << "'" << std::endl;
        } else {
            std::cout << "Total de professores encontrados: " << professoresDisciplina.tamanho() << std::endl;
            std::cout << std::string(70, '-') << std::endl;

            // Ordena por anos de experiência (decrescente)
            auto professoresOrdenados = professoresDisciplina.obterOrdenadoPorCriterio([](const Professor& a, const Professor& b) {
                return a.getAnosExperiencia() > b.getAnosExperiencia();
            });

            professoresOrdenados.imprimirTodos([](const Professor& professor) {
                std::cout << professor << std::endl;
            });
        }
        std::cout << std::string(70, '=') << std::endl;
    }

    /**
     * Gera relatório de disciplinas cursadas em um ano específico
     * @param filtroDisciplinas - filtro contendo as disciplinas
     * @param ano - ano para filtrar
     */
    static void relatorioDisciplinasPorAno(const Filtro<Disciplina>& filtroDisciplinas, int ano) {
        std::cout << "\n=== RELATÓRIO: DISCIPLINAS CURSADAS EM " << ano << " ===" << std::endl;
        std::cout << std::string(65, '-') << std::endl;

        auto disciplinasAno = filtroDisciplinas.filtrarPorCondicao([ano](const Disciplina& disciplina) {
            return disciplina.getAno() == ano;
        });

        if (disciplinasAno.estaVazia()) {
            std::cout << "Nenhuma disciplina encontrada para o ano " << ano << std::endl;
        } else {
            std::cout << "Total de disciplinas encontradas: " << disciplinasAno.tamanho() << std::endl;
            std::cout << std::string(65, '-') << std::endl;

            // Ordena por nome da disciplina
            auto disciplinasOrdenadas = disciplinasAno.obterOrdenadoPorCriterio([](const Disciplina& a, const Disciplina& b) {
                return a.getNome() < b.getNome();
            });

            disciplinasOrdenadas.imprimirTodos([](const Disciplina& disciplina) {
                std::cout << disciplina << std::endl;
            });

            // Estatísticas adicionais
            int totalCreditos = 0;
            int totalCargaHoraria = 0;

            disciplinasAno.imprimirTodos([&totalCreditos, &totalCargaHoraria](const Disciplina& disciplina) {
                totalCreditos += disciplina.getCreditos();
                totalCargaHoraria += disciplina.getCargaHoraria();
            });

            std::cout << std::string(65, '-') << std::endl;
            std::cout << "Total de Créditos: " << totalCreditos << std::endl;
            std::cout << "Total de Carga Horária: " << totalCargaHoraria << " horas" << std::endl;
        }
        std::cout << std::string(65, '=') << std::endl;
    }

    /**
     * Gera relatório estatístico genérico para qualquer coleção
     * @param filtro - filtro contendo os elementos
     * @param nome - nome do tipo de elemento para o relatório
     */
    template<typename T>
    static void relatorioEstatisticas(const Filtro<T>& filtro, const std::string& nome) {
        std::cout << "\n=== ESTATÍSTICAS: " << nome << " ===" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        std::cout << "Total de elementos: " << filtro.tamanho() << std::endl;
        std::cout << "Coleção vazia: " << (filtro.estaVazia() ? "Sim" : "Não") << std::endl;
        std::cout << std::string(40, '=') << std::endl;
    }

    /**
     * Gera relatório comparativo de médias de alunos por ano
     * @param filtroAlunos - filtro contendo os alunos
     */
    static void relatorioMediasPorAno(const Filtro<Aluno>& filtroAlunos) {
        std::cout << "\n=== RELATÓRIO: MÉDIAS POR ANO DE INGRESSO ===" << std::endl;
        std::cout << std::string(50, '-') << std::endl;

        // Encontra os anos únicos
        std::vector<int> anos;
        filtroAlunos.imprimirTodos([&anos](const Aluno& aluno) {
            bool anoExiste = false;
            for (int ano : anos) {
                if (ano == aluno.getAno()) {
                    anoExiste = true;
                    break;
                }
            }
            if (!anoExiste) {
                anos.push_back(aluno.getAno());
            }
        });

        // Ordena os anos
        std::sort(anos.begin(), anos.end());

        for (int ano : anos) {
            auto alunosAno = filtroAlunos.filtrarPorCondicao([ano](const Aluno& aluno) {
                return aluno.getAno() == ano;
            });

            if (!alunosAno.estaVazia()) {
                double somaMedias = 0.0;
                alunosAno.imprimirTodos([&somaMedias](const Aluno& aluno) {
                    somaMedias += aluno.getMedia();
                });

                double mediaGeral = somaMedias / alunosAno.tamanho();
                std::cout << "Ano " << ano << ": " << alunosAno.tamanho() << " alunos | "
                          << "Média geral: " << std::fixed << std::setprecision(2) << mediaGeral << std::endl;
            }
        }
        std::cout << std::string(50, '=') << std::endl;
    }
};

#endif // SISTEMA_RELATORIOS_H
