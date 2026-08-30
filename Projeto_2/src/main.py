"""Script principal para demonstração de Polimorfismo no cálculo de prêmios."""

from models.cliente import Cliente
from models.seguros import SeguroAuto, SeguroVida, SeguroResidencial

def main():
    # 1. Criação do cliente e proteção de dados sensíveis
    cliente = Cliente(nome="Alan Turing", cpf="123.456.789-00")
    
    # 2. Instanciando a lista de seguros (diferentes tipos misturados)
    apolices = [
        SeguroAuto(titular=cliente, valor_base=1000.0, placa="ABC-1234", ano=2008),
        SeguroAuto(titular=cliente, valor_base=1000.0, placa="XYZ-9876", ano=2021),
        SeguroVida(titular=cliente, valor_base=2500.0, idade=65),
        SeguroVida(titular=cliente, valor_base=2500.0, idade=35),
        SeguroResidencial(titular=cliente, valor_base=1200.0, tipo_residencia="CASA"),
        SeguroResidencial(titular=cliente, valor_base=1200.0, tipo_residencia="APARTAMENTO")
    ]
    
    print(f"--- Relatório de Prêmios - Cliente: {cliente.nome} ---")
    
    # 3. POLIMORFISMO EM AÇÃO
    # O laço interage com a abstração `Seguro`. O sistema não sabe se é Vida,
    # Auto ou Residencial; ele apenas invoca `calcular_premio()` e cada objeto
    # responde com sua própria regra de negócio.
    for apolice in apolices:
        tipo_seguro = apolice.__class__.__name__
        premio_final = apolice.calcular_premio()
        print(f"Apolice: {tipo_seguro.ljust(18)} | Valor do Prêmio: R$ {premio_final:,.2f}")

if __name__ == "__main__":
    main()