#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main() {
    SignalHandler::inicializar();

    try {
        LedgerPersistence db;

        std::cout << "(ENGINE) Inicializando base de dados..." << std::endl;
        auto historico = db.carregarDados();
        std::cout << "(ENGINE) Histórico carregado com sucesso. Registros: " << historico.size() << std::endl;

        std::cout << "(Engine) Sistema operacional e aguardando interceptações..." << std::endl;
        std::cout << "(Dica) Aperte CTRL+C no terminal para ativar o SignalHandler e observar o desligamento limpo." << std::endl;

        int count = 1;
        std::vector<std::string> buffer_transacoes;

        while(true) {
            std::string tx = "TXN_ID_" + std::to_string(count) + ", R$ 500.00, APPROVED";
            buffer_transacoes.push_back(tx);

            if(buffer_transacoes.size() >= 3) {
                std::cout << "(ENGINE) Processando lote e gravando no Ledger..." << std::endl;
                db.salvarDados(buffer_transacoes);
                buffer_transacoes.clear();
            }

            count++;

            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

    } catch (const StorageException& e) {
        std::cerr << "\n(CRITICAL ERROR) Falha na camada de armazenamento: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\n(UNKNOWN ERROR) Erro genérico de runtime: " << e.what() << std::endl;
    }

    return 0;
}