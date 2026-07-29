#ifndef DATA_FILTER_H
#define DATA_FILTER_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

template <typename T>
class DataFilter {
private:
    std::vector<T> elementos;

public:
    // Adiciona um novo elemento ao pipeline
    void adicionar(T elemento) {
        elementos.push_back(elemento);
    }

    // Filtra elementos com base em uma condição (expressão lambda)
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& item : elementos) {
            if (condicao(item)) {
                resultado.push_back(item);
            }
        }
        return resultado;
    }

    // Executa uma ação em cada elemento armazenado
    void processar(std::function<void(const T&)> acao) const {
        for (const auto& item : elementos) {
            acao(item);
        }
    }

    // Método auxiliar para obter o vetor completo se necessário
    const std::vector<T>& getElementos() const {
        return elementos;
    }
};

#endif // DATA_FILTER_H