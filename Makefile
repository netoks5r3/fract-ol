# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wremelli <nremelli@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 21:42:06 by wremelli          #+#    #+#              #
#    Updated: 2023/06/12 16:51:05 by wremelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

MAN_PATH	=	mandatory/
BON_PATH	=	bonus/

MAN_FILES	=	keys.c
BON_FILES	=	keys_bonus.c move_bonus.c
COMMON_FILES=	error.c events.c fractals.c hooks.c init.c utils.c

MANDATORY	=	$(addprefix $(MAN_PATH), $(MAN_FILES:.c=.o))
BONUS		=	$(addprefix $(BON_PATH), $(BON_FILES:.c=.o))
COMMON		=	$(addprefix $(MAN_PATH), $(COMMON_FILES:.c=.o))

CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS	=	-lmlx -lX11 -lXext -Imlx

MLX_PASTE	=	$(shell if [ -d p_mlx ]; then echo yes; else echo no; fi)

ifeq ($(MLX_PASTE), yes)
MLXFLAGS	+=	-L p_mlx -I p_mlx
endif

CHECK_BONUS	=	$(shell nm fractol 2>&1 | grep move)

RM			=	rm -f

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

ifeq ($(CHECK_BONUS),)
all: $(MANDATORY) $(COMMON)
	@make $(NAME) FILES="$^" --no-print-directory
else
all: 
endif

$(NAME): $(FILES)
	cc $(CFLAGS) $^ $(MLXFLAGS) -o $@

clean:
	$(RM) $(MANDATORY) $(BONUS) $(COMMON)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make --no-print-directory

ifeq ($(CHECK_BONUS),)
bonus: fclean
	@make $(NAME) FILES="$(BONUS) $(COMMON)" --no-print-directory
else
bonus: 
endif

.PHONY: all clean fclean re bonus

# Caso a pessoa não tenha mlx instalada
mlx:
ifeq ($(MLX_PASTE), no)
	@git clone https://github.com/42Paris/minilibx-linux p_mlx
	@make -C p_mlx
	@cd p_mlx
	@sed -i 's|FreeBSD|Linux|' p_mlx/Makefile.mk
	@sed -i 's|FreeBSD|Linux|' p_mlx/Makefile.gen
	@sed -i 's|FreeBSD|Linux|' p_mlx/test/Makefile.gen
	@sed -i 's|FreeBSD|Linux|' p_mlx/test/Makefile.mk
endif

# Codam(Alguma coisa)
# https://github.com/codam-coding-college/MLX42/wiki