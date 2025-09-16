#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include <functional>

// Usaremos um ponteiro de função estático para que o tratador de sinal
// possa chamar a função de salvamento de dados.
class SinalHandler {
public:
    // Configura os tratadores de sinal
    static void inicializar();
    
    // Registra a função que deve ser chamada para salvar os dados
    static void registrarFuncaoSalvar(std::function<void()> func);

private:
    // A função que efetivamente trata o sinal
    static void tratador(int sinal);
    
    // Armazena a função de salvamento. std::function é mais flexível que ponteiros de função C-style.
    static std::function<void()> funcaoSalvarDados;
};

#endif // SINALHANDLER_H