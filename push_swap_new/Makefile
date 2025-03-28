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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>         +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:00:00 by vhacman           #+#    #+#              #
#    Updated: 2025/03/27 14:00:00 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Cartella della libft (se esiste in src/libft)
LIBFT_DIR   = src/libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Include directory
INCLUDES    = -I include -I $(LIBFT_DIR)

# Sub-directory dei sorgenti
SRC_SUBDIRS = \
	main \
	src/algorithms/hybrid_sort \
	src/algorithms/hybrid_sort/hybrid_sort_utils \
	src/algorithms/merge_sort \
	src/algorithms/mini_sort_a \
	src/algorithms/ultra_chunk \
	src/error_handling \
	src/execute_optimal_moves \
	src/utils \
	src/utils/debug_functions \
	src/utils/stack_operations

# Raccolta di tutti i file .c
SRC         = $(foreach dir, $(SRC_SUBDIRS), $(wildcard $(dir)/*.c))

# Creazione degli oggetti corrispondenti
OBJ         = $(SRC:.c=.o)

# Regola di default
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)

# Compilazione di libft
$(LIBFT_A):
	make -C $(LIBFT_DIR)

# Regola generica per gli oggetti
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Pulizia
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

# Pulizia completa
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

# Esempio di test con valgrind
valgrind:
	@echo \"🧠 ɪɴɪᴛɪᴀʟɪᴢɪɴɢ ɴᴇᴜʀᴀʟ ꜱᴄᴀɴ...\"
	@echo \"🔍 ʟᴀᴜɴᴄʜɪɴɢ $(NAME) ᴜɴᴅᴇʀ ᴍᴇᴍᴏʀʏ ꜱᴜʀᴠᴇɪʟʟᴀɴᴄᴇ...\"
	@for i in {1..50}; do \
		ARG=\"$$(seq 0 499 | shuf | tr '\\n' ' ')\"; \
		valgrind --leak-check=full ./$(NAME) $$ARG; \
	done
	@echo \"✅ ᴍᴇᴍᴏʀʏ ꜱᴄᴀɴ ᴄᴏᴍᴘʟᴇᴛᴇ — ɴᴏ ꜱᴜʀᴠɪᴠᴏʀꜱ ʜᴏᴘᴇꜰᴜʟʟʏ ☠️\"

.PHONY: all clean fclean re valgrind
