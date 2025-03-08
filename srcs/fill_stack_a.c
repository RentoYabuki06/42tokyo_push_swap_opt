/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:59 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 14:39:59 by yabukirento      ###   ########.fr       */
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

static int	ft_isduplicated(t_stack *stack)
{
	// numが
}

static int	ft_error_syntax(char *num)
{
	// ifnumが適切でない場合は
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_init_stack_a(t_stack *stack, char **argv)
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
		if (ft_isduplicated(num))
			ft_free_error(stack);
		ft_append_node(&stack, (int)num);
	}
}
