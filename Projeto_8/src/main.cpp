#include <iostream>
#include <vector>
#include <string>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main() {
    SignalHandler::inicializar(); //Registra os hooks de sinal do SO

    try {
        LedgerPersistence db;

        // 1. Carregamento inicial — pode disparar FileCorruptedException
        auto historico = db.carregarDados();

        if (!historico.empty()) {
            std::cout << "[ENGINE] " << historico.size()
                      << " transação(ões) encontrada(s) no histórico:\n";
            for (const auto& t : historico) {
                std::cout << "  > " << t << "\n";
            }
        }

        // 2. Simulação de novas transações a persistir
        std::vector<std::string> novasTransacoes = {
            "2025-06-10,TXN-001,DEPOSITO,R$1500.00,APROVADO",
            "2025-06-10,TXN-002,SAQUE,R$200.00,APROVADO",
            "2025-06-10,TXN-003,TRANSFERENCIA,R$3000.00,PENDENTE",
        };

        std::cout << "[ENGINE] Persistindo " << novasTransacoes.size()
                  << " nova(s) transação(ões)...\n";
        db.salvarDados(novasTransacoes);

        // 3. Simula DiskWriteException: tenta gravar em caminho sem permissão
        std::cout << "\n[ENGINE] Simulando falha de escrita em disco...\n";
        try {
            //Força falha tentando um caminho de sistema sem permissão

            //Em ambiente real, usaríamos um path como "/root/ledger.csv"
            //Aqui forçamos o lançamento manual para fins didáticos:
            throw DiskWriteException(
                "Simulação: disco cheio detectado ao gravar TXN-004."
            );
        } catch (const DiskWriteException& e) {
            std::cerr << "[ENGINE] Capturado: " << e.what() << "\n";
            std::cerr << "[ENGINE] Transação rejeitada. Ledger íntegro.\n";
        }

        // 4. Simula FileCorruptedException
        std::cout << "\n[ENGINE] Simulando arquivo corrompido...\n";
        try {
            throw FileCorruptedException(
                "Linha 7 vazia inesperada — possível truncamento de escrita anterior."
            );
        } catch (const FileCorruptedException& e) {
            std::cerr << "[ENGINE] Capturado: " << e.what() << "\n";
            std::cerr << "[ENGINE] Acionar protocolo de recuperação de backup.\n";
        }

        std::cout << "\n[ENGINE] Sistema operacional e aguardando interceptações...\n";
        std::cout << "[ENGINE] Pressione Ctrl+C para testar o SignalHandler.\n";

        //Loop de espera — permite testar SIGINT/SIGTERM manualmente
        while (true) {
            //Em produção: aguardaria mensagens da fila de transações
            //Para testes: pressione Ctrl+C para disparar o tratador
            volatile int aguarda = 0;
            for (int i = 0; i < 100000000; ++i) aguarda++;
        }

    } catch (const StorageException& e) {
        std::cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: "
                  << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "[UNKNOWN ERROR] Erro genérico de runtime: "
                  << e.what() << "\n";
        return 2;
    }

    return 0;
}