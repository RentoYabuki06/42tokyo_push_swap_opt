/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:35:57 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 13:56:15 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stack(stack);
	exit(EXIT_FAILURE);
}

void	ft_freee_stack(t_stack *stack)
{
	//スタックをfreeする処理を記述
}
