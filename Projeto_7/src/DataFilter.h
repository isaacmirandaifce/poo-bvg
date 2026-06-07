#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>

template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    std::vector<T> filtrar(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const T& item : dados) {
            if (condicao(item)) {
                resultado.push_back(item);
            }
        }
        return resultado;
    }

    void processar(std::function<void(const T&)> acao) {
        for (const T& item : dados) {
            acao(item);
        }
    }
};

#endif