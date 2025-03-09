# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 21:10:53 by yabukirento       #+#    #+#              #
#    Updated: 2025/03/09 12:22:22 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/required_functions/push.c \
		./srcs/required_functions/reverse_rotate.c \
		./srcs/required_functions/rotate.c \
		./srcs/required_functions/swap.c \
		./srcs/main.c \
		./srcs/split.c \
		./srcs/error.c \
		./srcs/rotate_both.c \
		./srcs/init_node_a.c \
		./srcs/init_node_b.c \
		./srcs/stack_utils.c \
		./srcs/sort_small.c \
		./srcs/sort_large.c \
		./srcs/fill_stack_a.c \
		./srcs/set_median.c \
		./srcs/prep_for_push.c \

OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ./srcs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
