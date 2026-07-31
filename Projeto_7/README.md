# Projeto 7: Métodos e Classes Genéricas (C++)

Este projeto implementa um motor de filtragem genérico (DataFilter<T>) para o sistema acadêmico SecureBank Pro. O objetivo é unificar a lógica de busca e processamento de dados em uma única classe usando Templates e Expressões Lambda.

---

## Estrutura do Projeto

* src/DataFilter.h: Classe modelo (template) responsável por armazenar, filtrar e processar elementos.
* src/Transacao.h / .cpp: Classe de domínio para representação de transações bancárias.
* src/LogSeguranca.h / .cpp: Classe de domínio para logs do sistema.
* src/main.cpp: Testes práticos do filtro genérico com expressões lambda.
* docs/Diagrama_DataFilter_UML.png: Diagrama de classes UML mostrando a notação do template.

---

## Como Compilar e Executar

Abra o terminal na pasta raiz do projeto e execute os comandos:

```bash
# Compilação
g++ -std=c++11 src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp -o programa

# Execução no Linux
./programa

