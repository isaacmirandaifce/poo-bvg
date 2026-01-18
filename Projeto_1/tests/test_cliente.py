from src.cliente import Cliente

def test_atualizar_saldo():
    c = Cliente("A", 20, 100.0)
    c.atualizar_saldo(50)
    assert c.get_saldo() == 150.0
    c.atualizar_saldo(-25)
    assert c.get_saldo() == 125.0 
