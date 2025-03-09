from src.models.Monitor import Monitor

def test_monitor_heranca_multipla():
    monitor = Monitor(
        nome="Lucas Oliveira",
        email="lucas@universidade.com",
        matricula="2023001",
        curso="Ciência da Computação",
        disciplinasAluno=["Algoritmos", "Estruturas de Dados"],
        areaDeAtuacao="Computação Teórica",
        disciplinasMinistradas=["Matemática Discreta"],
        disciplinasMonitoradas=["Algoritmos", "Matemática Discreta"]
    )

    assert monitor._nome == "Lucas Oliveira", "O nome do monitor deveria ser Lucas Oliveira."
    assert monitor._curso == "Ciência da Computação", "O curso deveria ser Ciência da Computação."
    assert monitor._areaDeAtuacao == "Computação Teórica", "A área de atuação deveria ser Computação Teórica."
    assert monitor._disciplinasMonitoradas == ["Algoritmos", "Matemática Discreta"], (
        "As disciplinas monitoradas deveriam ser Algoritmos e Matemática Discreta."
    )

def test_listar_disciplinas_monitoradas():
    monitor = Monitor(nome="Ana Clara", disciplinasMonitoradas=["Estruturas de Dados"])
    assert monitor.listarDisciplinasMonitoradas() == "Disciplinas Monitoradas: Estruturas de Dados", (
        "O método deveria listar corretamente as disciplinas monitoradas."
    )

    monitor_sem_disciplinas = Monitor(nome="João Pedro")
    assert monitor_sem_disciplinas.listarDisciplinasMonitoradas() == (
        "Nenhuma disciplina está sendo monitorada no momento."
    ), "O método deveria informar que não há disciplinas monitoradas."


if __name__ == "__main__":
    print("Testando herança múltipla do Monitor...")
    test_monitor_heranca_multipla()
    print("Herança múltipla: OK!")

    print("Testando listagem de disciplinas monitoradas...")
    test_listar_disciplinas_monitoradas()
    print("Listagem de disciplinas: OK!")
