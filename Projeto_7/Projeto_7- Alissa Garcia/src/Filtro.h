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
    // Adiciona elemento
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Filtra por condição
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& e : elementos) {
            if (condicao(e)) {
                resultado.push_back(e);
            }
        }
        return resultado;
    }

    // Aplica ação a todos
    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& e : elementos) {
            acao(e);
        }
    }

    // Ordenação genérica
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }

    // Acesso à lista interna
    const std::vector<T>& getElementos() const {
        return elementos;
    }
};

#endif // FILTRO_H
