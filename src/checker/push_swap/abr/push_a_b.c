/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:07:48 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 21:33:44 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/push_swap.h"

static	void	push(t_stack **dest, t_stack **src)
{
	t_stack	*src_first;

	if (*src == NULL)
		return ;
	src_first = *src;
	*src = src_first->next;
	src_first->next = *dest;
	*dest = src_first;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
}
