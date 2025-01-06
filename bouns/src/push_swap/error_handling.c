/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:43:28 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 00:33:13 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_free_errors(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	ft_printf("\033[0;31mError\n\033[0m");
	exit(EXIT_FAILURE);
}

int	check_strg_emtghi(int ac, char **av)
{
	int	i;
	int	j;
	int	flags;

	i = 1;
	while (i < ac)
	{
		j = 0;
		flags = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				flags = 1;
			j++;
		}
		i++;
	}
	if (!flags)
		return (0);
	return (1);
}
