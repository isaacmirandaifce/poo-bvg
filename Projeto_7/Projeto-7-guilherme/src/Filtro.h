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

    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const T& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const T& elemento : elementos) {
            acao(elemento);
        }
    }

    void ordenarPor(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }

    const std::vector<T>& getElementos() const {
        return elementos;
    }
};

#endif 
