#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>
#include <algorithm>

template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    // Adiciona um novo elemento ao pipeline
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    // Filtra os dados com base em uma condição
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) {
        std::vector<T> dados_filtrados;
        for (const auto& elemento : dados) {
            if (condicao(elemento)) {
                dados_filtrados.push_back(elemento);
            }
        }
        return dados_filtrados;
    }

    // Processa os dados executando uma ação
    void processar(std::function<void(const T&)> acao) {
        for (const auto& elemento : dados) {
            acao(elemento);
        }
    }
};

#endif 