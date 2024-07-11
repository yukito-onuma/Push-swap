# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 16:01:54 by yonuma            #+#    #+#              #
#    Updated: 2024/07/05 18:15:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
SRCS = ./utils/ft_atoi.c \
	   ./utils/ft_lstsize.c \
	   ./printf/ft_printf.c \
	   ./printf/ft_utils.c \
	   ./printf/print_unsigned_int.c \
	   ./printf/return_chr.c \
	   ./printf/return_int.c \
	   ./printf/return_percent.c \
	   ./printf/return_pointer.c \
	   ./printf/return_str.c \
	   ./printf/return_ten.c \
	   ./printf/return_base.c \
	   ./stack/push_stack.c \
	   ./sort/sort.c \
	   push_swap.c \
	   main.c \
	   
# BONUS = 
	   
OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)
INCLUDES = -I includes

all : $(NAME)

# bonus : 
# 	@make all "OBJS = $(OBJS) $(OBJS_B)"

$(NAME) : $(OBJS) $(OBJS_B)
	ar rc $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean : 
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all
.PHONY : all clean fclean re
