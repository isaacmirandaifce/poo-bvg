from src.DataFilter import DataFilter
from src.Transacao import Transacao
from src.LogSeguranca import LogSeguranca

def main():
    filtro_transacao = DataFilter[Transacao]()
    filtro_transacao.adicionar(Transacao(1, 1500.00, "PIX"))
    filtro_transacao.adicionar(Transacao(2, 12000.00, "TED"))
    filtro_transacao.adicionar(Transacao(3, 8500.00, "PIX"))

    print("=== Transações Suspeitas (> R$ 10.000) ===")
    suspeitas = filtro_transacao.filtrar(lambda t: t.get_valor() > 10000.00)
    for s in suspeitas:
        print(s)

    filtro_log = DataFilter[LogSeguranca]()
    filtro_log.adicionar(LogSeguranca("2026-09-08 07:00", "INFO", "Sistema iniciado."))
    filtro_log.adicionar(LogSeguranca("2026-09-08 07:15", "CRITICAL", "Tentativa de invasão detectada!"))

    print("\n=== Logs Críticos ===")
    criticos = filtro_log.filtrar(lambda log: log.get_nivel() == "CRITICAL")
    for c in criticos:
        print(c)

    print("\n=== Processando Todos os Logs com Ação Customizada ===")
    filtro_log.processar(lambda log: print(f"[PROCESSADO] {log}"))

if __name__ == "__main__":
    main()