#ifndef RELATORIO_H        // Verifica se RELATORIO_H ainda não foi definido
#define RELATORIO_H        // Define RELATORIO_H para evitar múltiplas inclusões

// Classe base abstrata para geração de relatórios
class Relatorio {
public:
    virtual ~Relatorio() = default;  
    // Destrutor virtual padrão — garante destruição correta em herança

    virtual void gerarRelatorio() const = 0;  
    // Método puramente virtual (abstrato) que obriga as classes derivadas
    // a implementarem sua própria forma de gerar relatório
};

#endif // RELATORIO_H        // Fim da diretiva de inclusão