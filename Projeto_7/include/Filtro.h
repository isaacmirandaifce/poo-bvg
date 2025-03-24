#ifndef FILTRO_H
#define FILTRO_H
#include <vector>
#include <functional>
using namespace std;

template <typename T>
class Filtro {
    vector<T> elementos;
public:
    void adicionarElemento(T elemento) { elementos.push_back(elemento); }
    vector<T> filtrarPorCondicao(function<bool(const T&)> condicao) {
        vector<T> resultado;
        for (const auto& elem : elementos) {
            if (condicao(elem)) resultado.push_back(elem);
        }
        return resultado;
    }
};

#endif // FILTRO_H