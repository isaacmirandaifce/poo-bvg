#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>

template<typename T>
class Filtro {
private:
    std::vector<T> elementos;
public:
    // Adiciona um elemento à coleção
    void adicionarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    // Filtra os elementos com base em uma condição e retorna os elementos que satisfazem essa condição
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    // Aplica uma ação a cada elemento (por exemplo, imprimir informações)
    void imprimirTodos(std::function<void(const T&)> acao) const {
        for (const auto& elemento : elementos) {
            acao(elemento);
        }
    }

    // Ordena os elementos usando um comparador fornecido
    void ordenar(std::function<bool(const T&, const T&)> comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }

    // Retorna a coleção de elementos (caso seja necessário usá-la externamente)
    const std::vector<T>& getElementos() const {
        return elementos;
    }
};

#endif // FILTRO_H
