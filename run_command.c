/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:51:59 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:16:51 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_command(char *cmd, char **env)
{
	int		notfound;
	char	*lc_cmd;

	if (env_cmds(cmd, env))
		return (1);
	if (ft_strncmp(cmd, "exit", 4) == 0 && !ft_isprint(cmd[4]))
		return (cmd_exit(cmd));
	MALLOCHECK(lc_cmd = str_tolower(cmd));
	notfound = 0;
	if (ft_strncmp(lc_cmd, "clear", 5) == 0 && !ft_isprint(cmd[5]))
		return (cmd_clear(lc_cmd));
	if (ft_strncmp(lc_cmd, "echo", 4) == 0 && !ft_isprint(cmd[4]))
		return (cmd_echo(cmd, lc_cmd, env));
	if (ft_strncmp(lc_cmd, "cd", 2) == 0 && !ft_isprint(cmd[2]))
		return (cmd_cd(cmd, lc_cmd, env));
	if (ft_strchr_first_wd(cmd, '/') == 1 && ft_strdel(&lc_cmd))
		return (nopath_cmds(cmd, env));
	else
		notfound = path_cmds(cmd, env);
	if (notfound)
		b_printf("minishell: command not found: %s\n", cmd);
	ft_strdel(&lc_cmd);
	return (1);
}

int		retrieve_commands(char **env)
{
	int		i;
	char	**arr;

	i = 0;
	arr = normalize_cmds();
	while (arr && arr[i])
	{
		if (run_command(arr[i], env) == 0)
		{
			arrdel_str(arr, &arr[i]);
			return (0);
		}
		ft_strdel(&arr[i]);
		i++;
	}
	arrdel_str(arr, NULL);
	return (1);
}
