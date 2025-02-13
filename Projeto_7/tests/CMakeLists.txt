cmake_minimum_required(VERSION 3.10)
project(Projeto_7_Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/../include)

add_executable(test_Filtro test_Filtro.cpp ../src/Filtro.cpp ../src/Aluno.cpp)

enable_testing()
add_test(NAME test_Filtro COMMAND test_Filtro)