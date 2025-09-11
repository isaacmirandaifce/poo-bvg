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
        for (const auto& elem : elementos) {
            if (condicao(elem)) {
                resultado.push_back(elem);
            }
        }
        return resultado;
    }

    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& elem : elementos) {
            acao(elem);
        }
    }

    std::vector<T> ordenarPor(std::function<bool(const T&, const T&)> criterio) const {
        std::vector<T> copia = elementos;
        std::sort(copia.begin(), copia.end(), criterio);
        return copia;
    }
};

#endif // FILTRO_H