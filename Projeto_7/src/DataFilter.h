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

        for (const T& elemento : dados) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }

        return resultado;
    }

    void processar(std::function<void(const T&)> acao) {
        for (const T& elemento : dados) {
            acao(elemento);
        }
    }
};

#endif