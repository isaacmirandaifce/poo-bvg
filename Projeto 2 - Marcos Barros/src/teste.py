# Suponha que as classes Cliente, Carro e Seguro já foram definidas conforme explicamos antes.

# Criar cliente
cliente_teste = Cliente("João Silva", "123.456.789-00")

# Criar carro
carro_teste = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")

# Criar seguro
seguro_teste = Seguro(carro_teste, cliente_teste, 1500.00, "2025-01-01")

# Teste: Exibir informações do cliente
print("==== Teste Cliente ====")
cliente_teste.exibir_informacoes()
print("CPF acessado pelo método:", cliente_teste.get_cpf())

# Teste: Exibir detalhes do carro
print("\n==== Teste Carro ====")
carro_teste.exibir_detalhes()
print("Placa acessada pelo método:", carro_teste.get_placa())

# Teste: Atualizar cor
carro_teste.atualizar_cor("Preto")
print("Detalhes do carro após mudança de cor:")
carro_teste.exibir_detalhes()

# Teste: Calcular valor do seguro
print("\n==== Teste Seguro ====")
valor_calculado = seguro_teste.calcular_valor(1500.00, 0.1)
print("Valor calculado com taxa:", valor_calculado)

# Teste: Verificar vigência
vigente = seguro_teste.verificar_vigencia()
print("O seguro está vigente?", "Sim" if vigente else "Não")
