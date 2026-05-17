## como rodar o código: 
g++ main.cpp transacao.cpp contaBancaria.cpp -o TransacaoC

## Função amiga: 
A função amiga permite que a lógica do código seja mais limpa e segura, conectando duas classes distintas para realizar uma única validação. Dessa forma, a variável `saldo` fica encapsulada e protegida. Ela só pode ser modificada pelos métodos da própria classe e pela função "amiga", prevenindo assim tentativas de acesso indevido e alterações acidentais causadas por outras partes mal planejadas do código.
