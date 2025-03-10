/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:57 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 21:08:07 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_error(t_stack **stack, char **argv, bool is)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stack(stack);
	ft_free_split(argv, is);
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

void	ft_free_split(char **argv, bool is_split)
{
	int	i;

	i = 0;
	if (!is_split)
		return ;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
