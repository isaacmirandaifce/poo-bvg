#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

/**
 * Classe genérica para filtrar e manipular coleções de objetos
 * Template permite trabalhar com qualquer tipo de objeto
 */
template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    /**
     * Adiciona um novo elemento ao vetor
     * @param elemento O elemento a ser adicionado
     */
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    /**
     * Retorna os elementos que satisfazem a condição fornecida
     * @param condicao Função lambda que define a condição de filtro
     * @return std::vector<T> contendo os elementos filtrados
     */
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& el : elementos) {
            if (condicao(el)) {
                resultado.push_back(el);
            }
        }
        return resultado;
    }

    /**
     * Aplica uma ação (função) em todos os elementos
     * @param acao Função lambda que define a ação a ser executada
     */
    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& el : elementos) {
            acao(el);
        }
    }

    /**
     * Ordena os elementos de acordo com um critério fornecido
     * @param criterio Função lambda que define o critério de ordenação
     */
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }

    /**
     * Retorna todos os elementos armazenados
     * @return std::vector<T> com todos os elementos
     */
    std::vector<T> getElementos() const {
        return elementos;
    }

    /**
     * Retorna o número de elementos armazenados
     * @return size_t com o número de elementos
     */
    size_t tamanho() const {
        return elementos.size();
    }

    /**
     * Verifica se o filtro está vazio
     * @return true se vazio, false caso contrário
     */
    bool vazio() const {
        return elementos.empty();
    }

    /**
     * Remove todos os elementos do filtro
     */
    void limpar() {
        elementos.clear();
    }
};

#endif // FILTRO_H