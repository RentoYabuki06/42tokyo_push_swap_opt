# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 21:10:53 by yabukirento       #+#    #+#              #
#    Updated: 2025/03/09 16:13:55 by yabukirento      ###   ########.fr        #
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

SRCBONUS =	./bonus/checker_bonus.c \
			./bonus/utils_bonus.c \
			./bonus/free_bonus.c \
			./bonus/fill_stack_bonus.c \
			./bonus/operators/swap_bonus.c \
			./bonus/operators/push_bonus.c \
			./bonus/operators/rotate_bonus.c \
			./bonus/operators/rev_rotate_bonus.c \
			./bonus/get_next_line/get_next_line_bonus.c \
			./bonus/get_next_line/get_next_line_utils_bonus.c \

OBJSBONUS = $(SRCBONUS:.c=.o)

FT_PRINTF_DIR = ./srcs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

$(BONUS_NAME): $(OBJSBONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(FT_PRINTF)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSBONUS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
