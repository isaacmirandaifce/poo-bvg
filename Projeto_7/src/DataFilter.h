#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>

template <typename T>
class DataFilter {
private:
    std::vector<T> dados; // Container interno para armazenar os dados

public:
    // Adiciona um novo elemento ao pipeline
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    // Recebe uma regra de negócio (lambda) e retorna os itens aprovados
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& item : dados) {
            if (condicao(item)) {
                resultado.push_back(item);
            }
        }
        return resultado;
    }

    // Recebe uma ação (lambda) e a executa para cada elemento
    void processar(std::function<void(const T&)> acao) {
        for (const auto& item : dados) {
            acao(item);
        }
    }
};

#endif
