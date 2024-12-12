import { Carro } from '../src/carro.js';
import { Cliente } from '../src/cliente.js';
import { SeguroCarro, SeguroMoto } from '../src/seguroVeiculo.js';

// Testes
const cliente = new Cliente("João Silva", "123.456.789-00" ); //instanciando cliente
const carro = new Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234"); //instanciando carro
const seguroCarro = new SeguroCarro(cliente, carro, 1500.0, "01/01/2024 a 01/01/2025"); //instanciando seguro do carrop

// Exibindo dados do cliente e carro
console.log('Dados - Cliente e Carro')
console.log(cliente.exibirInformacoes());
console.log(carro.exibirDetalhes());
console.log('\n')
// Calculando valor do seguro e vendo a vigência
console.log('Dados - Calculo de seguro do CARRO e vigencia')
console.log(`Valor calculado do seguro: R$ ${seguroCarro.calcularValor(1200.0, 0.1).toFixed(2)}`);
console.log(`Seguro está válido? ${seguroCarro.verificarVigencia() ? 'Sim' : 'Não'}`);
console.log('\n')

// Atualizando cor do carro
console.log('Dados - Mudando a cor do carro')
carro.atualizarCor("Preto");
console.log(carro.exibirDetalhes());
console.log('\n')

// Testandoa agora o SeguroMoto (usando a classe do carro mesmo so pra testar)
const moto = new Carro(2021, "Honda", "CB500F", "Vermelha", "ABC-9876");
const seguroMoto = new SeguroMoto(cliente, moto, 800.0, "01/01/2024 a 01/01/2025");

// Exibindo dados do cliente e moto
console.log('Dados - Cliente e moto')
console.log(cliente.exibirInformacoes());
console.log(moto.exibirDetalhes());
console.log('\n')

// Calculando valor do seguro de moto e vendo a vigência
console.log('Dados - Calculando seguro MOTO e vigencia')
console.log(`Valor calculado do seguro de moto: R$ ${seguroMoto.calcularValor(700.0, 0.08).toFixed(2)}`);
console.log(`Seguro de moto está válido? ${seguroMoto.verificarVigencia() ? 'Sim' : 'Não'}`);
console.log('\n')
