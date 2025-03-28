# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>         +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:00:00 by vhacman           #+#    #+#              #
#    Updated: 2025/03/27 14:00:00 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Libft
LIBFT_DIR	= src/libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# Includes
INCLUDES	= -Isrc/includes -I$(LIBFT_DIR)

# Source directories
SRC_DIR		= src
SRC_SUBDIRS	= error_handling hybrid_sort hybrid_sort/hybrid_sort_utils \
			  merge_sort stack_operations stack_operations/print_operations \
			  utils main

# Gather all .c files from each subdirectory
SRC			= $(foreach dir,$(SRC_SUBDIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))

# Object files
OBJ			= $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

valgrind:
	@echo "🧠 ɪɴɪᴛɪᴀʟɪᴢɪɴɢ ɴᴇᴜʀᴀʟ ꜱᴄᴀɴ..."
	@echo "🔍 ʟᴀᴜɴᴄʜɪɴɢ $(NAME) ᴜɴᴅᴇʀ ᴍᴇᴍᴏʀʏ ꜱᴜʀᴠᴇɪʟʟᴀɴᴄᴇ..."
	@for i in {1..50}; do \
		ARG="$$(seq 0 499 | shuf | tr '\n' ' ')"; \
		valgrind --leak-check=full ./$(NAME) $$ARG; \
	done
	@echo "✅ ᴍᴇᴍᴏʀʏ ꜱᴄᴀɴ ᴄᴏᴍᴘʟᴇᴛᴇ — ɴᴏ ꜱᴜʀᴠɪᴠᴏʀꜱ ʜᴏᴘᴇꜰᴜʟʟʏ ☠️"


.PHONY: all clean fclean re valgrind
