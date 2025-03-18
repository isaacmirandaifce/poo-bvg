#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

template <typename T>
class Filtro {
private:
    std::vector<T> elementos; // Vetor que armazena os elementos

public:
    // Adiciona um elemento ao filtro
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Filtra elementos com base em uma condição
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& elem : elementos) {
            if (condicao(elem)) {
                resultado.push_back(elem);
            }
        }
        return resultado;
    }

    // Imprime todos os elementos aplicando uma ação específica
    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& elem : elementos) {
            acao(elem);
        }
    }

    // Ordena os elementos com base em um critério específico
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }
};

#endif // FILTRO_H
