#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

using namespace std;

int main() {
    cout << "===== SecureBank Pro - Motor de Persistencia Resiliente (Ledger Engine) =====" << endl << endl;

    SignalHandler::inicializar(); // Registra os hooks de sinal do SO (SIGINT/SIGTERM)

    try {
        LedgerPersistence db("ledger.csv");

        // 1. Carregamento inicial do historico (pode disparar FileCorruptedException).
        try {
            vector<string> historico = db.carregarDados();
            cout << "[ENGINE] Historico carregado: " << historico.size() << " transacao(oes) existente(s)." << endl;
        } catch (const FileCorruptedException& e) {
            cerr << "[RECUPERAVEL] Historico corrompido, iniciando ledger vazio: " << e.what() << endl;
        }

        // 2. Buffer de transacoes pendentes, protegido pelo SignalHandler.
        vector<string> bufferPendente;
        SignalHandler::registrarContexto(&db, &bufferPendente);

        cout << "[ENGINE] Sistema operacional e aguardando interceptacoes..." << endl;
        cout << "[ENGINE] Pressione Ctrl+C a qualquer momento para simular uma interrupcao (SIGINT)." << endl << endl;

        // 3. Loop de simulacao de transacoes.
        const int totalTransacoes = 5;
        for (int i = 1; i <= totalTransacoes; ++i) {
            string transacao = "TX" + to_string(i) + ";PIX;" + to_string(1000.0 * i);
            bufferPendente.push_back(transacao);
            cout << "[ENGINE] Transacao gerada: " << transacao << endl;

            // 4. Persistencia isolada: falha de disco nao derruba o loop inteiro.
            try {
                db.salvarDados(bufferPendente);
                cout << "[ENGINE] Buffer persistido com sucesso (" << bufferPendente.size() << " registro(s))." << endl;
                bufferPendente.clear();
            } catch (const DiskWriteException& e) {
                cerr << "[RECUPERAVEL] Falha ao persistir transacao: " << e.what() << endl;
            }

            this_thread::sleep_for(chrono::seconds(1));
        }

        cout << endl << "[ENGINE] Processamento concluido sem interrupcoes do SO." << endl;

    } catch (const StorageException& e) {
        cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "[UNKNOWN ERROR] Erro generico de runtime: " << e.what() << endl;
        return 1;
    }

    return 0;
}
