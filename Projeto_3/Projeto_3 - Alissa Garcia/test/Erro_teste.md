Observações sobre o comportamento do destrutor

Professor, ao executar o meu código, percebi que o destrutor da classe Pessoa está sendo acionado em momentos que acredito não serem adequados, resultando em um comportamento inesperado durante a entrada de dados. Até o momento, não consegui identificar exatamente a causa nem corrigir o problema.

Para ilustrar o que está acontecendo, segue um exemplo real da execução:

Eu digito os dados da primeira pessoa:
Nome: João
Telefone: 5555

Na segunda entrada:
Nome: Maria
Telefone: 7787
Assim que pressiono Enter após digitar o telefone da Maria, aparece a mensagem:
“A pessoa João está sendo destruída!”
Ou seja, o destrutor do objeto João é acionado antes mesmo de terminar a digitação das três pessoas.

Depois digito os dados da terceira pessoa:
Nome: Flávia
Telefone: 88956
Quando pressiono Enter, novamente são exibidas mensagens como:

“A pessoa João está sendo destruída!”

“A pessoa Maria está sendo destruída!”

Em seguida, o programa imprime corretamente os dados das três pessoas.

E, ao final da execução, surge mais uma vez:

“A pessoa João está sendo destruída!”

“A pessoa Maria está sendo destruída!”

“A pessoa Flávia está sendo destruída!”

Ou seja, cada objeto está sendo destruído múltiplas vezes e em momentos diferentes da execução — inclusive no meio da leitura dos dados de outras pessoas. Pelo meu entendimento, isso não deveria acontecer; os objetos deveriam ser destruídos apenas ao final do programa, quando o vector sai do escopo.

Como ainda não consegui encontrar a solução por conta própria, decidi registrar esse comportamento para o senhor avaliar e me orientar sobre o motivo de o destrutor estar sendo acionado tantas vezes e como posso corrigir isso.