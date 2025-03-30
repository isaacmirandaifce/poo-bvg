#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    // Adiciona um elemento ao filtro
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Filtra elementos com base em uma condição
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    // Aplica uma ação a cada elemento (exemplo: imprimir)
    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    // Ordenação genérica
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }
};

#endif // FILTRO_H
