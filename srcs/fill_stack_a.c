/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:59 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 18:41:14 by yabukirento      ###   ########.fr       */
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
		*stack = node;
		node->prev = NULL;
	}
	else
	{
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

void	ft_init_stack_a(t_stack **stack, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (ft_error_syntax(argv[i]))
			ft_free_error(stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_free_error(stack);
		if (ft_isduplicated(*stack, num))
			ft_free_error(stack);
		ft_append_node(stack, (int)num);
		i++;
	}
}
