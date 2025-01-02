/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:08:53 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 13:11:58 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		(ft_printf("\033[0;31mError\n\033[0m"), exit(EXIT_FAILURE));
	stack_a = valid_parse(ac, av);
	if (stack_not_sorted(&stack_a))
	{
		move_to_b(&stack_a, &stack_b, 0, 0);
		move_back_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
