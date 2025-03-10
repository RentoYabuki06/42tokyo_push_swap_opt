/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:36 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 16:09:55 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

void	ft_test_free_error(t_test_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_test_free_stack(stack);
	exit(EXIT_FAILURE);
}

void	ft_test_free_stack(t_test_stack **stack)
{
	t_test_stack	*current;
	t_test_stack	*next;

	if (!*stack)
		return ;
	current = ft_test_find_last(*stack);
	while (current)
	{
		next = current->prev;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = next;
	}
}
