cmake_minimum_required(VERSION 3.10)
project(tests_academicos)

# Configuração do Catch2 (framework de testes)
find_package(Catch2 REQUIRED)

# Executáveis de teste
add_executable(test_aluno test_aluno.cpp ../src/Aluno.cpp ../src/Usuario.cpp)
add_executable(test_professor test_professor.cpp ../src/Professor.cpp ../src/Usuario.cpp)
add_executable(test_funcionario test_funcionario.cpp ../src/Funcionario.cpp ../src/Usuario.cpp)
add_executable(test_monitor test_monitor.cpp ../src/Monitor.cpp ../src/Aluno.cpp ../src/Professor.cpp ../src/Usuario.cpp)

# Link com Catch2
target_link_libraries(test_aluno Catch2::Catch2)
target_link_libraries(test_professor Catch2::Catch2)
target_link_libraries(test_funcionario Catch2::Catch2)
target_link_libraries(test_monitor Catch2::Catch2)

# Adiciona testes ao CTest
include(CTest)
enable_testing()

add_test(NAME test_aluno COMMAND test_aluno)
add_test(NAME test_professor COMMAND test_professor)
add_test(NAME test_funcionario COMMAND test_funcionario)
add_test(NAME test_monitor COMMAND test_monitor)