/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:43 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 11:16:51 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = ft_find_max(*stack);
	if (biggest_node == *stack)
		ft_ra(stack);
	else if (biggest_node == (*stack)->next)
		ft_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		ft_sa(stack);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;

	min_node = ft_find_min(*stack_a);
	while ((*stack_a)->next)
	{
		if (*stack_a == min_node)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;
	t_stack	*max_node;
	t_stack	**top_node;

	min_node = ft_find_max(*stack_a);
	max_node = ft_find_min(*stack_a);
	top_node = stack_a;
	while ((*stack_a)->next)
	{
		if (*stack_a == min_node || *stack_a == max_node)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		*stack_a = (*stack_a)->next;
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	if (*top_node == max_node)
		ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	if (*top_node == max_node)
		ft_ra(stack_a);
}
