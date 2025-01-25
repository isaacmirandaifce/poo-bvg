
from src.models.FuncionarioAdministrativo import FuncionarioAdministrativo


def test_criar_funcionario_administrativo():
    '''Criando uma instância da classe Funcionario Administrativo'''

    funcionario_administrativo = FuncionarioAdministrativo(
        nome="Isaac",
        email="isaac@example.com",
        departamento="TI",
        cargo="Gerente"
    )
    print('Relatório: ')
    print(funcionario_administrativo.gerarRelatorio())

    '''Verificando se os atributos foram inicializados corretamente'''
    assert funcionario_administrativo._nome == "Isaac", "O nome não foi inicializado corretamente."
    assert funcionario_administrativo._email == "isaac@example.com", "O email não foi inicializado corretamente."
    assert funcionario_administrativo._departamento == "TI", "O departamento não foi inicializado corretamente."
    assert funcionario_administrativo._cargo == "Gerente", "O cargo não foi inicializado corretamente."

    print("Teste de criação de funcionario_administrativo passou com sucesso!")

if __name__ == "__main__":
    test_criar_funcionario_administrativo()
