from SCR.atv1 import Cliente # Importa a classe Cliente do módulo atv1 localizado na pasta SCR

# Criação de instâncias da classe Cliente e demonstração dos métodos
cliente_um = Cliente("Fernanda Lara", 20, 1000)
cliente_um.mostrarInformacoes()
cliente_um.atualizarSaldo(900)
cliente_um.mostrarInformacoes()

cliente_dois = Cliente("Raul Seixas", 44, 6000)
cliente_dois.mostrarInformacoes()
cliente_dois.atualizarSaldo(-1220)
cliente_dois.mostrarInformacoes()

cliente_tres = Cliente("Freddie Mercury", 45, 15000)
cliente_tres.mostrarInformacoes()
cliente_tres.atualizarSaldo(751)
cliente_tres.mostrarInformacoes()

cliente_quatro = Cliente("Nina", 29, 2)
cliente_quatro.mostrarInformacoes()
cliente_quatro.atualizarSaldo(-13000)
cliente_quatro.mostrarInformacoes()