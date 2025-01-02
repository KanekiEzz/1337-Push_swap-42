/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:21:41 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/04 23:36:59 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (*str)
		ft_putchar(*str++, count);
}
