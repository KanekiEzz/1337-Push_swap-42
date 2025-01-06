/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:17:26 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 20:46:24 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*lst_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_stack *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	while (tmp)
	{
		if (tmp->value > new->value)
			tmp->index++;
		else
			new->index++;
		tmp = tmp->next;
	}
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = lst_last(*stack);
	last->next = new;
}
