/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:20:29 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 18:44:53 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(int f1, int end[2], t_pipex *pipex, char **env)
{
	dup2(f1, 0);
	dup2(end[1], 1);
	close(end[0]);
	close(f1);
	if (execve(pipex->cmd_c[0], pipex->cmd_arg_c, env) == -1)
	{
		free_pipex(pipex);
		perror("Execve error :");
	}
	exit(0);
}

void	parent_process(int f2, int end[2], t_pipex *pipex, char **env)
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(f2, 1);
	dup2(end[0], 0);
	close(end[1]);
	close(f2);
	if (execve(pipex->cmd_p[0], pipex->cmd_arg_p, env) == -1)
	{
		free_pipex(pipex);
		perror("Execve error :");
	}
	exit(0);
}

void	pipex(int f1, int f2, char **av, char **env)
{
	int		end[2];
	pid_t	parent;
	t_pipex	*pip;

	pipe(end);
	parent = fork();
	pip = ft_init();
	init_pipex(pip, av, env);
	if (parent < 0)
		return (perror("Fork :"));
	if (!parent)
		child_process(f1, end, pip, env);
	else
		parent_process(f2, end, pip, env);
	free_pipex(pip);
}
