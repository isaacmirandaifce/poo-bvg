import { Cliente } from "../src/Cliente";

const cliente1 = new Cliente("João Silva", 30, 1000);
cliente1.mostrar_informacoes();
cliente1.atualizar_saldo(500);
cliente1.mostrar_informacoes();
