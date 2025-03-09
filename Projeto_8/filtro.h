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
    void adicionarElemento(T elemento) {
        elementos.push_back(elemento);
    }

    // Filtra os elementos com base na condição fornecida
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& elem : elementos) {
            if (condicao(elem)) {
                resultado.push_back(elem);
            }
        }
        return resultado;
    }

    // Executa uma ação em cada elemento da lista
    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& elem : elementos) {
            acao(elem);
        }
    }
};

#endif
