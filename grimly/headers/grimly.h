/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:33:36 by atemunov          #+#    #+#             */
/*   Updated: 2018/07/22 22:33:39 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

/*
**------------------------------ External Headers -----------------------------
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
**----------------------------- Macros Definition -----------------------------
*/


/*
**------------------------------ Global Variables -----------------------------
*/

char** 				maze;
int**				visited;
int					line;
int					cols;
int					start_row;
int					start_col;
char				*file;

enum	terrain
{
	empty,
	wall,
	goal,
	steps
};

/*
**---------------------------- Structure Definition ---------------------------
*/

typedef struct		s_env
{
	int				j;
	int				i;
	int				swap;
	char				c;
	int				fd;
}			t_env;

typedef struct		s_bfs
{
	int				x;
	int				y;
	struct s_bfs	*parent;
}					t_bfs;

t_list				*read_input(void);

/*
**----------------------------- Helping Functions ----------------------------
*/

int				add_steps(int steps);
void				print_steps(int tracker);
void				print_visited();
void				print_maze(int tracker);
int				dfs(int row, int col);
void				alloc_maze();
void				alloc_visited();
void				get_visited();
int				get_maze(char *file_name);

#endif
