#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "exceptions/StorageException.h"
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"

namespace {

/**
 * @brief Gera um lote simulado de transações no formato "id,valor,tipo",
 * apenas para exercitar salvarDados() sem depender de um gerador externo.
 */
std::vector<std::string> gerarLoteSimulado(int numeroLote) {
    std::vector<std::string> lote;
    const int transacoesPorLote = 3;

    for (int i = 1; i <= transacoesPorLote; ++i) {
        int id = (numeroLote - 1) * transacoesPorLote + i;
        double valor = 100.0 * id + 0.50;
        std::string tipo = (id % 2 == 0) ? "TED" : "PIX";

        lote.push_back(std::to_string(id) + "," + std::to_string(valor) + "," + tipo);
    }

    return lote;
}

} // namespace

int main() {
    LedgerPersistence db;

    // Registra a persistencia ativa ANTES de inicializar os hooks de sinal:
    // se um Ctrl+C chegar durante a propria inicializacao, o handler ja
    // deve saber qual arquivo fechar com seguranca.
    SignalHandler::registrarPersistencia(&db);
    SignalHandler::inicializar(); // Registra os hooks de sinal do SO

    try {
        // 1. Simular carregamento inicial (pode disparar FileCorruptedException)
        auto historico = db.carregarDados();
        std::cout << "[ENGINE] Historico carregado: " << historico.size()
                  << " registro(s) existente(s).\n";
    } catch (const FileCorruptedException& e) {
        // Isolamos FileCorruptedException do restante das StorageException:
        // um ledger corrompido na carga inicial nao deveria impedir o
        // sistema de continuar operando (ele apenas comeca "do zero").
        std::cerr << "[CRITICAL ERROR] " << e.what() << '\n';
        std::cerr << "[ENGINE] Prosseguindo com historico vazio apos falha de leitura.\n";
    } catch (const StorageException& e) {
        std::cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: "
                  << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "[UNKNOWN ERROR] Erro generico de runtime: " << e.what() << '\n';
    }

    std::cout << "[ENGINE] Sistema operacional e aguardando interceptacoes...\n";
    std::cout << "[ENGINE] (pressione Ctrl+C a qualquer momento para testar o SignalHandler)\n";

    const int totalLotes = 5;

    for (int lote = 1; lote <= totalLotes; ++lote) {
        std::vector<std::string> transacoesSimuladas = gerarLoteSimulado(lote);

        try {
            // Bloco try-catch LOCAL: uma falha de escrita em um unico lote
            // fica isolada aqui e nao derruba o loop inteiro do engine.
            db.salvarDados(transacoesSimuladas);
            std::cout << "[ENGINE] Lote " << lote << "/" << totalLotes
                      << " persistido com sucesso (" << transacoesSimuladas.size()
                      << " transacoes).\n";
        } catch (const DiskWriteException& e) {
            std::cerr << "[CRITICAL ERROR] Falha de escrita isolada no lote "
                      << lote << ": " << e.what() << '\n';
            continue; // segue para o proximo lote sem encerrar o processo
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "[ENGINE] Simulacao concluida. Encerrando de forma limpa.\n";
    return 0;
}
