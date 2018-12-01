/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:24:58 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/09 11:37:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_a_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		char_next(const char *s)
{
	while (*s)
	{
		if (is_a_space(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && is_a_space(s[i]))
		i++;
	s += i;
	i = 0;
	while (char_next(&s[i]))
		i++;
	new = (char *)malloc(sizeof(char) * i + 1);
	if (!new)
		return (0);
	while (j < i)
	{
		new[j] = *s;
		j++;
		s++;
	}
	new[j] = '\0';
	return (new);
}
