/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:13:16 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/23 11:10:30 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	ft_cases(char *fmt2, int *count, va_list ap2)
{
	while (*fmt2)
	{
		if (*fmt2 == '%' && *(fmt2 + 1) == 's' && fmt2++)
			ft_putstr_printf(va_arg(ap2, char *), count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == 'c' && fmt2++)
			ft_putchar_printf(va_arg(ap2, int), count);
		else if (*fmt2 == '%' && (*(fmt2 + 1) == 'd'
				|| *(fmt2 + 1) == 'i') && fmt2++)
			ft_putnbr_printf(va_arg(ap2, int), count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == 'p' && fmt2++)
			p_itoa_base(va_arg(ap2, unsigned long), 16, count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == 'o' && fmt2++)
			itoa_base_printf(va_arg(ap2, unsigned int), 8, count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == 'u' && fmt2++)
			itoa_base_printf(va_arg(ap2, unsigned int), 10, count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == 'x' && fmt2++)
			itoa_base_printf(va_arg(ap2, unsigned int), 16, count);
		else if (*fmt2 == '%' && *(fmt2 + 1) == '%' && fmt2++)
			ft_putchar_printf('%', count);
		else
			ft_putchar_printf(*fmt2, count);
		fmt2++;
	}
	va_end(ap2);
}

int		b_printf(const char *fmt, ...)
{
	va_list	ap;
	int		*count;
	int		ret;

	count = (int *)malloc(sizeof(int));
	*count = 0;
	va_start(ap, fmt);
	ft_cases((char *)fmt, count, ap);
	ret = *count;
	free(count);
	return (ret);
}
