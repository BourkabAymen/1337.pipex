/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:33:25 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/19 12:28:18 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// This function display an error message  
int	print_error(char *message)
{
	ft_putendl_fd(message, 1);
	exit(1);
}
// This function display an error message to stderror
int	exit_with_error(void)
{
	perror("Error");
	exit(1);
}
// This function returns 1 if sub is in s
int	ft_contains(char *s, char *sub)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && sub[j] && s[i + j] == sub[j])
			j++;
		if (!sub[j])
			return (1);
		i++;
	}
	return (0);
}

// This function calls ft_contains in order to check
// the occurance of the envirenment variable starting with PATH= 
// in the envp
// we call then ft_split in order to split this envirenment variable
// by : as a separator
// Then for each path in paths we add / then we add our command 
// that we we stock in path and we check its occrance by access
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_contains(envp[i], "PATH=") == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

// This function takes av as a string that contains 
// a command separated with its options by certain spaces 
// and we use split to separate them that we stock in cmd
// but we all know that its first element is the command itself
// Then we execute the command if it s possible by execve
// that takes the path with / and with the command
// it takes also cmd the array of strings that contains 
// the command with there options
// it takes also envp an array of all the envirenment variables
void	execute(char *av, char **envp, char **cmd)
{
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit_with_error();
	}
	if (execve(path, cmd, envp) == -1)
		exit_with_error();
}
