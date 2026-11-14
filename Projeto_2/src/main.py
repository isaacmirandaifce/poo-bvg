from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial

def main():
    print("---- Subsistema de Cálculo de Prêmios e Sinistros ----")
    
    cliente1 = Cliente("Diego José", "123.456.789-01")
    print(f"\nTitular dos Seguros: {cliente1.nome}")
    
    seguro_carro = SeguroAuto(titular=cliente1, valor_base=1000.0, placa="ABC-1234", ano=2002)
    
    seguro_vida = SeguroVida(titular=cliente1, valor_base=1000.0, idade=25)
    
    seguro_apto = SeguroResidencial(titular=cliente1, valor_base=1000.0, tipo_imovel="CASA")
    
    lista_seguros = [seguro_carro, seguro_vida, seguro_apto]
    
    print("\n--- Calculando Prémios (Polimorfismo em Ação) ---")
    
    for seguro in lista_seguros:
        nome_classe = seguro.__class__.__name__
        valor_final = seguro.calcular_premio()
        print(f"Tipo: {nome_classe} | Valor do Prémio: R$ {valor_final:.2f}")

if __name__ == "__main__":
    main()