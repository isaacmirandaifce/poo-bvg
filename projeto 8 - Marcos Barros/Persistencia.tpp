#include <iostream>

template <typename T>
void Persistencia::salvar(const std::vector<T>& dados, const std::string& nomeArquivo) {
    // Tenta abrir o arquivo para escrita
    std::ofstream outFile(nomeArquivo);

    // Se não for possível abrir, lança uma exceção
    if (!outFile.is_open()) {
        throw PermissaoNegadaException("Não foi possível abrir o arquivo para escrita: " + nomeArquivo);
    }

    // Itera sobre os dados e escreve cada um no formato CSV
    for (const auto& item : dados) {
        outFile << item.to_csv() << std::endl;
    }

    outFile.close();
}


template <typename T>
std::vector<T> Persistencia::carregar(const std::string& nomeArquivo) {
    std::vector<T> dados;
    // Tenta abrir o arquivo para leitura
    std::ifstream inFile(nomeArquivo);

    // Se o arquivo não existir, lança exceção
    if (!inFile.good()) {
        throw ArquivoNaoEncontradoException("Arquivo não encontrado: " + nomeArquivo);
    }

    // Se existir mas não puder ser aberto (ex: sem permissão)
    if (!inFile.is_open()) {
        throw PermissaoNegadaException("Não foi possível abrir o arquivo para leitura: " + nomeArquivo);
    }

    std::string linha;
    int numeroLinha = 1;
    // Lê o arquivo linha por linha
    while (std::getline(inFile, linha)) {
        if (linha.empty()) continue; // Pula linhas em branco
        try {
            // Tenta converter a linha para um objeto
            dados.push_back(T::from_csv(linha));
        } catch (const std::invalid_argument& e) {
            // Se a conversão falhar, lança exceção personalizada
            throw FormatoInvalidoException("Erro de formato na linha " + std::to_string(numeroLinha) + " do arquivo " + nomeArquivo + ": " + e.what());
        }
        numeroLinha++;
    }

    inFile.close();
    return dados;
}