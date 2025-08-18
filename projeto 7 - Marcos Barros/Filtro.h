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
    // Adicionar elemento
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Filtrar com base em uma condição
    Filtro<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        Filtro<T> resultado;
        for (const auto& e : elementos) {
            if (condicao(e)) {
                resultado.adicionarElemento(e);
            }
        }
        return resultado;
    }

    // Imprimir todos aplicando uma ação
    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& e : elementos) {
            acao(e);
        }
    }

    // Ordenação genérica
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }
};

#endif // FILTRO_H
