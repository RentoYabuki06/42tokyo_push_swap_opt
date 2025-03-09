/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:59 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 11:06:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_append_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		ft_free_error(stack);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_free_error(stack);
	node->next = NULL;
	node->value = num;
	if (!(*stack))
	{
		// ft_printf("first node\n");
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		// ft_printf("additional node\n");
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	
}

static int	ft_isduplicated(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

static int	ft_error_syntax(char *s)
{
	int	i;

	i = 11;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		i--;
		if (i == 0)
			return (TRUE);
		s++;
	}
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s)
		return (TRUE);
	return (FALSE);
}

void	ft_init_stack_a(t_stack **stack, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		// ft_printf("%s\n", argv[i]);
		if (ft_error_syntax(argv[i]))
			ft_free_error(stack);
		// ft_printf("hello\n");
		num = ft_atol(argv[i]);
		// ft_printf("%d\n", num);
		if (num > INT_MAX || num < INT_MIN)
			ft_free_error(stack);
		// ft_printf("world\n");
		if (ft_isduplicated(*stack, num))
			ft_free_error(stack);
		// ft_printf("!!!!\n");
		ft_append_node(stack, (int)num);
		// ft_printf("!!!!\n");
		i++;
	}
}
