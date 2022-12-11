/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:33:11 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/11 11:10:23 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

int		print_error(char *message);
char	*find_path(char *cmd, char **env);
int		ft_contains(char *s, char *sub);
void	execute(char *av, char **envp, char **cmd);

typedef struct s_var {
	int		args;
	pid_t	pid;
	int		fd[2];
	char	**cmd;
}	t_var;

#endif
