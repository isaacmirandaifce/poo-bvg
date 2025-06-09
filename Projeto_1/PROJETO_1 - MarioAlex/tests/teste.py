from src.cliente import Cliente

def test_cliente():
    cliente = Cliente("Teste", 25, 1000.0)
    assert cliente.get_nome() == "Teste"
    assert cliente.get_idade() == 25
    assert cliente.get_saldo() == 1000.0

    cliente.atualizar_saldo(500.0)
    assert cliente.get_saldo() == 1500.0
