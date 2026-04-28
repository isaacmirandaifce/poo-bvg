from models.cliente import cliente
from models.seguros import seguroAutomovel, seguroVida, seguroImovel

if __name__ == "__main__":
    cliente1 = cliente("Ada Lovelace", "111.222.333-44")
    cliente2 = cliente("Alan Turing", "999.888.777-66")

    carteira_seguros = [
        seguroAutomovel(cliente1, 1500, 2008, "JPG-2468"),
        seguroVida(cliente1, 1000, 65),
        seguroImovel(cliente1, 1050, "apartamento"),
        seguroAutomovel(cliente2, 2000, 2010, "PNG-1357"),
        seguroVida(cliente2, 2500, 30),
        seguroImovel(cliente2, 3000, "casa")

        
    ]
    print("\nCalculando Apólices:")
    for seguro in carteira_seguros:

        valor_final = seguro.calcular_premio()
        nome_titular = seguro.titular.nome
        tipo_seguro = seguro.__class__.__name__
        
        print(f"Titular: {nome_titular}\nSeguro: {tipo_seguro}\nPrêmio: R${valor_final:.2f}")