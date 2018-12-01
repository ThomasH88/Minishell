/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:50:53 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/21 16:49:35 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	ft_putchar_printf(char c, int *count)
{
	*count = *count + 1;
	write(1, &c, 1);
}

void	ft_putstr_printf(char *str, int *count)
{
	if (str == NULL)
		return (ft_putstr_printf("(null)", count));
	while (*str)
	{
		ft_putchar_printf(*str, count);
		str++;
	}
}
