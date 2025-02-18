# Variáveis de compilação
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/Projeto_6

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))

# Regra padrão
all: $(TARGET)

# Linkando os objetos para criar o executável
$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilando os arquivos .cpp para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Limpar arquivos de compilação
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Recompilar do zero
rebuild: clean all
