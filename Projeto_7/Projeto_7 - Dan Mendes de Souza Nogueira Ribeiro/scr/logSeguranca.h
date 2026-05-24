#ifndef Log_Seguranca
#define Log_Seguranca
#include <iostream>
#include <string>

class LogSeguranca
{
private:
    int timestamp;
    std::string nivel;
    std::string mensagem;

public:
    void setTimeStamp(double timestamp);
    void setNivel(std::string nivel);
    void setMensagem(std::string mensagem);

    int getTimeStamp();
    std::string getNivel();
    std::string getMensagem();
};

#endif