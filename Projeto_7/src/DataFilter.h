#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>
#include <algorithm>

// Criação do modelo genérico que permitem escrever funções ou classes 
// uma única vez e fazê-las funcionar com diferentes tipos de dados
template <typename T>

class DataFilter {
    private:
        std::vector<T> dados;
    
    public:
    // Insere um novo elemento do tipo genérico T no final do vector
        void adicionar(T elemento) {
            dados.push_back(elemento);
        }

    // Avalia os elementos armazenados e retornar apenas os que passam no teste.
        std::vector<T> filtrar(std::function<bool(const T&)> condicao) {
            std::vector<T> resultado;
            for(const auto& elemento : dados) {
                if (condicao(elemento)) {
                    resultado.push_back(elemento);
                }
            }

            return resultado;
        }
    // Executa uma ação arbitrária em cada item.
        void processar(std::function<void(const T&)> acao) {
            for (const auto& elemento : dados) {
                acao(elemento);
            }
        }
};

#endif