/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:56:44 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:15:26 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_tolower(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	MALLOCHECK(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)));
	while (s[i])
	{
		new[i] = ft_tolower(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*str_toupper(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	MALLOCHECK(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)));
	while (s[i])
	{
		new[i] = ft_toupper(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		str_is_print(char *s)
{
	size_t		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && ft_isprint(s[i]) == 0)
		i++;
	if (i != ft_strlen(s))
		return (1);
	return (0);
}

char	*strsub_replace(char *str, char *sub, char *rep)
{
	char	*new;
	int		i;
	size_t	len_sub;

	len_sub = ft_strlen(sub);
	if (str == NULL || ft_strstr(str, sub) == NULL ||
	(new = (char *)malloc(sizeof(char) * (ft_strlen(str)
	- len_sub + ft_strlen(rep) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*str && ft_strncmp(str, sub, len_sub) != 0)
	{
		new[i++] = *str;
		str++;
	}
	while (*rep)
	{
		new[i] = *rep;
		rep++;
		i++;
	}
	ft_strcpy(&new[i], str + len_sub);
	return (new);
}
