#include "SinalHandler.h"
#include <unistd.h>
#include <cstring>
#include <iostream>


volatile sig_atomic_t SinalHandler::sinal_recebido = 0;
int SinalHandler::ultimo_sinal = 0;
std::function<void(int)> SinalHandler::user_callback = nullptr;


void SinalHandler::inicializar(std::function<void(int)> callback) {
user_callback = callback;
// usar signal é suficiente para o exercício; para produção, prefira sigaction
std::signal(SIGINT, tratador);
std::signal(SIGTERM, tratador);
std::signal(SIGSEGV, tratador);
}


void SinalHandler::tratador(int sinal) {
// funções async-signal-safe: _exit, write, etc. Evite std::cerr aqui.
const char *msg = "\n[Sinal recebido] salvando/encerrando...\n";
write(STDERR_FILENO, msg, strlen(msg));
sinal_recebido = 1;
ultimo_sinal = sinal;
// se o usuário registrou um callback, apenas marque o sinal. O callback será chamado de forma segura no contexto principal.
}