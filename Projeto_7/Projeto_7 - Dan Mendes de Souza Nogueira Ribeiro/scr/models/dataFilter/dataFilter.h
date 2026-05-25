#ifndef dataFilter
#define dataFilter
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

template <typename T>
class DataFilter {
    private:
    std::vector<T> vetor;
    public:

   void adicionar(T elemento){
       vetor.push_back(elemento);
   };

   std::vector<T> filtrar(std::function<bool(const T &)> condicao) {
        std::vector<T> novoVetor;

        std::copy_if(vetor.begin(), vetor.end(), std::back_inserter(novoVetor), condicao);
        
        return vetor = novoVetor;
   };

   void processar(std::function<void(const T &)> acao){
       std::for_each(vetor.begin(), vetor.end(), acao);
   };

};

#endif
