# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:52:47 by tingo             #+#    #+#              #
#    Updated: 2018/12/03 16:00:33 by tingo            ###   ########.fr        #
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
	@$(CC) $(CFLAGS) -c $(SRC) -I $(IDIR) -L $(LDIR) -lft
	@mkdir -p $(ODIR)
	@mv $(_OBJ) $(ODIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(IDIR) -L $(LDIR) -lft

clean:
	@/bin/rm -rf $(ODIR)
	@echo remove $(ODIR)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo remove $(NAME)

re:	fclean all
