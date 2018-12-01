/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:22:15 by tholzheu          #+#    #+#             */
/*   Updated: 2018/09/18 22:40:02 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *h, const char *n)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (h[i] == '\0' && n[i] == '\0')
		return ((char *)&h[i]);
	while (h[i])
	{
		while (h[i] == n[count] && h[i])
		{
			count++;
			i++;
		}
		if (count == ft_strlen(n))
			return ((char *)&(h[i - count]));
		i = i + 1 - count;
		count = 0;
	}
	return (NULL);
}
