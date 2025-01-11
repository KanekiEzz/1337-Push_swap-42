/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:28:23 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 15:19:49 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_format_printf(va_list args, char format_sp, int *count)
{
	if (format_sp == '%')
		ft_putchar('%', count);
	else if (format_sp == 'c')
		ft_putchar((char)va_arg(args, int), count);
	else if (format_sp == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format_sp == 'd' || format_sp == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format_sp == 'u')
		ft_convert_base(va_arg(args, unsigned int), 10, "0123456789", count);
	else if (format_sp == 'x')
		ft_convert_base(va_arg(args, unsigned int), 16, "0123456789abcdef",
			count);
	else if (format_sp == 'X')
		ft_convert_base(va_arg(args, unsigned int), 16, "0123456789ABCDEF",
			count);
	else if (format_sp == 'p')
	{
		ft_putstr("0x", count);
		ft_convert_base_p(va_arg(args, unsigned long long), 16,
			"0123456789abcdef", count);
	}
	else
		ft_putchar(format_sp, count);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &count);
		else
		{
			i++;
			if (format[i] != '\0')
				ft_format_printf(args, format[i], &count);
		}
		if (format[i] == '\0')
			break ;
		i++;
	}
	va_end(args);
	return (count);
}
