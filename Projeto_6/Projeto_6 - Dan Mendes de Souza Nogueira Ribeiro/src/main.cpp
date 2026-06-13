#include <iostream>
#include <string>
#include <vector>
#include "base/usuarioAutenticavel.h"
#include "interfaces/relatorio.h"
#include "models/usuarioOperador.h"
#include "models/usuarioAuditor.h"
#include "models/usuarioAdmin.h"


int main() {
    std::vector<Relatorio*> relatorioDados;

    usuarioAdmin *usuarioAd1 = new usuarioAdmin(1, "FulanoAdmin2", "ABC001");

    if (usuarioAd1->autenticar("ABC001")){
        relatorioDados.push_back(usuarioAd1);
    }
    else{
        std::cout << std::endl << "Senha ou nome de usuario errado" << std::endl;

        delete usuarioAd1;
    }

    usuarioAdmin *usuarioAd2 = new usuarioAdmin(3, "FulanoAdmin2", "ABC002");

    if (usuarioAd2->autenticar("ABC001")){
        relatorioDados.push_back(usuarioAd2);
    }
    else{
        std::cout << std::endl << "Senha ou nome de usuario errado" << std::endl;

        delete usuarioAd2;
    }

    //////

    UsuarioAuditor *usuarioAu1 = new UsuarioAuditor(3, "FulanoAuditor1", "ABC003");

    if (usuarioAu1->autenticar("ABC003")){
        relatorioDados.push_back(usuarioAu1);
    }
    else{
        std::cout << std::endl << "Senha ou nome de usuario errado" << std::endl;

        delete usuarioAu1;
    };

    /////

    UsuarioOperador *usuarioOp1 = new UsuarioOperador(4, "FulanoOperador1", "ABC004");

    if (usuarioOp1->autenticar("ABC004")){
        usuarioOp1->registrarAcesso("acesso1", "13/06/2026 13:00", 1);
        usuarioOp1->registrarAcesso("acesso2", "13/06/2026 13:30", 3);
        usuarioOp1->registrarAcesso("acesso3", "13/06/2026 14:00", 4);

        relatorioDados.push_back(usuarioOp1);
    }
    else{
        std::cout << std::endl << "Senha ou nome de usuario errado" << std::endl;

        delete usuarioOp1;
    };

    for (int i = 0; i < relatorioDados.size(); i++){

        std::cout << std::endl;

        relatorioDados[i]->gerarRelatorio();
        
        std::cout << std::endl;
    };

    for (int i = 0; i < relatorioDados.size(); i++){

        delete (relatorioDados[i]);
    }

    relatorioDados.clear();

    return 0;
};