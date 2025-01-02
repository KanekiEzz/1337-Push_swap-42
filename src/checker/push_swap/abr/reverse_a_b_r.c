/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_a_b_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 08:05:44 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 20:15:30 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2)
		rotate(stack_a);
	if (ft_lstsize(*stack_b) >= 2)
		rotate(stack_b);
}
