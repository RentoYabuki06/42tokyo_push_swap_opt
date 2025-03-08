/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:18:47 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 19:56:37 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void	ft_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;


	while(stack_a)
	{
		best_match_index = LONG_MAX;
		current_b = stack_a;
		while (current_b)
		{
			if (current_b->value > stack_b->value && current_b->value < best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MAX)
			stack_a->target_node = ft_find_min(stack_a);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	ft_cost_cal(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

static void	ft_set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_set_median(stack_a);
	ft_set_median(stack_a);
	ft_set_target_a(stack_a, stack_b);
	ft_cost_cal(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}
