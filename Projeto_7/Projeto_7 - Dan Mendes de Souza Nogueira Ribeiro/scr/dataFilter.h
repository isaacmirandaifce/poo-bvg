#include <iostream>
#include <string>
#include <functional>
#include <vector>

template <typename T>
class DataFilter {
    private:
    vector<T> vetor;
    public:

   void adicionar(T elemento){
       vetor.push_back(elemento);
   };

   std::vector<T> filtrar(std::function<bool(const T &)> condicao) {
        std::vector<T> novoVetor;
        
        for (auto &item : vetor) {
            if (condicao(item)) {
                novoVetor.push_back(item);
            }
        }
        return novoVetor;
   };

   void processar(std::function<void(const T &)> acao){
       for (auto &item : vetor)
       {
           acao(item);
       }
   };

};