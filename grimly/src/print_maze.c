/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:33:24 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/22 22:33:26 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/grimly.h"

int		add_steps(int steps)
{
	int i;
	int j;
	int tracker;

	tracker = 0;
	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < line)
		{
			if (maze[i][j] != '1')
			{
				if (visited[i][j] == steps)
				{
					maze[i][j] = 'o';
					tracker++;
				}
			}
			j++;
		}
		i++;
	}
	return (tracker);
}

void	print_steps(int tracker)
{
	ft_putstr("RESULT IN ");
	ft_putnbr(tracker);
	ft_putstr(" STEPS!\n");
}

/*
 ** Internal Representation of maze. 1 for walls, 0 for empty space
 */

void	print_visited()
{
	int i;
	int j;

	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < line)
		{
			write(1, &visited[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

}

void	print_maze(int tracker)
{
	int i;
	int j;

	i = 0;
	while (i < cols)
	{
		j = 0;
		while (j < line)
		{
			write(1, &maze[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	print_steps(tracker);
}
