# Variáveis de compilação
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Arquivo executável final
TARGET = $(BIN_DIR)/Projeto_5

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Regras
all: $(TARGET)

# Linkando os objetos para criar o executável
$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilando os arquivos .cpp para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para compilar o main.cpp
$(BUILD_DIR)/main.o: main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

# Limpar arquivos de compilação
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Para compilar novamente do zero
rebuild: clean all
