# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME        = libft.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f
MAKEFLAGS	+= -s

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)
	@echo "✨ 𝓛𝓲𝓫𝓯𝓽 𝓬𝓸𝓷𝓳𝓾𝓻𝓮𝓭! ✨"

$(NAME): $(OBJS)
	@$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "🧹 𝓣𝓱𝓮 𝓯𝓸𝓻𝓰𝓮 𝓲𝓼 𝓬𝓵𝓮𝓪𝓷."

fclean: clean
	@$(RM) $(NAME)
	@echo "💀 𝓛𝓲𝓫𝓯𝓽 𝓼𝓪𝓬𝓻𝓲𝓯𝓲𝓬𝓮𝓭: 𝓯𝓬𝓵𝓮𝓪𝓷 𝓬𝓸𝓶𝓹𝓵𝓮𝓽𝓮."

re: fclean all
	@echo "🔁 𝓛𝓲𝓫𝓯𝓽 𝓻𝓮𝓫𝓸𝓻𝓷 𝓯𝓻𝓸𝓶 𝓽𝓱𝓮 𝓪𝓼𝓱𝓮𝓼..."


.PHONY: all clean fclean re
