/* importação da classe */
import {Cliente} from '../src/Cliente.js';
/* Criação de uma instância da classe, Exibição das informações do cliente, Atualização do saldo e Exibição das informações do cliente com o saldo atualizado*/
const cliente1 = new Cliente("João Silva", 30, 1000);
cliente1.mostrarInformações();
cliente1.atualizarSaldo(500);
cliente1.mostrarInformações();