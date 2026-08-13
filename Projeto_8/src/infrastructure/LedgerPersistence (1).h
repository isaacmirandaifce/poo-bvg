#ifndef LEDGERPERSISTENCE_H
#define LEDGERPERSISTENCE_H

#include <fstream>
#include <string>
#include <vector>

/**
 * @class LedgerPersistence
 * @brief Responsável por todo o I/O do Transaction Ledger (ledger.csv).
 *
 * Mantém o std::ofstream de escrita como atributo de instância (em vez de
 * uma variável local dentro de salvarDados) justamente para que, se um
 * SIGINT/SIGTERM chegar no meio de uma gravação, o SignalHandler consiga
 * acessar esse mesmo fluxo — via fecharComSeguranca() — e garantir
 * flush + close antes do processo encerrar, evitando partial writes.
 */
class LedgerPersistence {
private:
    static const std::string CAMINHO_ARQUIVO;
    static const std::string CAMINHO_LOG_EMERGENCIAL;

    std::ofstream fluxoSaida;

public:
    LedgerPersistence() = default;

    /// Garante que nenhum arquivo fique aberto/pendente mesmo em saída normal.
    ~LedgerPersistence();

    LedgerPersistence(const LedgerPersistence&) = delete;
    LedgerPersistence& operator=(const LedgerPersistence&) = delete;

    /**
     * @brief Grava cada transação em ledger.csv (modo append) e força o
     * esvaziamento do buffer com std::flush.
     * @throws DiskWriteException se o arquivo não puder ser aberto ou se
     * a escrita falhar (permissão/espaço em disco).
     */
    void salvarDados(const std::vector<std::string>& transacoes);

    /**
     * @brief Lê todas as linhas de ledger.csv.
     * @return Vetor vazio caso o arquivo ainda não exista (primeira
     * execução do sistema) — isso não é considerado corrupção.
     * @throws FileCorruptedException se o arquivo existir mas contiver
     * linhas vazias inesperadas ou se a leitura falhar no meio do arquivo.
     */
    std::vector<std::string> carregarDados();

    /**
     * @brief Fecha de forma segura qualquer arquivo pendente e grava um
     * log emergencial de encerramento. Chamado pelo SignalHandler quando
     * um sinal do SO é interceptado, e também pelo destrutor.
     *
     * `noexcept`: nunca deve lançar, pois é executado a partir de um
     * manipulador de sinal / destrutor, onde uma exceção não tratada
     * levaria a std::terminate().
     */
    void fecharComSeguranca() noexcept;
};

#endif // LEDGERPERSISTENCE_H
