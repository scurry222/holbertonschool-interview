#include "menger.h"

/**
 * next_menger_char - check to print '#' or ' '
 * @row: row to place character
 * @col: column to place character
 *
 * Return: '#' or ' '
 */
char next_menger_char(size_t row, size_t col)
{
	while (row && col)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
		row = row / 3;
		col = col / 3;
	}
	return ('#');
}

/**
 * menger - create a 2D menger sponge out of hashes
 * @level: amount of levels deep of menger sponge to create
 */
void menger(int level)
{
	size_t size, row, col;

	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			putchar(next_menger_char(row, col));
		putchar('\n');
	}
}
