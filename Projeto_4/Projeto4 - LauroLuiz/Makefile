# Makefile para o Sistema de Gerenciamento de Notas

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Directories
SRCDIR = src
DOCSDIR = docs
TESTSDIR = tests

# Source files
SOURCES = $(SRCDIR)/Aluno.cpp $(SRCDIR)/Disciplina.cpp $(SRCDIR)/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = gerenciamento_notas

# Default target
all: $(TARGET)

# Create target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories
dirs:
	mkdir -p $(SRCDIR) $(DOCSDIR) $(TESTSDIR)

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f $(SRCDIR)/*.o

# Install (copy files to src directory)
install: dirs
	cp Aluno.h $(SRCDIR)/
	cp Aluno.cpp $(SRCDIR)/
	cp Disciplina.h $(SRCDIR)/
	cp Disciplina.cpp $(SRCDIR)/
	cp main.cpp $(SRCDIR)/

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Help
help:
	@echo "Targets disponíveis:"
	@echo "  all      - Compila o projeto"
	@echo "  clean    - Remove arquivos de compilação"
	@echo "  dirs     - Cria estrutura de diretórios"
	@echo "  install  - Organiza arquivos na estrutura de diretórios"
	@echo "  run      - Executa o programa"
	@echo "  debug    - Compila em modo debug"
	@echo "  help     - Mostra esta ajuda"

.PHONY: all clean dirs install run debug help