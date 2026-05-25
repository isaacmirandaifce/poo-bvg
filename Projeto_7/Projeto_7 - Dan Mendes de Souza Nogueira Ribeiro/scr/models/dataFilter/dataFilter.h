#ifndef dataFilter
#define dataFilter
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

/**
 * @brief Classe template genérica para armazenar, filtrar e processar coleções de dados.
 * * @tparam T O tipo de dado (classe) que será manipulado pelo filtro sendo esse Transacao ou LogSeguranca.
 */
template <typename T>
class DataFilter
{
    private:
        /** @brief Vetor interno que armazena os elementos do tipo T. */
        std::vector<T> vetor;
    public:
        /**
         * @brief Adiciona um novo elemento ao final do vetor.
         * * @param elemento O objeto do tipo T a ser armazenado.
         */
        void adicionar(T elemento)
        {
            vetor.push_back(elemento);
        };

        /**
         * @brief Filtra os elementos do vetor com base em uma condição.
         * * Avalia cada elemento usando a função ou expressão lambda fornecida.
         * O vetor interno é atualizado para manter apenas os elementos que retornam "true".
         * * @param condicao Função (std::function) que recebe um elemento (const T&) e retorna um booleano.
         * @return std::vector<T> O vetor atualizado após a aplicação do filtro.
         */
        std::vector<T> filtrar(std::function<bool(const T &)> condicao)
        {
            std::vector<T> novoVetor;

            std::copy_if(vetor.begin(), vetor.end(), std::back_inserter(novoVetor), condicao);

            return vetor = novoVetor;
        };

        /**
         * @brief Processa todos os elementos do vetor aplicando uma ação a cada um deles.
         * * @param acao Função (std::function) que recebe um elemento (const T&) e executa uma lógica sem retorno.
         */
        void processar(std::function<void(const T &)> acao)
        {
            std::for_each(vetor.begin(), vetor.end(), acao);
        };
};

#endif
