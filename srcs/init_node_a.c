/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:18:47 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/28 16:16:50 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static int	ft_position_cost(int index, bool above_median, int stack_len)
// {
// 	if (above_median)
// 		return (index);
// 	return (stack_len - index);
// }

// static int	ft_get_total_cost(int cost_a, int cost_b, bool same_rotation)
// {
// 	int	total_cost;

// 	total_cost = cost_a + cost_b;
// 	if (same_rotation)
// 	{
// 		total_cost = cost_b;
// 		if (cost_a > cost_b)
// 			total_cost = cost_a;
// 	}
// 	else
// 	{
// 		if ()
// 	}
// 	return (total_cost);
// }

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

static int	ft_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	return (c);
}
static void	ft_cost_cal(t_stack *stack_a, t_stack *stack_b)
{
	int		len_a;
	int		len_b;
	// int		cost_a;
	// int		cost_b;
	int		cost_rr;
	int		cost_rrr;
	int		cost_separate;
	// bool	same_rotation;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		// cost_a = ft_position_cost(stack_a->index, \
		// 	stack_a->above_median, len_a);
		// cost_b = ft_position_cost(stack_a->target_node->index, \
		// 	stack_a->target_node->above_median, len_b);
		// same_rotation = false;
		// if (stack_a->above_median && stack_a->target_node->above_median)
		// 	same_rotation = true;
		// if (!stack_a->above_median && !stack_a->target_node->above_median)
		// 	same_rotation = true;
		// stack_a->push_cost = ft_get_total_cost(cost_a, cost_b, same_rotation);

		// 3パターンの計算
		// if (stack_a->above_median && stack_b->above_median)
		// {
		// 	stack_a->flag_operation = 1;
		// 	if (stack_a->index < stack_b->index)
		// 		stack_a->push_cost = stack_b->index;
		// 	else
		// 		stack_a->push_cost = stack_a->index;
		// }
		// else if (!stack_a->above_median && !stack_b->above_median)
		// {
		// 	stack_a->flag_operation = 2;
		// 	if ((len_a - stack_a->index) < (len_b - stack_b->index))
		// 		stack_a->push_cost = (len_b - stack_b->index);
		// 	else
		// 		stack_a->push_cost = (len_a - stack_a->index);
		// }
		// else 
		// {
		// 	if (stack_a->above_median)
		// 	{
		// 		stack_a->push_cost = stack_a->index + (len_b - stack_b->index);
		// 		if (stack_a->index > (len_b - stack_b->index))
		// 		{

		// 		}
		// 		else 
		// 		{

		// 		}
		// 	}
		// 	else
		// 		stack_a->push_cost = (len_a - stack_a->index) + stack_b->index;
		// }
		//

		// cost_rrの計算
		if (stack_a->index < stack_a->target_node->index)
		{
			if (stack_a->target_node->index - stack_a->index < len_b / 2)
				cost_rr = stack_a->target_node->index;
			else
				cost_rr = stack_a->index * 2 + (len_b - stack_a->target_node->index);
		}
		else
		{
			if (stack_a->index - stack_a->target_node->index < len_a / 2)
				cost_rr = stack_a->index;
			else
				cost_rr = (len_a - stack_a->index) + (stack_a->target_node->index) * 2;
		}
		// cost_rrrの計算
		if ((len_a - stack_a->index) < (len_b - stack_a->target_node->index))
		{
			if (stack_a->target_node->index + stack_a->index > len_b / 2)
				cost_rrr = len_b - stack_a->target_node->index;
			else
				cost_rrr = (len_a - stack_a->index) * 2 + (stack_a->target_node->index);
		}
		else
		{
			if (stack_a->index + stack_a->target_node->index > len_a / 2)
				cost_rrr = len_a - stack_a->index;
			else
				cost_rrr = (stack_a->index) + (len_b - stack_a->target_node->index) * 2;
		}
		// cost_separateの計算
		cost_separate = stack_a->index + (len_b - stack_a->target_node->index);
		if (cost_separate > (len_a - stack_a->index) + stack_a->target_node->index)
			cost_separate = (len_a - stack_a->index) + stack_a->target_node->index;
		// 最小のコストを選択
		stack_a->push_cost = ft_min(cost_rr, cost_rrr, cost_separate);
		if (stack_a->push_cost == cost_rr)
			stack_a->flag_operation = 1;
		else if (stack_a->push_cost == cost_rrr)
			stack_a->flag_operation = 2;
		else
			stack_a->flag_operation = 0;

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
