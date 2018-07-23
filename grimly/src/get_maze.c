/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:33:05 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/22 22:33:07 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/grimly.h"

void	alloc_maze()
{
	int i;

	i = 0;
	maze = malloc(cols * sizeof(char *));
	while (i < cols)
	{
		maze[i] = malloc(line * sizeof(char *));
		i++;
	}
}

void	alloc_visited()
{
	int i;

	i = 0;
	visited = malloc(cols * sizeof(char *));
	while (i < cols)
	{
		visited[i] = malloc(line * sizeof(char *));
		i++;
	}
}

void	get_visited()
{
	alloc_visited();
	int i;
	int j;

	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < line)
		{
			if (maze[i][j] == '*')
			{
				visited[i][j] = wall;
			}
			else if (maze[i][j] == '2')
			{
				visited[i][j] = goal;
			}
			else
			{
				visited[i][j] = empty;
			}
			j++;
		}
		i++;
	}
}

void	get_maze2(t_env all)
{
	alloc_maze();
	all.i = 0;
	while (all.i < cols)
	{
		all.j = 0;
		while (all.j < line)
		{
			(read(all.fd, &all.c, 1));
			if (all.c == '\n')
			{
				(read(all.fd, &all.c, 1));
			}
			maze[all.i][all.j] = all.c;
			if (all.c == '1')
			{
				start_row = all.i;
				start_col = all.j;
			}
			all.j++;
		}
		all.i++;
	}
	close(all.fd);
}

int	get_maze(char *file_name)
{
	char line_s[3] = { '\0' };
	char cols_s[3] = { '\0' };
	int line_i;
	int cols_i;
	t_env all;

	line_i = 0;
	cols_i = 0;
	all.swap = 0;
	all.fd = open(file_name, O_RDONLY);
	if (all.fd != -1)
	{
		while ((read(all.fd, &all.c, 1)))
		{
			write(1, &all.c, 1);
			if (all.c == '\n')
			{
				break ;
			}
			else if (all.c == ',')
			{
				all.swap = 1;
			}
			else if (all.swap != 0)
			{
				line_s[line_i] = all.c;
				line_i++;
			}
			else
			{
				cols_s[cols_i] = all.c;
				cols_i++;
			}
		}
	}
	else
	{
		return 0;
	}
	line = ft_atoi(line_s);
	cols = ft_atoi(cols_s);
	get_maze2(all);
	return 1;
}
