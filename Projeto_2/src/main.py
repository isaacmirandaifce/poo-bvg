"""
    Módulo Principal do Sistema de Seguros.
    Responsável por instanciar os objetos de clientes, veículos e seguros,
    e executar a demonstração das funcionalidades e interações do usuário.
"""
from models.cliente import Cliente
from models.seguro import SeguroVeiculo, SeguroCarro, SeguroMoto
from models.veiculo import Veiculo, Carro, Moto
from datetime import date

if __name__ == "__main__":
    """
        Criamos variaveis que armazenam a saida de nossas classes, atribuimos valores genéricos a essas classes, como pede à atividade.
    """
    cliente1 = Cliente("João Silva", "123.456.789-00")
    cliente2 = Cliente("Maria Oliveira", "135.791.357-11")
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    moto = Moto(2021, "Yamaha", "FZ-15", "Preta", "XYZ-1233")
    
    vigenciaCarro = date(2030, 1, 1)
    vigenciaMoto = date(2025, 1, 1)

    seguro_joao = SeguroCarro(cliente1, 1500.00, vigenciaCarro, carro)
    seguro_maria = SeguroMoto(cliente2, 2000.00, vigenciaMoto, moto)

    """
        Aqui, atribuimos um pouco de interação com o usuário, uma pergunta extremamente simples apenas para saber se o usuário quer trocar a cor do veiculo
        e testar a o método "trocar_cor" da classe "Veiculo".
    """
    trocar_cor = input(f"CLIENTE 1 - Quer trocar a cor do veiculo? S/s\nCor atual: {carro.cor}\n")
    if trocar_cor == "S" or trocar_cor == "s":
        cor_nova = input("Digite a nova cor do carro: ")
        carro.trocar_cor(cor_nova)

    print("--- INFORMAÇÕES DO SISTEMA ---")
    seguro_joao.cliente.exibir_info()
    seguro_joao.carro.exibir_detalhes()

    print("\n--- CLIENTE 2 ---\n")

    trocar_cor = input(f"CLIENTE 1 - Quer trocar a cor do veiculo? S/s\nCor atual: {carro.cor}\n")
    if trocar_cor == "S" or trocar_cor == "s":
        cor_nova = input("Digite a nova cor da moto: ")
        moto.trocar_cor(cor_nova)

    seguro_maria.cliente.exibir_info()
    seguro_maria.moto.exibir_detalhes()
    
    print("\n--- DETALHES DO SEGURO ---")
    print(f"Status da Vigência: {seguro_joao.verificar_vigencia()}")
    print(f"Valor Base do Seguro: R$ {seguro_joao.valor_base:.2f}")

    print(f"Status da Vigência: {seguro_maria.verificar_vigencia()}")
    print(f"Valor Base do Seguro: R$ {seguro_maria.valor_base:.2f}")
    
    valor_final_joao = seguro_joao.calcular_valor()
    valor_final_maria = seguro_maria.calcular_valor()

    print(f"Valor Final com Taxa de Risco: R$ {valor_final_joao:.2f}")
    print(f"Valor Final com Taxa de Risco: R$ {valor_final_maria:.2f}")

    print(f"\nAcesso seguro à placa encapsulada do carro: {carro.get_placa}")
    print(f"Acesso seguro à placa encapsulada da moto: {moto.get_placa}")