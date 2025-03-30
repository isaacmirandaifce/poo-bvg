export class Carro {
    #placa; 

    constructor(ano, marca, modelo, cor, placa) {
        this.ano = ano;
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.#placa = placa;
    }
    getPlaca() {
        return this.#placa;
    }
    setPlaca(placa) {
        this.#placa = placa;
    }

    exibir_detalhes() {
        console.log(`Ano: ${this.ano}`);
        console.log(`Marca: ${this.marca}`);
        console.log(`Modelo: ${this.modelo}`);
        console.log(`Cor: ${this.cor}`);
        console.log(`Placa: ${this.getPlaca()}`); 
    }
}

export class Cliente {
    #cpf;

    constructor(nome, cpf) {
        this.nome = nome;
        this.#cpf = cpf;
    }
    getCpf() {
        return this.#cpf;
    }
    setCpf(cpf) {
        this.#cpf = cpf;
    }

    exibir_informacoes() {
        console.log(`Nome: ${this.nome}`);
        console.log(`CPF: ${this.getCpf()}`);
    }
}

export class SeguroVeiculos {
    constructor(veiculo, vigencia, valorBase) {
        this.veiculo = veiculo;
        this.vigencia = vigencia;
        this.valorBase = valorBase;
    }
    exibir_info() {
        console.log(`Veículo: ${this.veiculo}`);
        console.log(`Vigência: ${this.vigencia}`);
        console.log(`Valor Base: ${this.valorBase}`);
    }
    calcularValorSeguro() {
        throw new Error('Método calcularValorSeguro deve ser implementado nas classes filhas');
    }
}

export class SeguroCarro extends SeguroVeiculos {
    constructor(veiculo, vigencia, valorBase, tipoCarro) {
        super(veiculo, vigencia, valorBase);
        this.tipoCarro = tipoCarro;
    }
    calcularValorSeguro(taxa) {
        let multiplicador = 1;

        if (this.tipoCarro === 'SUV') {
            multiplicador = 1.3;
        } else if (this.tipoCarro === 'Esportivo') {
            multiplicador = 1.5;
        }

        const valorSeguro = (this.valorBase * multiplicador) * taxa;
        console.log(`Valor do seguro do carro: R$ ${valorSeguro.toFixed(2)}`);
    }
}

export class SeguroMoto extends SeguroVeiculos {
    constructor(veiculo, vigencia, valorBase, cilindrada) {
        super(veiculo, vigencia, valorBase);
        this.cilindrada = cilindrada;
    }
    calcularValorSeguro(taxa) {
        let multiplicador = 1;

        if (this.cilindrada > 300) {
            multiplicador = 1.4;
        } else if (this.cilindrada > 200) {
            multiplicador = 1.2;
        }

        const valorSeguro = (this.valorBase * multiplicador) * taxa;
        console.log(`Valor do seguro da moto: R$ ${valorSeguro.toFixed(2)}`);
    }
}