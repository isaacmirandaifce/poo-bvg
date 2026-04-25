"""
 — Testes do Sistema de Seguros de Veículos

"""

from datetime import date
from classes import (
    Modelo, Carro, Cliente,
    Seguro, SeguroCarro, SeguroMoto
)


def titulo(texto: str):
    print(f"\n{'═'*55}")
    print(f"  {texto}")
    print('═'*55)

def subtitulo(texto: str):
    print(f"\n  ── {texto}")


# ══════════════════════════════════════════════════════════════════════════════
# Exercício 5 — Objetos com dados reais
# ══════════════════════════════════════════════════════════════════════════════
titulo("Exercício 5 — Objetos com Dados Reais")

modelo_corolla = Modelo("Corolla")
carro_joao = Carro(
    ano=2020,
    marca="Toyota",
    modelo=modelo_corolla,
    cor="Branco",
    placa="XYZ-1234"
)
joao = Cliente("João Silva", "123.456.789-00")
seguro1 = Seguro(
    cliente=joao,
    valor=1500.0,
    vigencia_inicio=date(2024, 1, 1),
    vigencia_fim=date(2025, 1, 1)
)
seguro1.adicionar_carro(carro_joao)

subtitulo("seguro1 : Seguro")
seguro1.exibir_detalhes()


# ══════════════════════════════════════════════════════════════════════════════
# Exercício 2 — Métodos das classes
# ══════════════════════════════════════════════════════════════════════════════
titulo("Exercício 2 — Métodos")

subtitulo("Cliente.exibir_informacoes()")
joao.exibir_informacoes()

subtitulo("Carro.exibir_detalhes()")
carro_joao.exibir_detalhes()

subtitulo("Carro.atualizar_cor('Prata')")
carro_joao.atualizar_cor("Prata")

subtitulo("Seguro.calcular_valor(base=1000, taxa=0.30)")
valor = seguro1.calcular_valor(1000.0, 0.30)
print(f"  Resultado: R$ {valor:,.2f}")

subtitulo("Seguro.verificar_vigencia()")
valido = seguro1.verificar_vigencia()
print(f"  Ativo: {valido}  (vigência encerrada em 01/01/2025)")


# ══════════════════════════════════════════════════════════════════════════════
# Exercício 3 — Múltiplos carros e múltiplos seguros
# ══════════════════════════════════════════════════════════════════════════════
titulo("Exercício 3 — Múltiplos Carros e Clientes")

subtitulo("Adicionando segundo carro ao seguro de João")
carro2 = Carro(2019, "Honda", Modelo("Civic"), "Preto", "ABC-5678")
seguro1.adicionar_carro(carro2)
print(f"  Carros segurados: {len(seguro1.listar_carros())}")
print(f"  Valor (2 carros, +10% extra): R$ {seguro1.calcular_valor(1000, 0.30):,.2f}")

subtitulo("Maria com dois seguros distintos (Exercício 3c)")
maria = Cliente("Maria Oliveira", "987.654.321-00")
seguro_maria1 = Seguro(maria, 0, date(2024, 6, 1), date(2025, 6, 1))
seguro_maria2 = Seguro(maria, 0, date(2024, 3, 1), date(2025, 3, 1))
seguro_maria1.adicionar_carro(Carro(2022, "Fiat", Modelo("Pulse"), "Vermelho", "JKL-9999"))
seguro_maria2.adicionar_carro(Carro(2021, "VW", Modelo("T-Cross"), "Branco", "MNO-1111"))
print("  Dois objetos Seguro referenciam o mesmo objeto Cliente 'maria'.")
print(f"  Ambos os seguros criados com sucesso.")


# ══════════════════════════════════════════════════════════════════════════════
# Exercício 4 — Herança e polimorfismo
# ══════════════════════════════════════════════════════════════════════════════
titulo("Exercício 4 — Herança: SeguroCarro e SeguroMoto")

subtitulo("SeguroCarro com cobertura a terceiros (+5%)")
sc = SeguroCarro(
    joao, 0,
    date(2024, 1, 1), date(2025, 1, 1),
    franquia=1000.0,
    cobre_terceiros=True
)
print(f"  Valor: R$ {sc.calcular_valor(1000, 0.30):,.2f}  (base=1000, taxa=30%, +5% terceiros)")

subtitulo("SeguroMoto 750cc — alto risco (+15%)")
sm = SeguroMoto(
    maria, 0,
    date(2024, 1, 1), date(2025, 1, 1),
    cilindradas=750,
    capacete_incluso=True
)
print(f"  Valor: R$ {sm.calcular_valor(1000, 0.30):,.2f}  (base=1000, taxa=30%, +15% risco)")
print(f"  Classificação: {sm.verificar_cilindradas()}")
print(f"  Capacete incluso: {sm.get_capacete()}")

subtitulo("SeguroMoto 150cc — cilindrada padrão")
sm2 = SeguroMoto(maria, 0, date(2025, 1, 1), date(2026, 1, 1), cilindradas=150)
print(f"  Valor: R$ {sm2.calcular_valor(1000, 0.30):,.2f}  (sem acréscimo de risco)")
print(f"  Classificação: {sm2.verificar_cilindradas()}")


# ══════════════════════════════════════════════════════════════════════════════
# Exercício 6 — Encapsulamento
# ══════════════════════════════════════════════════════════════════════════════
titulo("Exercício 6 — Encapsulamento")

subtitulo("Tentativa de acesso direto ao CPF (deve falhar)")
try:
    _ = joao.__cpf
    print("  ERRO: deveria ter bloqueado!")
except AttributeError:
    print("  BLOQUEADO ✓ — '__cpf' não é acessível diretamente.")

subtitulo("Acesso via get_cpf() — retorna dado mascarado")
print(f"  CPF: {joao.get_cpf()}")

subtitulo("Tentativa de acesso direto à placa (deve falhar)")
try:
    _ = carro_joao.__placa
    print("  ERRO: deveria ter bloqueado!")
except AttributeError:
    print("  BLOQUEADO ✓ — '__placa' não é acessível diretamente.")

subtitulo("Acesso via get_placa()")
print(f"  Placa: {carro_joao.get_placa()}")

subtitulo("verificar_vigencia() — pseudocódigo em ação")
hoje = date.today()
print(f"  Hoje: {hoje}")
print(f"  seguro1 ativo: {seguro1.verificar_vigencia()}")
print(f"  sm2 ativo    : {sm2.verificar_vigencia()}")


# ══════════════════════════════════════════════════════════════════════════════
# Resultado final
# ══════════════════════════════════════════════════════════════════════════════
print(f"\n{'═'*55}")
print("  Todos os testes executados sem erros!")
print('═'*55)
