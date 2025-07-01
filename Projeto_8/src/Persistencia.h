#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>

class SistemaAcademico; 

class Persistencia {
public:
    
    static void salvarDados(const SistemaAcademico& sistema);
    static void carregarDados(SistemaAcademico& sistema);
};

#endif 