# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: vhacman <vhacman@student.42roma.it>         +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:00:00 by vhacman           #+#    #+#              #
#    Updated: 2025/03/29 10:00:00 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = src/libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
INCLUDES    = -I include -I $(LIBFT_DIR)

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
	src/utils/stack_operations \
	src/utils/stack_operations/print_operations

SRC         = $(foreach dir,$(SRC_SUBDIRS),$(wildcard $(dir)/*.c))

OBJ_DIR     = obj
OBJ         = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #
#                              𝓑𝓾𝓲𝓵𝓭 𝓣𝓪𝓻𝓰𝓮𝓽𝓼                              #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #

all: $(NAME)
	@echo "✨ 𝓒𝓸𝓷𝓳𝓾𝓻𝓮𝓭 → 𝓹𝓾𝓼𝓱_𝓼𝔀𝓪𝓹 𝓲𝓼 𝓻𝓮𝓪𝓭𝔂!"

$(NAME): $(OBJ) $(LIBFT_A)
	@echo "🔧 𝓒𝓸𝓶𝓹𝓲𝓵𝓲𝓷𝓖 𝓽𝓱𝓮 𝓶𝓪𝓰𝓲𝓬..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	@echo "📦 𝓑𝓾𝓲𝓵𝓭𝓲𝓷𝓰 𝓛𝓲𝓫𝓯𝓽 𝓶𝓸𝓭𝓾𝓵𝓮..."
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

# Compilazione file .o nella struttura obj/ parallela a src/
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@) # Crea la sottocartella in obj/
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #
#                                𝓒𝓵𝓮𝓪𝓷𝓲𝓷𝓰                                   #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #

check:
	@echo "🔍 𝓥𝓮𝓻𝓲𝓯𝔂𝓲𝓷𝓰 𝔀𝓲𝓽𝓱 𝓬𝓱𝓮𝓬𝓴𝓮𝓻_𝓵𝓲𝓷𝓾𝔁..."
	@seq 0 99 | shuf | tr '\n' ' ' > args.txt
	@echo "📄 𝓐𝓻𝓰𝓾𝓶𝓮𝓷𝓽𝓼 𝓼𝓪𝓿𝓮𝓭 𝓽𝓸 args.txt:"
	@RESULT=$$(./$(NAME) $$(cat args.txt) | ./checker_linux $$(cat args.txt)); \
	echo "📣 𝓡𝓮𝓼𝓾𝓵𝓽: $$RESULT"; \
	if [ "$$RESULT" = "OK" ]; then \
		echo "✅ 𝓢𝓾𝓬𝓬𝓮𝓼𝓼: 𝓼𝓸𝓻𝓽𝓮𝓭 𝓬𝓸𝓻𝓻𝓮𝓬𝓽𝓵𝔂!"; \
	elif [ "$$RESULT" = "KO" ]; then \
		echo "❌ 𝓔𝓻𝓻𝓸𝓻: 𝓷𝓸𝓽 𝓼𝓸𝓻𝓽𝓮𝓭."; \
	else \
		echo "⚠️ 𝓤𝓷𝓴𝓷𝓸𝔀𝓷 𝓻𝓮𝓼𝓾𝓵𝓽: $$RESULT"; \
	fi

clean:
	@echo "🧹 𝓢𝔀𝓮𝓮𝓹𝓲𝓷𝓰 𝓞𝓫𝓳𝓮𝓬𝓽𝓼..."
	@rm -rf $(OBJ_DIR) # Rimuove la cartella obj e tutto il suo contenuto (file .o, sottocartelle, ecc.)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) valgrind.log args.txt

fclean: clean
	@echo "💣 𝓔𝓻𝓪𝓼𝓲𝓷𝓰 𝓔𝓧𝓮𝓬𝓾𝓽𝓪𝓫𝓵𝓮..."
	@rm -f $(NAME)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean
	@$(RM) valgrind.log args.txt
	@echo "🍺🥂🍸 𝓟𝓾𝓼𝓱 𝓢𝔀𝓪𝓹 𝓸𝓫𝓵𝓲𝓽𝓪𝓻𝓮𝓽𝓮𝓭: 𝓯𝓬𝓵𝓮𝓪𝓷 𝓬𝓸𝓶𝓹𝓵𝓮𝓽𝓮 🍻🍷🍹"


re: fclean all

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #
#                      𝓔𝔁𝓽𝓻𝓪 𝓜𝓪𝓰𝓲𝓬 (𝓿𝓪𝓵𝓰𝓻𝓲𝓷𝓭 𝓽𝓮𝓼𝓽)                      #
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #

valgrind:
	@echo "🧠 𝓘𝓷𝓲𝓽𝓲𝓪𝓵𝓲𝓏𝓲𝓷𝓰 𝓶𝓮𝓶𝓸𝓻𝔂 𝓼𝓬𝓪𝓷 𝓼𝓮𝓺𝓾𝓮𝓷𝓬𝓮..."
	@echo "🍸 𝓔𝓷𝓽𝓮𝓻𝓲𝓷𝓰 𝓽𝓱𝓮 𝓭𝓮𝓫𝓾𝓰 𝓭𝓲𝓶𝓮𝓷𝓼𝓲𝓸𝓷..."
	@rm -f valgrind.log
	@for i in {1..5}; do \
		ARG="$$(seq 0 49 | shuf | tr '\n' ' ')"; \
		echo "🧪 𝓣𝓮𝓼𝓽𝓲𝓷𝓰 𝔀𝓲𝓽𝓱 X 𝓷𝓾𝓶𝓫𝓮𝓻𝓼..." | tee -a valgrind.log; \
		valgrind --leak-check=full ./$(NAME) $$ARG >> valgrind.log 2>&1; \
		echo "-----------------------------------------" | tee -a valgrind.log; \
	done
	@echo "🎯 𝓜𝓲𝓼𝓼𝓲𝓸𝓷 𝓬𝓸𝓶𝓹𝓵𝓮𝓽𝓮: 𝓃𝑜 𝓁𝑒𝒶𝓀𝓈 𝒻𝑜𝓊𝓷𝒹 (𝓌𝑒 𝒽𝑜𝓅𝑒) 💥"
	@echo "📄 𝓛𝓸𝓰 𝓼𝓪𝓿𝓮𝓭 𝓽𝓸 → valgrind.log"
	@echo "🍷🍷🍷 𝓜𝓮𝓶𝓸𝓻𝔂 𝓼𝓬𝓪𝓷 𝓬𝓸𝓶𝓹𝓵𝓮𝓽𝓮 🍾🍾🍾"

.PHONY: all clean fclean re valgrind
