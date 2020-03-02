#include "sandpiles.h"

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: frist grid to add
 * @grid2: second grid to add, becomes buffer after initial addition
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	add_piles(grid1, grid2);
	while (unstable(grid1))
	{
		print_grid(grid1);
		disperse(grid1, grid2);
		add_piles(grid1, grid2);
	}
}

/**
 * add_piles - add both input grids together into first grid
 * @grid1: int matrix to hold value after addition
 * @grid2: int matrix to be the additive, then initialize to zero
 */
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
}

/**
 * unstable - check if grid is in a stable state
 * @grid: int matrix to view, all values must be below 3
 *
 * Return: 1 if unstable, 0 if not
 */
int unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * print_grid - print current state of grid
 * @grid: grid to either return or disperse, depending on threshold of
 *  dispersement
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * disperse - spread the value to adjacent elements in grid
 * @grid1: grid to check if dispersement necessary
 * @grid2: grid to add dispersement
 */
void disperse(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j] += 1;

				if (j > 0)
					grid2[i][j - 1] += 1;

				if (i < 2)
					grid2[i + 1][j] += 1;

				if (j < 2)
					grid2[i][j + 1] += 1;

				grid1[i][j] -= 4;
			}
	add_piles(grid1, grid2);
}
