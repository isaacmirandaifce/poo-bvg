#include <iostream>
using namespace std;

// Classe base abstrata para Pagamento com método virtual puro
class Pagamento {
public:
    virtual void processarPagamento(double valor) = 0; // Método que deve ser implementado pelas subclasses
    virtual ~Pagamento() {} // Destrutor virtual para garantir a destruição correta dos objetos derivados
};

// Pagamento em dinheiro
class PagamentoDinheiro : public Pagamento {
public:
    void processarPagamento(double valor) override {
        cout << "Processando pagamento em DINHEIRO de: R$ " << valor << endl;
        // Lógica adicional: calcular troco, registrar pagamento em caixa, etc.
    }
};

// Pagamento com cartão de crédito
class PagamentoCartaoCredito : public Pagamento {
public:
    void processarPagamento(double valor) override {
        cout << "Processando pagamento com CARTAO DE CREDITO de: R$ " << valor << endl;
        // Lógica adicional: solicitar autorização, verificar limite, etc.
    }
};

// Pagamento com cartão de débito
class PagamentoCartaoDebito : public Pagamento {
public:
    void processarPagamento(double valor) override {
        cout << "Processando pagamento com CARTAO DE DEBITO de: R$ " << valor << endl;
        // Lógica adicional: validar saldo, autorizar transação, etc.
    }
};

// Pagamento via PIX
class PagamentoPIX : public Pagamento {
public:
    void processarPagamento(double valor) override {
        cout << "Processando pagamento com PIX de: R$ " << valor << endl;
        // Lógica adicional: gerar QR Code, confirmar transferência instantânea, etc.
    }
};

// Pagamento com cupom promocional
class PagamentoCupom : public Pagamento {
public:
    void processarPagamento(double valor) override {
        cout << "Processando pagamento com CUPOM PROMOCIONAL para desconto sobre: R$ " << valor << endl;
        // Lógica adicional: aplicar desconto, validar validade do cupom, etc.
    }
};

int main() {
    // Criação de objetos do tipo Pagamento para cada método específico
    Pagamento* pgDinheiro = new PagamentoDinheiro();
    Pagamento* pgCartaoCredito = new PagamentoCartaoCredito();
    Pagamento* pgCartaoDebito = new PagamentoCartaoDebito();
    Pagamento* pgPIX = new PagamentoPIX();
    Pagamento* pgCupom = new PagamentoCupom();
    
    double valorPagamento = 150.00;
    
    // Utilizando polimorfismo para processar cada tipo de pagamento
    pgDinheiro->processarPagamento(valorPagamento);
    pgCartaoCredito->processarPagamento(valorPagamento);
    pgCartaoDebito->processarPagamento(valorPagamento);
    pgPIX->processarPagamento(valorPagamento);
    pgCupom->processarPagamento(valorPagamento);
    
    // Liberação da memória alocada
    delete pgDinheiro;
    delete pgCartaoCredito;
    delete pgCartaoDebito;
    delete pgPIX;
    delete pgCupom;
    
    return 0;
}
