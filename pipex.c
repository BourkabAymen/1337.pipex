/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:32:55 by abourkab          #+#    #+#             */
/*   Updated: 2022/12/11 11:10:47 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// For each process there s 0 and 1 our standard input and output
// Redirects 0 to filein
// Redirects 1 to fd[1] the entry of the pipe
// close fd[0] to avoid losing data
// and executes the 1st cmd
void	child_process(char **av, char **envp, int *fd, char **cmd)
{
	int	filein;

	filein = open(av[1], O_RDONLY);
	if (filein == -1)
		print_error("Error");
	dup2(fd[1], 1);
	dup2(filein, 0);
	close(fd[0]);
	execute(av[2], envp, cmd);
}

// For each process there s 0 and 1 our standard input and output
// Redirects 0 to fd[0] the exit of the pipe
// Redirects 1 to fileout
// close fd[1] to avoid losing data
// and executes the 1st cmd
void	parent_process(char **av, char **envp, int *fd, char **cmd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT, 777);
	if (fileout == -1)
		print_error("Error");
	dup2(fd[0], 0);
	dup2(fileout, 1);
	close(fd[1]);
	execute(av[3], envp, cmd);
}
// In the main function 
// If the number of arguments is not 5 display
// Error in arguments
// otherwise we use pipe in order to assigne two values
// to the first integers in var.fd so these integers are 
// file_descriptors and there s a certain channel between them
// that allows an intra commincation process
// so the entry is fd[1] and the exit is fd[0]
// Because we have to execute 2 commands so we gonna use fork 
// that creats 2 processes because executing the first command
// with execve will stop the process if it succeeded 
// And for each process var.pid has a value
// 0 if it's a child process
// and another value if we are in the parant process
// and -1 if it fails to create two processes
// we use waitpid to tell the parrent process to wait 
// till the child process is over so after that 
// the parent process is launched again

int	main(int ac, char **av, char **envp)
{
	t_var	var;

	if (ac != 5)
		return (print_error("Error in arguments"));
	else
	{
		if (pipe(var.fd) == -1)
			print_error("Error");
		var.pid = fork();
		if (var.pid == -1)
			print_error("Error");
		if (var.pid == 0)
			child_process(av, envp, var.fd, var.cmd);
		waitpid(var.pid, NULL, 0);
		parent_process(av, envp, var.fd, var.cmd);
	}
	return (0);
}
