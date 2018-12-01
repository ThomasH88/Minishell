/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:05:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/09 16:09:36 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ans;
	int		sign;

	if (ft_strlen(str) >= 19 && ft_strcmp(str, "9223372036854775807") > 0)
		return (-1);
	if (ft_strlen(str) >= 20 && ft_strcmp(str, "-9223372036854775808") > 0)
		return (0);
	sign = 1;
	ans = 0;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\r'
					|| *str == '\v' || *str == '\f' || *str == '\t'))
			str++;
		if (*str == '-' && str++)
			sign = -1;
		else if (*str == '+' && str++)
			sign = 1;
		while (*str && *str >= '0' && *str <= '9')
			ans = ans * 10 + (*str++ - '0');
	}
	return (sign * ans);
}
