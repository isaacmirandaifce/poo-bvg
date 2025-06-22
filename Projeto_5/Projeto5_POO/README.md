## 📚 Projeto Avaliativo 5 – Sistema Acadêmico com Herança, Polimorfismo, Sobrecarga e Sobrescrita (C++)

### 🎯 Objetivo

Desenvolver um sistema acadêmico em C++ aplicando conceitos fundamentais e avançados de Programação Orientada a Objetos, como:

* Herança (simples e múltipla)
* Polimorfismo (uso de ponteiros para classe base)
* Sobrescrita e sobrecarga de métodos
* Organização modular do código (arquivos `.h` e `.cpp`)

---

### 🧠 Conceitos Aplicados

🧠 Conceitos Aplicados
Herança
Permite que classes derivadas reutilizem atributos e métodos de uma classe base.
No projeto: Aluno, Professor e FuncionarioAdministrativo herdam da classe base Usuario.

Herança Múltipla
Permite que uma classe herde de duas ou mais classes base.
No projeto: A classe Monitor herda tanto de Aluno quanto de Professor.

Herança Virtual
Usada para evitar ambiguidade na herança múltipla quando a mesma classe base é herdada por mais de uma classe intermediária.
No projeto: Usuario é herdada virtualmente para prevenir conflitos de membros duplicados.

Polimorfismo
Capacidade de usar ponteiros ou referências da classe base para chamar métodos das classes derivadas, possibilitando comportamento dinâmico.
No projeto: Um vetor de ponteiros do tipo Usuario* chama o método gerarRelatorio() específico de cada objeto.

Sobrescrita (Override)
Reimplementação de um método da classe base nas classes derivadas para comportamento específico.
No projeto: Cada classe derivada implementa sua própria versão do método gerarRelatorio().

Sobrecarga (Overload)
Definição de múltiplos métodos com o mesmo nome, porém com diferentes parâmetros dentro da mesma classe.
No projeto: A classe Aluno tem duas versões do método gerarRelatorio(), uma sem parâmetros e outra com parâmetros.

Encapsulamento
Restrição do acesso direto a atributos, controlando-os via métodos públicos para proteger o estado do objeto.
No projeto: Todos os atributos são privados e acessados/modificados por métodos getters e setters.

                    |

---

### 📁 Estrutura de Arquivos

```
Projeto/
│
├── main.cpp
├── Usuario.h
├── Usuario.cpp
├── Aluno.h
├── Aluno.cpp
├── Professor.h
├── Professor.cpp
├── FuncionarioAdministrativo.h
├── FuncionarioAdministrativo.cpp
├── Monitor.h
├── Monitor.cpp
├── Disciplina.h
└── Disciplina.cpp
```

---

### 🧩 Classes e Responsabilidades

#### 🔷 Usuario *(classe abstrata)*

* Atributos: `nome`, `email`, `tipo`
* Método virtual puro: `gerarRelatorio()`

#### 🔷 Aluno

* Atributos adicionais: `matricula`, `curso`, `vector<Disciplina>`
* Métodos: `adicionarDisciplina()`, `gerarRelatorio()`, `gerarRelatorio(bool)`

#### 🔷 Professor

* Atributos adicionais: `areaDeAtuacao`, `disciplinasMinistradas`
* Método: `adicionarDisciplina()`, `gerarRelatorio()`

#### 🔷 FuncionarioAdministrativo

* Atributos: `departamento`, `cargo`
* Método: `gerarRelatorio()`

#### 🔷 Monitor *(herança múltipla)*

* Herda de `Aluno` e `Professor`
* Atributo: `disciplinasMonitoradas`
* Método: `adicionarDisciplinaMonitorada()`, `gerarRelatorio()`

#### 🔷 Disciplina

* Atributos: `nome`, `cargaHoraria`, `nota`
* Métodos: `setNota()`, `getNota()`, `getNome()`

---

### 💻 Exemplo de Uso

```cpp
Aluno a1("Maria", "maria@email.com", "2023A", "ADS");
Disciplina d1("POO", 60); d1.setNota(8.5);
a1.adicionarDisciplina(d1);

Professor p1("Carlos", "carlos@faculdade.com", "Engenharia");

Usuario* u = &a1;
u->gerarRelatorio(); // Executa versão do Aluno via polimorfismo
```

---

### 🔧 Requisitos Técnicos

* Linguagem: C++
* Modularização com arquivos `.h` e `.cpp`
* Uso de ponteiros para polimorfismo
* Herança virtual para evitar ambiguidade na herança múltipla
* Compilador recomendado: `g++`

---

### 🛠️ Compilação (g++)

```bash
g++ main.cpp Usuario.cpp Aluno.cpp Professor.cpp FuncionarioAdministrativo.cpp Monitor.cpp Disciplina.cpp -o sistema
./sistema
```

---

### 📌 Observações

* A herança múltipla exige o uso de **herança virtual** para evitar ambiguidade da classe base `Usuario`.
* Todos os atributos são **encapsulados** e manipulados por métodos.
* O sistema pode ser expandido com **interfaces, autenticação, ou banco de dados**, conforme o próximo projeto (Projeto Avaliativo 6).


