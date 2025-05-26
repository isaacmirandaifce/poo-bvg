from src.carro import Carro

def test_exibir_detalhes():
    carro = Carro(2020, "Toyota", "Corolla", "Preto", "ABC1234")
    resultado = carro.exibir_detalhes()
    assert resultado == "2020 Toyota Corolla - Cor: Preto, Placa: ABC1234"

def test_atualizar_cor():
    carro = Carro(2020, "Toyota", "Corolla", "Preto", "ABC1234")
    carro.atualizar_cor("Preto")
    assert carro.cor == "Preto"
