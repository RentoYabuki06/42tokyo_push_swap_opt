/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:43 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 11:59:41 by yabukirento      ###   ########.fr       */
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
	int	min;

	min = ft_find_min(*stack_a)->value;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->value == min)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		*stack_a = (*stack_a)->next;
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = ft_find_max(*stack_a)->value;
	max = ft_find_min(*stack_a)->value;
	ft_printf("max : %d\n", max);
	ft_printf("min : %d\n", min);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		*stack_a = (*stack_a)->next;
	}
	ft_printf("start : sort_three\n");
	ft_sort_three(stack_a);
	ft_printf("finish : sort_three\n");
	if ((*stack_b)->value > (*stack_b)->next->value)
		ft_sb(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
}
