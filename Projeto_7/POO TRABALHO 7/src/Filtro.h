#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>

template <typename T>
class Filtro {
private:
    std::vector<T> lista;

public:
    void adicionar(const T& item) {
        lista.push_back(item);
    }

    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& item : lista)
            if (condicao(item)) resultado.push_back(item);
        return resultado;
    }

    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(lista.begin(), lista.end(), criterio);
    }

    void paraCada(std::function<void(const T&)> acao) const {
        for (const auto& item : lista) acao(item);
    }
};

#endif
