# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 18:18:07 by yonuma            #+#    #+#              #
#    Updated: 2024/12/30 19:50:01 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap.a
EXEC = push_swap
SRCS = src/main.c \
       src/push_stack.c \
       src/push_swap.c \
	   src/rotate_stack_a.c \
	   src/search_sorted.c \
       src/sort.c \
	   src/sort1.c \
	   src/sort2.c \
	   src/utils.c \
	   src/utils2.c \
	   src/utils3.c \
	   src/sort_small.c \
	   src/calculate_cost.c
	   
LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)
INCLUDES = -Iinclude

all: $(LIBFT) $(PRINTF) $(EXEC)

$(NAME): $(OBJS)
	ar rc $@ $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(EXEC): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXEC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re