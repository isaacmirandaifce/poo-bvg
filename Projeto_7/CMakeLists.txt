cmake_minimum_required(VERSION 3.10)
project(Projeto_7)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Projeto_7 src/main.cpp src/Filtro.cpp src/Aluno.cpp src/Professor.cpp src/FuncionarioAdministrativo.cpp src/Disciplina.cpp)

add_subdirectory(tests)