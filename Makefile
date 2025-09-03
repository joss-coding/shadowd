CC      := clang
CFLAGS  := -Wall -Wextra -O2 -Iinclude -pthread
LDFLAGS := 

# Directorios base
SRC_DIR := src
OBJ_DIR := bin
OUT_DIR := $(HOME)/cryptoTest
BIN     := $(OUT_DIR)/main

# Buscar todos los .c recursivamente
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')

# Generar objetos correspondientes en bin/
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Asegurar directorios espejo en bin/
OBJ_DIRS := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(OBJ_DIRS))

# ========= Reglas ========= #

# Ejecutable final
$(BIN): $(OBJS)
	@mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✅ Ejecutable creado en: $(BIN)"

# Regla genérica para compilar .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 Compilado: $< → $@"

# ========= Comodidades ========= #

.PHONY: run
run: $(BIN)
	@echo "🚀 Ejecutando..."
	$(BIN) || ./$(BIN)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)
	@echo "🧹 Limpieza completa"