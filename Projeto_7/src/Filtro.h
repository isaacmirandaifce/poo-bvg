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
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& elem : elementos) {
            if (condicao(elem)) {
                resultado.push_back(elem);
            }
        }
        return resultado;
    }

    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& elem : elementos) {
            acao(elem);
        }
    }
};

#endif // FILTRO_H