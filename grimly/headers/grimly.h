#ifndef GRIMLY_H
# define GRIMLY_H

/*
**------------------------------ External Headers ------------------------------
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
**---------------------------- Structure Definition ---------------------------
*/

typedef struct			s_char
{
	char			full;
	char			empty;
	char			path;
	char			entrance;
	char			exit;
}				t_char;

typedef struct			s_node
{
	int			x;
	int			y;
	char			curr;
	struct s_2dpoints	*next;
}				t_node;


/*
**----------------------------- Helping Functions ----------------------------
*/

#endif
