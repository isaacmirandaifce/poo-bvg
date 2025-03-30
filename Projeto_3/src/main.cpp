#include <vector>
#include <iostream>
#include "../include/pessoa.h"
#include <cstdlib> // para usar "system("cls")"(limpa o terminal)
#include <unistd.h> // Para usar sleep()
int main(){
    std::vector<Pessoa> pessoas; // cria um vetor que armazenará objetos da classe Pessoa
    pessoas.push_back(Pessoa("Kaella", "12345-6789")); // o push_back é um método de vector. Esse método adiciona um objeto ao final do vetor
    pessoas.push_back(Pessoa("Joao", "98765-4321"));
    pessoas.push_back(Pessoa("Maria", "55555-5555"));
    
    //declarei variaveis para armazenar os valores que serão passados na criação do objeto
    std::string nome;
    std::string telefone;
    int opcao;

    while(opcao!=2){
        
        std::cout << "1. criar objeto" << std::endl;
        std::cout << "2. sair" << std::endl;
        std::cout << "Digite aqui: ";
        std::cin >> opcao;

        std::cin.ignore(); // utilizada para limpar o buffer de entrada. Logo após ler valores númericos e antes de usar std::getline() é uma ótima prática ut

        if(opcao == 1){
            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "Telefone: ";
            std::getline(std::cin, telefone);
            std::cout << " " << std::endl;
            pessoas.push_back(Pessoa(nome, telefone));
            std::cout << "Criando objeto..." << std::endl;
            sleep(2);  // Espera por 2 segundos antes de limpar a tela
            system("cls");
            }
        else if(opcao==2){
            break;
        }else{
            std::cout << "Opcao invalida" << std::endl;
            return 0;
        }
   }

//é um loop (laço) que percorre todos os elementos do vetor pessoas e chama o método exibirInformacoes() para cada objeto do tipo Pessoa armazenado nesse vetor.
// const Pessoa& pessoa: Isso significa que você pode acessar o objeto sem copiá-lo, mas não pode modificá-lo dentro do laço.
    std::cout << " " << std::endl;
    std::cout << "Pessoas cadastradas" << std::endl;
    for(const Pessoa& pessoa : pessoas){ //Uma referência é um apelido para um objeto(nesse caso, Pessoa& pessoa, pessoa é um apelido)
        pessoa.exibirInformacoes();
    }
    
    return 0;
}