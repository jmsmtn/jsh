SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := .

EXE := $(BIN_DIR)/jsh
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC=gcc

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall -Wextra -Werror -pedantic
#LDFLAGS  := -Llib
#LDLIBS   := -lm

.PHONY: all clean


#
# normal mode
#
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

#
# run build with debug flags
#
debug: CFLAGS := -Wall -Wextra -pedantic -g 
debug: all

#
# clean up binary and object directory
#
clean:
	@$(RM) -rv $(OBJ_DIR)
	@$(RM) -rv $(BIN_DIR)/$(EXE)

