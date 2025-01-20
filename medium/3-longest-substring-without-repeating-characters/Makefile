RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
RESET = \033[0m

FLAGS = -Wall -O2 -std=c++20
SRC_DIR = src
BIN_DIR = bin
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
TARGET = program


all: build run

build: $(OBJS)
	@echo "$(YELLOW)Building...$(RESET)"
	@g++ $(FLAGS) $^ -o $(BIN_DIR)/$(TARGET)

run:
	@echo "$(GREEN)Running...$(RESET)"
	@echo ""
	@bin/$(TARGET)

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@rm -f $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET)
	
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@g++ $(FLAGS) -c $< -o $@
