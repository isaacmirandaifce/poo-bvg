# Projeto Modularização em C++

Este projeto demonstra a utilização de modularização em C++ usando CMake e MinGW. Ele inclui três arquivos principais: main.cpp, aluno.cpp e disciplina.cpp.

### Requisitos

CMake instalado

MinGW (compilador GCC para Windows) instalado e configurado no PATH

### Estrutura de Diretórios
```
projeto_4
├── build/                 # Pasta para os arquivos gerados pelo CMake
├── src/                   # Código-fonte
│   ├── main.cpp
│   ├── aluno.cpp
│   ├── aluno.h
│   ├── disciplina.cpp
│   └── disciplina.h
├── CMakeLists.txt         # Configuração do projeto CMake
└── README.md              # Este arquivo
```
###  Configuração e Compilação

Para compilar o projeto, siga os passos abaixo no PowerShell:

##### Criar a pasta de build:
```
mkdir build
cd build
```
##### Gerar os arquivos de build com MinGW:
```
cmake .. -G "MinGW Makefiles"
```
##### Compilar o projeto:
```
mingw32-make
```
##### Executar o programa:
```
.\modularizacao_cpp.exe
```
### Atualização do Código

##### Alterações no código-fonte ou cabeçalhos (**\*\*\*\*, **): Apenas recompilar com
```
mingw32-make
```
##### Alterações no ``: É necessário limpar o cache e configurar novamente:
```
rm -r CMakeCache.txt CMakeFiles
cmake .. -G "MinGW Makefiles"
mingw32-make
```

Desenvolvido por Kaella Rodrigues de Sales.

