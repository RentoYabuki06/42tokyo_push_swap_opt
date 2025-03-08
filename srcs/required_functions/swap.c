/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:10:18 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 14:21:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !(stack->value) || !(stack->next->value))
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
