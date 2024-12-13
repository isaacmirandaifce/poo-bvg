import { Carro, Cliente, SeguroCarro } from './classes.js';

const meuCarro = new Carro(2022, "Toyota", "Corolla", "Preto", "ABC-1234");
const cliente1 = new Cliente("João", "123.456.789-00");
const seguroCarro = new SeguroCarro(meuCarro, "2024-12-31", 1000.00, "SUV");

meuCarro.exibir_detalhes();
cliente1.exibir_informacoes();
seguroCarro.exibir_info();
seguroCarro.calcularValorSeguro(1.1);