#ifndef USUARIOOPERADOR_H
#define USUARIOOPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <vector>
#include <iostream>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    // Classe Interna altamente encapsulada
    class HistoricoAcessos {
    public:
        std::string recurso;
        std::string dataHora;
        int status;
        HistoricoAcessos(std::string r, std::string d, int s) : recurso(r), dataHora(d), status(s) {}
    };

    std::vector<HistoricoAcessos> historico;

public:
    UsuarioOperador(int id, std::string user) : UsuarioAutenticavel(id, user) {
        // Simulando preenchimento do histórico
        historico.emplace_back("Caixa_01", "2026-07-08 10:00", 200);
    }

    bool autenticar(std::string senha) override {
        return senha == "op123";
    }

    void gerarRelatorio() const override {
        std::cout << "[Relatorio OPERADOR] Historico de acessos:\n";
        for (const auto& h : historico) {
            std::cout << " - Recurso: " << h.recurso << " | Status: " << h.status << "\n";
        }
    }
};

#endif
