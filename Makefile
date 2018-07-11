# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:52:47 by tingo             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/05/27 13:10:10 by tingo            ###   ########.fr        #
=======
#    Updated: 2018/05/30 15:56:13 by tingo            ###   ########.fr        #
>>>>>>> master
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11
NAME   = ft_ls

ODIR   = obj
SDIR   = src
LDIR   = libft
IDIR   = includes

_SRC   =
SRC    = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ   = $(_SRC:.c=.o)
OBJ    = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) src/* -I $(IDIR) -L $(LDIR) -lft

clean:
	@/bin/rm -rf $(ODIR)
	@echo remove $(ODIR)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo remove $(NAME)

re:	fclean all
