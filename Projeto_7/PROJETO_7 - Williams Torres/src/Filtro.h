#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

// Classe genérica Filtro<T>
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
    std::vector<T> filtrarPorCondicao(const std::function<bool(const T&)>& condicao) const {
        std::vector<T> resultado;
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    // Aplica uma ação a cada elemento (ex.: imprimir)
    void imprimirTodos(const std::function<void(const T&)>& acao) const {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    // Ordena os elementos com base em um comparador genérico
    void ordenarElementos(const std::function<bool(const T&, const T&)>& comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }
};

#endif // FILTRO_H
