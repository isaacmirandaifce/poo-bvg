"""
Módulo principal para demonstração do subsistema de cálculo de seguros.
"""
from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial

def main():
    """
    Função principal que instancia o cliente, associa diferentes seguros
    e demonstra o polimorfismo chamando o cálculo de prêmios a partir
    da lista interna do próprio cliente.
    """
    print("---- Subsistema de Cálculo de Prêmios e Sinistros ----")
    
    cliente1 = Cliente("Diego José", "123.456.789-01")
    print(f"\nTitular dos Seguros: {cliente1.nome}")
    print(f"CPF Protegido: {cliente1.cpf}") 
    
    seguro_carro = SeguroAuto(titular=cliente1, valor_base=1000.0, placa="ABC-1234", ano=2002)
    seguro_vida = SeguroVida(titular=cliente1, valor_base=1000.0, idade=25)
    seguro_apto = SeguroResidencial(titular=cliente1, valor_base=1000.0, tipo_imovel="CASA")

    print(f"\nTotal de seguros associados ao cliente: {len(cliente1.seguros)}")
    
    print("\n--- Calculando Prémios (Polimorfismo em Ação) ---")
    
    for seguro in cliente1.seguros:
        nome_classe = seguro.__class__.__name__
        valor_final = seguro.calcular_premio()
        print(f"Tipo: {nome_classe} | Valor do Prémio: R$ {valor_final:.2f}")


if __name__ == "__main__":
    main()