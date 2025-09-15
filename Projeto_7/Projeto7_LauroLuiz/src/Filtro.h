#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

/**
 * Classe genérica para filtragem e manipulação de coleções de objetos
 * Template T representa o tipo de objeto a ser manipulado
 */
template <typename T>
class Filtro {
private:
    std::vector<T> elementos; // Coleção de elementos do tipo T

public:
    /**
     * Construtor padrão
     */
    Filtro() = default;

    /**
     * Construtor que recebe um vetor inicial de elementos
     * @param elementosIniciais - vetor de elementos para inicializar o filtro
     */
    Filtro(const std::vector<T>& elementosIniciais) : elementos(elementosIniciais) {}

    /**
     * Adiciona um elemento à coleção
     * @param elemento - elemento do tipo T a ser adicionado
     */
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    /**
     * Adiciona múltiplos elementos à coleção
     * @param novosElementos - vetor de elementos a serem adicionados
     */
    void adicionarElementos(const std::vector<T>& novosElementos) {
        elementos.insert(elementos.end(), novosElementos.begin(), novosElementos.end());
    }

    /**
     * Filtra os elementos com base em uma condição específica
     * @param condicao - função lambda que define a condição de filtro
     * @return novo objeto Filtro contendo apenas os elementos que satisfazem a condição
     */
    Filtro<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        Filtro<T> resultado;
        std::copy_if(elementos.begin(), elementos.end(),
                     std::back_inserter(resultado.elementos), condicao);
        return resultado;
    }

    /**
     * Aplica uma ação a cada elemento da coleção
     * @param acao - função lambda que define a ação a ser executada
     */
    void imprimirTodos(std::function<void(const T&)> acao) const {
        std::for_each(elementos.begin(), elementos.end(), acao);
    }

    /**
     * Ordena os elementos com base em um critério específico
     * @param comparador - função lambda que define o critério de ordenação
     */
    void ordenarPorCriterio(std::function<bool(const T&, const T&)> comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }

    /**
     * Retorna uma cópia ordenada dos elementos sem modificar o original
     * @param comparador - função lambda que define o critério de ordenação
     * @return novo objeto Filtro com elementos ordenados
     */
    Filtro<T> obterOrdenadoPorCriterio(std::function<bool(const T&, const T&)> comparador) const {
        Filtro<T> resultado(*this);
        resultado.ordenarPorCriterio(comparador);
        return resultado;
    }

    /**
     * Busca o primeiro elemento que satisfaz uma condição
     * @param condicao - função lambda que define a condição de busca
     * @param encontrado - referência para indicar se o elemento foi encontrado
     * @return o primeiro elemento encontrado (válido apenas se encontrado for true)
     */
    T buscarPrimeiro(std::function<bool(const T&)> condicao, bool& encontrado) const {
        auto it = std::find_if(elementos.begin(), elementos.end(), condicao);
        encontrado = (it != elementos.end());
        return encontrado ? *it : T{};
    }

    /**
     * Conta quantos elementos satisfazem uma condição
     * @param condicao - função lambda que define a condição
     * @return número de elementos que satisfazem a condição
     */
    size_t contarPorCondicao(std::function<bool(const T&)> condicao) const {
        return std::count_if(elementos.begin(), elementos.end(), condicao);
    }

    /**
     * Verifica se algum elemento satisfaz uma condição
     * @param condicao - função lambda que define a condição
     * @return true se pelo menos um elemento satisfaz a condição
     */
    bool algumSatisfaz(std::function<bool(const T&)> condicao) const {
        return std::any_of(elementos.begin(), elementos.end(), condicao);
    }

    /**
     * Verifica se todos os elementos satisfazem uma condição
     * @param condicao - função lambda que define a condição
     * @return true se todos os elementos satisfazem a condição
     */
    bool todosSatisfazem(std::function<bool(const T&)> condicao) const {
        return std::all_of(elementos.begin(), elementos.end(), condicao);
    }

    /**
     * Remove elementos que satisfazem uma condição
     * @param condicao - função lambda que define a condição para remoção
     */
    void removerPorCondicao(std::function<bool(const T&)> condicao) {
        elementos.erase(
            std::remove_if(elementos.begin(), elementos.end(), condicao),
            elementos.end()
        );
    }

    /**
     * Limpa todos os elementos da coleção
     */
    void limpar() {
        elementos.clear();
    }

    /**
     * Retorna o número de elementos na coleção
     * @return tamanho da coleção
     */
    size_t tamanho() const {
        return elementos.size();
    }

    /**
     * Verifica se a coleção está vazia
     * @return true se a coleção estiver vazia
     */
    bool estaVazia() const {
        return elementos.empty();
    }

    /**
     * Retorna uma referência constante para o vetor de elementos
     * @return referência constante para os elementos
     */
    const std::vector<T>& obterElementos() const {
        return elementos;
    }

    /**
     * Operador de acesso por índice (somente leitura)
     * @param indice - índice do elemento
     * @return referência constante para o elemento no índice especificado
     */
    const T& operator[](size_t indice) const {
        return elementos[indice];
    }

    /**
     * Operador de acesso por índice (leitura e escrita)
     * @param indice - índice do elemento
     * @return referência para o elemento no índice especificado
     */
    T& operator[](size_t indice) {
        return elementos[indice];
    }
};

#endif // FILTRO_H
