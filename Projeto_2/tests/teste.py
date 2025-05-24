from main import Modelo, Carro, Cliente, Seguro

def exemplo_uso():
    modelo_fusca = Modelo("Fusca")
    carro1 = Carro(1985, "Volkswagen", modelo_fusca, "azul", "ABC-1234")
    cliente1 = Cliente("Fernando Rodrigues", "123.456.789-00")
    seguro1 = Seguro(carro1, cliente1, 1500.00, "2024-01-01 a 2024-12-31")

    print(seguro1)

if __name__ == "__main__":
    exemplo_uso()

