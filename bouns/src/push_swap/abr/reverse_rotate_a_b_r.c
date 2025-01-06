/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b_r.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 08:03:59 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 00:38:36 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = last;
	last->next = first;
	while (first->next != last)
		first = first->next;
	first->next = NULL;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, true);
	rrb(b, true);
}
