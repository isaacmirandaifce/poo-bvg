# Sistema Acadêmico com Filtros Genéricos

## 📋 Descrição

Este projeto implementa um sistema acadêmico em C++ que utiliza programação orientada a objetos e templates para gerenciar diferentes tipos de usuários (Alunos, Professores, Funcionários Administrativos e Monitores) com funcionalidades avançadas de filtragem e ordenação.

## 🏗️ Arquitetura

O sistema segue os princípios de POO com:
- **Herança**: Hierarquia de classes de usuários
- **Polimorfismo**: Interfaces comuns para diferentes tipos de usuários
- **Templates**: Classe genérica de filtros
- **Encapsulamento**: Dados protegidos com métodos de acesso controlado

### Compilação
```bash
# Usando g++
g++ -std=c++11 -o sistema_academico main.cpp src/Aluno/Aluno.cpp src/Professor/Professor.cpp src/FuncionarioAdministrativo/FuncionarioAdministrativo.cpp src/Monitor/Monitor.cpp src/Usuarios/Usuario.cpp src/Usuarios/UsuarioAutenticavel.cpp

### Execução
```bash
./sistema_academico
```

## 📖 Exemplos de Uso

### Filtragem de Alunos Aprovados
```cpp
// Filtrar alunos com média >= 7.0
auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
    return a.getMedia() >= 7.0;
});
```

### Ordenação por Nome
```cpp
// Ordenar alunos por nome
filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
    return a1.getNome() < a2.getNome();
});
```

### Filtrar Professores por Disciplina
```cpp
// Encontrar professores que ministram POO
auto professorsPOO = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
    return p.ministraDisciplina("POO");
});
```

## 🔑 Funcionalidades do Sistema de Filtros

### Métodos Disponíveis
- `adicionarElemento(T)`: Adiciona elemento ao filtro
- `filtrarPorCondicao(lambda)`: Retorna elementos que atendem condição
- `imprimirTodos(lambda)`: Executa ação em todos elementos
- `ordenar(lambda)`: Ordena elementos por critério
- `getElementos()`: Retorna todos elementos
- `tamanho()`: Número de elementos
- `vazio()`: Verifica se está vazio
- `limpar()`: Remove todos elementos

### Exemplos Avançados
```cpp
// Filtro genérico pode ser usado com qualquer tipo
Filtro<int> numeros;
Filtro<string> palavras;
Filtro<MinhaClasse> objetos;

// Condições complexas
auto alunosEspecificos = filtro.filtrarPorCondicao([](const Aluno& a) {
    return a.getCurso() == "ADS" && a.getMedia() >= 8.0;
});
```