/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:59 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 19:19:22 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_append_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (true);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (true);
	node->next = NULL;
	node->value = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (false);
}

static int	ft_isduplicated(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}

static int	ft_error_syntax(char *s)
{
	int	i;

	i = 11;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		s++;
	if (!ft_isdigit(*s))
		return (true);
	while (ft_isdigit(*s))
	{
		i--;
		if (i == 0)
			return (true);
		s++;
	}
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s)
		return (true);
	return (false);
}

bool	ft_init_stack_a(t_stack **stack, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			return (true);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (true);
		if (ft_isduplicated(*stack, num))
			return (true);
		if (ft_append_node(stack, (int)num))
			return (true);
		i++;
	}
	return (false);
}
