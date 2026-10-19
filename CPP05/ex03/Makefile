# Program name
NAME = forms

# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Colors
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m

# Directories
SRC_DIR = .
OBJ_DIR = objs

# Files
FILES = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp


OBJS = $(FILES:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Link executable
$(NAME): $(OBJS)
	@echo "$(YELLOW)[ BUILDING ]$(RESET) Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[ SUCCESS ]$(RESET) $(NAME) built successfully!"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[ COMPILING ]$(RESET) $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if missing
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@echo "$(RED)[ CLEAN ]$(RESET) Removing object files..."
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)[ OK ]$(RESET) Object files removed."

# Clean everything
fclean: clean
	@echo "$(RED)[ FCLEAN ]$(RESET) Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(GREEN)[ OK ]$(RESET) Full clean complete."

# Rebuild
re: fclean all

.PHONY: all clean fclean re
