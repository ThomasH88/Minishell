/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:25:04 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:40:24 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_relative_path(char *path, char **env)
{
	char	cwd[4096];
	char	*pwd;

	getcwd(cwd, 4096);
	ft_strcat(cwd, "/");
	ft_strcat(cwd, path);
	if (chdir(cwd) == -1)
	{
		if (access(cwd, F_OK) == -1)
			b_printf("cd: no such file or directory: %s\n", path);
		else if (access(cwd, X_OK) == -1)
			b_printf("cd: permission denied: %s\n", path);
		else
			b_printf("cd: error: %s\n", path);
	}
	pwd = getcwd(NULL, 0);
	change_env("PWD", pwd, env);
	ft_strdel(&path);
}

void	cd_absolute_path(char *path, char **env)
{
	char	*cwd;

	if (chdir(path) == -1)
	{
		if (access(path, F_OK) == -1)
			b_printf("cd: no such file or directory: %s\n", path);
		else if (access(path, X_OK) == -1)
			b_printf("cd: permission denied: %s\n", path);
		else
			b_printf("cd: error: %s\n", path);
	}
	ft_strdel(&path);
	cwd = getcwd(NULL, 0);
	change_env("PWD", cwd, env);
}

int		check_access(char *path)
{
	if (access(path, F_OK) == -1)
		return (-1);
	if (access(path, X_OK) == -1)
		return (-2);
	return (0);
}
