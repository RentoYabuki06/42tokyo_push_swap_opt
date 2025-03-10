/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:40:29 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 17:40:32 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_cost(int index, bool above_median, int stack_len)
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

void	ft_cost_cal(t_stack *stack_a, t_stack *stack_b)
{
	int		cost_a;
	int		cost_b;
	bool	same_rotation;
	t_stack	*target;

	target = stack_a->target_node;
	while (stack_a)
	{
		cost_a = ft_cal_cost(stack_a->index, \
			stack_a->above_median, ft_stack_len(stack_a));
		cost_b = ft_cal_cost(target->index, \
			target->above_median, ft_stack_len(stack_b));
		same_rotation = ((stack_a->above_median && target->above_median) || \
			(!stack_a->above_median && !target->above_median));
		stack_a->push_cost = ft_get_total_cost(cost_a, cost_b, same_rotation);
		stack_a = stack_a->next;
	}
}
