#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H
 
#include <string>
 
// Classe Base Abstrata — não pode ser instanciada diretamente
class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;
 
public:
    Dispositivo(const std::string& id, int ts);
 
    // Destrutor virtual: essencial para liberar memória corretamente
    // em hierarquias de herança com ponteiros da classe base
    virtual ~Dispositivo();
 
    // Método virtual puro
    virtual void processarDados() = 0;
 
    // Getter utilitário
    std::string getId() const;
};
 
#endif