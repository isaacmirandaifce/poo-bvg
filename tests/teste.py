import unittest
import sys
import os

# Adiciona o caminho do diretório src ao sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from cliente import Cliente

class TestCliente(unittest.TestCase):

    def test_criarCliente(self):
        # Corrigido: argumentos separados
        cliente = Cliente("Mario Alex", 20, 1000)
        self.assertEqual(cliente.nome, "Mario Alex")
        self.assertEqual(cliente.idade, 20)  # Corrigido: número, não string
        self.assertEqual(cliente.saldo, 1000)

    def test_atualizar_saldo(self):
        # Corrigido: nome do método e nome do teste
        cliente = Cliente("Mario Alex", 20, 1000)
        cliente.atualizar_saldo(250)
        self.assertEqual(cliente.saldo, 1250)

if __name__ == '__main__':
    unittest.main()
import unittest
import sys
import os

# Adiciona o caminho do diretório src ao sys.path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from cliente import Cliente

class TestCliente(unittest.TestCase):

    def test_criarCliente(self):
        cliente = Cliente("Mario Alex", 20, 1000)
        self.assertEqual(cliente.nome, "Mario Alex")
        self.assertEqual(cliente.idade, 20) 
        self.assertEqual(cliente.saldo, 1000)

    def test_atualizar_saldo(self):
        cliente = Cliente("Mario Alex", 20, 1000)
        cliente.atualizar_saldo(250)
        self.assertEqual(cliente.saldo, 1250)

if __name__ == '__main__':
    unittest.main()
