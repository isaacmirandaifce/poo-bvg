#include <iostream>
#include <string>
#include "logSeguranca.h"

void LogSeguranca::setTimeStamp(int timestamp)
{
    if (timestamp >= 0)
    {
        this->timestamp = timestamp;
    }
    else
    {
        std::cout << std::endl << "erro no timestamp" << std::endl;
    }
};
void LogSeguranca::setNivel(std::string nivel)
{
    if (nivel != "")
    {
        this->nivel = nivel;
    }
    else
    {
        std::cout << std::endl << "erro no nivel" << std::endl;
    }
};
void LogSeguranca::setMensagem(std::string mensagem)
{
    if (mensagem != "")
    {
        this->mensagem = mensagem;
    }
    else
    {
        std::cout << std::endl << "erro na mensagem" << std::endl;
    }
};

int LogSeguranca::getTimeStamp() const { return this->timestamp; };
std::string LogSeguranca::getNivel() const { return this->nivel; };
std::string LogSeguranca::getMensagem() const { return this->mensagem; };