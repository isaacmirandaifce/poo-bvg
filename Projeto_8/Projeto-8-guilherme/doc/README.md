
# 🎓 Projeto Avaliativo 8 — Sistema Acadêmico Resiliente em C++

## 📌 Objetivo
Este projeto amplia o sistema acadêmico desenvolvido nos Projetos 5, 6 e 7, integrando recursos avançados de **tratamento de exceções**, **manipulação de arquivos** e **resposta a sinais do sistema operacional**, tornando a aplicação mais **robusta e tolerante a falhas**.

## 📁 Exemplo de Arquivo CSV

### `alunos.csv`
```
Rafael Maciel;rafael@ifce.edu.br;Aluno;****;2023123;ADS;POO,IHC;
Erlano Benevides;erlanosousa10@ifce.edu.br;Aluno;****;2023124;ADS;POO,Redes;
Helena;lenis@ifce.edu.br;Aluno;****;2023125;Zootecnia;Calc,Física;

```

### `professores.csv`
```
Isaac Miranda;isaac@ifce.edu.br;Professor;****;Computação;POO,LP,
Magno Prudencio;magno@ifce.edu.br;Professor;****;Computação;Redes,BD,
Augustavo Feitosa;luizaugustavo@ifce.edu.br;Professor;****;Matemática;Álgebra,

```

### 🔧 Compilação:
```bash
g++ main.cpp src/**/*.cpp -o sistema -std=c++17
```

### ▶️ Execução:
```bash
./sistema
```