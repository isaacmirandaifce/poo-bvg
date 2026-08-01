#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>

template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    DataFilter() = default;
    ~DataFilter() = default;


    void adicionar(const T& elemento) {
        dados.push_back(elemento);
    }

 
    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& elemento : dados) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

  
    void processar(std::function<void(const T&)> acao) const {
        for (const auto& elemento : dados) {
            acao(elemento);
        }
    }

    size_t tamanho() const {
        return dados.size();
    }
};

#endif 