/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:23:00 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:14:23 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env_var(char *var, char **env)
{
	size_t		len;
	char		*ret_var;
	int			i;

	len = ft_strlen(var);
	ret_var = NULL;
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(var, env[i], len) == 0)
			ret_var = ft_strdup(&(env[i][len + 1]));
		i++;
	}
	return (ret_var);
}

char		**get_path_var(char **env)
{
	char	*path;
	char	**arr;
	char	*tmp;
	int		i;

	if ((path = get_env_var("PATH", env)) == NULL)
		return (NULL);
	i = 0;
	arr = ft_strsplit(path, ':');
	ft_strdel(&path);
	while (arr && arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		ft_strdel(&arr[i]);
		arr[i] = tmp;
		i++;
	}
	return (arr);
}

void		change_env(char *name, char *value, char **env)
{
	size_t		len;
	char		*full_var;
	char		*tmp;

	tmp = ft_strjoin(name, "=");
	full_var = ft_strjoin(tmp, value);
	ft_strdel(&tmp);
	ft_strdel(&value);
	len = ft_strlen(name);
	while (env && *env)
	{
		if (ft_strncmp(name, *env, len) == 0)
		{
			ft_strdel(env);
			*env = full_var;
			return ;
		}
		env++;
	}
	if (*env == NULL)
		*env = full_var;
	*(env + 1) = NULL;
}

void		remove_env_var(char *var, char **env)
{
	int		i;
	char	*tmp;

	if (env == NULL)
		return ;
	i = 0;
	while (env[i] && env[i + 1])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
		{
			tmp = env[i];
			env[i] = env[i + 1];
			env[i + 1] = tmp;
		}
		i++;
	}
	ft_strdel(&env[i]);
}
