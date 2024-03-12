# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 18:37:52 by lgarfi            #+#    #+#              #
#    Updated: 2023/12/27 01:06:15 by lgarfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CONSOLE DESIGN
WHITE=$'\033[0;37m
GREY=$'\033[0;30m
RED=$'\033[0;31m
GREEN=$'\033[0;32m
YELLOW=$'\033[0;33m
CYAN=$'\033[0;34m
PURPLE=$'\033[0;35m
DEF_COLOR = \033[0;39m

#variables

# dir

libft_dir = ./libft/
obj_libft_dir = ./libft/obj/

src_libft = $(shell find libft/ -type f -name "*.c" -exec basename {} \;)
src_fractol = $(shell find src/ -type f -name "*.c" && find src/ -name "libft.a")

#flag
CC= gcc
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

#include
HEADER_libft = libft/libft.h
header_fractol = #to do

# .o
obj_libft = $(addprefix $(obj_libft_dir), $(src_libft:.c=.o))

# .a
name_libft = libft.a
AR = ar rcs

# fractol
name_fractol = fractol


#del
RM = rm -rf

# rule

all: $(name_fractol)

fract-ol : $(name_fractol)

$(name_fractol) : $(name_libft) $(obj_libft)
			@make -C ./minilibx-linux
			@cc $(CFLAGS) $(src_fractol) $(MLX_FLAGS) -g3 -o $@
			@echo "${GREEN}    ✅ Compiling: fractol ✅$(DEF_COLOR)"

libft: ${name_libft}

${name_libft}: ${obj_libft}
	@${AR} ${name_libft} $?
	@ranlib $@
	@mv $(name_libft) src/
	@echo "${GREEN}    ✅ Libft created ✅${DEF_COLOR}"

$(obj_libft_dir)%o: $(libft_dir)%c $(header_libft) | $(obj_libft_dir)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) -g3 $(CFLAGS) -I libft/ -c $< -o $@

$(obj_libft_dir):
	mkdir -p $(obj_libft_dir)

norminette:
	@echo "⚠️ ${YELLOW} Checking The Norm ⚠️"
	@if norminette $(libft_dir) include/fractol.h src/ >/dev/null; then\
		echo " ${GREEN}    Norminette : OK${WHITE}\n";\
	else\
		echo " ${RED}    Norminette : KO${WHITE}\n";\
	fi

clean:
	@${RM} ${obj_libft} $(obj_libft_dir)
	@make -C ./minilibx-linux clean
	@echo "${CYAN}🚮 object file cleanded 🚮${DEF_COLOR}"

fclean:	clean
	@${RM} src/${name_libft} $(name_fractol)
	@echo "${GREEN}🫡 everything was cleaned sir 🫡"

re: fclean all

.PHONY : all clean fclean re bonus norminette fract-ol
