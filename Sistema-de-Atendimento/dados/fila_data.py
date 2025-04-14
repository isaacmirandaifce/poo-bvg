from collections import deque

fila_prioritaria = deque()
fila_normal = deque()
ultimas_chamadas = deque(maxlen=5)
senhas_aguardando = fila_normal + fila_prioritaria