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
	printf("here : %d\n", steps);
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
	
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < cols)
		{
			printf("%c", maze[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_putstr("RESULT IN ");
//	printf("here : %d\n", steps);
	ft_putnbr(steps - 1);
	ft_putstr(" STEPS!\n");
}

int	main(int argc, char *argv[])
{
	int i;
	
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			get_maze(argv[1]);
			get_visited();
		//	printf("%d, %d\n", line, cols);
			
			print_maze();
	//		print_visited();
		
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
