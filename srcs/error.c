/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:57 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 19:19:03 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_error(t_stack **stack, char **argv, int count)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stack(stack);
	ft_free_split(argv, count);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!*stack)
		return ;
	current = ft_find_last(*stack);
	while (current)
	{
		next = current->prev;
		current->target_node = NULL;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = next;
	}
}

void	ft_free_split(char **argv, int count)
{
	int	i;

	i = 1;
	if (count == 0)
		return ;
	while (count-- >= -1)
	{
		if (!argv[i])
			free(argv[i]);
		argv[i] = NULL;
		i--;
	}
}
