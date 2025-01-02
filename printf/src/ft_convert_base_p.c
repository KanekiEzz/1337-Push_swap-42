/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:17:55 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/05 01:26:47 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_base_p(unsigned long long nbr, unsigned int base,
		const char *base_str, int *count)
{
	if (nbr >= base)
		ft_convert_base_p(nbr / base, base, base_str, count);
	ft_putchar(base_str[nbr % base], count);
}
