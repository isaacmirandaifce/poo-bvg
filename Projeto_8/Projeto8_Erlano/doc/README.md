#  Projeto Avaliativo 8 — Sistema Acadêmico Resiliente em C++ — Erlano

##  Objetivo
Este projeto faz a continuação das partes 5, 6 e 7, juntando recursos avançados de, tratamento de exceções, manipulação de arquivos e resposta a sinais do sistema operacional, fazendo assim a aplicação passar a ser robusta e tolerante a falhas.

## Exemplo de Arquivo CSV

### `alunos.csv`
```
Erlano Sousa;erlanosousa10@ifce.edu.br;Aluno;****;2023124;ADS;POO,Redes;
Helena;lenis@ifce.edu.br;Aluno;****;2023125;Zootecnia;Calc,Física;
Rafael Nogueira;rafael@ifce.edu.br;Aluno;****;2023123;ADS;POO,IHC;

```

### `professores.csv`
```
Augustavo;luizaugustavo@ifce.edu.br;Professor;****;Matemática;Álgebra,
Isaac Miranda;isaac@ifce.edu.br;Professor;****;Computação;POO,LP,
Magno Prudencio;magno@ifce.edu.br;Professor;****;Computação;Redes,BD,
```

### Compilação:
```bash
g++ main.cpp src/**/*.cpp -o sistema -std=c++17
```

### Execução:
```bash
./sistema
```

