#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <memory>

/**
 * @brief Classe genérica para filtragem e manipulação de coleções de objetos
 * @tparam T Tipo dos elementos a serem filtrados
 */
template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    /**
     * @brief Construtor padrão
     */
    Filtro() = default;

    /**
     * @brief Construtor com lista inicial de elementos
     * @param elementosIniciais Lista de elementos inicial
     */
    Filtro(const std::vector<T>& elementosIniciais) : elementos(elementosIniciais) {}

    /**
     * @brief Adiciona um elemento ao filtro
     * @param elemento Elemento a ser adicionado
     */
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    /**
     * @brief Adiciona múltiplos elementos ao filtro
     * @param elementos Lista de elementos a serem adicionados
     */
    void adicionarElementos(const std::vector<T>& elementos) {
        this->elementos.insert(this->elementos.end(), elementos.begin(), elementos.end());
    }

    /**
     * @brief Filtra elementos com base em uma condição
     * @param condicao Função que define a condição de filtro
     * @return Filtro<T> Novo filtro com elementos que satisfazem a condição
     */
    Filtro<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        std::copy_if(elementos.begin(), elementos.end(), std::back_inserter(resultado), condicao);
        return Filtro<T>(resultado);
    }

    /**
     * @brief Aplica uma ação a cada elemento
     * @param acao Função a ser aplicada a cada elemento
     */
    void aplicarAcao(std::function<void(const T&)> acao) const {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    /**
     * @brief Imprime todos os elementos usando a ação padrão de impressão
     */
    void imprimirTodos() const {
        aplicarAcao([](const T& elemento) {
            std::cout << elemento << std::endl;
        });
    }

    /**
     * @brief Ordena os elementos com base em um critério
     * @param comparador Função de comparação para ordenação
     */
    void ordenarPor(std::function<bool(const T&, const T&)> comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }

    /**
     * @brief Retorna todos os elementos
     * @return std::vector<T> Vector com todos os elementos
     */
    std::vector<T> obterTodos() const {
        return elementos;
    }

    /**
     * @brief Retorna o número de elementos
     * @return size_t Número de elementos
     */
    size_t tamanho() const {
        return elementos.size();
    }

    /**
     * @brief Verifica se o filtro está vazio
     * @return true se vazio, false caso contrário
     */
    bool vazio() const {
        return elementos.empty();
    }

    /**
     * @brief Limpa todos os elementos
     */
    void limpar() {
        elementos.clear();
    }

    /**
     * @brief Operador de acesso aos elementos
     * @param index Índice do elemento
     * @return T& Referência para o elemento
     */
    T& operator[](size_t index) {
        return elementos[index];
    }

    /**
     * @brief Operador de acesso constante aos elementos
     * @param index Índice do elemento
     * @return const T& Referência constante para o elemento
     */
    const T& operator[](size_t index) const {
        return elementos[index];
    }
};

#endif // FILTRO_H