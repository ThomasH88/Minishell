/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:25:35 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 15:47:55 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*new;
	int		len;

	len = size_of_nb(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	if (n < 0)
	{
		n = -n;
		new[0] = '-';
	}
	new[len] = '\0';
	while (n >= 10)
	{
		new[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	new[len - 1] = n + 48;
	return (new);
}
