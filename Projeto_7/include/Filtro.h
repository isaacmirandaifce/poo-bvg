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
    void adicionarElemento(T elemento) {
        elementos.push_back(elemento);
    }

    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        std::copy_if(elementos.begin(), elementos.end(), std::back_inserter(resultado), condicao);
        return resultado;
    }

    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }
};

#endif // FILTRO_H