# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 07:55:31 by rcosta-c          #+#    #+#              #
#    Updated: 2024/08/13 09:09:33 by rcosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = \
	ft_printchar.c ft_printf.c ft_printnbr.c ft_printptr.c \
	ft_p_strlen.c ft_printstr.c ft_printx_lbase.c \
	ft_printx_ubase.c ft_printnbr_base.c ft_printu.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLR_RMV         := \033[0m
RED                 := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
CYAN            := \033[1;36m


all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	make bonus -C libft
	cp libft/libft.a $(NAME)
	$(AR) -r $@ $?
	@echo "$(GREEN) $(NAME) created ✔️"

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	make clean -C libft
	rm -f $(OBJECTS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	@echo "$(RED)Deleting $(CYAN) $(NAME) $(CLR_RMV)bynary ✔️"

re: fclean all

.PHONY: all bonus clean fclean re
