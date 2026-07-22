#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H

#include <string>
#include <vector>

// Responsavel pelo I/O resiliente das transacoes do SecureBank Pro (ledger.csv).
class LedgerPersistence {
private:
    std::string caminhoArquivo;

public:
    LedgerPersistence();
    explicit LedgerPersistence(const std::string& caminhoArquivo);

    // Grava as transacoes no arquivo, forcando o flush do buffer.
    // Dispara DiskWriteException caso o fluxo de escrita falhe.
    void salvarDados(const std::vector<std::string>& transacoes);

    // Le as transacoes do arquivo.
    // Dispara FileCorruptedException caso os dados estejam inconsistentes.
    std::vector<std::string> carregarDados();

    std::string getCaminhoArquivo() const;
};

#endif // LEDGERPERSISTENCE_H
