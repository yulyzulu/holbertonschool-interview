#include "menger.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
*menger - Function that draw a 2D version of the Menger sponge
*@level: The level of the Menger Sponge to draw
*/
void menger(int level)
{
	int i, j, x, y, cons = 1, size;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			while (cons)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					printf(" ");
					break;
				}
				if (x == 0 || y == 0)
				{
					printf("#");
					break;
				}
				x = x / 3;
				y = y / 3;
			}
		}
		printf("\n");
	}

}
