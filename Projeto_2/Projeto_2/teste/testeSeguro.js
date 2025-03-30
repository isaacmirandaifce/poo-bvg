import Carro from "../src/carro.js";
import Cliente from "../src/cliente.js";
import Seguro from "../src/seguro.js";

const testarSeguro = () => {
  const carro = new Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234");
  const cliente = new Cliente("João Silva", "123.456.789-00");
  const seguro = new Seguro(carro, cliente, 1500, "2025-01-01");

  console.log("Testando Seguro:");
  console.log(seguro.calcularValor(1000, 0.15)); /*Espera: Valor calculado com base em 1000 + 15% (1150)*/
  console.log(seguro.verificarVigencia() ? "Seguro válido" : "Seguro expirado"); /*Espera: "Seguro válido"*/
};

testarSeguro();
