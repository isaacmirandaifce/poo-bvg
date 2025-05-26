from src.cliente import Cliente

def test_exibir_informacoes():
    cliente = Cliente("João", "123.456.789-00")
    resultado = cliente.exibir_informacoes()
    assert resultado == "Nome: João | CPF: 123.456.789-00"
