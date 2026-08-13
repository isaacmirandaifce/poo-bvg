#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>
#include <algorithm>

/**
 * @class DataFilter
 * @tparam T Tipo de dado armazenado e processado pelo pipeline.
 *
 * @brief Motor genérico de filtragem e processamento de dados.
 *
 * Unifica a lógica antes duplicada em FiltroTransacao, FiltroLogAcesso e
 * FiltroCliente (violação do princípio DRY). DataFilter<T> não conhece as
 * regras de negócio de nenhum domínio específico: a regra é sempre
 * injetada de fora, via std::function/lambda, nos métodos filtrar() e
 * processar(). Isso mantém a classe fechada para modificação e aberta
 * para extensão (princípio Open/Closed do SOLID).
 *
 * ⚠️ Nota de arquitetura: como se trata de uma classe template, toda a
 * implementação dos métodos permanece neste próprio arquivo .h. O
 * compilador precisa "ver" o corpo completo de cada método no ponto de
 * instanciação (ex.: DataFilter<Transacao>); separar a implementação em
 * um DataFilter.cpp exigiria instanciação explícita e quebraria o uso
 * genérico da classe para tipos futuros.
 */
template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    /**
     * @brief Adiciona um novo elemento ao pipeline de dados.
     * @param elemento Elemento do tipo T a ser armazenado.
     */
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    /**
     * @brief Retorna quantos elementos estão atualmente armazenados.
     */
    std::size_t tamanho() const {
        return dados.size();
    }

    /**
     * @brief Aplica uma condição (regra de negócio) a cada elemento do
     * pipeline e retorna um novo vetor apenas com os elementos aprovados.
     *
     * @param condicao Função/lambda que recebe um `const T&` e retorna
     * `bool`, decidindo se o elemento deve ser mantido no resultado.
     * @return std::vector<T> Novo vetor contendo somente os elementos
     * para os quais condicao(elemento) == true.
     */
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        std::copy_if(dados.begin(), dados.end(), std::back_inserter(resultado), condicao);
        return resultado;
    }

    /**
     * @brief Executa uma ação para cada elemento armazenado no pipeline,
     * sem alterar o conteúdo interno (ex.: imprimir na tela, gravar log).
     *
     * @param acao Função/lambda que recebe um `const T&` e não retorna
     * valor, executando um efeito colateral por elemento.
     */
    void processar(std::function<void(const T&)> acao) const {
        for (const T& elemento : dados) {
            acao(elemento);
        }
    }
};

#endif // DATAFILTER_H
