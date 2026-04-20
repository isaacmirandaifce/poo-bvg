#ifndef FILTRO_H
#define FILTRO_H
#include <vector>
#include <functional>
template <typename T>
class Filtro {
    std::vector<T> elementos;
public:
    void adicionarElemento(T elem){ elementos.push_back(elem); }
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> cond){
        std::vector<T> resultado;
        for(auto& e: elementos) if(cond(e)) resultado.push_back(e);
        return resultado;
    }
    void imprimirTodos(std::function<void(const T&)> acao){
        for(auto& e: elementos) acao(e);
    }
};
#endif
