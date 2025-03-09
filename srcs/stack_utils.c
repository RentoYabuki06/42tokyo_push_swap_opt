/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:31:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 11:54:49 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (TRUE);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	ft_stack_len(t_stack *stack)
{
	int		len;

	len = 1;
	if (!stack->next)
		return (len);
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*ft_find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	current = stack;
	min_node = stack;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	current = stack;
	max_node = stack;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}
