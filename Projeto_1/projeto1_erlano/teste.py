#importa a classe "Cliente" do arquivo "isaac.py"
from isaac import Cliente

#Inicializa a classe criando e adicionando informações ao objeto
cliente1 = Cliente("Erlano Benevides", 19, 50.0)

#Mostra as informações do objeto, depois atualiza o valor do saldo e depois imprime denovo
cliente1.mostrar_informacoes()
cliente1.atualizar_saldo(50.0)
cliente1.mostrar_informacoes()