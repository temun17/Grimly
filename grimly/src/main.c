#include "../headers/grimly.h"

char**	maze;
int**	visited;
int	line;
int	cols;
int	start_row;
int	start_col;

enum terrain
{
	empty,
	wall,
	goal,
	steps
};

void	alloc_maze()
{
	int i;

	i = 0;
	maze = malloc(line * sizeof(char *));
	while (i < line)
	{
		maze[i] = malloc(cols * sizeof(char *));
		i++;
	}
}

void	alloc_visited()
{
	int i;

	i = 0;
	visited = malloc(line * sizeof(char *));
	while (i < line)
	{
		visited[i] = malloc(cols * sizeof(char *));
		i++;
	}
}


void	get_maze(char *file_name)
{
	char c;
	char line_s[3] = { '\0' };
	char cols_s[3] = { '\0' };
	int line_i;
	int cols_i;
	int swap;
	int j;
	int i;

	line_i = 0;
	cols_i = 0;
	swap = 0;
	FILE* file = fopen(file_name, "r");

	if (file)
	{
		while ((c = getc(file)) != EOF)
		{
			printf("%c", c);
			if (c == '\n')
			{
				break ;
			}
			else if (c == ',')
			{
				swap = 1;
			}
			else if (swap != 0)
			{
				line_s[line_i] = c;
				line_i++;
			}
			else
			{
				cols_s[cols_i] = c;
				cols_i++;
			}
		}
	}
	line = ft_atoi(line_s);
	cols = ft_atoi(cols_s);

	alloc_maze();
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < cols)
		{
			c = getc(file);
			if (c == '\n')
			{
				c = getc(file);
			}
			maze[i][j] = c;
			if (c == '1')
			{
				start_row = i;
				start_col = j;
			}
			j++;
		}
		i++;
	}
	fclose(file);	
}

void	get_visited()
{
	alloc_visited();
	int i;
	int j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < cols)
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

/*
 ** Recursive Function called DFS selecting an arbitrary node as the root
 ** in the case of the graph and explores as far as possible along each
 ** branch before backtracking.
 */

/*int	bfs(int row, int col)
  {
  int tries;
  int* current = &visited[row][col];

  tries = 0;
  if (*current->mode == 2)
  while (1)
  {
 *current->mode = 3;

 if (*current->up != NULL)
 {
 if (*current->up->mode == 1)
 {
 printf("Found the solution\n");
 *current->up->mode = 5;
 return 1;
 }
 else if (*current->up->mode == 0)
 {
 *current->up->mode = 3;
 ptrLast->next = *current->up;
 ptrLast = *current->up;
 }
 }
 if (*current->left != NULL)
 {
 if (*current->left->mode == 1)
 {
 printf("Found the solution\n");
 *current->left->mode = 5;
 return 1;
 }
 else if (*current->left->mode == 0)
 {
 *current->left->mode = 3;
 ptrLast->next = *current->left;
 ptrLast = *current->left;
 }
 }
 if (*current->down != NULL)
 {
 if (*current->down->mode == 1)
 {
 printf("Found the solution\n");
 *current->down->mode = 5;
 return 1;
 }
 else if (*current->down->mode == 0)
 {
 *Current->down->mode = 3;
 ptrLast->next = *current->down;
 ptrLast = *current->down;
 }
 }
 if (*current->right != NULL)
 {
 if (*current->right->mode == 1)
 {
 printf("Found the solution\n");
 *current->right->mode = 5;
 return 1;
 }
 else if (*current->right->mode == 0)
 {
 *current->right->mode = 3;
 ptrLast->next = *current->right;
 ptrLast = *current->right;
 }
 }
if (*current->next != 0)
	*current = *current->next;
	else
{
	printf("Nowhere to go, can't reach destination.\n");
	return 0;
}
tries++;
if (tries > 2000)
{
	printf("Didn't found the solution after 2000 tires.\n");
	return 0;
}
}
else
{
	printf("Properly set beginning tile to mode2.\n");
	return 0;
}
} */


int	dfs(int row, int col) {
	int* current = &visited[row][col];

	if (*current == goal) {
		return 1;
	}

	if (*current == empty) {
		*current = wall;

		if (dfs(row + 1, col)) {
			*current = steps;
			return 1;
		}	
		if (dfs(row, col - 1)) {
			*current = steps;
			return 1;
		}
		if (dfs(row, col + 1)) {
			*current = steps;
			return 1;
		}
		if (dfs(row - 1, col)) {
			*current = steps;
			return 1;
		}	
	}
	return 0;
}

void	add_steps()
{
	int i;
	int j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < cols)
		{
			if (maze[i][j] != '1')
			{
				if (visited[i][j] == steps)
				{
					maze[i][j] = 'o';
				}
			}
			j++;
		}
		i++;
	}
}

int			fixmap(t_bfs *solution, int steps)
{
	solution = solution->parent;
	while (solution->parent != NULL)
	{
		solution = solution->parent;
		steps++;
	}
	return (steps);
}

static void	print_steps(int steps)
{
	ft_putstr("RESULT IN ");
	ft_putnbr(steps);
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
	while (i < line)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d", visited[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

void	print_maze()
{
	int i;
	int j;
	int steps;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < cols)
		{
			printf("%c", maze[i][j]);
			j++;
		}
		steps = j;
		printf("\n");
		i++;
	}
	print_steps(steps);
}

int	dup_check(char *str)
{
	char	arr[128];
	int		i;

	i = 0;
	while (i < 128)
		arr[i++] = 0;
	i = 0;
	while (str[i])
	{
		if (!(arr[(int)str[i]]))
			arr[(int)str[i]] = str[i];
		i++;
	}
	while (*str)
	{
		if (arr[(int)*str])
		{
			arr[(int)*str] = 0;
			str++;
		}
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	int fd;

	fd = 0;
	if (argc == 2 || argc == 3 || argc == 4)
	{
		i = 1;
		if (access(argv[i++], F_OK) == -1)
		{
			ft_putendl("MAP ERROR");
			close(fd);
		}
	}
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			//get_maze(argv[i]);
			//get_visited();
			//	printf("%d, %d\n", line, cols);

			//print_maze();
			//	print_visited();

			get_maze(argv[i]);
			get_visited();
			//	bfs();
			dfs(start_row, start_col);
			add_steps();
			print_maze();
			i++;
		}
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" <input filename> ");
	}	
	return 0;
}
