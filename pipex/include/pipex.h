/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:21:34 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/27 18:10:19 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*path;
	char	**env;
	char	**cmd_c;
	char	**cmd_p;
	char	**cmd_arg_c;
	char	**cmd_arg_p;
}	t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(t_pipex *s, size_t n);
t_pipex	*ft_init(void);
void	free_pipex(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, char **ag, char **env);
void	pipex(int f1, int f2, char **av, char **env);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

#endif
