/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:33:17 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/22 22:33:20 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/grimly.h"

int	main(int argc, char **argv)
{
	int i;
	int tracker;
	int index;


	i = 1;
	index = 1;
	if (argc == 1)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <input filename> ");
	}
	while (index < argc)
	{
		/*
		get_maze(argv[i]);
		get_visited();

		print_maze();
		print_visited();
		*/

		if(!get_maze(argv[index]))
		{
			ft_putendl("MAP ERROR");
			index++;
			continue ;
		}
		get_visited();
		dfs(start_row, start_col);
		tracker = add_steps(steps);
		print_maze(tracker);
		index++;
	}
	return 0;
}
