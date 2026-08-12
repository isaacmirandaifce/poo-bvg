#ifndef RELATORIO_H
#define RELATORIO_H

/**
 * @interface Relatorio
 * @brief Contrato operacional puramente abstrato (<<interface>>).
 *
 * Toda classe que precisa expor dados de auditoria/relatorio para o
 * sistema de mensageria interno deve assinar este contrato. Por conter
 * apenas metodos virtuais puros e nao possuir dados/estado proprio,
 * esta classe se comporta como uma interface (nao pode ser instanciada).
 */
class Relatorio {
public:
    // Destrutor virtual: obrigatorio em toda interface/classe base
    // polimorfica para garantir destruicao correta via ponteiro de base.
    virtual ~Relatorio() = default;

    /**
     * @brief Metodo virtual puro que forca cada classe concreta a
     *        implementar sua propria logica de geracao de relatorio.
     */
    virtual void gerarRelatorio() const = 0;
};

#endif // RELATORIO_H
