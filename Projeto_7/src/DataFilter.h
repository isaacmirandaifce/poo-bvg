#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>

template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    // Adiciona um novo elemento ao pipeline
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    // Filtra elementos com base em uma condição (Lambda / std::function)
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& item : dados) {
            if (condicao(item)) {
                resultado.push_back(item);
            }
        }
        return resultado;
    }

    // Processa os dados armazenados executando uma ação
    void processar(std::function<void(const T&)> acao) const {
        for (const auto& item : dados) {
            acao(item);
        }
    }
};

#endif // DATAFILTER_H