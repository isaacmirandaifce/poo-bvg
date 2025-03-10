import os
import signal
import csv
import sys

class ArquivoNaoLocalizadoException(Exception):
  pass

class PermissaoNegadaException(Exception):
  pass

def carregar_dados(arquivo):
  try:
    if not os.path.exists(arquivo):
      raise ArquivoNaoLocalizadoException(f"O arquivo {arquivo} não foi localizado.")

    with open(arquivo, mode='r', encoding='utf-8') as f:
      reader = csv.reader(f)
      return [linha for linha in reader]

  except FileNotFoundError:
    raise ArquivoNaoLocalizadoException(f"Erro: o {arquivo} não foi encontrado.")
  
  except PermissionError:
    raise PermissaoNegadaException(f"Erro: permissão negada para acessar o arquivo {arquivo}")

def salvar_Dados(arquivo, dados):
  try:
    with open(arquivo, mode='w', newline='', encoding='utf-8') as f:
      writer = csv.writer(f)
      writer.writerows(dados)
  except PermissionError:
    raise PermissaoNegadaException(f"Erro: Permissão negada para gravar no arquivo {arquivo}")

def tratador_sinal(sig, frame):
  print(f"\Sinal {sig} recebido. Salvando dados antes de sair...")
  sys.exit(0)

signal.signal(signal.SIGINT, tratador_sinal)
signal.signal(signal.SIGTERM, tratador_sinal)

class SistemaAcademico:
  def __init__(self, arquivo_alunos='alunos.csv'):
    self.arquivo_alunos = arquivo_alunos
    self.alunos = self.carregar_alunos()

  def carregar_alunos(self):
    try:
      return carregar_dados(self.arquivo_alunos)
    except ArquivoNaoLocalizadoException as e:
      print(e)
      return []

  def adicionar_aluno(self, nome, matricula):
    self.alunos.append([nome, matricula])
    salvar_Dados(self.arquivo_alunos, self.alunos)
    print(f"Aluno {nome} adicionado com sucesso")

def main():
  sistema = SistemaAcademico()
  while True:
    print("\n1. Adicionar Aluno\n2. Listar Alunos\n3. Sair")
    opcao = input("Escolha uma opção: ")

    if opcao == '1':
      nome = input("Nome do aluno: ")
      matricula = input("Matrícula do aluno: ")
      sistema.adicionar_aluno(nome, matricula)
    elif opcao == '2':
      print("Lista de Alunos:")
      for aluno in sistema.alunos:
        print(f"Nome: {aluno[0]}, Matrícula: {aluno[1]}")
    elif opcao == '3':
      print("Saindo...")
      break
    else:
      print("Opção inválida")

if __name__ == "__main__":
  main()