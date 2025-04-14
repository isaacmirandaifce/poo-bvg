#ifndef FILTRO_H
#define FILTRO_H

#include <vector>
#include <functional>

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
        for (const auto& elemento : elementos) {
            if (condicao(elemento)) {
                resultado.push_back(elemento);
            }
        }
        return resultado;
    }

    // Método getElementos() adicionado
    std::vector<T> getElementos() const {
        return elementos;
    }
};

#endif // FILTRO_H