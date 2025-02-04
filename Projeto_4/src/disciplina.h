#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>

class Disciplina {
    private:
            std::string nome;
            int cargaHoraria;
            float nota;

    public:
            // constructor
            Disciplina();
            Disciplina(const std::string& nome, int cargaHoraria, float nota);

            // method
            void setNota(float nota);
            float getNota() const;

            // friend function
            friend bool verifiedAprovacao(const Disciplina& disciplina);          
};

#endif