
from src.persistencia import salvar_dados_csv, carregar_dados_csv
from src.excessao import ArquivoNaoEncontrado, PermissaoNegada, FalhaConversaoDeDados
from src.aluno import Aluno
dados = [
    {"nome": "Kayron", "senha": "1234"},
    {"nome": "ViniJr", "senha": "alaMadrid322"}
]
campos = ["nome", "senha"]
salvar_dados_csv("teste/dados_teste.csv", dados, campos)
try:
    alunos = carregar_dados_csv("teste_alunos.csv")
    for linha in alunos:
        aluno = Aluno(linha["nome"], linha["senha"])
        print(aluno.gerar_relatorio())
        print("Autenticado?", aluno.autenticar(linha["senha"]))
except ArquivoNaoEncontrado as e:
    print(e)
except PermissaoNegada as e:
    print(e)

try:
    carregar_dados_csv("Mundial_Time_Verde.csv")
    
except ArquivoNaoEncontrado as e:
    print("Exceção capturada: ", e)