#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    /* Método para adicionar um elemento ao filtro */
    void adicionarElemento(T elemento) {
        elementos.push_back(elemento);
    }

    /* Método para filtrar elementos com base em uma condição */
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    /* Método para imprimir todos os elementos, aplicando uma ação a cada um */
    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    /* Método para ordenar os elementos */
    void ordenarPorCondicao(std::function<bool(const T&, const T&)> condicao) {
        std::sort(elementos.begin(), elementos.end(), condicao);
    }
};

#endif // FILTRO_H
