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

# define HEIGHT 10
# define WIDTH 10
# define MAX 100

# define TRUE 1
# define FALSE 0

# define initial 1
# define waiting 2

/*
**---------------------------- Structure Definition ---------------------------
*/

struct node
{
	int mode;
	struct node	*up;
	struct node *left;
	struct node *down;
	struct node *right;
	struct node *next;
};

typedef struct point
{
	int y;
	int x;
}Point;

struct node matrix[HEIGHT][WIDTH];

typedef struct		s_key
{
	char			*key;
	int				row;
	int				column;
	int				**arr;
	int				startx;
	int				starty;
}					t_key;

typedef struct		s_rs
{
	int				run;
	int				n;
	int				exits;
	int				entrance;
}					t_rs;

typedef struct		s_bfs
{
	int				x;
	int				y;
	struct s_bfs	*parent;
}					t_bfs;

typedef struct		s_queue
{
	struct s_bfs	*node;
	struct s_queue	*next;
}					t_queue;


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

void	setupMatrix(void);
void	printMatrix(void);
void	makeWall(Point first, Point second);
Point	makePoint(int y, int x);
int		validcard(int fd);
int		dup_check(char *str);

#endif
