/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:42:43 by tholzheu          #+#    #+#             */
/*   Updated: 2018/09/18 22:54:01 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;
	size_t		count;
	size_t		tmp;

	i = 0;
	count = 0;
	if (h[i] == '\0' && n[i] == '\0' && len)
		return ((char *)&h[i]);
	while (h[i] && len)
	{
		tmp = len;
		while (h[i] == n[count] && h[i] && len)
		{
			count++;
			i++;
			len--;
		}
		len = tmp;
		if (count == ft_strlen(n))
			return ((char *)&(h[i - count]));
		i = i + 1 - count;
		count = 0;
		len--;
	}
	return (NULL);
}
