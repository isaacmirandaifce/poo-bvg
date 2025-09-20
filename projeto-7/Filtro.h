#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional> // Para usar std::function
#include <algorithm>  // Para usar std::sort
#include <iostream>

// Criar uma classe genérica Filtro<T>
template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    // Método para adicionar um objeto ao filtro
    void adicionarElemento(T elemento) {
        elementos.push_back(elemento);
    }

    // Método para filtrar com base em uma condição (lambda) e retornar um novo filtro com os resultados
    Filtro<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        Filtro<T> resultado;
        for (const T& elem : this->elementos) {
            if (condicao(elem)) {
                resultado.adicionarElemento(elem);
            }
        }
        return resultado;
    }

    // Método para aplicar uma ação (como imprimir) a cada elemento
    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const T& elem : this->elementos) {
            acao(elem);
        }
    }

    // Funcionalidade Adicional: Ordenação genérica
    void ordenar(std::function<bool(const T& a, const T& b)> comparador) {
        std::sort(this->elementos.begin(), this->elementos.end(), comparador);
    }
};

#endif // FILTRO_H
