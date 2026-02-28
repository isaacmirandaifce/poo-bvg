# Projeto Modularização em C++

Este projeto demonstra a utilização de modularização em C++ usando CMake e MinGW. Ele inclui três arquivos principais: main.cpp, aluno.cpp, disciplina.cpp, professor.cpp, usuario.cpp, monitor.cpp e funcionarioAdministrativo.cpp.

### Requisitos

CMake instalado

MinGW (compilador GCC para Windows) instalado e configurado no PATH

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


