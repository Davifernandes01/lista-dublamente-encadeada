# Makefile

# Diretórios
SRC_DIR = apps
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
SRC_DIR_SRC = src

# Arquivos
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR_SRC)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
EXE_FILE = $(BIN_DIR)/apps

# Compilador e opções
CC = gcc
CFLAGS = -I$(INCLUDE_DIR)

# Regras de compilação
all: $(EXE_FILE)

$(EXE_FILE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXE_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE)

.PHONY: all clean
