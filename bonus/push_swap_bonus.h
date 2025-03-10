/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:27:05 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 12:39:38 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdbool.h>
# include "./get_next_line/get_next_line_bonus.h"
# include "../srcs/libft/libft.h"

typedef struct s_test_stack
{
	int					value;
	struct s_test_stack	*next;
	struct s_test_stack	*prev;
}	t_test_stack;

void			ft_test_sa(t_test_stack **stack_a);
void			ft_test_sb(t_test_stack **stack_b);
void			ft_test_ss(t_test_stack **stack_a, t_test_stack **stack_b);
void			ft_test_pa(t_test_stack **stack_a, t_test_stack **stack_b);
void			ft_test_pb(t_test_stack **stack_a, t_test_stack **stack_b);
void			ft_test_ra(t_test_stack **stack_a);
void			ft_test_rb(t_test_stack **stack_b);
void			ft_test_rr(t_test_stack **stack_a, t_test_stack **stack_b);
void			ft_test_rra(t_test_stack **stack_a);
void			ft_test_rrb(t_test_stack **stack_b);
void			ft_test_rrr(t_test_stack **stack_a, t_test_stack **stack_b);

t_test_stack	*ft_test_find_last(t_test_stack *stack);

void			ft_init_stack_test(t_test_stack **stack, char **argv);

void			ft_test_free_error(t_test_stack **stack);
void			ft_test_free_stack(t_test_stack **stack);

#endif