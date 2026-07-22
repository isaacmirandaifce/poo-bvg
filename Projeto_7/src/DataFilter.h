#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <vector>
#include <functional>
#include <algorithm>

// Classe Template (Generica): motor unico de armazenamento, filtragem e
// processamento de dados, reutilizavel para qualquer tipo T (Transacao,
// LogSeguranca, etc). Como e uma classe template, a implementacao dos
// metodos precisa ficar neste mesmo header, pois o compilador so gera o
// codigo concreto no momento em que a classe e instanciada com um tipo T.
template <typename T>
class DataFilter {
private:
    std::vector<T> dados;

public:
    void adicionar(T elemento) {
        dados.push_back(elemento);
    }

    std::vector<T> filtrar(std::function<bool(const T&)> condicao) const {
        std::vector<T> resultado;
        for (const T& item : dados) {
            if (condicao(item)) {
                resultado.push_back(item);
            }
        }
        return resultado;
    }

    void processar(std::function<void(const T&)> acao) const {
        for (const T& item : dados) {
            acao(item);
        }
    }

    size_t tamanho() const {
        return dados.size();
    }
};

#endif // DATAFILTER_H
