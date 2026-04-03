#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>
#include <algorithm>

template <typename T>
class Filtro {
private:
    std::vector<T> elementos;
public:
    void adicionarElemento(const T& elemento) { elementos.push_back(elemento); }

    std::vector<T> filtrarPorCondicao(const std::function<bool(const T&)>& condicao) const {
        std::vector<T> resultado;
        for (const auto& e : elementos) {
            if (condicao(e)) resultado.push_back(e);
        }
        return resultado;
    }

    void imprimirTodos(const std::function<void(const T&)>& acao) const {
        for (const auto& e : elementos) acao(e);
    }

    void ordenarPor(const std::function<bool(const T&, const T&)>& criterio) {
        std::sort(elementos.begin(), elementos.end(), criterio);
    }

    const std::vector<T>& getTodos() const { return elementos; }
};

#endif // FILTRO_H
