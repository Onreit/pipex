/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:20:29 by tjalo             #+#    #+#             */
/*   Updated: 2022/05/24 18:02:44 by tjalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    pipex(int f1, int f2)
{
    int     end[2];
    pid_t   parent;

    pipe(end);
    parent = fork();
    if (parent < 0)
        return (perror("Fork :"));
    if (!parent)
        //child_process(f1, cmd1)
    else
        //parent_process(f2, cm2)
}