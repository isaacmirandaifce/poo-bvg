#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <vector>
#include <functional>
#include <algorithm>

/**
 * @brief Classe utilitária para ordenação genérica
 */
class Ordenador {
public:
    /**
     * @brief Ordena um vector com base em um critério
     * @tparam T Tipo dos elementos
     * @param elementos Vector a ser ordenado
     * @param comparador Função de comparação
     */
    template <typename T>
    static void ordenar(std::vector<T>& elementos, std::function<bool(const T&, const T&)> comparador) {
        std::sort(elementos.begin(), elementos.end(), comparador);
    }

    /**
     * @brief Ordena um vector em ordem ascendente (requer operador <)
     * @tparam T Tipo dos elementos
     * @param elementos Vector a ser ordenado
     */
    template <typename T>
    static void ordenarAscendente(std::vector<T>& elementos) {
        std::sort(elementos.begin(), elementos.end());
    }

    /**
     * @brief Ordena um vector em ordem descendente (requer operador >)
     * @tparam T Tipo dos elementos
     * @param elementos Vector a ser ordenado
     */
    template <typename T>
    static void ordenarDescendente(std::vector<T>& elementos) {
        std::sort(elementos.begin(), elementos.end(), std::greater<T>());
    }
};

#endif // ORDENADOR_H