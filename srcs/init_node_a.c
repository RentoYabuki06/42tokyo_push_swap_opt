/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:18:47 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/28 15:29:55 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_position_cost(int index, bool above_median, int stack_len)
{
	if (above_median)
		return (index);
	return (stack_len - index);
}

static int	ft_get_total_cost(int cost_a, int cost_b, bool same_rotation)
{
	if (same_rotation)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static void	ft_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	current_match_value;

	while (stack_a)
	{
		current_match_value = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value \
				&& current_b->value > current_match_value)
			{
				current_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (current_match_value == LONG_MIN)
			stack_a->target_node = ft_find_min(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	ft_cost_cal(t_stack *stack_a, t_stack *stack_b)
{
	int		len_a;
	int		len_b;
	int		cost_a;
	int		cost_b;
	bool	same_rotation;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		cost_a = ft_position_cost(stack_a->index, \
			stack_a->above_median, len_a);
		cost_b = ft_position_cost(stack_a->target_node->index, \
			stack_a->target_node->above_median, len_b);
		same_rotation = false;
		if (stack_a->above_median && stack_a->target_node->above_median)
			same_rotation = true;
		if (!stack_a->above_median && !stack_a->target_node->above_median)
			same_rotation = true;
		stack_a->push_cost = ft_get_total_cost(cost_a, cost_b, same_rotation);
		stack_a = stack_a->next;
	}
}

void	ft_init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_set_median(stack_a);
	ft_set_median(stack_b);
	ft_set_target_a(stack_a, stack_b);
	ft_cost_cal(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}
