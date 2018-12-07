# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:52:47 by tingo             #+#    #+#              #
#    Updated: 2018/12/06 19:26:07 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11 -g
NAME   = ft_ls

ODIR   = obj
SDIR   = src
LDIR   = libft
IDIR   = includes

_SRC   = ft_ls.c \
				 dir.c \
         ft_qsort.c \
         ft_qsortc.c \
         main.c \
         stack.c
SRC    = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ   = $(_SRC:.c=.o)
OBJ    = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: $(NAME)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -c $(SRC) -I $(IDIR)
	@mkdir -p $(ODIR)
	@mv $(_OBJ) $(ODIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/obj/* -I $(IDIR) -L $(LDIR) -lft

clean:
	@make clean -C libft
	@/bin/rm -rf $(ODIR)
	@echo remove $(ODIR)

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo remove $(NAME)

re:	fclean all
