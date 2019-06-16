/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:00:03 by tholzheu          #+#    #+#             */
/*   Updated: 2019/06/15 17:22:49 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# define MALLOCHECK(addr) if((addr) == 0) return (0)

int			retrieve_commands(char **env);
int			run_command(char *cmd, char **env);

int			str_is_print(char *s);
char		*str_tolower(char *s);
char		*str_toupper(char *s);
char		*strsub_replace(char *str, char *sub, char *rep);

int			ft_strchr_first_wd(char *cmd, int c);
char		**normalize_cmds(void);
void		trim_cmds(char **arr);
char		*remove_quotes(char *s);
void		handle_expansions(char **cmds, char **env);

int			arrdel_str(char **arr, char **words_to_free);

int			cmd_clear(char *cmd);
int			cmd_echo(char *cmd, char *lc_cmd, char **env);
int			cmd_cd(char *cmd, char *lc_cmd, char **env);
int			cmd_exit(char *cmd);

int			nopath_cmds(char *cmd, char **env);
int			path_cmds(char *cmd, char **env);

void		cd_relative_path(char *path, char **env);
void		cd_absolute_path(char *path, char **env);
int			check_access(char *path);

char		*get_env_var(char *var, char **env);
char		**get_path_var(char **env);
void		change_env(char *name, char *value, char **env);
void		remove_env_var(char *var, char **env);

int			cmd_env(char *cmd, char **env);
int			cmd_setenv(char *cmd, char **env);
int			cmd_unsetenv(char *cmd, char **env);
int			env_cmds(char *cmd, char **env);

#endif
