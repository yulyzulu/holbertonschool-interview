#include "slide_line.h"

/**
*direction_left - Move to the left
*@line: Pointer to an array of integers
*@size: size of the array
*Return: 1 uppon success, or 0 upon failure
*/
int direction_left(int *line, int size)
{
	int x, y;
	int tmp = line[0], aux = 0;

	for (x = 0; x < size; x++)
	{
		for (y = x + 1; y < size; y++)
		{
			if (line[y] != 0)
			{
				if (tmp == line[y])
				{
					tmp = tmp + line[y];
					line[y] = 0;
					break;
				}
				else if (tmp == 0)
				{
					tmp = line[y];
					line[x] = tmp;
					line[y] = 0;
				}
				else
				{
					tmp = line[x];
					aux = 1;
					break;
				}
			}
		}
		line[x] = tmp;
		if (aux == 1)
		{
			tmp = line[x + 1];
			aux = 0;
		}
		else
			tmp = 0;
	}
	return (1);
}


/**
*direction_rigth - Move to the right
*@line: Pointer to an array of integers
*@size: size of the array
*Return: 1 uppon success, or 0 upon failure
*/
int direction_right(int *line, int size)
{
	int x, y;
	int tmp = line[size - 1], aux = 0;

	for (x = size - 1; x >= 0; x--)
	{
		for (y = x - 1; y >= 0; y--)
		{
			if (line[y] != 0)
			{
				if (tmp == line[y])
				{
					tmp = tmp + line[y];
					line[y] = 0;
					break;
				}
				else if (tmp == 0)
				{
					tmp = line[y];
					line[x] = tmp;
					line[y] = 0;
				}
				else
				{
					tmp = line[x];
					aux = 1;
					break;
				}
			}
		}
		line[x] = tmp;
		if (aux == 1)
		{
			tmp = line[x - 1];
			aux = 0;
		}
		else
			tmp = 0;
	}
	return (1);
}

/**
*slide_line - Function that slides and merges an array of integers
*@line: pointer to an array of integers
*@size: size of the array
*@direction: left or right
*Return: 1 uppon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction == SLIDE_LEFT)
		return (direction_left(line, (int)size));
	if (direction == SLIDE_RIGHT)
		return (direction_right(line, (int)size));
	return (0);
}
