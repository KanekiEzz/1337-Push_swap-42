/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:07:54 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 17:43:25 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	char	*join_string(char *lst, char *str)
{
	char	*tmp;
	char	*joined;

	tmp = lst;
	joined = ft_strjoin(lst, str);
	lst = ft_strjoin(joined, " ");
	free(joined);
	free(tmp);
	return (lst);
}

static	char	*validate_and_join(char **ptr)
{
	int		i;
	int		j;
	char	*lst;
	char	*tmp;

	lst = calloc(1, 1);
	i = 0;
	while (ptr[i] != NULL)
	{
		j = 0;
		if ((ptr[i][0] == '-' || ptr[i][0] == '+') && ft_strlen(ptr[i]) > 1)
			j++;
		while (ptr[i][j] != '\0')
		{
			if (!valid_number(ptr[i][j]))
				(free_string(ptr), free(lst),
					ft_printf("\033[0;31mError\n\033[0m"), exit(EXIT_FAILURE));
			j++;
		}
		tmp = lst;
		lst = join_string(lst, ptr[i++]);
	}
	free_string(ptr);
	return (lst);
}

static	void	check_for_duplicates(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*check_rep;

	curr = stack;
	while (curr != NULL)
	{
		check_rep = curr->next;
		while (check_rep != NULL)
		{
			if (curr->value == check_rep->value)
			{
				ft_printf("\033[0;31mError: Duplicate values found\n\033[0m");
				exit(EXIT_FAILURE);
			}
			check_rep = check_rep->next;
		}
		curr = curr->next;
	}
}

static	char	*parse_arguments(int ac, char **av)
{
	char	*lst;
	char	*parsed;
	char	*tmp;
	int		i;

	lst = calloc(1, 1);
	i = 1;
	if (!lst)
		return (NULL);
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			(free(lst), ft_printf("\033[0;31mError\n\033[0m"),
				exit(EXIT_FAILURE));
		parsed = validate_and_join(ft_split(av[i], ' '));
		if (!parsed)
			(free(lst), exit(EXIT_FAILURE));
		tmp = lst;
		lst = ft_strjoin(lst, parsed);
		(free(tmp), free(parsed));
		if (!lst)
			exit(EXIT_FAILURE);
		i++;
	}
	return (lst);
}

t_stack	*valid_parse(int ac, char **av)
{
	char	*lst;
	t_stack	*stack_a;

	if (ac <= 1)
		return (NULL);
	if (check_strg_emtghi(ac, av) == 0)
	{
		ft_printf("\033[0;31mError\n\033[0m");
		exit (EXIT_FAILURE);
	}
	lst = parse_arguments(ac, av);
	if (!lst)
		return (NULL);
	stack_a = create_stack(ft_split(lst, ' '));
	free(lst);
	if (!stack_a)
		return (NULL);
	check_for_duplicates(stack_a);
	return (stack_a);
}
