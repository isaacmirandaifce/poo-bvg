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
    


    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }
 
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) {
        std::vector<T> resultado;
        for (const auto& el : elementos) {
            if (condicao(el)) {
                resultado.push_back(el);
            }
        }
        return resultado;
    }


    void imprimirTodos(std::function<void(const T&)> acao) {
        for (const auto& el : elementos) {
            acao(el);
        }
    }

    
    void ordenar(std::function<bool(const T&, const T&)> criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }

     
    std::vector<T> getElementos() const {
        return elementos;
    }


    size_t tamanho() const {
        return elementos.size();
    }
 

    bool vazio() const {
        return elementos.empty();
    }


    void limpar() {
        elementos.clear();
    }
};

#endif 