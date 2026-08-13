#include "LedgerPersistence.h"
#include "../exceptions/StorageException.h"

#include <ctime>
#include <iostream>

const std::string LedgerPersistence::CAMINHO_ARQUIVO = "ledger.csv";
const std::string LedgerPersistence::CAMINHO_LOG_EMERGENCIAL = "emergencial.log";

namespace {
/// Gera um timestamp legível para os logs (ex.: "2026-08-11 19:30:02").
std::string timestampAtual() {
    std::time_t agora = std::time(nullptr);
    char buffer[32];
    std::tm tmBuffer{};
#if defined(_WIN32)
    localtime_s(&tmBuffer, &agora);
#else
    localtime_r(&agora, &tmBuffer);
#endif
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tmBuffer);
    return std::string(buffer);
}
} // namespace

LedgerPersistence::~LedgerPersistence() {
    fecharComSeguranca();
}

void LedgerPersistence::salvarDados(const std::vector<std::string>& transacoes) {
    fluxoSaida.open(CAMINHO_ARQUIVO, std::ios::out | std::ios::app);

    if (!fluxoSaida.is_open()) {
        throw DiskWriteException(
            "Nao foi possivel abrir '" + CAMINHO_ARQUIVO +
            "' para escrita (permissao negada ou disco indisponivel).");
    }

    for (const std::string& transacao : transacoes) {
        fluxoSaida << transacao << '\n';
        if (fluxoSaida.fail()) {
            throw DiskWriteException(
                "Falha ao persistir transacao em '" + CAMINHO_ARQUIVO +
                "' (possivel disco cheio).");
        }
    }

    fluxoSaida << std::flush;
    if (fluxoSaida.fail()) {
        throw DiskWriteException(
            "Falha ao esvaziar o buffer de escrita de '" + CAMINHO_ARQUIVO + "'.");
    }

    fluxoSaida.close();
}

std::vector<std::string> LedgerPersistence::carregarDados() {
    std::ifstream entrada(CAMINHO_ARQUIVO);

    // Primeira execucao: o ledger ainda nao existe. Isso nao e corrupcao.
    if (!entrada.is_open()) {
        return {};
    }

    std::vector<std::string> registros;
    std::string linha;

    while (std::getline(entrada, linha)) {
        if (linha.empty()) {
            throw FileCorruptedException(
                "Linha vazia inesperada encontrada em '" + CAMINHO_ARQUIVO +
                "' (registro #" + std::to_string(registros.size() + 1) + ").");
        }
        registros.push_back(linha);
    }

    // getline retorna false tanto em EOF quanto em falha real de leitura.
    // eof() distingue os dois casos: se NAO for eof, houve falha de fato.
    if (entrada.bad() || (entrada.fail() && !entrada.eof())) {
        throw FileCorruptedException(
            "Falha de leitura em '" + CAMINHO_ARQUIVO + "' antes do fim do arquivo.");
    }

    return registros;
}

void LedgerPersistence::fecharComSeguranca() noexcept {
    try {
        if (fluxoSaida.is_open()) {
            fluxoSaida << std::flush;
            fluxoSaida.close();
        }

        std::ofstream log(CAMINHO_LOG_EMERGENCIAL, std::ios::app);
        if (log.is_open()) {
            log << "[" << timestampAtual()
                << "] Encerramento seguro executado - arquivo '" << CAMINHO_ARQUIVO
                << "' fechado sem partial writes.\n";
        }
    } catch (...) {
        // fecharComSeguranca() e noexcept e pode ser chamada de dentro de um
        // manipulador de sinal: nunca pode propagar excecao.
        std::cerr << "[LedgerPersistence] Falha ao registrar log emergencial.\n";
    }
}
