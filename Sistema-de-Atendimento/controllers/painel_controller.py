from dados.fila_data import ultimas_chamadas

def listar_ultimas_chamadas():
    """
    Retorna a lista das últimas senhas chamadas com seus respectivos guichês.
    """
    return [
        {
            "guiche": item[0],
            "codigo": item[1]
        }
        for item in ultimas_chamadas
    ]
