class Cliente {
    //criação das classes
    String nome_cliente;
    int idade_cliente;
    double saldo_cliente;

    void apresentar() {
        System.out.println("Cliente: " + nome_cliente + " Idade: " + idade_cliente + " Saldo: R$ " + saldo_cliente);
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo_cliente += valor;
            System.out.println("Depósito de R$ " + valor + " realizado com sucesso!");
        }else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo_cliente) {
            saldo_cliente -= valor;
            System.out.println("Saque no valor de R$: " + valor);
        }else if (valor > saldo_cliente) {
            System.out.println("Saldo insuficiente");
        }else {
            System.out.println("Valor inválido");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Cliente cliente = new Cliente();

        cliente.nome_cliente = "João Silva";
        cliente.idade_cliente = 30;
        cliente.saldo_cliente = 1000.0;
        cliente.apresentar();

        cliente.depositar(500.0);
        cliente.apresentar();
        cliente.sacar(200.0);
        cliente.apresentar();
        cliente.sacar(1200.0);
        cliente.apresentar();
    }
}