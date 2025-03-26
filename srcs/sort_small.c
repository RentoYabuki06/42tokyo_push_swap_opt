/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:50:43 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/26 15:01:49 by yabukirento      ###   ########.fr       */
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
	int		min;
	t_stack	*min_node;
	int		position;
	t_stack	*current;

	min_node = ft_find_min(*stack_a);
	min = min_node->value;
	position = 0;
	current = *stack_a;
	while (current && current->value != min && position++ >= 0)
		current = current->next;
	if (position <= 1)
	{
		while ((*stack_a)->value != min)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	count;

	min = ft_find_min(*stack_a)->value;
	max = ft_find_max(*stack_a)->value;
	count = 0;
	while ((*stack_a)->next && count < 2)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
		{
			ft_pb(stack_a, stack_b);
			count++;
		}
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	if ((*stack_b)->value > (*stack_b)->next->value)
		ft_sb(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
}
