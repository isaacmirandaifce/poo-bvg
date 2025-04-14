from dados.fila_data import fila_prioritaria, fila_normal

def pegar_proxima_senha():
    if fila_prioritaria:
        return fila_prioritaria.popleft()
    elif fila_normal:
        return fila_normal.popleft()
    else:
        return None