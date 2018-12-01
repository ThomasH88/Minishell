/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:27:12 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:12:31 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_environ(void)
{
	extern char		**environ;
	char			**env;
	int				i;

	MALLOCHECK(env = (char **)malloc(sizeof(char *) * 100));
	if (environ == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	env[99] = NULL;
	return (env);
}

int			main(void)
{
	char	**env;

	MALLOCHECK(env = get_environ());
	b_printf("\e[1;1H\e[2J");
	while (1)
	{
		ft_putstr("$> ");
		if (retrieve_commands(env) == 0)
			exit(0);
	}
	return (0);
}
