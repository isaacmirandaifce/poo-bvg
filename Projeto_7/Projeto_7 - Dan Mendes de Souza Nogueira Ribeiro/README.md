## como executar o código: 
g++ main.cpp models/Transação/transacao.cpp models/Funções/funcoes.cpp models/LogSegurança/logSeguranca.cpp -o filtro

---

## Explicação do projeto (Templates):
O código foi projetado em torno de uma classe genérica (Template), cujo atributo principal é um `std::vector` capaz de armazenar qualquer tipo de dado. No contexto deste projeto, essa estrutura é instanciada para gerenciar objetos das classes LogSeguranca e Transacao. A classe possui um método de filtro genérico que permite extrair dados específicos de forma dinâmica, recebendo expressões lambda que ditam as regras de busca. O que torna essa ferramenta extremamente poderosa é que o compilador só gera o código da função para os tipos que efetivamente chamamos. Portanto, se um tipo não for utilizado, ele não gera sobrecarga ou problemas de compilação.