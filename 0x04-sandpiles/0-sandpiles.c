#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: integer sandpile1
 * @grid2: integer sandpile2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, x, y;
	int sandpile[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (sandpile_static(grid1) == 1)
	{
		printf("=\n");
		print_grid(grid1);
		copy(sandpile, grid1);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (sandpile[x][y] > 3)
				{
					grid1[x][y] = grid1[x][y] - 4;
					if (x != 2)
						grid1[x + 1][y] = grid1[x + 1][y] + 1;
					if (x != 0)
						grid1[x - 1][y] = grid1[x - 1][y] + 1;
					if (y != 2)
						grid1[x][y + 1] = grid1[x][y + 1] + 1;
					if (y != 0)
						grid1[x][y - 1] = grid1[x][y - 1] + 1;
				}
			}
		}
	}
}
/**
 * sandpile_static- Funcion that verifies static sandpile
 * @sandpile: integer
 * Return: integer
 */
int sandpile_static(int sandpile[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (sandpile[x][y] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * print_grid - Function to prind grid
 * @grid: Integer grid
 */

static void print_grid(int grid[3][3])
{
	int i, j;

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
 * copy- Function to copy sandpile
 * @sandpile: integer
 * @grid1: integer
 */
void copy(int sandpile[3][3], int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sandpile[i][j] = grid1[i][j];
		}
	}
}
